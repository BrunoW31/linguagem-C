#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>

typedef struct{
	char nome[30];
	char telefone[20];
}Agenda;


int main(){
	setlocale(LC_ALL, "portuguese");
	
	Agenda *agenda = malloc(sizeof(Agenda));
	
	char ler[100];
	int i=0;

	FILE *file = fopen("agenda.txt", "a+");
	
	if( file == NULL ){
		perror("Erro ao abrir arquivo");
	}

	printf("\nDigite o nome: ");
	fgets(agenda->nome, sizeof(agenda->nome), stdin);
	fflush(stdin);
	printf("\nDigite o telefone: ");
	fgets(agenda->telefone, sizeof(agenda->telefone), stdin);
	fflush(stdin);
	fprintf(file, "\nNome: %sTelefone: %s\n", agenda->nome, agenda->telefone);
	printf("\nContato agendado com sucesso\n");

	while( fgets(ler, sizeof(ler), file )){
		printf("%s", ler);
	}

	fclose(file);
	
	return 0;
}
