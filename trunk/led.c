/*
<generator>
	<handlers doGet="doGet"/>
	<args>
		<arg name="nled" type="uint8" />
		<arg name="etat" type="uint8" />
	</args>
</generator>
*/

#include <rflpc17xx/rflpc17xx.h>

static char doGet(struct args_t *args){
	rflpc_led_init() ;
	
	switch (args->nled)
	{
		case 0: 
			if (args->etat == 1) rflpc_led_set(RFLPC_LED_1);
			else rflpc_led_clr(RFLPC_LED_1);
			break;
		case 1: 
			if (args->etat == 1) rflpc_led_set(RFLPC_LED_2);
			else rflpc_led_clr(RFLPC_LED_2);
			break;
		case 2: 
			if (args->etat == 1) rflpc_led_set(RFLPC_LED_3);
			else rflpc_led_clr(RFLPC_LED_3);
			break;
		case 3: 
			if (args->etat == 1) rflpc_led_set(RFLPC_LED_4);
			else rflpc_led_clr(RFLPC_LED_4);
			break;
	} 
	

	return 0 ;
}
