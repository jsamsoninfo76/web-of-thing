/*
<generator>
	<handlers init="init" doGet="doGet"/>
	<args>
		<arg name="dir" type="uint8" />
	</args>
</generator>
*/

#include <rflpc17xx/rflpc17xx.h>

static char currentPosition = '';

void configure_timer(void)
{
   rflpc_timer_enable(RFLPC_TIMER0);
   rflpc_timer_set_clock(RFLPC_TIMER0,RFLPC_CCLK_8);
   rflpc_timer_set_pre_scale_register(RFLPC_TIMER0, rflpc_clock_get_system_clock()/8000000); /* microsecond timer */
   rflpc_timer_start(RFLPC_TIMER0);
}

void wait(int micros)
{
   uint32_t start = rflpc_timer_get_counter(RFLPC_TIMER0);
   while ((rflpc_timer_get_counter(RFLPC_TIMER0) - start) < micros);
   return;
}

void position_start(void){
	int i;
	for(i=0 ; i<23; i++){
		rflpc_gpio_set_pin(2,5);
		wait(600);
		rflpc_gpio_clr_pin(2,5);
		wait(20000+600);
	}
	currentPosition = 'g';
}

void position_middle(void){
	int i;
	for(i=0 ; i<23 ; i++){
		rflpc_gpio_set_pin(2,5);
		wait(1500);
		rflpc_gpio_clr_pin(2,5);
		wait(20000-1500);
	}
	currentPosition = 'h';
}

void position_end(void){
	int i;
	for(i=0 ; i<23 ; i++){
		rflpc_gpio_set_pin(2,5);
		wait(2400);
		rflpc_gpio_clr_pin(2,5);
		wait(20000-2400);
	}
	currentPosition = 'd';
}

static char doGet(struct args_t *args){
	rflpc_gpio_set_pin_mode_output(2,5);
	rflpc_led_init();
	configure_timer();
	
	int dir = args->dir;

	if (currentPosition == '') position_start();
	

	switch(dir)
	{
		case 'd' : position_end();
		break;

		case 'g' : position_start();
		break;
		
		case 'h' : position_middle();
		break;
	}	
	
	out_str(dir);

	return 1 ;
}
