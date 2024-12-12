#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ret;
    int pid;
    int status;


    while (1)
    {
        pid = fork();
        if (pid == 0)
        {
            ret = system("jgdb -device cortex-a7");
            if (ret < 0)
            {
                perror("system");
            }

            return ret;
        }
        else
        {
            waitpid(pid, &status, 0);
            usleep(1000);
        }

    }

    return 0;
}
