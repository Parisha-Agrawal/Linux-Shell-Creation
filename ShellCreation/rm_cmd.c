#include <stdio.h>
#include <time.h>
#include<string.h>
#include <errno.h>
#include<unistd.h>
#include<stdlib.h>
extern int errno ;

int main(int a, char**args) {
    // printf("a: %d\n",a);
    if (a == 2){
        // printf("args[0]: %s\n",args[0]);
        // printf("args[1]: %s\n",args[1]);
        int status = unlink(args[1]);
        if (!status){
            //deleted successfully
        }
        else{
            printf("Error in deleteing: %s\n", strerror(errno));
        }
        return 0;
    }
    else if(a == 3){
        char * current_directory = malloc(100 * sizeof(char));
        getcwd(current_directory, 100);
        if (current_directory == NULL){
            printf("%s\n", "We could not get the directory of the file you are deleting !!!" );
            return 0;
        }
        if (!strcmp(args[2], current_directory)){
            if (!strcmp(args[2], "history.txt") || !strcmp(args[2], "shell.c") || !strcmp(args[2], "mkdir.c") || !strcmp(args[2], "ls.c") || !strcmp(args[2], "cat.c") || !strcmp(args[2], "date.c") || !strcmp(args[2], "rm.c") || !strcmp(args[2], "rm.c") || !strcmp(args[2], "rm") || !strcmp(args[2], "mkdir") || !strcmp(args[2], "ls") || !strcmp(args[2], "date") || !strcmp(args[2], "cat") || !strcmp(args[2], "shell")) {
                printf("%s\n", "You are not permitted to delete the code files of the project!!!");
                return 0;
            }
        }

        if (!strcmp(args[1], "-i")) {
            while (1) {
                printf("%s\n", "Are you sure you want to delete this file? (Y/N)");
                char *ch = malloc(100 * sizeof(char));
                scanf("%s", ch);
                if (!strcmp(ch, "Y") || !(strcmp(ch, "N"))) {
                    if (!strcmp(ch, "Y")) {
                        int status = unlink(args[2]);
                        if (!status) {
                            //deleted successfully
                            return 0;
                        }
                        else {
                            printf("Error in deleteing: %s\n", strerror(errno));
                            return 0;
                        }
                    }
                    else
                        return 0;
                }
                else {
                    printf("%s\n", "Please enter a valid choice (Y/N)");
                }
            }
        }
        else if (!strcmp(args[1], "-v")){
            int status = unlink(args[2]);
            if (!status){
                printf("removed '%s'\n", args[2]);
                return 0;
            }
            else
            {
                printf("Error in deleteing: %s\n", strerror(errno));
                return 0;
            }

        }
        else{
		    printf("Option not supported");
        }
        return 0;
    }
    else{
        printf("Excess number of arguments");
    }
}