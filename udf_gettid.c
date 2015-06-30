#include <string.h>
#include <mysql.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  
#include <linux/unistd.h> 
#include <unistd.h>
#include <sys/syscall.h> 

my_bool gettid_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
  if (args->arg_count != 0)
  {
    strcpy(message, "gettid() requires no arguments");
    return 1;
  }

  return 0;
}

long long gettid(UDF_INIT *initid, UDF_ARGS *args,
              char *is_null, char *error)
{
  return(syscall( __NR_gettid ));
}

