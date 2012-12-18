#include <rflpc17xx/rflpc17xx.h>

enum control_action {OFF=0b00, ON=0b01, FADE_IN=0b10, FADE_OUT=0b11};

struct control_command_s
{
  enum control_action green:2;
  enum control_action red:2;
  enum control_action blue:2;
  int fade_speed:1;
  int can_latch:1;
};

typedef struct control_command_s control_command;

int led_strip_size;
control_command COMMANDE_ALL_OFF;
int spi_port_used;

int init_hl1606(rflpc_spi_t port, int latch);
int put_command(control_command commande);
void flush_command();
