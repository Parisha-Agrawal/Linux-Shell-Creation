#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>


#define MAXCOM 500
#define MAXLIST 50
#define clear() printf("\033[H\033[J")

void shellBegins(){
	clear();
	char* username = getenv("USER");
	printf("USER is: @%s \n", username);
}

int takeInput(char* str){
	char* buf;
	buf = readline("\n>>> ");
	if(strlen(buf) != 0){
		add_history(buf);
		strcpy(str, buf);
		return 0;
	} else {
		return 1;
	}
}

void printDir(){
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}

void openHelp(){
	printf("List of Commands supported:\n");
	printf("Internal commands:\ncd\necho\npwd\n");
	printf("External commands:\nls (-a, -1)\ncat(-n, -E)\ndate(-u, -R)\nrm(-i, -v)\nmkdir(-p, -v)\n");
	return;
}


void* date_cmd(void* arg){
    pthread_detach(pthread_self());
	system("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/date_cmd");  
    pthread_exit(NULL);
}

void* date_cmd_1arg(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/date_cmd ";
	strcat(binaryFile,parsed);
	system(binaryFile);
    pthread_exit(NULL);
}

void* mkdir_cmd_1arg(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/mkdir_cmd ";
	strcat(binaryFile,parsed);
	system(binaryFile);  
    pthread_exit(NULL);
}

void* mkdir_cmd_v(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/mkdir_cmd -v ";
	strcat(binaryFile,parsed);
	system(binaryFile);  
    pthread_exit(NULL);
}

void* mkdir_cmd_p(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/mkdir_cmd -p ";
	strcat(binaryFile,parsed);
	system(binaryFile);  
    pthread_exit(NULL);
}

void* rm_cmd_1arg(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/rm_cmd ";
	strcat(binaryFile,parsed);
	system(binaryFile);
    pthread_exit(NULL);
}

void* rm_cmd_i(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/rm_cmd -i ";
	strcat(binaryFile,parsed);
	system(binaryFile);
    pthread_exit(NULL);
}

void* rm_cmd_v(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/rm_cmd -v ";
	strcat(binaryFile,parsed);
	system(binaryFile);
    pthread_exit(NULL);
}

void* cat_cmd_1arg(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/cat_cmd ";
	strcat(binaryFile,parsed);
	system(binaryFile);
    pthread_exit(NULL);
}

void* cat_cmd_n(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/cat_cmd -n ";
	strcat(binaryFile,parsed);
	system(binaryFile);
    pthread_exit(NULL);
}

void* cat_cmd_E(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/cat_cmd -E ";
	strcat(binaryFile,parsed);
	system(binaryFile);
    pthread_exit(NULL);
}


void* ls_cmd(void* arg){
    pthread_detach(pthread_self());
	// execl("/home/parisha/myFilesCreated/ls_cmd",NULL);
	system("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/ls_cmd");  
    pthread_exit(NULL);
}

void* ls_cmd_1arg(void* arg){
	char* parsed = (char*) arg;
    pthread_detach(pthread_self());
	char binaryFile[] = "/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/ls_cmd ";
	strcat(binaryFile,parsed);
	system(binaryFile);
    pthread_exit(NULL);
}

int externalCommandHandler_usingPthread(char** parsed){
    // printf("External Command Handler executing : %s\n",parsed[0]);
	int NoOfExtCmds = 5, i, switchExtArg = 0;
	char* ListOfExtCmds[NoOfExtCmds];
	char* username;
	int tCreated=0;

    ListOfExtCmds[0] = "ls";
	ListOfExtCmds[1] = "mkdir";
	ListOfExtCmds[2] = "date";
	ListOfExtCmds[3] = "cat";
	ListOfExtCmds[4] = "rm";


	for (i = 0; i < NoOfExtCmds; i++) {
		if (strcmp(parsed[1], ListOfExtCmds[i]) == 0) {
			switchExtArg = i + 1;
			break;
		}
	}

    pthread_t ptid;

	switch(switchExtArg){
		case 1:
			if (parsed[2]==NULL){
            	pthread_create(&ptid, NULL, &ls_cmd, NULL);
				tCreated = 1;
			}
			else if (parsed[3]==NULL){
				pthread_create(&ptid, NULL, &ls_cmd_1arg, parsed[2]);
				tCreated = 1;
			}
			else{
				printf("Excess number of arguments provided");
			}
			break;
		case 2:
			if (parsed[2]==NULL){
            	printf("Insufficient arguments provided");
			}
			else if (parsed[3]==NULL){
				pthread_create(&ptid, NULL, &mkdir_cmd_1arg, parsed[2]);
				tCreated = 1;
			}
			else if (parsed[4]==NULL){
				if (!strcmp(parsed[2],"-p")){
					pthread_create(&ptid, NULL, &mkdir_cmd_p, parsed[3]);
					tCreated = 1;
				}
				else if (!strcmp(parsed[2],"-v")){
					pthread_create(&ptid, NULL, &mkdir_cmd_v, parsed[3]);
					tCreated = 1;
				}
				else{
					printf("Option not supported");
				}
			}
			else{
				printf("Excess number of arguments provided");
			}
			break;
		case 3:
			if (parsed[2]==NULL){
            	pthread_create(&ptid, NULL, &date_cmd, NULL);
				tCreated = 1;
			}
			else if (parsed[3]==NULL){
				pthread_create(&ptid, NULL, &date_cmd_1arg, parsed[2]);
				tCreated = 1;
			}
			else{
				printf("Excess number of arguments provided");
			}
			break;
		case 4:
			if (parsed[2]==NULL){
            	printf("Insufficient arguments provided");
			}
			else if (parsed[3]==NULL){
				pthread_create(&ptid, NULL, &cat_cmd_1arg, parsed[2]);
				tCreated = 1;
			}
			else if (parsed[4]==NULL){
				if (!strcmp(parsed[2],"-n")){
					pthread_create(&ptid, NULL, &cat_cmd_n, parsed[3]);
					tCreated = 1;
				}
				else if (!strcmp(parsed[2],"-E")){
					pthread_create(&ptid, NULL, &cat_cmd_E, parsed[3]);
					tCreated = 1;
				}
				else{
					printf("Option not supported");
				}
			}
			else{
				printf("Excess number of arguments provided");
			}

			break;
		case 5:
			if (parsed[2]==NULL){
            	printf("Insufficient arguments provided");
			}
			else if (parsed[3]==NULL){
				pthread_create(&ptid, NULL, &rm_cmd_1arg, parsed[2]);
				tCreated = 1;
			}
			else if (parsed[4]==NULL){
				if (!strcmp(parsed[2],"-i")){
					pthread_create(&ptid, NULL, &rm_cmd_i, parsed[3]);
					tCreated = 1;
				}
				else if (!strcmp(parsed[2],"-v")){
					pthread_create(&ptid, NULL, &rm_cmd_v, parsed[3]);
					tCreated = 1;
				}
				else{
					printf("Option not supported");
				}
			}
			break;
		default:
            printf("Command not recognized!! Use help to know more about the shell!!");
            break;
		pthread_exit(NULL);
	}


	if (!pthread_equal(ptid, pthread_self())){
		if (tCreated == 1){
        	pthread_join(ptid, NULL);
		}
        return 0;
    }
}


int externalCommandHandler_usingFork(char** parsed){
    // printf("External Command Handler executing : %s\n",parsed[0]);
	int NoOfExtCmds = 5, i, switchExtArg = 0;
	char* ListOfExtCmds[NoOfExtCmds];
	char* username;

    ListOfExtCmds[0] = "ls";
	ListOfExtCmds[1] = "mkdir";
	ListOfExtCmds[2] = "date";
	ListOfExtCmds[3] = "cat";
	ListOfExtCmds[4] = "rm";


	for (i = 0; i < NoOfExtCmds; i++) {
		if (strcmp(parsed[0], ListOfExtCmds[i]) == 0) {
			switchExtArg = i + 1;
			break;
		}
	}

    int pid = fork();
    if (pid < 0) {
        printf("\nFailed forking child..");
        return 0;
    } else if (pid == 0) {
        switch (switchExtArg) {
        case 1:		//ls
			if (sizeof(parsed)==1){
            	execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/ls_cmd",NULL);
			}
			else{
				execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/ls_cmd",parsed[0],parsed[1],NULL);
			}
            break;
        case 2:		//mkdir
			if (parsed[1]==NULL){
            	printf("Insuficient arguments");
			}			
            else if (parsed[2]==NULL){
            	execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/mkdir_cmd",parsed[0],parsed[1],NULL);
			}
			else if (parsed[3]==NULL){
				execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/mkdir_cmd",parsed[0],parsed[1],parsed[2],NULL);
			}
			else{
				// printf("size: %d ",sizeof(parsed));
				// printf("0: %s , 1: %s ",parsed[0],parsed[1]);
				printf("Excess number of arguments provided");
			}
			break;
        case 3:		//date
            if (sizeof(parsed)==1){
            	execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/date_cmd",NULL);
			}
			else{
				execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/date_cmd",parsed[0],parsed[1],NULL);
			}
            break;
        case 4:		//cat
			if (parsed[1]==NULL){
            	printf("Insuficient arguments");
			}	
			else if (parsed[2]==NULL){
            	execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/cat_cmd",parsed[0],parsed[1],NULL);
			}
			else if (parsed[3]==NULL){
				execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/cat_cmd",parsed[0],parsed[1],parsed[2],NULL);
			}
			else{
				// printf("size: %d ",sizeof(parsed));
				// printf("0: %s , 1: %s ",parsed[0],parsed[1]);
				printf("Excess number of arguments provided\n");
			}
            break;
        case 5:		//rm
			if (parsed[1]==NULL){
            	printf("Insuficient arguments");
			}	
            else if (parsed[2]==NULL){
            	execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/rm_cmd",parsed[0],parsed[1],NULL);
			}
			else if (parsed[3]==NULL){
				execl("/home/parisha/myFilesCreated/A1_2021270_ParishaAgrawal/rm_cmd",parsed[0],parsed[1],parsed[2],NULL);
			}
			else{
				// printf("size: %d ",sizeof(parsed));
				// printf("0: %s , 1: %s ",parsed[0],parsed[1]);
				printf("Excess number of arguments provided\n");
			}
			break;
        default:
            printf("Command not recognized!! Use help to know more about the shell!!\n");
            break;
        }
        exit(0);
        return 0;
    } else {
        // waiting for child to terminate
        // printf("In wait\n");
        wait(NULL); 
        return 0;
    }
}

int ownCmdHandler(char** parsed){
	int NoOfOwnCmds = 5, i, switchOwnArg = 0;
	char* ListOfOwnCmds[NoOfOwnCmds];
	char* username;

    ListOfOwnCmds[0] = "exit";
	ListOfOwnCmds[1] = "cd";
	ListOfOwnCmds[2] = "echo";
	ListOfOwnCmds[3] = "pwd";
	ListOfOwnCmds[4] = "help";	

	for (i = 0; i < NoOfOwnCmds; i++) {
		if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) {
			switchOwnArg = i + 1;
			break;
		}
	}

	switch (switchOwnArg) {
	case 1:		//exit
		printf("Bye!! Have a Nice Day!!\n\n");
		exit(0);
	case 2:		//cd
		int ret = chdir(parsed[1]);
		if (ret < 0){
			printf("cd: %s: No such file or directory\n",parsed[1]);
		}
		return 0;
	case 3:		//echo
		int j = 1;
		while (parsed[j] != NULL){
			printf("%s ",parsed[j]);
			j++;
		}
		return 0;
	case 4:		//pwd
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		printf("%s\n", cwd);
		return 0;
	case 5:	//help
		openHelp();
		return 0;
	default:
        if (!strcmp(parsed[0],"&t")){
			// printf("Using pythread\n");
            externalCommandHandler_usingPthread(parsed);
        }
        else{
			// printf("Using fork\n");
		    externalCommandHandler_usingFork(parsed);
        }
		return 0;
	}
}

int parsePipe(char* str, char** strpiped){
    for (int i = 0; i<2; i++) {
        strpiped[i] = strsep(&str, "|");
        if (strpiped[i] == NULL)
            break;
    }
  
    if (strpiped[1] == NULL)
        return 0;
	return 1;
}

void parseSpace(char* str, char** parsed){
    for (int i = 0; i < MAXLIST; i++) {
        parsed[i] = strsep(&str, " ");
  
        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }
}

void processString(char* str, char** parsed, char** parsedpipe){
	char* strpiped[2];
	int piped = 0;
	piped = parsePipe(str, strpiped);
	if (piped) {
		parseSpace(strpiped[0], parsed);
		parseSpace(strpiped[1], parsedpipe);
	} else {
		parseSpace(str, parsed);
	}
	ownCmdHandler(parsed);
}

int main(){
	char inputString[MAXCOM], *parsedArgs[MAXLIST];
	char* parsedArgsPiped[MAXLIST];
	int execFlag = 0;
	shellBegins();
	while (1) {
		printDir();
		if (takeInput(inputString))
			continue;
		processString(inputString, parsedArgs, parsedArgsPiped);
	}
	return 0;
}