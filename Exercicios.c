#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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
    inserir_posicao(&lista, 15, 2); 

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
    inserir_posicao(&lista, 15, 2); 

    imprimir_lista(lista);

    remover_valor(&lista, 10); 

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

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Pilha {
    int *elementos;
    int topo;
    int capacidade;
} Pilha;

No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

Pilha* criar_pilha(int capacidade) {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->elementos = (int*)malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

void empilhar(Pilha *p, int valor) {
    if (p->topo == p->capacidade - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    p->elementos[++p->topo] = valor;
}

int desempilhar(Pilha *p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->elementos[p->topo--];
}

void imprimir_reverso(No *head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    int tamanho = 0;
    No *atual = head;
    while (atual != NULL) {
        tamanho++;
        atual = atual->prox;
    }

    Pilha *p = criar_pilha(tamanho);
    atual = head;
    while (atual != NULL) {
        empilhar(p, atual->dado);
        atual = atual->prox;
    }

    printf("Lista em reverso: ");
    while (p->topo != -1) {
        printf("%d ", desempilhar(p));
    }
    printf("\n");

    free(p->elementos);
    free(p);
}

int main() {
    No *head = criar_no(1);
    head->prox = criar_no(2);
    head->prox->prox = criar_no(3);
    head->prox->prox->prox = criar_no(4);

    printf("Lista original: ");
    No *atual = head;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");

    imprimir_reverso(head);

    free(head->prox->prox->prox);
    free(head->prox->prox);
    free(head->prox);
    free(head);

    return 0;
}

//Exercicio 9

#define TAMANHO_MAX 100

int pilha[TAMANHO_MAX];
int topo = -1;

bool esta_vazia() {
    return topo == -1;
}

bool esta_cheia() {
    return topo == TAMANHO_MAX - 1;
}

void push(int valor) {
    if (esta_cheia()) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    pilha[++topo] = valor;
}

int pop() {
    if (esta_vazia()) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return pilha[topo--];
}

int topo_pilha() {
    if (esta_vazia()) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return pilha[topo];
}

int main() {
    
    push(10);
    push(20);
    push(30);

    printf("Topo: %d\n", topo_pilha()); 

    printf("Elementos removidos: ");
    while (!esta_vazia()) {
        printf("%d ", pop());
    }
    printf("\n"); 

    
    printf("Tentativa de pop em pilha vazia: %d\n", pop());

    return 0;
}

//Exercicio 10

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

Pilha* criar_pilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

bool esta_vazia(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha *p) {
    if (esta_vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    No *temp = p->topo;
    int valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int topo(Pilha *p) {
    if (esta_vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return p->topo->dado;
}

void liberar_pilha(Pilha *p) {
    while (!esta_vazia(p)) {
        pop(p);
    }
    free(p);
}

int main() {
    Pilha *p = criar_pilha();

    push(p, 10);
    push(p, 20);
    push(p, 30);

    printf("Topo: %d\n", topo(p));  

    printf("Elementos removidos: ");
    while (!esta_vazia(p)) {
        printf("%d ", pop(p));
    }
    printf("\n");  

    printf("Tentativa de pop em pilha vazia: %d\n", pop(p));

    liberar_pilha(p);
    return 0;
}

//Exercicio 11

typedef struct No {
    char dado;
    struct No *prox;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

Pilha* criar_pilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

bool esta_vazia(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, char valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

char pop(Pilha *p) {
    if (esta_vazia(p)) {
        return '\0';
    }
    No *temp = p->topo;
    char valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int verificar_balanceamento(const char *expressao) {
    Pilha *p = criar_pilha();
    int i = 0;
    while (expressao[i] != '\0') {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            push(p, expressao[i]);
        } else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            char topo = pop(p);
            if ((expressao[i] == ')' && topo != '(') ||
                (expressao[i] == ']' && topo != '[') ||
                (expressao[i] == '}' && topo != '{')) {
                while (!esta_vazia(p)) {
                    pop(p);
                }
                free(p);
                return 0;
            }
        }
        i++;
    }
    int balanceado = esta_vazia(p);
    liberar_pilha(p);
    return balanceado;
}

void liberar_pilha(Pilha *p) {
    while (!esta_vazia(p)) {
        pop(p);
    }
    free(p);
}

int main() {
    printf("%d\n", verificar_balanceamento("({[]})"));
    printf("%d\n", verificar_balanceamento("([)]"));
    return 0;
}

//Exercicio 12

#define MAX_SIZE 100

typedef struct {
    char itens[MAX_SIZE];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

int esta_cheia(Pilha *p) {
    return p->topo == MAX_SIZE - 1;
}

void push(Pilha *p, char elemento) {
    if (!esta_cheia(p)) {
        p->itens[++p->topo] = elemento;
    }
}

char pop(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->itens[p->topo--];
    }
    return '\0';
}

void inverter_string(char *str) {
    Pilha p;
    inicializar(&p);
    
    for (int i = 0; str[i] != '\0'; i++) {
        push(&p, str[i]);
    }
    
    int i = 0;
    while (!esta_vazia(&p)) {
        str[i++] = pop(&p);
    }
}

int main() {
    char texto[] = "hello";
    printf("Original: %s\n", texto);
    
    inverter_string(texto);
    printf("Invertida: %s\n", texto);
    
    return 0;
}

//Exercicio 13

#define MAX_SIZE 100

typedef struct {
    char itens[MAX_SIZE];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, char elemento) {
    if (p->topo < MAX_SIZE - 1) {
        p->itens[++p->topo] = elemento;
    }
}

char pop(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->itens[p->topo--];
    }
    return '\0';
}

int eh_palindromo(const char *str) {
    Pilha p;
    inicializar(&p);
    int len = strlen(str);
    int meio = len / 2;
    
    for (int i = 0; i < meio; i++) {
        push(&p, tolower(str[i]));
    }
    
    int inicio = meio + (len % 2);
    for (int i = inicio; i < len; i++) {
        if (tolower(str[i]) != pop(&p)) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char texto1[] = "radar";
    char texto2[] = "Anotaram a data da maratona";
    char texto3[] = "hello";
    
    printf("%s: %s\n", texto1, eh_palindromo(texto1) ? "Sim" : "Não");
    printf("%s: %s\n", texto2, eh_palindromo(texto2) ? "Sim" : "Não");
    printf("%s: %s\n", texto3, eh_palindromo(texto3) ? "Sim" : "Não");
    
    return 0;
}

//Exercicio 14

#define MAX_SIZE 100

typedef struct {
    int itens[MAX_SIZE];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

int esta_cheia(Pilha *p) {
    return p->topo == MAX_SIZE - 1;
}

void push(Pilha *p, int elemento) {
    if (!esta_cheia(p)) {
        p->itens[++p->topo] = elemento;
    }
}

int pop(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->itens[p->topo--];
    }
    return -1;
}

int topo(Pilha *p) {
    if (!esta_vazia(p)) {
        return p->itens[p->topo];
    }
    return -1;
}

void ordenar_pilha(Pilha *p) {
    Pilha aux;
    inicializar(&aux);
    
    while (!esta_vazia(p)) {
        int temp = pop(p);
        
        while (!esta_vazia(&aux) && topo(&aux) > temp) {
            push(p, pop(&aux));
        }
        
        push(&aux, temp);
    }
    
    while (!esta_vazia(&aux)) {
        push(p, pop(&aux));
    }
}

void imprimir_pilha(Pilha *p) {
    Pilha temp;
    inicializar(&temp);
    
    while (!esta_vazia(p)) {
        int val = pop(p);
        printf("%d ", val);
        push(&temp, val);
    }
    
    while (!esta_vazia(&temp)) {
        push(p, pop(&temp));
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializar(&p);
    
    push(&p, 34);
    push(&p, 3);
    push(&p, 31);
    push(&p, 98);
    push(&p, 92);
    push(&p, 23);
    
    printf("Pilha original: ");
    imprimir_pilha(&p);
    
    ordenar_pilha(&p);
    
    printf("Pilha ordenada: ");
    imprimir_pilha(&p);
    
    return 0;
}

//Exercicio 15

