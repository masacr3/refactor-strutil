#include <stdio.h>
#include <stdlib.h>
#include "strutil.h"

int main(){
  char* cadena = "leo,piola,gg";
  char** s = split(cadena,',');
  
  fprintf(stdout, "cadena original: %s\n", cadena);
  printf("\n");
  
  for(int i=0; s[i]; i++){
    fprintf(stdout, "%d - %s\n",i, s[i]);
  }
  
  char* j = join(s,',');
  
  fprintf(stdout, "\n join-> %s", j);
  
  
  free_strv(s);
  free(j);
  return 0;
}
