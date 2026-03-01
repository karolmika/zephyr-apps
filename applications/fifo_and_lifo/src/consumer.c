#include <zephyr/kernel.h>
#include <zephyr/logging/log.h> 

#include <stdlib.h>

#include "common.h"

LOG_MODULE_REGISTER(consumer, LOG_LEVEL_INF);

/* Reference to shared fifo from producer */
extern struct k_fifo telemetry_fifo;

/* Setting the thread for Consumer work*/
#define CONSUMER_STACK_SIZE 2048
#define CONSUMER_PRIORITY 4
#define CONSUMER_THREAD_INTERVAL_IN_SECONDS 2

K_THREAD_STACK_DEFINE(consumer_stack_area, CONSUMER_STACK_SIZE);
struct k_thread consumer_thread_data;
extern void consumer_thread_fn(void *, void *, void *);

/* Reference to shared queue from producer */
extern struct k_msgq msg_queue;

K_THREAD_DEFINE(consumer_thread_id, CONSUMER_STACK_SIZE, consumer_thread_fn, NULL, NULL, NULL, 
    CONSUMER_PRIORITY, 0, 0);

void consumer_thread_fn(void *, void *, void *)
{
    LOG_INF("Consumer thread started!");

    struct sensor_data *recv_data = NULL;
       
    while(1)
    {
        LOG_INF("Consumer thread running.");

        recv_data = k_fifo_get(&telemetry_fifo, K_NO_WAIT);
        if (recv_data) {
            int32_t temp_int = (int32_t)(recv_data->temperature * 100.0f + 0.5f);
            int32_t hum_int = (int32_t)(recv_data->humidity * 100.0f + 0.5f);
            LOG_INF("Received data: ID=%d, Temp=%d.%02d, Humidity=%d.%02d",
                recv_data->data_id,
                temp_int / 100, abs(temp_int % 100),
                hum_int / 100, abs(hum_int % 100));
        } else {
            LOG_INF("No data received from FIFO.");
        }

        LOG_INF("Addr: %p", recv_data);
        LOG_INF("-------------------");

        //k_free(recv_data);  // Free the allocated memory after processing

        k_sleep(K_SECONDS(CONSUMER_THREAD_INTERVAL_IN_SECONDS));
    }
}