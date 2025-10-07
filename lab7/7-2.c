#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_READERS 5
#define MAX_WRITERS 2

sem_t mutex, write_sem; // mutex for readers count, write_sem for writers
int reader_count = 0;   // number of active readers

// Function prototypes
void *reader(void *arg);
void *writer(void *arg);

int main()
{
    pthread_t rthreads[MAX_READERS], wthreads[MAX_WRITERS];

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&write_sem, 0, 1);

    // Create reader threads
    for (int i = 0; i < MAX_READERS; i++)
    {
        pthread_create(&rthreads[i], NULL, reader, (void *)(long)(i + 1));
    }

    // Create writer threads
    for (int i = 0; i < MAX_WRITERS; i++)
    {
        pthread_create(&wthreads[i], NULL, writer, (void *)(long)(i + 1));
    }

    // Join threads (infinite loops, program runs indefinitely)
    for (int i = 0; i < MAX_READERS; i++)
        pthread_join(rthreads[i], NULL);
    for (int i = 0; i < MAX_WRITERS; i++)
        pthread_join(wthreads[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&write_sem);

    return 0;
}

void *reader(void *arg)
{
    int id = (int)(long)arg;
    while (1)
    {
        // Entry section
        sem_wait(&mutex);
        reader_count++;
        if (reader_count == 1)
            sem_wait(&write_sem); // first reader locks writer
        sem_post(&mutex);

        // Critical section
        printf("Reader %d is reading\n", id);
        sleep(1); // simulate reading

        // Exit section
        sem_wait(&mutex);
        reader_count--;
        if (reader_count == 0)
            sem_post(&write_sem); // last reader releases writer
        sem_post(&mutex);

        sleep(1); // simulate doing other work
    }
}

void *writer(void *arg)
{
    int id = (int)(long)arg;
    while (1)
    {
        sem_wait(&write_sem); // exclusive access for writer

        // Critical section
        printf("Writer %d is writing\n", id);
        sleep(2); // simulate writing

        sem_post(&write_sem); // release write lock

        sleep(1); // simulate doing other work
    }
}
