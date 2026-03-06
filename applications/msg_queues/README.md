# General informations
This is demo application to demonstrate use of messages queues. In contains two threads:
- producing thread that generates random data and puts them into the queue
- consuming thread that reads the data and in prints them

The generated data is city name taken from the fixed dictionary. 
City name choosen based on the index that is randomly generated is put into the queue. 
Each city string is treated as 10 + 1 (1 because of string terminator at the end) bytes, even if city name is less. Buffer for the queue can contain 10 city names. In current setup, if queue is full, producer thread wait 5 second to try again. Consumer thread every 3 seconds grabs new data from queue, so this means after reaching 10 elements in queue buffer, the overflow shouldn't be a problem. It only slows down the producer tread, beacue it need to wait to put a new element to the queue. Normall flow for the producing thread is to put new city every 2 seconds. After reaching full buffer, it will be 3 seconds (the same as consumer).

# Supported platforms
- native_sim

