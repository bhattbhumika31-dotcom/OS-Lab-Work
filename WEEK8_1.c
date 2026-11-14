
// SHARED MEMORY - WRITER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key;
    int shmid;
    char *shared;

    // STEP 1: Generate unique key
    // Writer aur Reader dono same key use karenge.
    key = ftok(".", 'S');

    // STEP 2: Create shared memory
    // 1024 = Memory size
    // 0666 = Read and Write permission
    // IPC_CREAT = Create memory if it does not exist.
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if (shmid == -1)
    {
        perror("shmget");
        return EXIT_FAILURE;
    }

    // STEP 3: Attach shared memory
    // Shared memory ko current process se connect karta hai.
    shared = (char *)shmat(shmid, NULL, 0);

    if (shared == (char *)-1)
    {
        perror("shmat");
        return EXIT_FAILURE;
    }

    // STEP 4: Take input from user
    // Input directly shared memory mein store hoga.
    printf("Enter data: ");
    fgets(shared, 1024, stdin);

    printf("Data written to shared memory.\n");

    // STEP 5: Detach shared memory
    // Current process ka connection disconnect karta hai.
    shmdt(shared);

    return EXIT_SUCCESS;
}
