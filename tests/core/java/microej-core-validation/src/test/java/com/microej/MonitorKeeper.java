/*
 * Java
 *
 * Copyright 2013-2020 MicroEJ Corp. All rights reserved.
 * This library is provided in source code for use, modification and test, subject to license terms.
 * Any modification of the source code will break MicroEJ Corp. warranties on the whole library.
 */
package com.microej;

/**
 * Synchronizes on a list of monitors and sleeps for a while.
 */
public class MonitorKeeper implements Runnable {
	static final int THREAD_COUNT = 5;
	static final int MONITOR_PER_THREAD_COUNT = 7;
	static final int SLEEP_TIME = 5_000;
	static int errorCount;

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
