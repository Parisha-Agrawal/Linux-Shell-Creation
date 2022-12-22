#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

FILE *fileF;
extern int errno ;
int count = 1;
void print(char *file_name, int optionO) {
    fileF = fopen(file_name, "r");
    if (fileF == NULL){
        printf("Error in opening this file: %s\n", strerror(errno));
        return;
    }
    char *lineL = malloc(1000 * sizeof(char));
    while (fgets(lineL, 1000, fileF) != NULL){
        if (optionO == 1){
            printf("%s", lineL);
        }
        else if (optionO == 2){
            printf("%d %s", count++, lineL);
        }
        else if (optionO == 3){
            lineL[strlen(lineL) - 1] = '\0';
            printf("%s$\n", lineL);
        }
    }
    fclose(fileF);
}

int main(int a, char**args) {
	if (a == 2){
		print(args[1], 1);
		return 0;
	}
	else if(a == 3){
		int index = 0;
		int n = strlen(args[1]);
		char *string = malloc(1000 * sizeof(char));
		string[0] = '\0';
		int i = 0;
		while (i <= n){
			if (i == n || args[1][i] == ' '){
				// printf("%s.. ",args[1]);
				// printf("%s.. ",string);
				if (!strcmp(args[1], "-E")){
                    print(args[2], 3);
                }
                else if (!strcmp(args[1], "-n")){
                    print(args[2], 2);
                }
                else{
                    printf("Option not supported");
                }
				string[0] = '\0';
				i++;
				index = 0;
			}
			else{
				string[index++] = args[1][i++];
				string[index] = '\0';
			}
		}
	}
	else{
		printf("Excess number of arguments provided!!");
	}
    return 0;
}