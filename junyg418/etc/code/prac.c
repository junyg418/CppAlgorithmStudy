#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/wait.h>

pid_t glob_pid1, glob_pid2;

void print_child_pids() {
    printf("first process : %d\n", glob_pid1);
    printf("second process: %d\n", glob_pid2);
}

int main() {
    pid_t pid1, pid2;
    int status;

    // 첫 번째 자식 프로세스 생성
    pid1 = fork();

    if (pid1 < 0) {
        // fork 실패
        perror("Fork failed");
        exit(-1);
    } else if (pid1 == 0) {
        // 자식 프로세스 1
        printf("Child process_1 : 'ps -al'\n");
        system("ps -al");
        perror("");
        exit(0);
    }
    else {
        glob_pid1 = pid1;
    }

    // 부모 프로세스가 이 부분으로 진행됨

    // 두 번째 자식 프로세스 생성
    pid2 = fork();

    if (pid2 < 0) {
        // fork 실패
        perror("Fork failed");
        exit(-1);
    } else if (pid2 == 0) {
        // 자식 프로세스 2
        printf("Child process 2 executing 'ls -l'\n");
        system("ls -l");
        perror("");
        exit(0);
    }
    else {
        glob_pid2 = pid2;
    }

    // 부모 프로세스가 이 부분으로 진행됨

    // 두 자식 프로세스가 종료될 때까지 기다림
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);

    // 부모 프로세스가 종료될 때에 2개의 자식 프로세스 아이디를 출력
    atexit(print_child_pids);

    return 0;
}