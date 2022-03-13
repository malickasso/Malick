#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
     pid_t pid_fils;
     pid_fils=fork();
     if (pid_fils<0)
     {
         fprintf (stderr, "Eurreur de cr�ation du processus (%d) (%d)\n", pid_fils, errno);
         return 1;
     }

    if(pid_fils==0)
    {
        printf ("je suis le fils, mon pid est %d \n", getpid());
        printf ("voici le pid de mon p�re %d \n", getpid());
    }
    else
    {
        int status ;
        pid_t pid2=wait(&status);
        printf ("je suis le p�re, mon pid est %d \n", getpid());
        printf ("voici le pid de mon fils, %d \n", pid_fils, status);
    }

    return 0;
}
