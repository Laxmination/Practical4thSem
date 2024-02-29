#include<iostream>
#define FALSE 0
#define TRUE 1
#define N 2  /*number fo process*/

int turn; /*whose turn is it?*/
int interested[N]; /*all values initially 0 FALSE*/

void enter_region(int process) /*process is 0 or 1 */
{
    int other; /*number of the process */
    other =1 -process;
    interested[process] =TRUE;
    turn =process;
    while (turn ==process && interested[other] ==TRUE)
    {
        /*busy waiting*/
    }
}
 void leave_region(int process)
 {
     interested[process] =FALSE;
 }

 int main()
 {
    return 0;
 }

