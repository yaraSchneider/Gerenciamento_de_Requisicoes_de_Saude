#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    Fila* filaAtendimento = criar_fila();

    // Simulação de chegada de paciente
    Paciente p1 = {"Joao Silva", 101, "CONS-01"};
    inserir(filaAtendimento, p1);
    
    Paciente p2 = {"Maria Oliveira", 102, "RAIO-X"};
    inserir(filaAtendimento, p2);

    // Monitoramento em tempo real
    printf("Pacientes aguardando: %d\n", obter_tamanho(filaAtendimento));

    if (obter_tamanho(filaAtendimento) > 0) {
        Paciente* atendido = remover(filaAtendimento);
        printf("Atendendo agora: %s\n", atendido->nome);
        free(atendido); // Evita vazamento de memória do retorno
    }

    printf("Pacientes restantes: %d\n", obter_tamanho(filaAtendimento));

    liberar_fila(filaAtendimento);
    return 0;
}