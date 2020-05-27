/*
 * Java
 *
 * Copyright 2013-2020 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
package com.microej;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;

import org.junit.BeforeClass;
import org.junit.Test;

import ej.bon.Immortals;
import ej.bon.Immutables;
import ej.bon.Util;

/**
 * Tests for MicroEJ Core port. Before releasing a MicroEJ Platform, TCK should be:
 * <ul>
 * <li>caffeineMark results should be similar to caffeineMark results without RTOS</li>
 * <li>this test must pass</li>
 * </ul>
 * Test features:
 * <ul>
 * <li>FPU</li>
 * <li>Read Only Memory</li>
 * <li>Visible clock</li>
 * <li>Time</li>
 * <li>Monotonic Time</li>
 * <li>Java Round robin</li>
 * </ul>
 */
public class MicroejCoreValidation {

	public static final String VERSION = "2.4.0";

	public static final String PROPERTY_SUFFIX = "MJVMPortValidation.";
	public static final String OPTION_CLOCK_NB_SECONDS = "clock.seconds";

	static Class THIS_CLASS = MicroejCoreValidation.class;

	// Time constants
	public static final int MAX_SLEEP_DELTA = 10;

	// Round Robin constants
	public static final int NB_THREADS = 4;
	public static final int ROUND_ROBIN_TEST_DURATION = 10000;
	public static final int ROUND_ROBIN_MIN_COUNTER_REQUIRED = 500;
	public static final int ROUND_ROBIN_MAX_DELTA_PERCENTAGE_ALLOWED = 5;

	public static volatile boolean ROUND_ROBIN_IS_RUNNING;
	public static Object ROUND_ROBIN_LOCK = new Object();
	public static long[] ROUND_ROBIN_TASK_COUNTERS;

	// Set this fields volatile so we are sure accesses are not optimized
	volatile public static double double3 = 3d;
	volatile public static double double4 = 4d;
	volatile public static float float3 = 3f;
	volatile public static float float4 = 4f;

	private static void printProduct() {
		final String sep = "*****************************************************************************************************";
		System.out.println(sep);
		System.out.println("*                                  MicroEJ Core Validation - " + VERSION
				+ "                                  *");
		System.out.println(sep);
		System.out.println(
				"* Copyright 2013-2020 MicroEJ Corp. All rights reserved.                                            *");
		System.out.println(
				"* This library is provided in source code for use, modification and test, subject to license terms. *");
		System.out.println(
				"* Any modification of the source code will break MicroEJ Corp. warranties on the whole library.     *");
		System.out.println(sep);
		System.out.println();
	}

	private static int getOptionAsInt(String optionName, int defaultValue, String unit) {
		String propertyName = PROPERTY_SUFFIX + optionName;
		String valueStr = System.getProperty(propertyName);
		int value;
		if (valueStr == null) {
			value = defaultValue;
			System.out.println("Property '" + propertyName + "' is not set (default to '" + value + "' " + unit
					+ (value > 1 ? "s" : "") + ")");
		} else {
			try {
				value = Integer.parseInt(valueStr);
				System.out.println(
						"Property '" + propertyName + "' is set to '" + value + "' " + unit + (value > 1 ? "s" : ""));
			} catch (NumberFormatException e) {
				value = defaultValue;
				System.out.println("Property '" + propertyName + "' is invalid (set to '" + valueStr + "', default to '"
						+ value + "' " + unit + (value > 1 ? "s" : "") + ")");
			}
		}
		return value;
	}

	private static void tryToSynchronizeOn(List<Object[]> objects, boolean mustFail) {
		MonitorKeeper.errorCount = 0;
		Thread[] threads = new Thread[MonitorKeeper.THREAD_COUNT];

		try {
			for (int i = 0; i < threads.length; i++) {
				threads[i] = new Thread(new MonitorKeeper(objects.get(i)));
			}

			for (Thread thread : threads) {
				thread.start();
			}

			for (Thread thread : threads) {
				try {
					thread.join();
				} catch (InterruptedException e) {
				}
			}

			boolean success;
			if (mustFail) {
				success = MonitorKeeper.errorCount > 0;
			} else {
				success = MonitorKeeper.errorCount == 0;
			}
			assertTrue("Too many synchronized monitors.", success);
		} catch (IndexOutOfBoundsException ioobe) {
			fail("No objects to synchronize on, aborting.");
		}
	}

	private static List<Object[]> objectsFromRam() {
		List<Object[]> objects = new ArrayList<>();

		for (int i = 0; i < MonitorKeeper.THREAD_COUNT; i++) {
			Object[] objects2 = new Object[MonitorKeeper.MONITOR_PER_THREAD_COUNT];
			for (int j = 0; j < objects2.length; j++) {
				objects2[j] = new Object();
			}
			objects.add(objects2);
		}

		return objects;
	}

	private static List<Object[]> objectsFromImmortals() {
		List<Object[]> objects = new ArrayList<>();

		for (int i = 0; i < MonitorKeeper.THREAD_COUNT; i++) {
			Object[] objects2 = new Object[MonitorKeeper.MONITOR_PER_THREAD_COUNT];
			for (int j = 0; j < objects2.length; j++) {
				Object object = new Object();
				Immortals.setImmortal(object);
				objects2[j] = object;
			}
			objects.add(objects2);
		}

		return objects;
	}

	private static List<Object[]> objectsFromImmutables() {
		List<Object[]> objects = new ArrayList<>();
		int objectID = 0;

		try {
			for (int i = 0; i < MonitorKeeper.THREAD_COUNT; i++) {
				Object[] objects2 = new Object[MonitorKeeper.MONITOR_PER_THREAD_COUNT];
				for (int j = 0; j < objects2.length; j++) {
					Object object = Immutables.get("array" + objectID++);
					objects2[j] = object;
				}
				objects.add(objects2);
			}
		} catch (NoSuchElementException nsee) {
			System.out.println("Can't find the requested object in the immutables, check your launch configuration.");
		}

		return objects;
	}

	private static List<Object[]> stringsFromImmutables() {
		List<Object[]> objects = new ArrayList<>();

		objects.add(new String[] { "0", "1", "2", "3", "4", "5", "6" });
		objects.add(new String[] { "7", "8", "9", "10", "11", "12", "13" });
		objects.add(new String[] { "14", "15", "16", "17", "18", "19", "20" });
		objects.add(new String[] { "21", "22", "23", "24", "25", "26", "27" });
		objects.add(new String[] { "28", "29", "30", "31", "32", "33", "34" });

		return objects;
	}

	private static List<Object[]> classes() {
		List<Object[]> objects = new ArrayList<>();

		objects.add(new Class[] { Integer.class, Boolean.class, Long.class, Float.class, Double.class, Thread.class,
				Object.class });
		objects.add(new Class[] { Byte.class, Character.class, Calendar.class, ArrayList.class, List.class, Class.class,
				Exception.class });
		objects.add(new Class[] { InputStream.class, OutputStream.class, Map.class, HashMap.class, Hashtable.class,
				Reader.class, Writer.class });
		objects.add(new Class[] { Number.class, Throwable.class, String.class, Short.class, Enum.class, Runtime.class,
				Package.class });
		objects.add(new Class[] { System.class, Math.class, StringBuilder.class, StringBuffer.class, Runnable.class,
				Iterable.class, Iterator.class });

		return objects;
	}

	static native float testFPU(float a, float b);

	static native double testFPU(double a, double b);

	static float testFPUJava(float a, float b) {
		return a * b;
	}

	static double testFPUJava(double a, double b) {
		return a * b;
	}

	/**
	 * @throws java.lang.Exception
	 *             If an error occurred.
	 */
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		printProduct();
	}

	@Test
	public void testVisibleClock() {
		System.out.println("-> Check visible clock (LLMJVM_IMPL_getCurrentTime validation)...");
		int defaultNbSeconds = 10;
		int nbSeconds = getOptionAsInt(OPTION_CLOCK_NB_SECONDS, defaultNbSeconds, "second");

		// Check if a message is printed every seconds in terminal:
		long timeStart = System.currentTimeMillis();
		int seconds = 0;
		long nbMilliSeconds = nbSeconds * 1000;
		while (true) {
			long time = System.currentTimeMillis();
			long delta = time - timeStart;
			int newSecond = (int) (delta / 1000);
			if (newSecond > seconds) {
				System.out.println(newSecond);
				seconds = newSecond;
			}

			if (delta > nbMilliSeconds) {
				break; // end of test
			}
		}

		// ensure both API returns same value
		long timeEnd1 = System.currentTimeMillis();
		long timeEnd2 = Util.platformTimeMillis();
		long delta = timeEnd2 - timeEnd1;
		CheckHelper.check(THIS_CLASS, "Util.platformTimeMillis() != System.currentTimeMillis()" + MAX_SLEEP_DELTA,
				delta <= MAX_SLEEP_DELTA);

		// ensure nano time is valid
		delta = (Util.platformTimeNanos() / 1000000) - Util.platformTimeMillis();
		CheckHelper.check(THIS_CLASS, "Util.platformTimeNanos()/1000000 != Util.platformTimeMillis()" + MAX_SLEEP_DELTA,
				delta <= MAX_SLEEP_DELTA);
		fail("Not yet implemented");
	}

	@Test
	public void testTime() {
		System.out.println(
				"-> Check schedule request and wakeup (LLMJVM_IMPL_scheduleRequest and LLMJVM_IMPL_wakeupVM validation)...");
		long delay = 5 * 1000;
		System.out.println("Waiting for " + delay / 1000 + "s...");
		long timeBefore = System.currentTimeMillis();
		try {
			Thread.sleep(delay);
		} catch (InterruptedException e) {
			throw new Error();
		}
		long timeAfter = System.currentTimeMillis();
		System.out.println("...done");
		long realDelay = timeAfter - timeBefore;
		CheckHelper.check(THIS_CLASS, "realDelay>=delay", realDelay >= delay);
		long delta = realDelay - delay;
		CheckHelper.check(THIS_CLASS, "delta(=" + delta + ")<=" + MAX_SLEEP_DELTA, delta <= MAX_SLEEP_DELTA);
	}

	@Test
	public void testMonotonicTime() {
		System.out.println(
				"-> Check monotonic time (LLMJVM_IMPL_getCurrentTime, LLMJVM_IMPL_setApplicationTime validation)...");
		long delay = 5 * 1000;
		long elapsedTime = 100;
		long timeOffset = 50_000;
		System.out.println("Waiting for " + delay / 1000 + "s...");
		long monotonicTimeBefore = Util.platformTimeMillis();
		Util.setCurrentTimeMillis(System.currentTimeMillis() + timeOffset);

		try {
			Thread.sleep(delay);
		} catch (InterruptedException e) {
			throw new Error();
		}
		long montonicTimeAfter = Util.platformTimeMillis();
		System.out.println("...done");
		CheckHelper.check(THIS_CLASS, "monotonic time not set", montonicTimeAfter >= monotonicTimeBefore + delay
				&& montonicTimeAfter <= monotonicTimeBefore + delay + elapsedTime);
	}

	@Test
	public void testJavaRoundRobin() {
		System.out.println("-> Check Java round robin (LLMJVM_IMPL_scheduleRequest validation)...");
		System.out.println("For a best resut, please disable all the C native tasks except the MicroEJ task.");
		int nbThreads = NB_THREADS;
		CheckHelper.check(THIS_CLASS, "nbThreads >= 2", nbThreads >= 2);

		ROUND_ROBIN_TASK_COUNTERS = new long[nbThreads];
		int priority = Thread.currentThread().getPriority() - 1;
		Thread[] threads = new Thread[nbThreads];
		for (int i = threads.length; --i >= 0;) {
			Thread t = new Thread(new RoundRobinTestTask(i));
			threads[i] = t;
			t.setPriority(priority);
			t.start();
		}

		// Poll until all threads are waiting on the monitor
		while (RoundRobinTestTask.COUNTER < NB_THREADS) {
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}

		System.out.println("Starting tasks and wait for " + (ROUND_ROBIN_TEST_DURATION / 1000) + " seconds...");
		synchronized (ROUND_ROBIN_LOCK) {
			ROUND_ROBIN_IS_RUNNING = true;
			ROUND_ROBIN_LOCK.notifyAll(); // start !
		}

		try {
			Thread.sleep(ROUND_ROBIN_TEST_DURATION);
		} catch (InterruptedException e1) {
			CheckHelper.check(THIS_CLASS, "Unexpected InterruptedException", false);
		}

		// stop threads
		ROUND_ROBIN_IS_RUNNING = false;
		for (int i = threads.length; --i >= 0;) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				throw new Error();
			}
		}
		System.out.println("...done.");

		long totalCounter = 0;
		long minCounter = Long.MAX_VALUE;
		long maxCounter = 0;
		for (int i = threads.length; --i >= 0;) {
			long counter = ROUND_ROBIN_TASK_COUNTERS[i];
			totalCounter += counter;
			maxCounter = Math.max(maxCounter, counter);
			minCounter = Math.min(minCounter, counter);
		}

		long deltaCounter = maxCounter - minCounter;
		long averageCounter = totalCounter / threads.length;
		long deltaPercentage;
		if (minCounter > 0) {
			deltaPercentage = (deltaCounter * 100) / minCounter;
		} else {
			deltaPercentage = 100;
		}

		CheckHelper.check(THIS_CLASS,
				"counter increments < " + ROUND_ROBIN_MIN_COUNTER_REQUIRED + " (actually " + minCounter + ")",
				minCounter >= ROUND_ROBIN_MIN_COUNTER_REQUIRED);

		CheckHelper.check(THIS_CLASS, "delta percentage > " + ROUND_ROBIN_MAX_DELTA_PERCENTAGE_ALLOWED + " (actually "
				+ deltaPercentage + ")", deltaPercentage <= ROUND_ROBIN_MAX_DELTA_PERCENTAGE_ALLOWED);

		if (deltaPercentage > ROUND_ROBIN_MAX_DELTA_PERCENTAGE_ALLOWED) {
			// Print some information when the test fails
			System.out.println("Min counter = " + minCounter);
			System.out.println("Max counter = " + maxCounter);
			System.out.println("Average = " + averageCounter);
			System.out.println("Delta = " + deltaCounter);
			System.out.println("Delta Percentage = " + deltaPercentage);
		}
	}

	@Test
	public void testIsInReadOnlyMemory() {
		System.out.println("-> Check isInReadOnlyMemory (LLBSP_IMPL_isInReadOnlyMemory validation)...");

		try {
			String s = "literal string";
			synchronized (s) {
				System.out.println("Test synchronize on literal string");
			}
		} catch (IllegalMonitorStateException e) {
			CheckHelper.check(THIS_CLASS,
					"IllegalMonitorStateException during synchronization on immutable object (literal string)", false);
		}

		try {
			synchronized (MJVMPortValidation.class) {
				System.out.println("Test synchronize on class");
			}
		} catch (IllegalMonitorStateException e) {
			CheckHelper.check(THIS_CLASS,
					"IllegalMonitorStateException during synchronization on immutable object (class)", false);
		}

		/*
		 * There is a limit of the number of the synchronized monitors in flash but not in ram. We test this limit is
		 * reached for the objects in flash but not for the objects in ram. If the LLBSP_IMPL_isInReadOnlyMemory
		 * function is not correctly implemented this test can highlight it.
		 */
		System.out.println("Test multiple synchronize");
		tryToSynchronizeOn(objectsFromRam(), false);
		tryToSynchronizeOn(stringsFromImmutables(), true);
		tryToSynchronizeOn(classes(), true);
		tryToSynchronizeOn(objectsFromImmortals(), false);
		tryToSynchronizeOn(objectsFromImmutables(), true);
	}

	@Test
	public void testFPU() {
		System.out.println("-> Check FPU (soft/hard FP option)...");
		// In BSP, write and compile the following functions:
		// --------------------
		// #include "sni.h"
		// jfloat Java_com_is2t_microjvm_test_MJVMPortValidation_testFPU__FF (jfloat a, jfloat b) {return a * b;}
		// jdouble Java_com_is2t_microjvm_test_MJVMPortValidation_testFPU__DD (jdouble a, jdouble b) {return a * b;}
		// --------------------

		CheckHelper.check(THIS_CLASS,
				"test 'float * float' in Java: FPU option is not coherent between MicroEJ Platform and BSP",
				(int) testFPUJava(float3, float4), 12f);
		CheckHelper.check(THIS_CLASS,
				"test 'double * double' in Java: FPU option is not coherent between MicroEJ Platform and BSP",
				(int) testFPUJava(double3, double4), 12);
		CheckHelper.check(THIS_CLASS,
				"test 'float * float' in C: FPU option is not coherent between MicroEJ Platform and BSP",
				(int) testFPU(float3, float4), 12);
		CheckHelper.check(THIS_CLASS,
				"test 'double * double' in C: FPU option is not coherent between MicroEJ Platform and BSP",
				(int) testFPU(double3, double4), 12);

		float parsedFloat = Float.parseFloat("1234.5");
		CheckHelper.check(THIS_CLASS,
				"test 'parse float string': strtof C function not correctly implemented (check your libc configuration)",
				parsedFloat, 1234.5f);

		double parsedDouble = Double.parseDouble("1234.5");
		CheckHelper.check(THIS_CLASS,
				"test 'parse double string': strtod C function not correctly implemented (check your libc configuration)",
				parsedDouble, 1234.5d);

		String floatToString = Float.toString(1234.5f);
		CheckHelper.check(THIS_CLASS,
				"test 'float to string': snprintf C function not correctly implemented (check your libc configuration)",
				floatToString, "1234.5");

		String doubleToString = Double.toString(1234.5d);
		CheckHelper.check(THIS_CLASS,
				"test 'double to string': snprintf C function not correctly implemented (check your libc configuration)",
				doubleToString, "1234.5");
	}

}

/**
 * Synchronizes on a list of monitors and sleeps for a while.
 */
class MonitorKeeper implements Runnable {
	static final int THREAD_COUNT = 5;
	static final int MONITOR_PER_THREAD_COUNT = 7;
	static final int SLEEP_TIME = 5_000;
	public static int errorCount;

	private final Object[] monitors;

	public MonitorKeeper(Object[] monitors) {
		this.monitors = monitors;
	}

	@Override
	public void run() {
		try {
			synchronizeAll(0);
		} catch (Error e) {
			errorCount++;
		}
	}

	private void synchronizeAll(int monitorIndex) {
		if (monitorIndex < this.monitors.length) {
			synchronized (this.monitors[monitorIndex]) {
				synchronizeAll(monitorIndex + 1);
			}
		} else {
			try {
				Thread.sleep(SLEEP_TIME);
			} catch (InterruptedException e) {
			}
		}
	}

}
