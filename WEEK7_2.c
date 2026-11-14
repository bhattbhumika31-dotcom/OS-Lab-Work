
// MESSAGE QUEUE - RECEIVER

#include <stdio.h>      // printf(), perror()
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE
#include <sys/ipc.h>    // ftok() ke liye
#include <sys/msg.h>    // Message Queue functions ke liye


// Same message structure define karna zaroori hai
// Jo Sender program mein use kiya tha.

struct message
{
    long type;          // Message ka type
    char text[100];     // Message ka actual data
};


int main(void)
{
    key_t key;          // Message Queue ki key
    int msgid;          // Message Queue ID
    struct message msg; // Received message store karega


    // STEP 1: Generate same key
    // Sender ki tarah same directory "." aur 'A'
    // use karna zaroori hai.
    // Isse dono same Message Queue access karenge.

    key = ftok(".", 'A');


    // STEP 2: Access Message Queue
    // msgget() existing queue ko access karega.
    // IPC_CREAT lagaya hai, agar queue exist nahi karti
    // toh ye create bhi kar sakta hai.

    msgid = msgget(key, 0666 | IPC_CREAT);


    // Agar msgget() fail hota hai toh -1 return karega.
    if (msgid == -1)
    {
        perror("msgget");
        return EXIT_FAILURE;
    }


    // STEP 3: Receive message
    // msgrcv() Message Queue se message receive karta hai.
    // msgid = Queue ID
    // &msg = Received message store karne ka address
    // sizeof(msg.text) = Maximum message size
    // 1 = Sirf type 1 ka message receive karna
    // 0 = Normal receiving mode.

    msgrcv(msgid,
           &msg,
           sizeof(msg.text),
           1,
           0);


    // STEP 4: Display received message
    // Received message ko screen par display karega.

    printf("Received: %s", msg.text);


    // STEP 5: Delete Message Queue
    // msgctl() queue ko control karta hai.
    // IPC_RMID = Message Queue ko permanently remove karna.
    // NULL = Additional information nahi deni.

    msgctl(msgid, IPC_RMID, NULL);


    // Program successfully terminate ho gaya.
    return EXIT_SUCCESS;
}
