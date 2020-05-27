/*
 * Java
 *
 * Copyright 2013-2020 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
package com.microej;

/**
 *
 */
public class RoundRobinTestTask implements Runnable {

	public static int COUNTER = 0;

	private final int id;

	public RoundRobinTestTask(int id) {
		this.id = id;
	}

	@Override
	public void run() {
		synchronized (MJVMPortValidation.ROUND_ROBIN_LOCK) {
			if (!MJVMPortValidation.ROUND_ROBIN_IS_RUNNING) {
				++COUNTER;
				System.out.println("Task " + this.id + " is waiting for start...");
				try {
					MJVMPortValidation.ROUND_ROBIN_LOCK.wait();
				} catch (InterruptedException e) {
					throw new Error();
				}
			}
		}
		while (MJVMPortValidation.ROUND_ROBIN_IS_RUNNING) {
			++MJVMPortValidation.ROUND_ROBIN_TASK_COUNTERS[this.id];
		}
		System.out.println("Task " + this.id + " ends.");
	}

}
