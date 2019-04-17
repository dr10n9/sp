#include "../include/util.h"

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

bool char_toupper(char * ch){
    if(*ch >= 'a' && *ch <= 'z') {
        *ch = (*ch) - 32;
        return true;
    }
    return false;
}

int str_toupper(char * str){
    int sz = str_len(str), changed = 0;
    char * p_str;
    for(int i = 0; i < sz; i++){
        if(char_toupper(&str[i])) changed++;
    }
    return changed;
}