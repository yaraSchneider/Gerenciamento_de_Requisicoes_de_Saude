#ifndef LISTA_H
#define LISTA_H

typedef struct Paciente {
    int id;
    char nome[50];
    struct Paciente* prev;
    struct Paciente* next;
} Paciente;

typedef struct {
    Paciente* head;
    Paciente* tail;
    int size;
} Lista;

// Funções do TAD
void inicializar(Lista* lista);

void inserir_emergencia(Lista* lista, int id, char nome[]);
void inserir_triagem(Lista* lista, int id, char nome[]);

void atender_paciente(Lista* lista);
void remover_paciente_id(Lista* lista, int id);

void imprimir_auditoria(Lista* lista);

#endif