Q.1) Generate parent process to write unnamed pipe and will read from it

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pipe(pipefd);

    if (fork() == 0) {
        close(pipefd[0]);
        write(pipefd[1], "Hello from parent process", 26);
        close(pipefd[1]);
        exit(0);
    } else {
        char buffer[30];
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("%s\n", buffer);
        close(pipefd[0]);
    }

    return 0;
}

Output:
Hello from parent process