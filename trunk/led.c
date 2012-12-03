/*
<generator>
	<handlers doGet="doGet"/>
	<args>
		<arg name="nled" type="uint8" />
		<arg name="init" type="uint8" />
	</args>
</generator>
*/

#define NBLEDS 6
#include <rflpc17xx/rflpc17xx.h>


static int tab[NBLEDS];
static int estInit = 0 ;

static void initTab(){
    if(estInit == 0){
        int i;
        for(i=0 ; i<NBLEDS ; i++ ){
            tab[i] = 0 ;
        }
    }
    estInit = 1 ;
}

static char doGet(struct args_t *args){
    rflpc_led_init() ;
    rflpc_gpio_set_pin_mode_output(2,5);
    rflpc_gpio_set_pin_mode_output(2,4);
    initTab() ;
    
    unsigned nomLed ;
    int numLed = args->nled ;
    int init = args->init ;
    
	switch (numLed)
	{
		case 0: nomLed=RFLPC_LED_1 ;
                break;
            
		case 1: nomLed=RFLPC_LED_2 ;
                break;
            
		case 2: nomLed=RFLPC_LED_3 ;
                break;
            
		case 3: nomLed=RFLPC_LED_4 ;
                break;
        
 	        case 4: nomLed = 5;
          	break;
            
        	case 5: nomLed = 4;
            	break;
	}
	
    if (!init)
    {
     if (tab[numLed] == 0){
        if(numLed < 4)
            rflpc_led_set(nomLed);
        else
            rflpc_gpio_set_pin(2, nomLed);
        
        tab[numLed] = 1 ;
     }else{
        if(numLed < 4)
            rflpc_led_clr(nomLed);
        else
            rflpc_gpio_clr_pin(2, nomLed);
        tab[numLed] = 0 ;
     }
    }
    
    out_uint(tab[numLed]);

    return 1 ;
}
