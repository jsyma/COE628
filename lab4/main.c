/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: jsma
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

char input[50];
char cmd1[10];
char cmd2[10];
  
void cmdInput(){
    int  count1 = 0;
    int count2 = 0;

    for (int i = 0; i < strlen(input); i++){
        if (count1 == 0){
            cmd1[count1] = input[i];
            count1++;
        }
        else if(input[i] == '|'){
            i++;
        }
        else{
            cmd2[count2] = input[i];
            count2++;
        }
    }

}

int main(int argc, char** argv) {
    FILE* demo;
    int fd[2], pid;
    printf("Your Command> ");
    fgets(input, 50, stdin);
    cmdInput();
    pid = fork();
    pipe(fd); 
    demo = fopen("file.txt", "w+");
    if(pid == 0){
        dup2(fd[1], 1);
        close(fd[0]);
        system(cmd1);
        fprintf(demo, "%s", argv[1]);
        exit(0);
    }
    else{
        dup2(fd[0], 0);
        close(fd[1]);
        system(cmd2);
        fprintf(demo, "%s", argv[1]);
    }
    fclose(demo);
    return (EXIT_SUCCESS);
}
