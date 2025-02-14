#include "cs457_crypto.h"

int main(void){
    char* xaraktires;
    char* s; /* Αρχικοποίηση της μεταβλητής s*/
    char* ss;
    char* c;
    int r,i,m;
    r=open("/dev/urandom", O_RDONLY);
    /*printf("Give me a text for encryption.\n");
    ss = (char*)malloc(100 * sizeof(char)); 
    if(ss==NULL){
        printf("Memory allocation for ss failed.");
        return -1;
    }
    scanf(" %s",s);
    m=strlen(s);
    ss=s;
    xaraktires = (char*)malloc((m+1) * sizeof(char)); /* Πρόσθεση παρενθέσεων για σωστή προτεραιότητα 
    c=one_time_pad_encr(s,strlen(ss),xaraktires);
    for(i=0;i<strlen(ss);i++){
        printf("%x",c[i]);
    }
    printf("\n");
    c=one_time_pad_decr(c,strlen(ss), xaraktires);
    printf("%s",c);
    printf("\n");
    /*  (2)  
    c= affine_encr("aF F$N"); 
    printf("\n%s\n",c);
    c=affine_decr(c);
    printf("%s\n",c);/*
    /*  (4)  */
    c=trithemius_encr("Nori 09 tzatzai!(){}[]");
    printf("\n%s\n",c);
    c=trithemius_decr(c);
    printf("Trithemius: %s\n",c);
    /*  (5)  */
    c=scytale_encr("123@ nori 09 tzatzai",3);
    printf("\n%s\n",c);
    c=scytale_decr(c,3);
    printf("Scytale: %s\n",c);
    /*  (6)  */
    c=rail_fence_encr("noriana 09 tzatzai !",3);
    printf("\n%s\n",c);
    c=rail_fence_decr(c,3);
    printf("Rail: %s\n",c);
    /*  (3)  */
    //substitution_decr();
    return 0;
}
