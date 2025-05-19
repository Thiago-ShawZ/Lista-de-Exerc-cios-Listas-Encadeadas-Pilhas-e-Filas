#include <stdio.h>
#include <stdlib.h>

//Exercicío 1
typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_inicio(No **lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(No **lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    novo->dado = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void imprimir_lista(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;

    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 20);

    imprimir_lista(lista);

    return 0;
}

//Exercicío 2

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_inicio(No **lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(No **lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

int contar_nos(No *lista) {
    int cont = 0;
    No *atual = lista;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

void imprimir_lista(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;

    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 20);

    imprimir_lista(lista);

    int total = contar_nos(lista);
    printf("Total de nós: %d\n", total);

    return 0;
}

//Exercicío 3

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_inicio(No **lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(No **lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

int contar_nos(No *lista) {
    int cont = 0;
    No *atual = lista;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

int buscar_elemento(No *lista, int valor) {
    No *atual = lista;
    while (atual != NULL) {
        if (atual->dado == valor) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

void imprimir_lista(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;

    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 20);

    imprimir_lista(lista);

    int total = contar_nos(lista);
    printf("Total de nós: %d\n", total);

    int valor = 10;
    if (buscar_elemento(lista, valor)) {
        printf("Elemento %d encontrado na lista.\n", valor);
    } else {
        printf("Elemento %d não encontrado na lista.\n", valor);
    }

    return 0;
}

//Exercicio 4

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_inicio(No **lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(No **lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

int contar_nos(No *lista) {
    int cont = 0;
    No *atual = lista;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

int buscar_elemento(No *lista, int valor) {
    No *atual = lista;
    while (atual != NULL) {
        if (atual->dado == valor) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

void inserir_posicao(No **lista, int valor, int posicao) {
    if (posicao < 0) return;

    if (posicao == 0) {
        inserir_inicio(lista, valor);
        return;
    }

    int i = 0;
    No *atual = *lista;
    while (atual != NULL && i < posicao - 1) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        inserir_fim(lista, valor);
        return;
    }

    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;

    novo->dado = valor;
    novo->prox = atual->prox;
    atual->prox = novo;
}

void imprimir_lista(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;

    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    inserir_fim(&lista, 20);
    inserir_posicao(&lista, 15, 2);  // Insere 15 na posição 2

    imprimir_lista(lista);

    int total = contar_nos(lista);
    printf("Total de nós: %d\n", total);

    int valor = 10;
    if (buscar_elemento(lista, valor)) {
        printf("Elemento %d encontrado na lista.\n", valor);
    } else {
        printf("Elemento %d não encontrado na lista.\n", valor);
    }

    return 0;
}

//Exercicio 5
