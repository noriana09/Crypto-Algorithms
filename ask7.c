#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int value, key;
    /* elegxos an einai swsta ta orismata */
    if (strcmp(argv[1], "add") != 0 && strcmp(argv[1], "read") != 0 && strcmp(argv[1], "range-read") != 0) {
        printf("Lathos orisma!\n");
        return 1;
    } 
    /* periptosi gia tin add */
    if (strcmp(argv[1], "add") == 0) {
        file = fopen(argv[2], "a");
        if (file == NULL) {
            printf("Adinamia anoigmatos arxeioy.\n");
            return -1;
        }
        fprintf(file, "%s,%s\n", argv[3], argv[4]); /* grafw sto arxeio */
        fclose(file);
    } else if (strcmp(argv[1], "read") == 0) {   /* periptosi gia to read */
        file = fopen(argv[2], "r");
        if (file == NULL) {
            printf("Adinamia anoigmatos arxeioy.\n");
            return -1;
        }
        while (fscanf(file, "%d,%d", &value, &key) == 2) {
            if (value == atoi(argv[3])) {
                printf("Key: %d has value: %d\n", value, key); /* opoy to vriskw to tiponw */
            }
        }
        fclose(file);
    }else if (strcmp(argv[1], "range-read") == 0){  /* periptosi gia to range-read */
        if(atoi(argv[3])>=atoi(argv[4])){
            printf("To evros den einai egkiro");
            return 1;
        }
        file = fopen(argv[2], "r");
        if (file == NULL) {
            printf("Adinamia anoigmatos arxeioy.\n");
            return -1;
        }
        while (fscanf(file, "%d,%d", &value, &key) == 2) {
            if (value >= atoi(argv[3]) && value <= atoi(argv[4])) {  /* typonw osa anoikoyn se afto to evros */
                printf("Key: %d has value: %d\n", value, key);
            }
        }
        fclose(file);
    }
    return 0;
}
