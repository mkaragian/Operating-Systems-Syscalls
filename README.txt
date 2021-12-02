====================================

	Michalis Karagiannakis
	      csd4355

====================================

This README file describes my implementation of system calls, set_period_params() and get_period_params().

Firstly I followed all the instructions and modified the right files of the OS so the two new system calls may exist.

In set_period_params, I print my name, my number and the arguments in kernel level with printk and if execution time is less than the time of the period , I update
the task_struct members of the current procedure with the arguments that are given as parameters of the system call. If the system call succeeds it returns 0 but
if it fails , it returns EINVAL.

In get_period_params,