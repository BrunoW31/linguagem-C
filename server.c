// servidor.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         // Para close()
#include <arpa/inet.h>      // Para inet_addr(), htons(), etc.
#include <sys/socket.h>     // Para funções de socket()

#define PORTA 12345         // Porta que o servidor irá escutar
#define TAM_BUFFER 1024     // Tamanho do buffer de leitura

int main() {
    int servidor_fd, novo_socket;
    struct sockaddr_in endereco;  // Estrutura para armazenar IP e porta
    int opt = 1;
    int addrlen = sizeof(endereco);
    char buffer[TAM_BUFFER] = {0};  // Buffer para armazenar a mensagem recebida

    // 1. Criando o socket do tipo TCP/IPv4
    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd == -1) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    // 2. Permite reutilizar a porta caso o servidor seja reiniciado rapidamente
    setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 3. Configurando a estrutura com o endereço do servidor
    endereco.sin_family = AF_INET;                // Tipo de endereço: IPv4
    endereco.sin_addr.s_addr = INADDR_ANY;        // Aceita conexões de qualquer IP local
    endereco.sin_port = htons(PORTA);             // Converte a porta para o formato de rede

    // 4. Associa o socket criado com a porta e IP configurados
    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0) {
        perror("Erro no bind");
        exit(EXIT_FAILURE);
    }

    // 5. Coloca o socket em modo de escuta, aguardando conexões
    if (listen(servidor_fd, 3) < 0) {
        perror("Erro no listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor aguardando conexões na porta %d...\n", PORTA);

    // 6. Aguarda e aceita uma conexão de um cliente
    novo_socket = accept(servidor_fd, (struct sockaddr *)&endereco, (socklen_t*)&addrlen);
    if (novo_socket < 0) {
        perror("Erro no accept");
        exit(EXIT_FAILURE);
    }

    // 7. Recebe dados enviados pelo cliente
    read(novo_socket, buffer, TAM_BUFFER);
    printf("Mensagem recebida do cliente: %s\n", buffer);

    // 8. Envia uma resposta de volta ao cliente
    char *resposta = "Olá, cliente! Mensagem recebida com sucesso.\n";
    send(novo_socket, resposta, strlen(resposta), 0);

    // 9. Fecha os sockets (conexão e escuta)
    close(novo_socket);
    close(servidor_fd);

    return 0;
}

