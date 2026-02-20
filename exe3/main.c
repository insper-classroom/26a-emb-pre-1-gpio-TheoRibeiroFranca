#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_VERMELHO = 4;
const int LED_VERDE = 6;
const int BTN_VERMELHO = 28;
const int BTN_VERDE = 26;
int main() {
  stdio_init_all();

  gpio_init(LED_VERMELHO);
  gpio_init(LED_VERDE);
  gpio_set_dir(LED_VERMELHO, GPIO_OUT);
  gpio_set_dir(LED_VERDE, GPIO_OUT);

  gpio_init(BTN_VERMELHO);
  gpio_set_dir(BTN_VERMELHO, GPIO_IN);
  gpio_pull_up(BTN_VERMELHO);

  gpio_init(BTN_VERDE);
  gpio_set_dir(BTN_VERDE, GPIO_IN);
  gpio_pull_up(BTN_VERDE);

  int led_vermelho_estado = 0;
  int led_verde_estado = 0;

  gpio_put(LED_VERMELHO, led_vermelho_estado);
  gpio_put(LED_VERDE, led_verde_estado);

  while (true) {
    if (gpio_get(BTN_VERMELHO) == 0) {
      while(!gpio_get(BTN_VERMELHO)) {
      }
      led_vermelho_estado = !led_vermelho_estado;
      gpio_put(LED_VERMELHO, led_vermelho_estado);
      sleep_ms(20);
    }

    if (gpio_get(BTN_VERDE) == 0) {
      while(!gpio_get(BTN_VERDE)) {
      }
      led_verde_estado = !led_verde_estado;
      gpio_put(LED_VERDE, led_verde_estado);
      sleep_ms(20);
    }
  }
}
