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
    fork();
    printf("moo\n");
    fork();
    printf("oink\n");
    fork();
    printf("baa\n");
    exit(0);
    return 0;
}
