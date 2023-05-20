#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int num_children;
    printf("Enter the number of child processes to be generated: ");
    scanf("%d", &num_children);

    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            printf("Child process %d with ID %d (Parent ID %d)\n", i+1, getpid(), getppid());
            exit(0);
        }
    }

    printf("Parent process with ID %d\n", getpid());
    return 0;
}

