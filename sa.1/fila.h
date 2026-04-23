#ifndef FILA_H
#define FILA_H

typedef struct {
    char nome[40];
    int codigo_inscricao;
    char codigo_procedimento[10];
} Paciente;

typedef struct no {
    Paciente dado;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

// Funcionalidades do TAD
Fila* criar_fila();
int inserir(Fila* f, Paciente p);
Paciente* remover(Fila* f);
int obter_tamanho(Fila* f);
void liberar_fila(Fila* f);

#endif