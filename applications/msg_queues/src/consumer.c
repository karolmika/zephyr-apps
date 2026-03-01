#include <zephyr/kernel.h>
#include <zephyr/logging/log.h> 

LOG_MODULE_REGISTER(consumer, LOG_LEVEL_INF);

/* Setting the thread for Consumer work*/
#define CONSUMER_STACK_SIZE 500
#define CONSUMER_PRIORITY 5

K_THREAD_STACK_DEFINE(consumer_stack_area, CONSUMER_STACK_SIZE);
struct k_thread consumer_thread_data;
extern void consumer_thread_fn(void *, void *, void *);

K_THREAD_DEFINE(consumer_thread_id, CONSUMER_STACK_SIZE, consumer_thread_fn, NULL, NULL, NULL, 
    CONSUMER_PRIORITY, 0, 0);

void consumer_thread_fn(void *, void *, void *)
{
    LOG_INF("Consumer thread started!");
    
    while(1)
    {
        k_sleep(K_SECONDS(5));
    }
}