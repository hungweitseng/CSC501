#define _GNU_SOURCE  
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sched.h>
#include <sys/syscall.h>
#include <time.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int child_pid;
    char filename[] = "output.txt";
    int fd;
    struct timeval time_start, time_end;
    gettimeofday(&time_start, NULL);	
#ifdef FORKEXEC
    int saved_stdout, saved_stderr;
#endif
    fprintf(stderr,"Hello, CSC501\n");
#ifdef FORKEXEC
    fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    saved_stdout = dup(1); // Save the current stdout
    saved_stderr = dup(2); // Save the current stderr
    dup2(fd, 1); // Redirect stdout to fd
    dup2(fd, 2); // Redirect stderr to fd
#endif
    child_pid = fork();
    if (child_pid == 0) 
    {
#ifndef FORKEXEC
        fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        dup2(fd, 1); // Redirect stdout to fd
        dup2(fd, 2); // Redirect stderr to fd
        close(fd);
        fprintf(stderr,"Child is %d\n", getpid());
#endif
        execvp("./noise",NULL);
    } 
    else 
    {
#ifdef FORKEXEC
        close(fd);
        dup2(saved_stdout, 1);
        dup2(saved_stderr, 2);
#endif
        fprintf(stderr,"My child is %d\n", child_pid); 
    }
    	gettimeofday(&time_end, NULL);
	printf("Total %d\n",((time_end.tv_sec * 1000000 + time_end.tv_usec) - (time_start.tv_sec * 1000000 + time_start.tv_usec)));
    return 0;
}
