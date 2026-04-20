#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Define LED pin
#define LED_PIN  GPIO_NUM_2

void app_main(void)
{
    // Configure GPIO pin as output
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << LED_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pull_down_en = 0,
        .pull_up_en = 0,
    };
    
    // Apply configuration
    gpio_config(&io_conf);
    
    printf("LED blinking started on GPIO %d\n", LED_PIN);
    
    // Blink LED forever
    while (1) {
        // Turn LED ON
        gpio_set_level(LED_PIN, 1);
        printf("LED ON\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Wait 1 second
        
        // Turn LED OFF
        gpio_set_level(LED_PIN, 0);
        printf("LED OFF\n");
        vTaskDelay(100 / portTICK_PERIOD_MS);  // Wait 1 second
    }
}
