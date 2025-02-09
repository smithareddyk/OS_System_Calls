#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{
        struct processstat p;
        int uniq = fork();
        if (uniq == 0)
        {
                int f = open("ex1.txt", 0);
                uniqIOperation(f);
                close(f);
                if (getprocessstats(uniq, &p) < 0)
                {
                        exit();
                }
                exit();
        }

        else
        {
                wait();
        }
        int pid = fork();
        if (pid == 0)
        {
                int f = open("ex1.txt", 0);
                headOperation(f, 6);
                close(f);
                if (getprocessstats(pid, &p) < 0)
                {
                        exit();
                }

                exit();
        }
        else
        {
                wait();
        }
        exit();
}
