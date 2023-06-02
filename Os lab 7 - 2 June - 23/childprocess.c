#include<stdio.h>
#include<unistd.h>

int main() {
    pid_t pid = fork(); // Create a child process

    if(pid == 0) { // Child process
        printf("Child process\n");
        printf("Exiting...\n");
    }
    else { // Parent process
        sleep(5); // Wait for 5 seconds before terminating the parent process
    }

    return 0;
}

