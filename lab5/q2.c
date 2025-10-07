#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void sortStrings(char *arr[], int n) {
    // Sorting strings using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide at least one string as a command-line argument.\n");
        return 1;
    }

    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        // fork() failed
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process: Sort the strings and display them
        printf("Child Process - Sorted Strings:\n");
        sortStrings(argv + 1, argc - 1);  // Sort the strings passed in arguments

        // Display sorted strings
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
        exit(0);  // Exit the child process
    } else {
        // Parent process: Wait for the child to finish and then display unsorted strings
        wait(NULL);  // Wait for the child process to finish

        // Display unsorted strings
        printf("\nParent Process - Unsorted Strings:\n");
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}

