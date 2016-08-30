#define _GNU_SOURCE  
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sched.h>
#include <sys/syscall.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int child_pid;
    fprintf(stderr,"Hello, CSC501\n");
    child_pid = fork();
    if (child_pid == 0) 
    {
#ifdef EXEC
        execvp("./noise",NULL);
#endif
        fprintf(stderr,"Child is %d\n", getpid());
    } 
    else 
    {
        fprintf(stderr,"My child is %d\n", child_pid); 
    }
    return 0;
}
