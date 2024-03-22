#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void pwnme()
{
    char buffer[32];
    memset(buffer, 0, 32);
    puts(
      "For my first trick, I will attempt to fit 56 bytes of user input into 32 bytes of stack buffe r!"
    );
    puts("What could possibly go wrong?");
    puts(
      "You there, may I have your input please? And don\'t worry about null bytes, we\'re using read ()!\n"
    );
    printf("> ");
    read(0,buffer,56);
}

int main()
{
    printf("Roberry ret2Win - Based on ropemporium.com ret2win");
    printf("ARM v8 - RPI4B");
    pwnme();
    printf("Exitting...");
    return 0;
}

int ret2Win()
{
    printf("Ret2Winer! Here's your flag:");
    system("/bin/cat flag.txt");
    return 0;
}