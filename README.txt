====================================

	Michalis Karagiannakis
	      csd4355

====================================

This README file describes my implementation of system calls, set_period_params() and get_period_params().

Firstly I followed all the instructions and modified the right files of the OS so the two new system calls may exist.

In set_period_params, I print my name, my number(AM) and the arguments in kernel level with printk and if execution time* is less than the time of the period , I update
the task_struct members of the current procedure with the arguments that are given as parameters of the system call. If the system call succeeds it returns 0 but
if it fails , it returns EINVAL.

*Because we get the execution_time in milliseconds, I convert it to seconds and then I compare it to period.

In get_period_params, I print my name, my number(AM) and that I call get_period_params. After that, I check if params is NULL. If it is NULL I return EINVAL but
if it is not NULL I return 0. If params is not NULL I call access_ok for params in order to check if it is "legal" to access it. If I can access it, I change
its fields with the values of task_struct with get_current().