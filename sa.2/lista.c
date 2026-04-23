#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inicializar(Lista* lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

void inserir_emergencia(Lista* lista, int id, char nome[]) {
    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));

    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prev = NULL;
    novo->next = lista->head;

    if (lista->head != NULL)
        lista->head->prev = novo;
    else
        lista->tail = novo;

    lista->head = novo;
    lista->size++;
}

void inserir_triagem(Lista* lista, int id, char nome[]) {
    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));

    novo->id = id;
    strcpy(novo->nome, nome);
    novo->next = NULL;
    novo->prev = lista->tail;

    if (lista->tail != NULL)
        lista->tail->next = novo;
    else
        lista->head = novo;

    lista->tail = novo;
    lista->size++;
}

void atender_paciente(Lista* lista) {
    if (lista->head == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    Paciente* temp = lista->head;

    printf("Atendendo: %s (ID %d)\n", temp->nome, temp->id);

    lista->head = temp->next;

    if (lista->head != NULL)
        lista->head->prev = NULL;
    else
        lista->tail = NULL;

    free(temp);
    lista->size--;
}

void remover_paciente_id(Lista* lista, int id) {
    Paciente* atual = lista->head;

    while (atual != NULL) {
        if (atual->id == id) {

            if (atual == lista->head) {
                lista->head = atual->next;
                if (lista->head != NULL)
                    lista->head->prev = NULL;
                else
                    lista->tail = NULL;
            }
            else if (atual == lista->tail) {
                lista->tail = atual->prev;
                lista->tail->next = NULL;
            }
            else {
                atual->prev->next = atual->next;
                atual->next->prev = atual->prev;
            }

            printf("Removido: %s (ID %d)\n", atual->nome, atual->id);

            free(atual);
            lista->size--;
            return;
        }

        atual = atual->next;
    }

    printf("Paciente não encontrado!\n");
}

void imprimir_auditoria(Lista* lista) {
    Paciente* atual;

    printf("\n--- INICIO -> FIM ---\n");
    atual = lista->head;
    while (atual != NULL) {
        printf("[%d - %s] -> ", atual->id, atual->nome);
        atual = atual->next;
    }
    printf("NULL\n");

    printf("\n--- FIM -> INICIO ---\n");
    atual = lista->tail;
    while (atual != NULL) {
        printf("[%d - %s] -> ", atual->id, atual->nome);
        atual = atual->prev;
    }
    printf("NULL\n");
}