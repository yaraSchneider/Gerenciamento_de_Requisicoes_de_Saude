#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila* criar_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

int inserir(Fila* f, Paciente p) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0; // Falha na alocação
    
    novo->dado = p;
    novo->proximo = NULL;

    if (f->fim == NULL) { // Fila vazia
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    
    f->fim = novo;
    f->tamanho++;
    return 1;
}

Paciente* remover(Fila* f) {
    if (f->inicio == NULL) return NULL;

    No* temp = f->inicio;
    Paciente* p = (Paciente*) malloc(sizeof(Paciente));
    *p = temp->dado;

    f->inicio = f->inicio->proximo;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
    f->tamanho--;
    return p;
}

int obter_tamanho(Fila* f) {
    return (f != NULL) ? f->tamanho : 0;
}

void liberar_fila(Fila* f) {
    if (f != NULL) {
        No* atual = f->inicio;
        while (atual != NULL) {
            No* prox = atual->proximo;
            free(atual);
            atual = prox;
        }
        free(f);
    }
}