#include "cs457_crypto.h"

char* one_time_pad_encr(char* text,int leng, char* key){ /* polaplasiazei ka8e gramma toy text me to key */
    char* kripto;
    int i;
    kripto = (char*)malloc(leng * sizeof(char));
    for(i=0;i<leng;i++){
        kripto[i]=text[i]^key[i];
    }
    kripto[i]='\0';
    return kripto;
}

char* one_time_pad_decr(char* text,int leng, char* key){ /* pollaplasiaxei ka8e gramma toy text me to key*/
    char* apokripto;
    int i;
    apokripto = (char*)malloc(leng * sizeof(char));
    for(i=0;i<leng;i++){
        apokripto[i]=text[i]^key[i];
    }
    apokripto[i]='\0';
    return apokripto;
}

char* affine_encr(char *text){   
    char* text2 = malloc((strlen(text) + 1) * sizeof(char)); 
    int i = 0, k, tmp;
    while(text[i] != '\0') {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {  /* koitaei an ptokeitai gia gramma */
            if (text[i] >= 'A' && text[i] <= 'Z')  k = text[i] - 'A'; /* an einai megala*/
            else  k = text[i] - 'a';                                  /* an einai mikara */
            tmp = (5 * k + 8) % 26;                                   /* efarmolzei th synartisi */
            text2[i] = (char)(tmp + ((text[i] >= 'A' && text[i] <= 'Z') ? 'A' : 'a')); 
        } else {
            text2[i] = text[i];                                      /* an den einai gramma to afinw opos einai */
        }
        i++;
    }
    text2[i] = '\0';
    return text2;
}

char* affine_decr(char *text){
   char* text2 = malloc((strlen(text) + 1) * sizeof(char)); 
    int i = 0, k, tmp;
    while(text[i] != '\0') {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) { 
            if (text[i] >= 'A' && text[i] <= 'Z')  k = text[i] - 'A';
            else  k=text[i]-'a'; 
            tmp=(21 * (k - 8)) % 26;                             /* efarmozw th synartisi*/
            if (tmp < 0) tmp += 26;   
            text2[i] = (char)(tmp + ((text[i] >= 'A' && text[i] <= 'Z') ? 'A' : 'a')); 
        } else {
            text2[i] = text[i];                    /* an den einai gramma to afinw opws eiai */
        }
        i++;
    }
    text2[i] = '\0'; 
    return text2;
}

char* trithemius_encr(char* text){
    char trith[52][52];
    int thesiStath=0,thesiMet=0;
    char P[52];                 /* Pinakas me tha grammata A-Z,a-z*/
    int i,j=65;
    char* text2=(char*)malloc(strlen(text)*sizeof(char));
    for(i=0;i<26;i++){ /* Dimiourgia pinaka me A-Z*/
        P[i]='A'+i;
        j++;
    }
    j=0;
    for(i=26;i<52;i++){ /* Dimiourgia pinaka me a-z*/
        P[i]='a'+j;
        j++;
    }
    for(i=0;i<52;i++){  /* Dimiurgia pinaka 52x52*/
        for(j=0;j<52;j++){
            if(thesiStath>52) thesiStath=0;
            if(thesiMet>52) thesiMet=0;
            trith[i][j]=P[thesiMet];
            thesiMet++;
        }
        thesiStath++;
        thesiMet=thesiStath;
    }
    thesiStath=0;
    for(i=0;i<strlen(text);i++){
        if(thesiStath>52) thesiStath=0;
        for(j=0;j<52;j++){
            if((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z')){
                if(text[i]==P[j]){
                    text2[i]=trith[thesiStath][j]; /* Bazw to grama poy uparxei sth 8esh thesiStath */
                    break;
                }
            }else{
                text2[i]=text[i];
                break;
            }
        }
        thesiStath++;
    }
    return text2;
}

char* trithemius_decr(char* text){
    char trith[52][52];
    int thesiStath=0,thesiMet=0;
    char P[52];
    int i,j=65;
    char* text2=(char*)malloc(strlen(text)*sizeof(char));
    for(i=0;i<26;i++){ /* Dimiourgia pinaka me A-Z*/
        P[i]='A'+i;
        j++;
    }
    j=0;
    for(i=26;i<52;i++){ /* Dimiourgia pinaka me a-z*/
        P[i]='a'+j;
        j++;
    }
    for(i=0;i<52;i++){  /* Dimiurgia pinaka 52x52*/
        for(j=0;j<52;j++){
            if(thesiStath>52) thesiStath=0;
            if(thesiMet>52) thesiMet=0;
            trith[i][j]=P[thesiMet];
            thesiMet++;
        }
        thesiStath++;
        thesiMet=thesiStath;
    }
    thesiStath=0;
    for(i=0;i<strlen(text);i++){  /* Vriskw se poio grama toy pragmatikoy pinaka P antistoixei to kriptografimeno minima*/
        for(j=0;j<52;j++){
            if((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z')){
                if(text[i]==trith[thesiStath][j]){
                    text2[i]=P[j];
                }
            }else{
                text2[i]=text[i];
            }
        }
        if(thesiStath>52) thesiStath=0;
        else thesiStath++;
    }
    return text2;
}

char* scytale_encr(char* text, unsigned int x){
    int m, k, z, i, j;
    int megethos = 0;
    char* text2;
    char** pinakas;
    megethos = strlen(text);
    k = megethos / x;      /* gia na upologisw tis grammes */
    z = megethos % x;
    if(z > 0)             /* an exv ypoloipo vazw +1 grammh */
        k++;
    text2 = (char*)malloc(strlen(text) * sizeof(char));
    pinakas = (char**)malloc(k * sizeof(char*));
    if (pinakas == NULL || text2 == NULL) {
        printf("Apotixia desmefsis mnimis\n");
        exit(0);
    }
    for (i = 0; i < k; i++) {
        pinakas[i] = (char*)malloc(x * sizeof(char));
        if (pinakas[i] == NULL) {
            printf("Apotixia desmefsis mnimis\n");
            exit(0);
        }
    }
    m = 0;
    for (i = 0; i < k; i++) {     /* vazw to text ston pinaka */
        for (j = 0; j < x; j++) {
            if (m < megethos) {
                pinakas[i][j] = text[m];
                m++;
            } else {
                pinakas[i][j] = '\0';  /* ama periswvoyn grammes vazw ton termatiko xaraktira */
            }
        }
    }
    m = 0;
    for (j = 0; j < x; j++) {      /* diavazw to text apo tis stiles*/
        for (i = 0; i < k; i++) {
            if (pinakas[i][j] != '\0') {
                text2[m] = pinakas[i][j];
                m++;
            }
        }
    }

    for (i = 0; i < k; i++) {
        free(pinakas[i]);
    }
    free(pinakas);
    return text2;  /* to epistrefw */
}

char* scytale_decr(char* text, unsigned int x) {
    int m, k, z, i, j;
    int megethos = 0;
    char* text2 = (char*)malloc(strlen(text) * sizeof(char));
    char** pinakas; 
    z = 0;
    megethos = strlen(text);
    k = megethos / x;    /* fia na vrw tis grammes*/
    z = megethos % x;
    if (z > 0) k++;    /* an exw ypoloipo +1 grammh */
    pinakas = (char**)malloc(k * sizeof(char*));
    if (pinakas == NULL || text2 == NULL) {
        printf("Apotixia desmefsis mnimis\n");
        exit(0);
    }
    for (i = 0; i < k; i++) {
        pinakas[i] = (char*)malloc(x * sizeof(char));
        if (pinakas[i] == NULL) {
            printf("Apotixia desmefsis mnimis\n");
            exit(0);
        }
    }
    m = 0;
    for (j = 0; j < x; j++) {   /* bazw to keimeno ston pinaka */
        if (z > 0 && j >= z) {
            for (i = 0; i < k - 1; i++) {
                pinakas[i][j] = text[m];
                m++;
            }
            pinakas[i][j] = '\0';  /* analoga me to oipoloipo poy exw se kapoia kena ths teleytaias grammhs vazw to keno*/
        } else {
            for (i = 0; i < k; i++) {
                pinakas[i][j] = text[m];
                m++;
            }
        }
    }
    m = 0;
    for (i = 0; i < k; i++) {   /* diavazw apo tis grammes to pinaka m ekana */
        for (j = 0; j < x; j++) {
            if (pinakas[i][j] != '\0') {
                text2[m] = pinakas[i][j];
                m++;
            }
        }
    }
    for (i = 0; i < k; i++) {
        free(pinakas[i]);
    }
    free(pinakas);
    return text2; /* to epistrefw */
}


char* rail_fence_encr(char* text, unsigned int x) {
    int i, j, m, f;
    char* text2 = (char*)malloc(strlen(text) * sizeof(char));
    char** pinakas = (char**)malloc(x * sizeof(char*));
    if (pinakas == NULL || text2 == NULL) {
        printf("Apotixia desmefsis mnimis\n");
        exit(0);
    }
    for (i = 0; i < x; i++) {
        pinakas[i] = (char*)malloc(strlen(text) * sizeof(char));
        if (pinakas[i] == NULL) {
            printf("ΑApotixia desmefsis mnimis\n");
            exit(0);
        }
    }
    m = 0;
    f = 0;
    for (i = 0; i < x; i++) {
        for (j = 0; j < strlen(text); j++) {  /* arxikopoiw ton pinaka me ton termatiko xaraktira*/
            pinakas[i][j] = '\0';
        }
    }
    for (j = 0; j < strlen(text); j++) {  /* me toys diktes m & f ptoxoraw gia na vrw to zik zak*/
        if (m < x && f == 0) {
            pinakas[m][j] = text[j]; /* bazw to keimeno se aftes tis 8esis*/
            if (m == x - 1) {
                f = 1;
                m--;
            } else {
                m++;
            }
        } else if (f == 1) {
            pinakas[m][j] = text[j];  /* bazw to keimeno se aftes tis 8esis*/
            if (m == 0) {
                f = 0;
                m++;
            } else {
                m--;
            }
        }
    }
    m = 0;
    for (i = 0; i < x; i++) {       /* diavazw tis grammes */
        for (j = 0; j < strlen(text); j++) {
            if (pinakas[i][j] != '\0') {
                text2[m] = pinakas[i][j];
                m++;
            }
        }
    }
    for (i = 0; i < x; i++) {
        free(pinakas[i]);
    }
    free(pinakas);
    return text2;
}

char* rail_fence_decr(char* text, unsigned int x) {
    int i, j, m, f;
    char* text2 = (char*)malloc(strlen(text) * sizeof(char));
    char** pinakas = (char**)malloc(x * sizeof(char*));
    if (pinakas == NULL || text2 == NULL) {
        printf("Apotixia desmefsis mnimisς\n");
        exit(0);
    }
    for (i = 0; i < x; i++) {
        pinakas[i] = (char*)malloc(strlen(text) * sizeof(char));
        if (pinakas[i] == NULL) {
            printf("Apotixia desmefsis mnimis\n");
            exit(0);
        }
    }
    m = 0; f = 0;
    for (i = 0; i < x; i++) {
        for (j = 0; j < strlen(text); j++) {
            pinakas[i][j] = '\0';           /* arxikopoiw me ton keno xaraltira */
        }
    }
    for (j = 0; j < strlen(text); j++) {  /* me toys diktes m & f vriskw to zik zak*/
        if (m < x && f == 0) {
            pinakas[m][j] = '*';   /* stis thesis saftes vazw to * gia na kserw poies einai */
            if (m == x - 1) {
                f = 1;
                m--;
            } else {
                m++;
            }
        } else if (f == 1) {
            pinakas[m][j] = '*';   /* stis thesis saftes vazw to * gia na kserw poies einai */
            if (m == 0) {
                f = 0;
                m++;
            } else {
                m--;
            }
        }
    }
    m = 0;
    for (i = 0; i < x; i++) {
        for (j = 0; j < strlen(text); j++) {
            if (pinakas[i][j] == '*') {   /* opoy exei asteraki vazw to text*/
                pinakas[i][j] = text[m];
                m++;
            }
        }
    }
    m = 0; f = 0; i = 0;
    for (j = 0; j < strlen(text); j++) {  /* proxoraw pali me vasi to zik zak gia na parw to text moy */
        if (m < x && f == 0) {
            text2[i] = pinakas[m][j];
            i++;
            if (m == x - 1) {
                f = 1;
                m--;
            } else {
                m++;
            }
        } else if (f == 1) {
            text2[i] = pinakas[m][j];
            i++;
            if (m == 0) {
                f = 0;
                m++;
            } else {
                m--;
            }
        }
    }
    for (i = 0; i < x; i++) {
        free(pinakas[i]);
    }
    free(pinakas);
    return text2;
}

void substitution_decr(void) {
    FILE* file;
    FILE* file2;
    char A[52];   
    int B[52];
    char c, g1, g2;
    int metritis = 0, f, i, j, f2;
    char* p;
    char* s;
    char* s2;
    j = 0;
    for (i = 0; i < 52; i++) {
        B[i] = 0;
        if (i < 26)
            A[i] = 'A' + i;
        else {
            A[i] = 'a' + j;
            j++;
        }
    }
    file = fopen("ask3.txt", "r");
    if (file == NULL) {
        printf("Adinamia anoigmatos arxeioy.\n");
        return;
    }
    while (fscanf(file, "%c", &c) != EOF) {
        for (i = 0; i < 52; i++) {
            if (A[i] == c) {
                B[i]++;     /* metraw ti suxnothta kaue xarakthra */
            }
        }
        metritis++;
        if (c != ' ')
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
    for (i = 0; i < 52; i++) {
        printf("%c : %d\n", A[i], B[i]);  /* typonw thn syxnothta */
    }
    fclose(file);
    f = metritis;
    p = (char*)malloc(metritis * sizeof(char));
    s = (char*)malloc(metritis * sizeof(char));
    s2 = (char*)malloc(metritis * sizeof(char));
    for (i = 0; i < metritis; i++) {
        p[i] = '*';  /* arxikopoiw ton minaka me * */
    }
    file = fopen("ask3.txt", "r");
    if (file == NULL) {
        printf("Adinamia anoigmatos arxeioy.\n");
        free(p);
        return;
    }
    i = 0;
    while (fscanf(file, "%c", &c) != EOF) {
        if (c == ' ')
            p[i] = ' ';   /* opou exei keno vazxw keno ston pinaka */
        i++;
    }
    fclose(file);
    while (f > 0) {
        printf("\nDwse ena gramma.\n");
        scanf(" %c", &g1);
        printf("Dwse se poio gramma adistoixei.\n");
        scanf(" %c", &g2);
        file = fopen("ask3.txt", "r");
        if (file == NULL) {
            printf("Adinamia anoigmatos arxeiou.\n");
            return;
        }
        i = 0;
        while (fscanf(file, "%c", &c) != EOF) {
            if (c == g1) {   /* opoy vriskei to gramma to adikathista */
                p[i] = g2;
                f--;
            }
            i++;
        }
        fclose(file);
        f2 = 0;
        for (i = 0; i < metritis; i++) {
            printf("%c", p[i]);
            if (p[i] == '*')  /* elegxos an to arxeio apokriptografithike */
                f2 = 1;
        }
        printf("\nEnter partially decrypted word: ");
        scanf(" %s", s);
        file2 = fopen("words.txt", "r");
        if (file2 == NULL) {
            printf("Adinamia anoigmatos arxeiou.\n");
            return;
        }
        printf("\n");
        while (fscanf(file2, " %s", s2) != EOF) {  /* skanarei to arxeio worn.txt kai emfanizei tis pi8anes leksis*/
            if (strlen(s) == strlen(s2)) {
                f2 = 0;
                for (i = 0; i < strlen(s); i++) {
                    if (s[i] != '*' && s[i] != s2[i]) {
                        f2 = 1;
                    }
                }
                if (f2 == 0)
                    printf("%s\n", s2);
            }
        }
        if (f2 == 0)
            break;
    }
    free(p);
}
