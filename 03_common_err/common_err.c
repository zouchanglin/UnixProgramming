#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>

void func_err(char *fmt, ...){
    int length = 0;
    va_list vl;
    char* buf = NULL;
    va_start(vl, fmt);

    length = snprintf(NULL, 0, fmt, vl);
    va_end(vl);

    if(length == 0) return;
    
    buf = (char*)malloc(length + 1);
    va_start(vl, fmt);
    vsnprintf(buf, length + 1, fmt, vl);
    va_end(vl);
    
    printf("%d:%s -> %s\n", errno, strerror(errno), buf);

    free(buf);
    buf = NULL;
}

int main(){
    func_err("错误消息%s, %d", "Hello", 100);
    return 0;
}
