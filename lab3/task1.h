//
// Created by dr10n9 on 15.04.19.
//

#ifndef LAB3_TASK1_H
#define LAB3_TASK1_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int task1();
void signal_handler( int signo, siginfo_t *si, void * ucontext );

#endif //LAB3_TASK1_H
