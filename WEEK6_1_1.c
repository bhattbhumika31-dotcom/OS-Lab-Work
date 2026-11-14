
// FIFO - WRITER PROGRAM

#include <stdio.h>      // printf(), perror()
#include <stdlib.h>     // EXIT_SUCCESS, EXIT_FAILURE
#include <string.h>     // strlen()
#include <sys/stat.h>   // mkfifo() ke liye
#include <fcntl.h>      // open(), O_WRONLY ke liye
#include <unistd.h>     // write(), close() ke liye

int main(void)
{
    int fd;                 // File descriptor store karega
    char message[100];      // User ka message store karega


    // STEP 1: Create FIFO
    // mkfifo() ek named pipe create karta hai.
    // "myfifo" = FIFO file ka naam
    // 0666 = Read aur Write permissions

    mkfifo("myfifo", 0666);


    // STEP 2: Open FIFO in write mode
    // open() FIFO ko open karta hai.
    // O_WRONLY = Sirf writing ke liye open karna.
    // fd mein opened FIFO ka file descriptor milega.

    fd = open("myfifo", O_WRONLY);


    // Agar FIFO open nahi hoti toh -1 return hota hai.
    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }


    // STEP 3: Take input from user
    // User se message input lenge.
    // fgets() input ko message array mein store karega.

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);


    // STEP 4: Write message into FIFO
    // write() message ko FIFO mein send karta hai.
    // fd = FIFO ka file descriptor
    // message = Data jo send karna hai
    // strlen(message) + 1 = Message size including '\0'

    write(fd, message, strlen(message) + 1);


    // STEP 5: Close FIFO
    // close() FIFO ka file descriptor close karta hai.

    close(fd);


    // Program successfully terminate ho gaya.
    return EXIT_SUCCESS;
}
