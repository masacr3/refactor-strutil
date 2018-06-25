#include <stdio.h>
#include "strutil.h"

int main(){
  char* cadena = "hola como estas";
  char** s = split(cadena,' ');
  
  fprintf(stdout, "cadena original: %s\n", cadena);
  printf("\n");
  
  for(int i=0; s[i]; i++){
    fprintf(stdout, "%s", s[i]);
  }
  
  free_strv(s);
  return 0;
}
