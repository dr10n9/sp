#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    union sigval value;
    if(argc < 2) printf("no pid\n");
    else {
        printf("%d\n", getpid());
        sigqueue(atoi(argv[1]), 1, value);
//        kill(atoi(argv[1]), 1);
    }
    return 0;
}