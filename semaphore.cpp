#include<iostream>

#define N 100
typedef semaphore;
semaphore =1; /*control access to CR*/
semaphore empty =N;
semaphore full =0;

void procedure(void)
{
    int item;
    while (TRUE)
    {
        item =produce.item();
        /*Generate something to put in buffer*/
        down(empty); /*decrement empty count*/
        down(&mute x) /*enter CR*/

        insert_item(item); /*put*/
    }
    
}