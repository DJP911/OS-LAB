#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid, wpid;
    int status = 0;
    int i;

    // Create four child processes
    for (i = 1; i <= 4; i++) {
        pid = fork();

        if (pid == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) { // Child process
            printf("Child process %d with PID %d created\n", i, getpid());
            sleep(5); // Sleep for 5 seconds before terminating
            printf("Child process %d with PID %d terminated\n", i, getpid());
            exit(i); // Terminate with exit status equal to i
        }
    }

    // Wait for the fourth child process to terminate first
    while ((wpid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) == 4) {
                printf("Fourth child process with PID %d terminated last\n", wpid);
                break;
            }
        }
    }

    // Wait for the remaining child processes to terminate in any order
    while ((wpid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            printf("Child process with PID %d terminated\n", wpid);
        }
    }

    // Parent process terminates last
    printf("Parent process with PID %d terminated\n", getpid());

    return 0;
}

