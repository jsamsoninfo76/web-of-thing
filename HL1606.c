#include "HL1606.h"
#include <rflpc17xx/rflpc17xx.h>

extern int led_strip_size;
extern control_command COMMANDE_ALL_OFF;
extern int spi_port_used;

int
init_hl1606(rflpc_spi_t port, int length)
{
  rflpc_spi_init(port, RFLPC_SPI_MASTER, RFLPC_CCLK_8, 8, 32, 1);

  spi_port_used = port;
  led_strip_size = length;

  rflpc_gpio_set_pin_mode_output(2, 0);
  rflpc_gpio_clr_pin(2, 0);
  
  COMMANDE_ALL_OFF.blue = OFF;
  COMMANDE_ALL_OFF.green = OFF;
  COMMANDE_ALL_OFF.red = OFF;
  COMMANDE_ALL_OFF.fade_speed = 0;
  COMMANDE_ALL_OFF.can_latch = 1;

  return 1;
}

int
put_command(control_command commande)
{
  rflpc_spi_write(spi_port_used, *((int*)&commande));  
  while(!(rflpc_spi_tx_fifo_empty(spi_port_used))) ;
  return 1;
}

void
flush_command()
{
  rflpc_gpio_set_pin(2, 0);
  RFLPC_DELAY(100000);
  rflpc_gpio_clr_pin(2, 0);
}

