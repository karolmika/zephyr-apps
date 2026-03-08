#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <string.h>
#include <stdio.h>

LOG_MODULE_REGISTER(producer, LOG_LEVEL_INF);

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

struct sensor_data {
    void *fifo_reserved; /* 1st word reserved for use by fifo */
    int data_id;
    float temperature;
    float humidity;
};

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
    
    while(1)
    {
        LOG_INF("Producer thread running.");
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