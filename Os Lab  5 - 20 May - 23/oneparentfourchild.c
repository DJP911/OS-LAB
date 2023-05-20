#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid[4];
    int i, status;

    // create 4 child processes
    for (i = 0; i < 4; i++) {
        pid[i] = fork();
        if (pid[i] == -1) {
            printf("Error creating process\n");
            exit(1);
        } else if (pid[i] == 0) {
            printf("Child process %d with id %d\n", i+1, getpid());
            exit(0);
        }
    }

    // wait for all child processes to terminate
    for (i = 0; i < 4; i++) {
        waitpid(pid[i], &status, 0);
        printf("Child process %d with id %d terminated\n", i+1, pid[i]);
    }

    // parent process terminates last
    printf("Parent process with id %d terminating last\n", getpid());

    return 0;
}

