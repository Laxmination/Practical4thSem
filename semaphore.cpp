#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

#define N 100

std::mutex mutex;
std::condition_variable full, empty;

void procedure(void)
{
int item;
while (true)
     {
         item =produce.item();
         empty.wait(); 
         std: :unique_lock<std::mutex> lock(mutex);

        insert_item(item);
        lock.unlock();
        full.notify_one();
     }
     }

void consumer(void)
{
    int item;
    while (true)
    {
       std::unique_lock<std::mutex> lock(mutex); 
       full.wait(lock); 
       item = remove_item(); 
       lock.unlock();  
       empty.notify_one();
       consume_item(item);
    }
}

int main()
{
    std::thread producer_thread(procedure);
    std::thread consumer_thread(consumer);
    producer_thread.join();
    consumer_thread.join();
    return 0;
}