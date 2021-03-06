// ----------------------------------------------------------------
// ESPECIFICAÇÃO: O programa deve determinar se um identificador
// é ou não válido. Um identificador válido deve começar com uma
// letra e conter apenas letras ou dígitos. Além disto, deve ter
// no mínimo 1 caractere e no máximo 6 caracteres de comprimento
// ----------------------------------------------------------------

#include <stdio.h>
#include <string.h>
int valid_s(char *ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    return 1;
  else
    return 0;
}

int valid_f(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
    return 1;
  else
    return 0;
}

int Identifier(char achar[]) {
  //char achar;
  int  length, valid_id;
  length = 0;
  printf("Identificador: ");
  //achar = fgetc(stdin);
  valid_id = valid_s(achar[0]);
  if(valid_id) {
    length = 1;
  }
  //achar = fgetc(stdin);
  //while(achar != '\n') {
  int i = 0;
  while(achar[i] != NULL){
    if(!(valid_f(achar[i]))) {
      valid_id = 0;
    }
    length++;
    i++;
    //achar = fgetc(stdin);
  }
  if (valid_id && (length >= 1) && (length <= 6)) {
    printf("Valido\n");
    return 0;
  }
  else {
    printf("Invalido\n");
    return 1;
  }
}


int main(int argc, char *in[])
{
  if (argc != 2) {
		printf("Usage: %s iface\n", in[0]);
		return 1;
	}
  char temp[100];
	strcpy(temp, in[1]);
  //printf("%s", temp);
  int i = Identifier(temp);
  //char tempi[5];
  //tempi[5] = 0 ;
  return i;
  //return 0;
}
