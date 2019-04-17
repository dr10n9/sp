#ifndef TASK1_H
#define TASK1_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "./util.h"

typedef struct {
    int totalBytes;
    int toUpperBytes;
} result;

result * Result(int totalBytes, int toUpperBytes);
void task1(const char * src_fn, const char * dest_fn);
void printResult(result r);

#endif