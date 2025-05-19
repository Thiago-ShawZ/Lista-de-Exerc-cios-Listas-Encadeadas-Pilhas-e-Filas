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

void remover_valor(No **lista, int valor) {
    if (*lista == NULL) return;

    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return;
    }

    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
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

    remover_valor(&lista, 10);  // Remove o valor 10 da lista

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

//Exercicio 6

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

void remover_valor(No **lista, int valor) {
    if (*lista == NULL) return;

    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return;

    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
}

void inverter_lista(No **lista) {
    No *anterior = NULL;
    No *atual = *lista;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *lista = anterior;
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
    inserir_posicao(&lista, 15, 2);

    printf("Lista original:\n");
    imprimir_lista(lista);

    inverter_lista(&lista);

    printf("Lista invertida:\n");
    imprimir_lista(lista);

    return 0;
}

//Exercicio 7

typedef struct No {
    int dado;
    struct No *prox;
} No;

No* encontrar_meio(No *head) {
    if (head == NULL) {
        return NULL;
    }

    No *slow = head;
    No *fast = head;

    while (fast != NULL && fast->prox != NULL) {
        slow = slow->prox;
        fast = fast->prox->prox;
    }

    return slow;
}

No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

void imprimir_lista(No *head) {
    No *atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    No *head = criar_no(1);
    head->prox = criar_no(2);
    head->prox->prox = criar_no(3);
    head->prox->prox->prox = criar_no(4);
    head->prox->prox->prox->prox = criar_no(5);

    printf("Lista: ");
    imprimir_lista(head);

    No *meio = encontrar_meio(head);
    if (meio != NULL) {
        printf("Nó do meio: %d\n", meio->dado);
    }

    free(head->prox->prox->prox->prox);
    free(head->prox->prox->prox);
    free(head->prox->prox);
    free(head->prox);
    free(head);

    return 0;
}

//Exercicio 8

