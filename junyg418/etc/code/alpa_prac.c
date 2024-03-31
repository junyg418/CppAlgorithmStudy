# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

pid_t pid;

void run_command(char *command) {
    if ((pid = fork()) < 0) {
        perror("fork failed");
        exit(-1);
    }

    if (pid == 0) {
        system(command);
        exit(0);
    }
}

void print_help(){
            printf("\
ls : 현재 디렉토리에 있는 내용 리스트를 출력\n\
ps : Process State의 약자로 현재 실행중인 프로세스와 상태를 출력\n\
who : 로그인한 사용자의 정보를 출력\n\
last : 시스템 로그인 로그를 출력\n\
cal : 달력 출력\n\
pwd : 현재 디렉토리 출력\n\
date : 시간 출력\n\
quit : 종료\n");
}


int main(){
    printf("Linux mini shell\n");
    char command[100];

    while(1){
        printf(">");
        scanf("%s", command);

        if (strcmp(command, "help") == 0){
            print_help();
        }
        else if (strcmp(command, "ls") == 0){
            run_command("ls");
        }
        else if (strcmp(command, "ps") == 0){
            run_command("ps");
        }
        else if (strcmp(command, "who") == 0){
            run_command("who");
        }
        else if (strcmp(command, "last") == 0){
            run_command("last");
        }
        else if (strcmp(command, "cal") == 0){
            run_command("cal");
        }
        else if (strcmp(command, "pwd") == 0){
            run_command("pwd");
        }
        else if (strcmp(command, "date") == 0){
            run_command("date");
        }
        else if (strcmp(command, "quit") == 0){
            break;
        }
        else{
            printf("not valid command!\n");
            continue;
        }
        waitpid(pid, NULL, 0);
    }
}