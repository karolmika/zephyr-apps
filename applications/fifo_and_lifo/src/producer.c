#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

LOG_MODULE_REGISTER(producer, LOG_LEVEL_INF);

K_FIFO_DEFINE(telemetry_fifo);

/* Setting the thread for Producer work*/
#define PRODUCER_THREAD_INTERVAL_IN_SECONDS 1
#define PRODUCER_STACK_SIZE 2048
#define PRODUCER_PRIORITY 6

/* Producer thread data */
K_THREAD_STACK_DEFINE(producer_stack_area, PRODUCER_STACK_SIZE);
struct k_thread producer_thread_data;
extern void producer_thread_fn(void *, void *, void *);

K_THREAD_DEFINE(producer_thread_id, PRODUCER_STACK_SIZE, producer_thread_fn, NULL, NULL, NULL, 
    PRODUCER_PRIORITY, 0, 0);

/*-------------------------------------
 * PRIVATE FUNCTION PROTOTYPES
 *-----------------------------------*/
/**
 * @brief Generates a random number between min and max (inclusive) that is different from prev_value.
 * This is used to ensure that the producer selects a different city each time.
 * @param min The minimum value of the random number (inclusive).
 * @param max The maximum value of the random number (inclusive).
 * @param prev_value The previous value to avoid returning.
 * @return A random number between min and max that is different from prev_value.
 */
static uint32_t generate_unique_number(uint32_t min, uint32_t max, uint32_t prev_value);

void producer_thread_fn(void *, void *, void *)
{
    uint32_t rnd = 0;
    uint32_t prev_rnd = 0; 
    
    LOG_INF("Producer thread started!");

    struct sensor_data data_tmp= {
        .data_id = 0,
        .temperature = 20.0f,
        .humidity = 50.0f
    };

    struct sensor_data *data = NULL;
    
    while(1)
    {
        LOG_INF("Producer thread running.");

        data = k_malloc(sizeof(struct sensor_data));  

        if (!data) {
            LOG_ERR("Failed to allocate memory for sensor data");
            k_sleep(K_SECONDS(PRODUCER_THREAD_INTERVAL_IN_SECONDS));
            continue;
        }

        /* Update data for next iteration */
        data->data_id = data_tmp.data_id++;
        data->temperature = data_tmp.temperature + 0.5f;
        data->humidity = data_tmp.humidity + 0.3f;

        /* Remember last temperature and humidity */
        data_tmp.data_id = data->data_id + 1;
        data_tmp.temperature = data->temperature;
        data_tmp.humidity = data->humidity;

        /* Put data into FIFO */
        k_fifo_put(&telemetry_fifo, data);

        /* Log the sent data */
        int32_t temp_int = (int32_t)(data->temperature * 100.0f + 0.5f);
        int32_t hum_int = (int32_t)(data->humidity * 100.0f + 0.5f);
        LOG_INF("Sent data: ID=%d, Temp=%d.%02d, Humidity=%d.%02d",
                data->data_id,
                temp_int / 100, abs(temp_int % 100),
                hum_int / 100, abs(hum_int % 100));

        LOG_INF("Addr: %p", data);
        LOG_INF("-------------------");

        k_sleep(K_SECONDS(PRODUCER_THREAD_INTERVAL_IN_SECONDS));
    }
}

/*-------------------------------------
 * PRIVATE FUNCTION DEFINITIONS
 *-----------------------------------*/

static uint32_t generate_unique_number(uint32_t min, uint32_t max, uint32_t prev_value) 
{
    uint32_t rnd;
    do {
        rnd = min + (sys_rand32_get() % (max - min + 1));
    } while (rnd == prev_value);
    return rnd;
} 