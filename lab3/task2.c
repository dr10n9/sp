//
// Created by dr10n9 on 10.04.19.
//

#include "task2.h"
typedef struct tm tm;
typedef struct datum_s {
    pid_t pid;
    tm time;
    char buff[100];
} datum_t;

int task2() {
    int fd;
    time_t currentTime;
    char buff[100];
    datum_t* datum = NULL;

    fd = shm_open("/lab3", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR); // create or open POSIX shared memory object

    if(fd == -1) {
        printf("Error on shm_open");
        return -1;
    }

    if(ftruncate(fd, sizeof(datum_t)) == -1) {
        printf("error on ftruncate");
        return -1;
    }

    datum = mmap(NULL, sizeof(datum_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (datum == MAP_FAILED) {
        printf("Error while trying to mmap() fd!");
        return -1;
    }

    printf("pid: %d\n", getpid());

    while(1) {
        printf("Enter string:\n");
        fgets(buff, 100, stdin);
        msync(datum, sizeof(datum_t), MS_SYNC);
        printf("\nDatum info:\npid: %d\ntime: %sdata: %s\n", datum->pid, asctime(&(datum->time)), datum->buff);
        datum->pid = getpid();
        time(&currentTime);
        datum->time = (*localtime(&currentTime));
        strcpy(datum->buff, buff);
    }

    shm_unlink("/lab3"); //unlink POSIX shared memory object5
    return 1;
}