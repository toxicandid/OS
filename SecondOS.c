#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

// Function declarations
void asc(int a[], int n);
void dsc(int a[], int n);

int main() {
    // Number of elements in the array
    int n = 5;
    
    // Array to be sorted
    int a[5] = {2, 5, 3, 7, 1};
    
    // Process ID variable
    pid_t pid;

    // Create a child process using fork
    pid = fork();

    // Check for fork error
    if (pid < 0) {
        perror("Fork Error\n");
    } else if (pid == 0) {
        // Child process
        printf("Child process ID: %ld\n", (long)getpid());
    } else {
        // Parent process
        printf("Parent process ID: %ld\n", (long)getpid());
    }

    // Switch based on the fork result
    switch (pid) {
        case -1:
            // Fork error
            printf("\nFork error\n");
            exit(-1);
            
        case 0:
            // Child process
            printf("\nChild executes.....\n");
            
            // Sorting array in ascending order
            asc(a, n);
            
            // Exit the child process
            exit(pid);

        default:
            // Parent process
            // Wait for the child process to complete
            wait(NULL);
            
            printf("\nParent executes.....\n");
            
            // Sorting array in descending order
            dsc(a, n);
            
            // Display process information
            system("ps -elf");
            
            // Exit the parent process
            exit(pid);
    }

    return 0;
}

// Function to sort array in ascending order
void asc(int a[], int n) {
    int i, j, temp;
    
    // Bubble sort algorithm for ascending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    // Display the sorted array in ascending order
    printf("\nArray sorted in ascending order is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Function to sort array in descending order
void dsc(int a[], int n) {
    int i, j, temp;
    
    // Bubble sort algorithm for descending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    // Display the sorted array in descending order
    printf("\nArray sorted in descending order is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
