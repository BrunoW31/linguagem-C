#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <errno.h>
#define BUF 100

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    FILE *file = fopen("arquivo.txt", "w");
    if(file == NULL){
        perror("erro ao criar ou abrir arquivo!\n");
        return (1);
    }

    int rec = 0;
    char nome0[BUF];
    char nome1[BUF];
    char nome2[BUF];
    char nome3[BUF];
    char nome4[BUF];

    printf("Digite seu nome: ");
    fgets(nome0, sizeof(nome0), stdin);
    fflush(stdin);
    printf("Digite seu nome: ");
    fgets(nome1, sizeof(nome1), stdin);
    fflush(stdin);
    printf("Digite seu nome: ");
    fgets(nome2, sizeof(nome2), stdin);
    fflush(stdin);
    printf("Digite seu nome: ");
    fgets(nome3, sizeof(nome3), stdin);
    fflush(stdin);
    printf("Digite seu nome: ");
    fgets(nome4, sizeof(nome4), stdin);
    fflush(stdin);

    fprintf(file, " nome1: %s nome2: %s nome3: %s nome4: %s nome5: %s\n", nome0, nome1, nome2, nome3, nome4);
    fclose(file);

    system("clear");

    printf("Deseja le os arquivos? 1- sim, 2 - não. \n");
    scanf(" %d", &rec);

    system("clear");

    if(rec == 1){
        FILE *arqv = fopen("arquivo.txt", "r");
        char ler[BUF];
        if(arqv == NULL){
            perror("Erro ao ler aqruivo!\n");
            return (1);
        }
        while(fgets(ler, sizeof(ler), arqv)){
            printf("%s", ler);
        }
        fclose(arqv);

    } else if(rec == 2) {
        printf("saindo...\n");
        return (1);
    } else {
        printf("Erro!!!\n");
        return (1);
    }

    return 0;
}
