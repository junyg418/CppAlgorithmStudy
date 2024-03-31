#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void print_logo() {
    printf("linux mini shell\n");
}

void print_prompt() {
    printf(">");
}

void print_help() {
    printf("Usage: \n");
    printf("  help - Display this help message\n");
    printf("  quit - Exit the program\n");
    printf("  ls   - List files and directories\n");
    printf("  ps   - Display process status\n");
    printf("  who  - Show who is logged on\n");
    printf("  last - Show last logged in users\n");
    printf("  cal  - Display calendar\n");
    printf("  pwd  - Print working directory\n");
    printf("  date - Display current date and time\n");
}

void execute_command(char* command) {
    if (strcmp(command, "help") == 0) {
        print_help();
    } else if (strcmp(command, "quit") == 0) {
        exit(0);
    } else if (strcmp(command, "ls") == 0) {
        execlp("ls", "ls", NULL);
    } else if (strcmp(command, "ps") == 0) {
        execlp("ps", "ps", NULL);
    } else if (strcmp(command, "who") == 0) {
        execlp("who", "who", NULL);
    } else if (strcmp(command, "last") == 0) {
        execlp("last", "last", NULL);
    } else if (strcmp(command, "cal") == 0) {
        execlp("cal", "cal", NULL);
    } else if (strcmp(command, "pwd") == 0) {
        execlp("pwd", "pwd", NULL);
    } else if (strcmp(command, "date") == 0) {
        execlp("date", "date", NULL);
    } else {
        printf("not valid command!\n");
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    print_logo();

    while (1) {
        print_prompt();
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // remove trailing newline character

        execute_command(command);
    }

    return 0;
}