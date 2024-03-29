#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

int main() {
    int pipefd[2];
    pid_t cpid;
    char buf;

    // 创建管道
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 创建子进程
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    /* 子进程 */
        close(pipefd[1]);  // 关闭写端

        // 从管道读取数据并打印
        while (read(pipefd[0], &buf, 1) > 0) {
            write(STDOUT_FILENO, &buf, 1);
        }

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } else {            /* 父进程 */
        close(pipefd[0]);  // 关闭读端

        // 向管道写入数据
        const char* msg = "Hello from parent!";
        write(pipefd[1], msg, strlen(msg));
        close(pipefd[1]);  // 关闭写端，触发EOF

        wait(NULL);       // 等待子进程结束
        exit(EXIT_SUCCESS);
    }
}
