#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
extern int errno;

void trim_the_name(char *args){
    int n = strlen(args);
    while (n > 0 && args[n - 1] == ' ' || args[n - 1] == '\n'){
        args[n - 1] = '\0';
        n--;
    }
}

int main(int a, char**args) {
    // printf("a: %d\n",a);
    if (a == 2){
        // printf("line 22\n");
        // printf("%s\n",args[0]);
        // printf("%s\n",args[1]);
        int status = mkdir(args[1], 0777);
        if (status){
            printf("mkdir: cannot create directory '%s': %s\n",args[1], strerror(errno));
        }
        else{
            // printf("Directory created successfully\n");
        }
    }
    else if (a==3){
        // printf("line 34\n");
        // printf("%s\n",args[0]);
        // printf("%s\n",args[1]);
        // printf("%s\n",args[2]);
        if (!strcmp(args[1], "-v")){
            int status = mkdir(args[2], 0777);
            if (!status)
                printf("mkdir: created directory '%s'",args[2]);
            else
                printf("mkdir: cannot create directory '%s': %s\n",args[2], strerror(errno));
        }
        // printf("%s\n",args[1]);
        else if (!strcmp(args[1], "-p")){
            char directories[1000][100];
            char string[100];
            int i = 0;
            int index = 0;
            int position = 0;
            int n = strlen(args[2]);
            while (i <= n){
                if (i == n || args[2][i] == '/'){
                    directories[index][position] = '\0';
                    position = 0;
                    index++;
                    i++;
                }
                else{
                    directories[index][position++] = args[2][i++];
                }
            }
            for (int i = 0; i < index; i++){
                trim_the_name(directories[i]);
                if (strlen(directories[i]) == 0){
                    printf("ERROR!! One of the directories has an empty name\n");
                    return 0;
                }
            }
            for (int i = 0; i < index; i++){
                int res = chdir(directories[i]);
                if (res == 0){
                    //entered succesffuly
                }
                else
                {
                    int status = mkdir(directories[i], 0777);
                    if (!status)
                    {
                        // printf("Directory %s Created Successfully\n",args[1]);
                        res = chdir(directories[i]);
                        if (res != 0)
                        {
                            printf("Some Error in directory entering of %s\n", directories[i]);
                            return 1;
                        }
                    }
                    else
                    {
                        printf("Error: %s\n", strerror(errno));
                    }
                }
            }
        }
        else{
            printf("Option not recognised");
        }
    }
    return 0;
}