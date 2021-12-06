 /* Michalis Karagiannakis csd4355 */

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm-generic/errno-base.h>
#include <asm-generic/current.h>

asmlinkage long sys_set_period_params(int period, int execution_time, int num_of_periods) {
	printk("Michalis Karagiannakis csd4355: Called system call set_period_params with args: %d %d %d\n",period, execution_time, num_of_periods);
	int execution_time_secs;
	execution_time_secs = execution_time / 1000;
	if(execution_time_secs <= period) {
		get_current()->period = period;
		get_current()->execution_time = execution_time;
		get_current()->num_of_periods = num_of_periods;
		return 0;
	}else{
		return EINVAL;
	}
}
