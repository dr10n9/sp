#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define BUF_SIZE 4096

char * my_bzero(char * str, size_t sz);
char * itoa(int num);
bool char_toupper(char * ch);
int str_toupper(char * str);
int str_len(char * str);
