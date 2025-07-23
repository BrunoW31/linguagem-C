#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define URL "agenda.txt"

typedef struct { // estruct para agenda
    char nome[60];
    char telefone[30];
}Agenda;

void abreAgenda(Agenda *agenda){
    FILE *file; // define ponteiro para arquivo
    file = fopen( URL, "a"); // abre arquivo
    if( file == NULL){ // Testa se arquivo abriu corretamente
        perror("Erro ao abrir arquivo!\n");
        return;
    }

    fprintf(file, "Nome: %s, Telefone: %s\n", agenda->nome, agenda->telefone);
    fclose(file);
}

void RecebeDadoUsuario(Agenda *agenda){
    // recebe dados do usuario
    printf("Digite o nome do Contato: ");
    fgets(agenda->nome, sizeof(agenda->nome), stdin);
    agenda->nome[strcspn(agenda->nome, "\n")] = '\0';
    printf("Digite o telefone: ");
    fgets(agenda->telefone, sizeof(agenda->telefone), stdin);
    agenda->telefone[strcspn(agenda->telefone, "\n")] = '\0';

}    

int main(){
    Agenda *agenda = malloc(sizeof(Agenda));
            if(agenda == NULL){
            perror("Erro ao alocar memoria\n");
            return 1;
        }
    int op = 0;

    while ( op == 0 ){
        RecebeDadoUsuario(agenda);
        abreAgenda(agenda);

        printf("Cadastro realizado com sucesso!\n");
        system("clear");
        //printf("Nome contato: %s\n", agenda->nome);
        //printf("Telefone: %s\n", agenda->telefone);
        printf("0=SIM  1=NAO\n\nDeseja cadastrar mais um? \n");
        scanf(" %i", &op);
                while(getchar() != '\n' && !feof(stdin)); // limpa o buffer do teclado apos ler um inteiro
    }

    free(agenda);
    return 0;
}
