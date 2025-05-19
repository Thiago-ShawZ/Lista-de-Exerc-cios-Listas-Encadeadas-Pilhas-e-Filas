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

