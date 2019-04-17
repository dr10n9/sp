#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "task2.h"
#include "task1.h"

int lfd; // log file descriptor

void signal_handler( int signo, siginfo_t *si, void * ucontext );

int main() {
    return task1();
//    return task2();
}

