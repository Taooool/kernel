// init: The initial sys-level program

#include "kernel/include/types.h"
#include "kernel/include/stat.h"
#include "kernel/include/file.h"
#include "kernel/include/fcntl.h"

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  // if(open("console", O_RDWR) < 0){
  //   mknod("console", CONSOLE, 0);
  //   open("console", O_RDWR);
  // }
  dev(O_RDWR, CONSOLE, 0);
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    printf("init: starting sh\n");
    pid = fork();
    if(pid < 0){
      printf("init: fork failed\n");
      exit(1);
    }
    if(pid == 0){
      exec("sh", argv);
      printf("init: exec sh failed\n");
      exit(1);
    }

    // for(;;){
    //   // this call to wait() returns if the shell exits,
    //   // or if a parentless process exits.
    //   wpid = wait((int *) 0);
    //   if(wpid == pid){
    //     // the shell exited; restart it.
    //     break;
    //   } else if(wpid < 0){
    //     printf("init: wait returned an error\n");
    //     exit(1);
    //   } else {
    //     // it was a parentless process; do nothing.
    //   }
    // }
  }
}
