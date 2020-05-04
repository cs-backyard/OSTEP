#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main(int argc, char *argv[]){
    if(!fork()){
        printf("child process before close stdout\n");
        close(STDOUT_FILENO);
        printf("child process after close stdout\n");
    }    
    return 0;
}

