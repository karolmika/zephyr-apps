#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>

LOG_MODULE_REGISTER(producer, LOG_LEVEL_INF);

#define FIRST_ELEMENT 0
#define NUM_OF_CITIES 10 
// #define MAX_CITY_NAME_LENGTH 20  

/* Setting the thread for Producer work*/
#define PRODUCER_THREAD_INTERVAL_IN_SECONDS 1
#define PRODUCER_STACK_SIZE 500
#define PRODUCER_PRIORITY 5
K_THREAD_STACK_DEFINE(producer_stack_area, PRODUCER_STACK_SIZE);
struct k_thread producer_thread_data;
extern void producer_thread_fn(void *, void *, void *);

K_THREAD_DEFINE(producer_thread_id, PRODUCER_STACK_SIZE, producer_thread_fn, NULL, NULL, NULL, 
    PRODUCER_PRIORITY, 0, 0);

/* Database of cities to select from */
const char *city_database[] = {
    "Paris", "Berlin", "Tokyo", "Madrit", "Rome", "London", "New York", "Moscow", "Beijing", "Sydney"};

/*-------------------------------------
 * PRIVATE FUNCTION PROTOTYPES
 *-----------------------------------*/
static uint32_t generate_number(uint32_t min, uint32_t max);

void producer_thread_fn(void *, void *, void *)
{
    uint32_t rnd = generate_number(FIRST_ELEMENT, NUM_OF_CITIES-1);

    /* Msg queue data*/
    struct k_msgq msg_queue;

    for(int i = 0; i < NUM_OF_CITIES; i++) {
        LOG_INF("Size of City %d: %d", i, sizeof(city_database[0]));
    }

    k_msgq_init(&msg_queue, city_database, sizeof(city_database[0]), NUM_OF_CITIES);
    
    LOG_INF("Producer thread started!");
    
    while(1)
    {
        // LOG_INF("Random number: %d", rnd);
        LOG_INF("Selected city: %s", city_database[rnd]);
        int result = k_msgq_put(&msg_queue, city_database[rnd], K_SECONDS(10));
        if (result != 0) {
            LOG_ERR("Failed to put message in queue");
        }
        k_sleep(K_SECONDS(PRODUCER_THREAD_INTERVAL_IN_SECONDS));

        // Search for new number to select new city
        rnd = generate_number(FIRST_ELEMENT, NUM_OF_CITIES);
    }
}

/*-------------------------------------
 * PRIVATE FUNCTION DEFINITIONS
 *-----------------------------------*/

static uint32_t generate_number(uint32_t min, uint32_t max) 
{
    return min + (sys_rand32_get() % (max - min + 1));
} 