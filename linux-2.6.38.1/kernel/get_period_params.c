/* Michalis Karagiannakis csd4355 */

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/period_params.h>
#include <asm/uaccess.h>
#include <asm-generic/errno-base.h>
#include <asm-generic/current.h>


asmlinkage long sys_get_period_params(struct period_params * params) {
	printk("Michalis Karagiannakis csd4355: Called system call get_period_params\n");

	if(params==NULL) {
		return EINVAL;
	}else{
		if(access_ok(VERIFY_WRITE, params, sizeof(struct period_params))) {
               		params->period = get_current()->period;
                	params->execution_time = get_current()->execution_time;
                	params->num_of_periods = get_current()->num_of_periods;
        	}
		return 0;
	}
}
