/* Michalis Karagiannakis csd4355 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#define set_period_params(period,execution_time,num_of_periods) syscall(341,period,execution_time,num_of_periods)


#define get_period_params(params) syscall(342,params)

int main() {

	struct period_params * params=NULL;
	printf("SET_SUCCESS - Return value : %d\n",set_period_params(5,300,4));
	printf("GET_ERROR - Return value : %d -Before memory allocation\n",get_period_params(params)); 

	
	params = malloc(sizeof(struct period_params));
	printf("GET_SUCCESS - Return value : %d -After memory allocation\n",get_period_params(params));	
	
	printf("\n");
	
	printf("params->period = %d\n",params->period);
	printf("params->execution_time = %d\n",params->execution_time);
	printf("params->num_of_periods = %d\n",params->num_of_periods);
		
	printf("\n");

	printf("SET_ERROR - Return value : %d\n",set_period_params(2,3000,4));
	printf("GET_SUCCESS - Return value : %d\n",get_period_params(params));

	printf("\n");
	
	printf("params->period = %d\n",params->period);
	printf("params->execution_time = %d\n",params->execution_time);
	printf("params->num_of_periods = %d\n",params->num_of_periods);
	
	printf("\n");
	printf("The values did not change because set_period_params failed\n");
	printf("\n");
	
	printf("SET_SUCCESS - Return value : %d\n",set_period_params(9,1500,3));
	printf("GET_SUCCESS - Return value : %d\n",get_period_params(params));
	
	printf("\n");
	
	printf("params->period = %d\n",params->period);
	printf("params->execution_time = %d\n",params->execution_time);
	printf("params->num_of_periods = %d\n",params->num_of_periods); 

	printf("\n");
}
