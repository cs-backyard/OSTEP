#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    int fd = open("./hw2.output", O_CREAT | O_WRONLY | O_APPEND);
    if(fork()){
        printf("i'am parent process[%d]\n", getpid());
        write(fd, "parent process!\n", 16);
    }else{
        printf("i'am child process[%d]\n", getpid());
        write(fd, "child process!\n", 15);
    }
    return 0;
}