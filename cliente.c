// cliente.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         // Para close()
#include <arpa/inet.h>      // Para inet_addr(), htons()
#include <sys/socket.h>     // Para funções de socket()

#define PORTA 12345         // Porta do servidor
#define TAM_BUFFER 1024     // Tamanho do buffer de leitura

int main() {
    int sock = 0;
    struct sockaddr_in servidor;   // Estrutura com endereço do servidor
    char buffer[TAM_BUFFER] = {0}; // Buffer para armazenar resposta

    // 1. Cria um socket TCP/IPv4
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    // 2. Configura o endereço do servidor (localhost:127.0.0.1)
    servidor.sin_family = AF_INET;                        // Tipo IPv4
    servidor.sin_port = htons(PORTA);                     // Porta do servidor
    servidor.sin_addr.s_addr = inet_addr("127.0.0.1");    // IP do servidor (localhost)

    // 3. Conecta ao servidor
    if (connect(sock, (struct sockaddr *)&servidor, sizeof(servidor)) < 0) {
        perror("Erro na conexão com o servidor");
        exit(EXIT_FAILURE);
    }

    // 4. Envia uma mensagem ao servidor
    char *mensagem = "Olá, servidor!";
    send(sock, mensagem, strlen(mensagem), 0);

    // 5. Aguarda e lê a resposta do servidor
    read(sock, buffer, TAM_BUFFER);
    printf("Resposta do servidor: %s\n", buffer);

    // 6. Fecha o socket
    close(sock);

    return 0;
}

