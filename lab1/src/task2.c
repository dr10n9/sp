#include "../include/task2.h"
#include "../include/util.h"
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>
#include <poll.h>
#include <stropts.h>

#define WAIT_S 5
#define WAIT_MS 0

typedef struct pollfd pollfd;
void task2_1(char *identifier) {
    struct timeval wait = {WAIT_S, WAIT_MS};
    int state;
    fd_set in;
    FD_ZERO(&in);
    FD_SET(STDIN_FILENO, &in);
    if((state = select(STDIN_FILENO + 1, &in, NULL, NULL, &wait)) == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
    } else {
        if(!state) {
            perror("timeout: ");
            exit(EXIT_FAILURE);
        } else {
            char *c = malloc(BUF_SIZE);
            c = my_bzero(c, BUF_SIZE);            
            read(STDIN_FILENO, c, BUF_SIZE);
            printf("%s : %s\n", identifier, c);
            free(c);
        }
    }
}

void task2_2(char * identifier) {
    pollfd fds[1];
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;
    int ret = poll(fds, 1, WAIT_S * 1000);
    if( ret == -1) {
        perror("poll");
        exit(EXIT_FAILURE);
    }
    if(ret == 0) {
        printf("timeout\n");
        exit(EXIT_SUCCESS);
    } else {
        char *c = malloc(BUF_SIZE);
        read(STDIN_FILENO, c, BUF_SIZE);
        printf("%s : %s", identifier, c);
        free(c);
    }
}
