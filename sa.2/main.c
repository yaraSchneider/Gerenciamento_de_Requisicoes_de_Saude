#include <stdio.h>
#include "lista.h"

void teste_basico(Lista* lista) {
    printf("\n===== TESTE 1: INSERÇÕES =====\n");

    inserir_triagem(lista, 1, "Joao");
    inserir_triagem(lista, 2, "Maria");
    inserir_emergencia(lista, 3, "Carlos"); // deve ir pro topo

    imprimir_auditoria(lista);
}

void teste_remocoes(Lista* lista) {
    printf("\n===== TESTE 2: REMOÇÃO DO TOPO =====\n");
    atender_paciente(lista);
    imprimir_auditoria(lista);

    printf("\n===== TESTE 3: REMOÇÃO DO MEIO =====\n");
    inserir_triagem(lista, 4, "Ana");
    inserir_triagem(lista, 5, "Pedro");
    imprimir_auditoria(lista);

    remover_paciente_id(lista, 4); // remove do meio
    imprimir_auditoria(lista);

    printf("\n===== TESTE 4: REMOÇÃO DO FINAL =====\n");
    remover_paciente_id(lista, 5); // remove tail
    imprimir_auditoria(lista);
}

void teste_casos_extremos(Lista* lista) {
    printf("\n===== TESTE 5: LISTA VAZIA =====\n");

    atender_paciente(lista);
    atender_paciente(lista);
    atender_paciente(lista);

    imprimir_auditoria(lista);

    printf("\n===== TESTE 6: REMOVER INEXISTENTE =====\n");
    remover_paciente_id(lista, 999);

    printf("\n===== TESTE 7: INSERIR APÓS ESVAZIAR =====\n");
    inserir_emergencia(lista, 10, "Lucas");
    imprimir_auditoria(lista);
}

int main() {
    Lista lista;
    inicializar(&lista);

    teste_basico(&lista);
    teste_remocoes(&lista);
    teste_casos_extremos(&lista);

    return 0;
}