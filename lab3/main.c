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
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/*
 * 
 */
int main(int argc, char** argv) {
    while (1){
        printf("Your command> ");
        char ch;
        char *array = malloc(sizeof (char*)*100);
        
        while ((ch = getchar()) != '\n'){
            int len = strlen(array);
            array[len] = ch;
            array[len + 1] = '\0';
        }
        
        char *process = strtok(array, " ");
        char **r = NULL;
        int i = 0;
        
        while (process){
            r = realloc(r, sizeof (char*)*++i);
            r[i-1] = process;
            process = strtok(NULL, "\0");
        }
        
        r = realloc(r, sizeof (char*) * (i + 1));
        
        if (array[strlen(array) - 1] == '&'){
            if (fork() == 0){
                printf("\nParent Process Is Waiting\n");
                printf("Parent Process Ends\n");
                printf("Child Process Created\n");
                execvp(array, r);
            }
        }else{
            if (fork() == 0){
                printf("Child Process Created\n");
                printf("Child Process Ended\n");
                execvp(array,r);
            } else{
                printf("Parent Process Is Waiting\n");
                wait(NULL);
                printf("Parent Process Ends\n");
            }if (array[strlen(array) - 1] == '&'){
                if (fork() == 0){
                    printf("Child Process Created\n");
                    execvp(array, r);
                }
            }
        }
        
    }
    return (EXIT_SUCCESS);
}





