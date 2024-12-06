#include "hal/gpio_types.h"
#include "soc/gpio_num.h"
#include <stdio.h>
#include <stdint.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void app_main(void)
{
  // setup pin for button use
  gpio_set_direction(GPIO_NUM_22, GPIO_MODE_INPUT);
  gpio_set_pull_mode(GPIO_NUM_22, GPIO_PULLUP_ONLY);

  // setup LED
  gpio_set_direction(GPIO_NUM_26, GPIO_MODE_OUTPUT);

  while (1) {
    // check state of button and toggle LED accordingly
    if (gpio_get_level(GPIO_NUM_22)) {
      gpio_set_level(GPIO_NUM_26, 0);
    } else {
      gpio_set_level(GPIO_NUM_26, 1);
    }
    // yield time back to the rtos
    // also must divide by portTICK_PERIOD_MS because value is MCU ticks
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
