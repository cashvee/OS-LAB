#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void bubbleSort(char *a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                char *t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int partition(char *a[], int l, int h)
{
    char *p = a[h];
    int i = l - 1;
    for (int j = l; j < h; j++)
        if (strcmp(a[j], p) < 0)
        {
            i++;
            char *t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    char *t = a[i + 1];
    a[i + 1] = a[h];
    a[h] = t;
    return i + 1;
}

void quickSort(char *a[], int l, int h)
{
    if (l < h)
    {
        int pi = partition(a, l, h);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h);
    }
}

int main()
{
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char *a[n];
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++)
    {
        a[i] = malloc(100);
        scanf("%s", a[i]);
    }

    fflush(stdout); // very important before fork()
    pid_t c1 = fork();

    if (c1 == 0)
    {
        char *b[n];
        for (int i = 0; i < n; i++)
            b[i] = strdup(a[i]);
        bubbleSort(b, n);
        printf("\nChild 1 (Bubble Sort):\n");
        for (int i = 0; i < n; i++)
            printf("%s\n", b[i]);
        exit(0);
    }

    wait(NULL);
    fflush(stdout);
    pid_t c2 = fork();

    if (c2 == 0)
    {
        char *b[n];
        for (int i = 0; i < n; i++)
            b[i] = strdup(a[i]);
        quickSort(b, 0, n - 1);
        printf("\nChild 2 (Quick Sort):\n");
        for (int i = 0; i < n; i++)
            printf("%s\n", b[i]);
        exit(0);
    }

    wait(NULL);
    printf("\nParent (Original Order):\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", a[i]);
    return 0;
}
