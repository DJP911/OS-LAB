#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) { // child process
        sleep(5);
        printf("Child process %d\n", getpid());
        printf("Parent process %d\n", getppid());
    } else { // parent process
        printf("Parent process %d\n", getpid());
        sleep(2); // wait for 2 seconds
        printf("Orphan process %d\n", getpid());
    }

    return 0;
}

