
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include "./include/util.h"
#include "./include/task1.h"
#include "./include/task2.h"


#define WAIT_S 5
#define WAIT_MS 0

typedef struct pollfd pollfd;
int main(int argc, char * argv[]) {
    // task1(argv[1], argv[2]);
    task2_2(argv[1]);
    return 0;    
}



// task2 using poll

// char * c = task2();
// pollfd fds[1];
// fds[0].fd = STDIN_FILENO;
// fds[0].events = POLLIN;
// int ret = poll(fds, 1, WAIT_S * 1000);
// if(ret == 0) {
//     printf("timeout\n");
// } else {
//     char *c = malloc(BUF_SIZE);
//     read(STDIN_FILENO, c, BUF_SIZE);
//     printf("%s : %s", argv[1], c);
// }


// task 2 using select

// struct timeval wait = {WAIT_S, WAIT_MS};
//     int state;
//     fd_set in;
//     FD_ZERO(&in);
//     FD_SET(STDIN_FILENO, &in);
//     if((state = select(STDIN_FILENO + 1, &in, NULL, NULL, &wait)) == -1) {
//         perror("select()");
//         return 0;
//     } else {
//         if(!state) {
//             printf("timeout (%ds)\n", WAIT_S);
//         } else {
//             char *c = malloc(BUF_SIZE);
//             c = my_bzero(c, BUF_SIZE);            
//             read(STDIN_FILENO, c, BUF_SIZE);
//             printf("%s: %s", argv[1], c);
//         }
//     }

