#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>

void func_err(const char *fmt, ...)
{   
    int length = 0;
    char *buf = NULL;
    va_list vl;
    va_start(vl, fmt);
    
    length = snprintf(NULL, 0, fmt, vl);
    va_end(vl);
    
    if(length <= 0) return;
    
    buf = (char*)malloc(length + 1);
    if(buf == NULL) return;
    
    va_start(vl, fmt);
    vsnprintf(buf, length, fmt, vl);
    printf("errno = %d, desc = %s, %s\n", errno, strerror(errno), buf);
    va_end(vl);
    
    free(buf);
    buf = NULL;
}

// struct dirent *readdir(DIR *dirp);
// DIR *opendir(const char *name);
// int closedir(DIR *dirp)
int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("param error!\n");
        return -1;
    }
    //DIR *tmpDir = opendir("/root");
    DIR *tmpDir = opendir(argv[1]);
    struct dirent * dp = NULL;
    if(tmpDir == NULL){
        func_err("open failed!");
        return -1;
    }

    while((dp = readdir(tmpDir)) != NULL){
        printf("%s\n", dp->d_name);
    }

    int ret  = closedir(tmpDir);
    printf("ret = %d, issuccess = %s\n", ret, ret == 0?"true":"false");
    return 0;

}

