#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/*  (1)  */
char* one_time_pad_encr(char* text,int leng, char* key);
char* one_time_pad_decr(char* text,int leng, char* key);
/*  (2)  */
char* affine_encr(char *text);
char* affine_decr(char *text);
/*  (4)  */
char* trithemius_encr(char* text);
char* trithemius_decr(char* text);
/*  (5)  */
char* scytale_encr(char* text, unsigned int x);
char* scytale_decr(char* text, unsigned int x);
/*  (6)  */
char* rail_fence_encr(char* text, unsigned int x);
char* rail_fence_decr(char* text, unsigned int x);
/*  (3)  */
void substitution_decr(void);
