
#include <stdio.h>
#include <string.h>
#include <FreeRTOS.h>
#include <task.h>
#include <bl_gpio.h>

#define RED_LED_PIN 14
#define GREEN_LED_PIN 17
#define BLUE_LED_PIN 3

#define DELAY 500

void enable_pin(uint8_t pin)
{
    bl_gpio_output_set(pin, 1);
    vTaskDelay(DELAY);
    bl_gpio_output_set(pin, 0);
    vTaskDelay(DELAY);
}

void blink_test(void *param)
{
    bl_gpio_enable_output(RED_LED_PIN, 0, 0);
    bl_gpio_enable_output(GREEN_LED_PIN, 0, 0);
    bl_gpio_enable_output(BLUE_LED_PIN, 0, 0);

    while (1)
    {
        enable_pin(RED_LED_PIN);
        enable_pin(GREEN_LED_PIN);
        enable_pin(BLUE_LED_PIN);     
    }
}

void main(void)
{
    xTaskCreate(blink_test, "blink", 1024, NULL, 15, NULL);
}
