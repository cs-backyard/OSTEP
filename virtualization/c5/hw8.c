#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<assert.h>

int main(int argc, char *argv[]){
    int pipfd[2];
    assert(pipe(pipfd) != -1);
    if(fork()){
        close(pipfd[1]);
        char buffer;
        printf("child read from pipe:\n");
        while(read(pipfd[0], &buffer, 1) > 0){
            printf("%c", buffer);
        }
        close(pipfd[0]);
    }else{
        close(pipfd[0]);
        write(pipfd[1], "use pipe!\n", 10);
        wait(NULL);
        close(pipfd[1]);
    }
    return 0;
}

