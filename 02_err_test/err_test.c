#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char* argv[]){
    DIR *tmpDir = opendir(argv[1]);
    struct dirent * dp = NULL;
    if(tmpDir == NULL){
        //printf("errno = %d, desc = %s\n", errno, strerror(errno));      
        perror(" 打开失败 ");
        return -1;
    }

//    printf("errno = %d, desc = %s\n", errno, strerror(errno));
    return 0;
}
