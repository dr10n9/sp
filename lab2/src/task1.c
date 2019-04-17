//
// Created by dr10n9 on 12.03.19.
//


#include "../include/tasks.h"

void task1() {
    pid_t pid;
    switch(pid = fork()) {
        case -1:
            printf("error");
            break;
        case 0:
            pid = getpid();
            for(int i = 0; i < 150; i++){
                printf("CHILD: pid: %d; ppid: %d; gid: %d; sid: %d.\n", pid, getppid(), getgid(), getsid(pid));
            }
            break;
        default:
            printf("PARENT: child pid %d\n", pid);
            for(int i = 0; i < 150; i++){
                printf("PARENT: pid: %d; gid: %d; sid: %d.\n", getpid(), getgid(), getsid(getpid()));
            }
            wait(&pid);
            printf("child terminated");
//            printf("child with pid %d terminated\n", wait(&pid));
            break;
    }
}