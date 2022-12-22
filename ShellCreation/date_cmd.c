#include<stdio.h>
#include<time.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){
    if (argc == 1){
        time_t time1;
		struct tm *information;
		char string[80];
		time( &time1 );
		information = localtime( &time1 );
		strftime(string, 80, "%a %b %d %H:%M:%S %Z %Y", information);
		printf("%s", string);
    }
    //Options supported: -u, -R
    else if (argc == 2){
		// printf("Using options\n");
		if (argv[1][0] == '-'){
            int op_u = 0, op_R = 0;
			char *p = (char*)(argv[1] + 1);
			while(*p){
				if(*p == 'u') op_u = 1;
                else if(*p == 'R') op_R = 1;
				else{
					printf("Option not available");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			if (op_u == 1){
                time_t time1;
                struct tm *information;
                char string[80];
                time( &time1 );
                information = gmtime( &time1 );
                strftime(string, 80, "%a %b %d %H:%M:%S UTC %Y", information);
                printf("%s", string);
            }
            if (op_R == 1){
                time_t time1;
                struct tm *information;
                char string[80];
                time(&time1);
                information = localtime(&time1);
                strftime(string, 80, "%a, %b %d %H:%M:%S %z", information);
		        printf("%s", string);
            }
		}
		else{
		printf("Option not recognized");
		}
	}
	else{
		printf("Option not recognized");
	}
	return 0;
}
