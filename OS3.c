#include<stdio.h>
#include<unistd.h>

int main()
{
    if (fork() && fork())
    {
        fork();
        printf("Hello, Coders");
        return 0;
    }
    
}