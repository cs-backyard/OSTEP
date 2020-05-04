#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

#include<sys/wait.h>

int main(int argc, char *argv[]){
    if(fork()){
        // wait(NULL);
        sleep(1);
        printf("goodbay\n");
    }else{
        printf("hello\n");
    }
    return 0;
}