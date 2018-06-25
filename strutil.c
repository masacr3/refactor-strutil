#include <string.h>

/* devuelve la cantidad de bytes hasta el separador*/
size_t buscar(const char* s, char sep){
	size_t cont = 0;
	
	for(int i=0; s[i] && s[i] != sep; i++) cont++;
	
	return cont;
}

/* devuelve la cantidad de aparaciones del separador */
size_t contar_sep(const char* s, char sep){
	size_t cont = 0;
	
	for(int i=0; s[i]; i++) if( s[i] == sep ) cont++;
	
	return cont;
}


char **split(const char* str, char sep){
	if (sep == '\0' || !str) return NULL;
	
	size_t cant_sep = contar_sep(str,sep);
	
	char** _split = (char**)malloc(sizeof(char*) * (cant_sep + 2) );
	
	if (!_split) return NULL;
	
	
}
