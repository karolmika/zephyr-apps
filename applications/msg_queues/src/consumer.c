#include <zephyr/kernel.h>
#include <zephyr/logging/log.h> 

LOG_MODULE_REGISTER(consumer, LOG_LEVEL_INF);

/* Setting the thread for Consumer work*/
#define CONSUMER_STACK_SIZE 2048
#define CONSUMER_PRIORITY 5
#define MAX_CITY_NAME_LENGTH 10
#define CONSUMER_THREAD_INTERVAL_IN_SECONDS 3

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
    
    char received_city[MAX_CITY_NAME_LENGTH + 1] = {0};
    
    while(1)
    {
        int result = k_msgq_get(&msg_queue, received_city, K_SECONDS(10));
        if (result == 0) {
            LOG_INF("Received city from queue: %s", received_city);
        } else {
            LOG_INF("Failed to get message from queue, result: %d", result);
        }
        k_sleep(K_SECONDS(CONSUMER_THREAD_INTERVAL_IN_SECONDS));
    }
}