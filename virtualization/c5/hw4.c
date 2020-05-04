#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    if(!fork()){
        execl("/bin/ls", "ls", "-alh", NULL);
        printf("you should't see this!\n");
    }
    return 0;
}

