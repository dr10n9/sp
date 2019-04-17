//
// Created by dr10n9 on 13.03.19.
//
#include "../include/tasks.h"
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <dirent.h>

char * itoa(int num);
int str_len(char *str);

void task2() {
    pid_t pid, sid;
    int log_fd;
    char *str = malloc(100);
    char dir[100];
    getcwd(dir, 100);
    printf("dir: %s\n", dir);
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if(pid > 0) {
        log_fd = open(strcat(dir, "/test.log"), O_WRONLY | O_APPEND | O_CREAT, 0644);
        printf("%d\n", log_fd);
        sprintf(str, "child created by %d\n", getpid());
        printf("%s\n", str);
        printf("%d\n", write(log_fd, str, str_len(str)));
        close(log_fd);
        exit(EXIT_SUCCESS);
    }
    if (pid == 0) {
        sid = setsid();
        chdir("/");
        if (sid < 0) exit(EXIT_FAILURE);
        for (int i = 0; i < 255; i++) close(i);
        open("/dev/null", O_WRONLY);
        dup(0);
        dup(0);
        log_fd = open(strcat(dir, "/daemon.log"), O_WRONLY | O_APPEND | O_CREAT, 0644);
        sprintf(str, "daemon pid: %d\n", getpid());
        printf("%ld\n", write(log_fd, str, str_len(str)));
        while (true) {}
    }
}

char * my_bzero(char * str, size_t sz){
    char * res = str;
    int i = 0;
    while(i < sz){
        res[i] = '\0';
        i++;
    }
    return res;
}

int str_len(char * str){
    int len = 0;
    while(*str++) {
        len++;
    }
    return len;
}

char * itoa(int num){
    if(num == 0) return "0";
    int num_length = floor(log10(abs(num))) + 1, counter;
    char * res;
    if(num < 0) {
        res = malloc(num_length + 1);
        counter = num_length + 1;
        res = my_bzero(res, num_length + 1);
        res[0] = '-';
        num = -num;
    } else {
        res = malloc(num_length);
        counter = num_length;
        res = my_bzero(res, num_length);
    }
    if(num < 0) {}
    while(num) {
        counter--;
        res[counter] = num % 10 + '0';
        num /= 10;
    }
    return res;
}
