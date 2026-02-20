#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN =28;
const int LED_VERMELHO = 5;
const int LED_ROXO = 8;
const int LED_AZUL = 11;
const int LED_AMARELO = 15;
int main() {
  stdio_init_all();
  gpio_init(LED_VERMELHO);
  gpio_init(LED_ROXO);
  gpio_init(LED_AZUL);
  gpio_init(LED_AMARELO);
  gpio_set_dir(LED_VERMELHO, GPIO_OUT);
  gpio_set_dir(LED_ROXO, GPIO_OUT);
  gpio_set_dir(LED_AZUL, GPIO_OUT);
  gpio_set_dir(LED_AMARELO, GPIO_OUT);
  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if (gpio_get(BTN) == 0) {
      while(!gpio_get(BTN)) {
      }
      gpio_put(LED_VERMELHO, 1);
      sleep_ms(300);
      gpio_put(LED_VERMELHO, 0);
      gpio_put(LED_ROXO, 1);
      sleep_ms(300);
      gpio_put(LED_ROXO, 0);
      gpio_put(LED_AZUL, 1);
      sleep_ms(300);
      gpio_put(LED_AZUL, 0);
      gpio_put(LED_AMARELO, 1);
      sleep_ms(300);
      gpio_put(LED_AMARELO, 0);
    }
  }
}
