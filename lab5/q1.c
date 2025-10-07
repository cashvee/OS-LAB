#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    pid_t pid; // variable to store process ID

    pid = fork(); // Create a child process

    if (pid < 0) { // fork() failed
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) { // Child process
        printf("\nChild Process:\n");
        printf("PID: %d\n", getpid());    // Get the process ID of the child
        printf("PPID: %d\n", getppid());  // Get the parent process ID (PPID)
        
    } else { // Parent process
        printf("\nParent Process:\n");
        printf("PID: %d\n", getpid());    // Get the process ID of the parent
        printf("PPID(parent of parent process): %d\n", getppid());  // Get the parent process ID (PPID)
        
    }

    return 0;
}

