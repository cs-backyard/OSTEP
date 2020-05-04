#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<assert.h>


int main(int argc, char* argv[]){
    int x = 100;
    printf("current process[%d] x: %d\n", getpid(), x);
    pid_t pid = fork();
    assert(pid > -1);
    if(pid){
        printf("child process[%d] x: %d\n", getpid(), ++x);
    }else{
        printf("parent process[%d] x: %d\n", getpid(), ++x);
    }
    return 0;
}