//
// Created by dr10n9 on 15.04.19.
//

#include "task1.h"

int lfd;

void signal_handler( int signo, siginfo_t *si, void * ucontext ) {
    // else printf("not null\n");
    printf("signo: %d\n", signo);
    printf("signal info:\n"
           "si_signo: %d\n"
           "si_errno: %d\n"
           "si_uid: %d\n"
           "si_pid: %d\n", si->si_signo, si->si_errno, si->si_uid, si->si_pid);
    exit(1);
};

int task1() {
    char buff[100];
    int counter = 0;
    int bytesWritten = 0;

    static struct sigaction oldSigact;
    static struct sigaction sigact;

    bytesWritten = sprintf(buff, "process with pid=%d stared\n", getpid());

    lfd = open("test.log", O_CREAT | O_RDWR | O_APPEND, 0644);
    write(lfd, buff, bytesWritten);
    close(lfd);

    sigaction(SIGHUP, NULL, &oldSigact); // to save old handler

    sigact.sa_sigaction = signal_handler; //
    sigact.sa_flags = SA_SIGINFO;
    sigaction(SIGHUP, &sigact, NULL);

    printf("%d\n", getpid());

    while(1) {
        printf("sleeping\n");
        sleep(1);
    }

    return 0;
};



//    char buff[] =
//            "si_signo:\n"
//            "\tSignal number being delivered. This field is always set.\n"
//            "si_code:\n"
//            "\tSignal code. This field is always set. Refer to Signal Codes for information on valid settings, and for which of the remaining fields are valid for each code.\n"
//            "si_value:\n"
//            "\tSignal value.\n"
//            "si_errno:\n"
//            "\tIf non-zero, an errno value associated with this signal.\n"
//            "si_pid:\n"
//            "\tProcess ID of sending process.\n"
//            "si_uid:\n"
//            "\tReal user ID of sending process.\n"
//            "si_addr:\n"
//            "\tAddress at which fault occurred.\n"
//            "si_status:\n"
//            "\tExit value or signal for process termination.\n"
//            "si_band:\n"
//            "\tBand event for SIGPOLL/SIGIO.\n"
//            "st_mtime:\n"
//            "\tTime of last data modification.\n\n";

//    printf("buff:\n%s", buff);