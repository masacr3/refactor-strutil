#include "strutil.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	
	_split[ cant_sep + 1 ] = NULL;
	
	size_t inicio = 0;
	
	for (int i=0; i <= cant_sep; i++){
		//calculo cuantos bytes voy a copiar
		size_t bytes = buscar(&str[inicio], sep);
		
		//creo la cadena + 1 (para el caracter '\0'
		char* s = malloc( sizeof(char) * (bytes + 1));
	
		if( !s ){
			strv_free(_split);
			return NULL;
		}
		
		//copio los caracteres a s
		memcpy(s, &str[inicio], bytes);
		
		//inserto el byte '\0'
		s[bytes] = '\0';
		
		//vinculo la cadena al split
		_split[i] = s;
		
		//salto el separador
		inicio += bytes + 1;
		
	}
	return _split;
}
