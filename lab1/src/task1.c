#include "../include/task1.h"
#include "../include/util.h"

result * Result(int total, int upped) {
    result * r = (void *)malloc(sizeof(result));
    r->totalBytes = total;
    r->toUpperBytes = upped;
    return r;
}

void printResult(result r) {
    printf("Total bytes: %s\nUpped: %s\n", r.totalBytes, r.toUpperBytes);
}

void task1(const char * src_fn, const char * dest_fn){
    int src_fd, dest_fd;
    src_fd = open(src_fn, O_RDONLY);
    if(src_fd < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }
    dest_fd = open(dest_fn, O_WRONLY | O_CREAT, 0644);
    if(dest_fd < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }
    char * buf = malloc(BUF_SIZE);
    int totalBytes = 0;
    int toUpperBytes = 0;
    while(read(src_fd, my_bzero(buf, BUF_SIZE), BUF_SIZE) > 0){
        toUpperBytes += str_toupper(buf);
        totalBytes += write(dest_fd, buf, str_len(buf));
    }
    free(buf);
    close(src_fd);
    close(dest_fd);
    printf("total bytes: %d\ntoUpperBytes: %d\n", totalBytes, toUpperBytes);
    // result r = {totalBytes, toUpperBytes};
    // return r;
}
