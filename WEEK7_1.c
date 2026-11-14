
// MESSAGE QUEUE - SENDER

#include <stdio.h>      // printf(), perror()
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE
#include <string.h>     // strlen()
#include <sys/ipc.h>    // ftok() ke liye
#include <sys/msg.h>    // Message Queue functions ke liye


// Message ka structure define kar rahe hain
struct message
{
    long type;          // Message ka type store karega
    char text[100];     // Actual message store karega
};


int main(void)
{
    key_t key;          // Message Queue ki unique key
    int msgid;          // Message Queue ka ID
    struct message msg; // Structure ka variable


    // STEP 1: Generate unique key
    // ftok() current directory "." aur character 'A'
    // ki help se key generate karta hai.
    // Sender aur Receiver dono same key use karenge.

    key = ftok(".", 'A');


    // STEP 2: Create or access Message Queue
    // key = Queue ki unique key
    // 0666 = Read and Write permission
    // IPC_CREAT = Queue exist nahi karti toh create karo

    msgid = msgget(key, 0666 | IPC_CREAT);


    // Agar msgget() fail hota hai toh -1 return karta hai.
    if (msgid == -1)
    {
        perror("msgget");
        return EXIT_FAILURE;
    }


    // STEP 3: Assign message type
    // Message ko type 1 assign kar rahe hain.
    // Receiver isi type ka message receive karega.

    msg.type = 1;


    // STEP 4: Take message input
    // User se message input lenge.
    // fgets() input ko msg.text mein store karega.
    // sizeof(msg.text) = Maximum 100 characters.

    printf("Enter message: ");
    fgets(msg.text, sizeof(msg.text), stdin);


    // STEP 5: Send message
    // msgsnd() message ko Message Queue mein send karta hai.
    // msgid = Message Queue ID
    // &msg = Message structure ka address
    // strlen(msg.text) + 1 = Message ki length including '\0'
    // 0 = No special flag; normal sending.

    msgsnd(msgid,
           &msg,
           strlen(msg.text) + 1,
           0);


    // Confirmation message
    printf("Message sent.\n");


    // Program successfully terminate ho gaya.
    return EXIT_SUCCESS;
}
