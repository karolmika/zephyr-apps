#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);



/*-------------------------------------
 * PRIVATE PROTOTYPES
 *-----------------------------------*/

int main(void)
{
    LOG_INF("Message queues application started!");
    return 0;
}
