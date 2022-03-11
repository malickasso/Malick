#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc , char *argv[]){
  pid_t pid = fork();
  if(pid < 0){

    fprintf(stderr, "Erreur de cr�ation du processus (%d) (%d)\n", pid, errno);
    return 1;
  }
  if(pid == 0){

     printf("je suis le fils (%d), mon p�re est (%d)\n", getpid(), getppid());
  }else{

    int status;
    pid_t pid2 = wait(&status);
    printf("Je suis le p�re (%d) mon fils que je viens de cr�er (%d)"
           "s'est termin� avec le code d'erreur (%d)", getpid(), pid, status);
  }
  printf("Ou suis-je?\n");
  return 0;
}
