#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>

LOG_MODULE_REGISTER(producer, LOG_LEVEL_INF);

#define FIRST_ELEMENT 0
#define NUM_OF_CITIES 10 
#define MAX_CITY_NAME_LENGTH 10     // Noty Including null terminator
#define MSG_QUEUE_SIZE ((NUM_OF_CITIES)*(MAX_CITY_NAME_LENGTH + 1)*(sizeof(char))) 

/* Setting the thread for Producer work*/
#define PRODUCER_THREAD_INTERVAL_IN_SECONDS 1
#define PRODUCER_STACK_SIZE 2048
#define PRODUCER_PRIORITY 5
K_THREAD_STACK_DEFINE(producer_stack_area, PRODUCER_STACK_SIZE);
struct k_thread producer_thread_data;
extern void producer_thread_fn(void *, void *, void *);

/* Shared message queue */
char msg_queue_buffer[MSG_QUEUE_SIZE] = {0};
struct k_msgq msg_queue;

static int init_queue_once(void)
{
    k_msgq_init(&msg_queue, msg_queue_buffer, MAX_CITY_NAME_LENGTH + 1, NUM_OF_CITIES);
    return 0;
}
SYS_INIT(init_queue_once, PRE_KERNEL_2, 0);

K_THREAD_DEFINE(producer_thread_id, PRODUCER_STACK_SIZE, producer_thread_fn, NULL, NULL, NULL, 
    PRODUCER_PRIORITY, 0, 0);

/* Database of cities to select from */
const char *city_database[]= {
    "Paris", "Berlin", "Tokyo", "Madrit", "Rome", "London", "New York", "Moscow", "Beijing", "Sydney"};

/*-------------------------------------
 * PRIVATE FUNCTION PROTOTYPES
 *-----------------------------------*/
static uint32_t generate_number(uint32_t min, uint32_t max);

void producer_thread_fn(void *, void *, void *)
{
    uint32_t rnd = generate_number(FIRST_ELEMENT, NUM_OF_CITIES - 1);

    /* Msg queue data*/
    char city_name[MAX_CITY_NAME_LENGTH + 1] = {0};   
    
    LOG_INF("Producer thread started!");
    
    while(1)
    {
        LOG_INF("-------------------");
        LOG_INF("Selected city: %s", city_database[rnd]);
        memset(city_name, 0, sizeof(city_name));
        memcpy(city_name, city_database[rnd], strlen(city_database[rnd]));
        int result = k_msgq_put(&msg_queue, city_name, K_SECONDS(5));
        LOG_INF("k_msgq_put result: %d", result);

        int offset = 0;
        for (int i = 0; i < NUM_OF_CITIES; i++) {
            offset = i * (MAX_CITY_NAME_LENGTH + 1);
            if( strlen(&msg_queue_buffer[offset]) > 0) {
                LOG_INF("Cities in queue: %s", &msg_queue_buffer[offset]);
            }
        }

        if (result != 0) {
            LOG_ERR("Failed to put message in queue");
        }
        k_sleep(K_SECONDS(PRODUCER_THREAD_INTERVAL_IN_SECONDS));

        // Search for new number to select new city
        rnd = generate_number(FIRST_ELEMENT, NUM_OF_CITIES - 1);
    }
}

/*-------------------------------------
 * PRIVATE FUNCTION DEFINITIONS
 *-----------------------------------*/

static uint32_t generate_number(uint32_t min, uint32_t max) 
{
    return min + (sys_rand32_get() % (max - min + 1));
} 