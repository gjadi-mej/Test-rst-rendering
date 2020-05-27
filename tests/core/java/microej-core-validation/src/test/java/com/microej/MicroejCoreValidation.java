/*
 * Java
 *
 * Copyright 2013-2020 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
package com.microej;

import static org.junit.Assert.fail;

import org.junit.BeforeClass;
import org.junit.Test;

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

	static Class THIS_CLASS = MJVMPortValidation.class;

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

	/**
	 * @throws java.lang.Exception
	 */
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		printProduct();
	}

	@Test
	public void test() {
		fail("Not yet implemented");
	}

}
