#include <stdio.h>
#include <stdlib.h>
int main() {
    key_t key;
    int shmid;
    char *shared;
    key = ftok(".", 'S');
    shmid=shmget(key,1024,0666);
    if(shmid==-1){
        perror("shmget");
        exit(1);
    }
    shared=(char *)shmat(shmid,NULL,0);
    if(shared==(char *)-1){
        perror("shmat");
        exit(1);
    }
    printf("Data read from shared memory: %s\n", shared);
    shmdt(shared);
    return 0;
}