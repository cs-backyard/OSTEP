#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    int res = 0;
    pid_t pid = 0;
    printf("current process[%d]\n", getpid());
    if((pid = fork())){
        res = waitpid(pid, NULL, 0);
        printf("parent process[%d] wait value: %d\n", getpid(), res);
    }else{
        res = wait(NULL);
        printf("child process[%d] wait return: %d\n", getpid(), res);
    }
    return 0;
}

