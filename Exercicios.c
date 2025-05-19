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

#define TAMANHO_MAX 100

typedef struct {
    int elementos[TAMANHO_MAX];
    int frente;
    int tras;
    int tamanho;
} FilaCircular;

void inicializar(FilaCircular *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

bool esta_vazia(FilaCircular *f) {
    return f->tamanho == 0;
}

bool esta_cheia(FilaCircular *f) {
    return f->tamanho == TAMANHO_MAX;
}

void enfileirar(FilaCircular *f, int valor) {
    if (esta_cheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->tras = (f->tras + 1) % TAMANHO_MAX;
    f->elementos[f->tras] = valor;
    f->tamanho++;
}

int desenfileirar(FilaCircular *f) {
    if (esta_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int valor = f->elementos[f->frente];
    f->frente = (f->frente + 1) % TAMANHO_MAX;
    f->tamanho--;
    return valor;
}

int frente(FilaCircular *f) {
    if (esta_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    return f->elementos[f->frente];
}

int main() {
    FilaCircular fila;
    inicializar(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    printf("Frente: %d\n", frente(&fila));
    printf("Desenfileirar: %d\n", desenfileirar(&fila));
    printf("Desenfileirar: %d\n", desenfileirar(&fila));
    printf("Frente: %d\n", frente(&fila));

    enfileirar(&fila, 40);
    enfileirar(&fila, 50);

    printf("Desenfileirar: %d\n", desenfileirar(&fila));
    printf("Desenfileirar: %d\n", desenfileirar(&fila));
    printf("Desenfileirar: %d\n", desenfileirar(&fila));

    return 0;
}

//Exercicio 16

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

Fila* criar_fila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

bool esta_vazia(Fila *f) {
    return f->inicio == NULL;
}

void enfileirar(Fila *f, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    if (esta_vazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileirar(Fila *f) {
    if (esta_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }

    No *temp = f->inicio;
    int valor = temp->dado;

    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
    return valor;
}

int frente(Fila *f) {
    if (esta_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    return f->inicio->dado;
}

void liberar_fila(Fila *f) {
    while (!esta_vazia(f)) {
        desenfileirar(f);
    }
    free(f);
}

int main() {
    Fila *f = criar_fila();

    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 30);

    printf("Frente: %d\n", frente(f));
    printf("Desenfileirar: %d\n", desenfileirar(f));
    printf("Desenfileirar: %d\n", desenfileirar(f));

    enfileirar(f, 40);
    enfileirar(f, 50);

    printf("Frente: %d\n", frente(f));
    printf("Desenfileirar: %d\n", desenfileirar(f));
    printf("Desenfileirar: %d\n", desenfileirar(f));
    printf("Desenfileirar: %d\n", desenfileirar(f));

    liberar_fila(f);
    return 0;
}

//Exercicio 17

typedef struct No {
    char *binario;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

Fila* criar_fila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileirar(Fila *f, const char *valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->binario = strdup(valor);
    novo->prox = NULL;
    
    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

char* desenfileirar(Fila *f) {
    if (f->inicio == NULL) return NULL;
    
    No *temp = f->inicio;
    char *valor = temp->binario;
    
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(temp);
    return valor;
}

void gerar_binarios(int N) {
    if (N <= 0) return;
    
    Fila *f = criar_fila();
    enfileirar(f, "1");
    
    for (int i = 0; i < N; i++) {
        char *atual = desenfileirar(f);
        printf("\"%s\"%s", atual, i < N-1 ? ", " : "");
        
        char *temp1 = (char*)malloc(strlen(atual) + 2);
        char *temp2 = (char*)malloc(strlen(atual) + 2);
        
        strcpy(temp1, atual);
        strcat(temp1, "0");
        enfileirar(f, temp1);
        
        strcpy(temp2, atual);
        strcat(temp2, "1");
        enfileirar(f, temp2);
        
        free(atual);
    }
    
    while (f->inicio != NULL) {
        char *temp = desenfileirar(f);
        free(temp);
    }
    free(f);
}

int main() {
    int N = 5;
    printf("Números binários para N=%d: [", N);
    gerar_binarios(N);
    printf("]\n");
    return 0;
}

//Exercicio 18

#define MAX_SIZE 100

typedef struct {
    int elementos[MAX_SIZE];
    int frente;
    int tras;
    int tamanho;
} Fila;

typedef struct {
    int elementos[MAX_SIZE];
    int topo;
} Pilha;

void inicializar_fila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila *f) {
    return f->tamanho == MAX_SIZE;
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha *p) {
    return p->topo == MAX_SIZE - 1;
}

void enfileirar(Fila *f, int valor) {
    if (!fila_cheia(f)) {
        f->tras = (f->tras + 1) % MAX_SIZE;
        f->elementos[f->tras] = valor;
        f->tamanho++;
    }
}

int desenfileirar(Fila *f) {
    if (!fila_vazia(f)) {
        int valor = f->elementos[f->frente];
        f->frente = (f->frente + 1) % MAX_SIZE;
        f->tamanho--;
        return valor;
    }
    return -1;
}

void empilhar(Pilha *p, int valor) {
    if (!pilha_cheia(p)) {
        p->elementos[++p->topo] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (!pilha_vazia(p)) {
        return p->elementos[p->topo--];
    }
    return -1;
}

void inverter_primeiros_k(Fila *f, int k) {
    if (k <= 0 || k > f->tamanho) return;
    
    Pilha p;
    inicializar_pilha(&p);
    
    for (int i = 0; i < k; i++) {
        empilhar(&p, desenfileirar(f));
    }
    
    while (!pilha_vazia(&p)) {
        enfileirar(f, desempilhar(&p));
    }
    
    for (int i = 0; i < f->tamanho - k; i++) {
        enfileirar(f, desenfileirar(f));
    }
}

void imprimir_fila(Fila *f) {
    int pos = f->frente;
    for (int i = 0; i < f->tamanho; i++) {
        printf("%d ", f->elementos[pos]);
        pos = (pos + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializar_fila(&f);
    
    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    enfileirar(&f, 40);
    enfileirar(&f, 50);
    
    printf("Fila original: ");
    imprimir_fila(&f);
    
    inverter_primeiros_k(&f, 3);
    
    printf("Fila após inverter os primeiros 3: ");
    imprimir_fila(&f);
    
    return 0;
}

//Exercicio 19

typedef struct No {
    int dado;
    struct No *prox;
} No;

int detectar_ciclo(No *head) {
    if (head == NULL || head->prox == NULL) {
        return 0;
    }

    No *slow = head;
    No *fast = head->prox;

    while (fast != NULL && fast->prox != NULL) {
        if (slow == fast) {
            return 1;
        }
        slow = slow->prox;
        fast = fast->prox->prox;
    }

    return 0;
}

No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

int main() {
    No *head = criar_no(1);
    head->prox = criar_no(2);
    head->prox->prox = criar_no(3);
    head->prox->prox->prox = criar_no(4);
    
    printf("Lista sem ciclo: %d\n", detectar_ciclo(head));
    
    head->prox->prox->prox->prox = head->prox;
    printf("Lista com ciclo: %d\n", detectar_ciclo(head));
    
    return 0;
}

//Exercicio 20

typedef struct No {
    int valor;
    struct No *prox;
} No;

No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

No* unir_listas_ordenadas(No *lista1, No *lista2) {
    No dummy; 
    No *atual = &dummy;
    dummy.prox = NULL;

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->valor <= lista2->valor) {
            atual->prox = lista1;
            lista1 = lista1->prox;
        } else {
            atual->prox = lista2;
            lista2 = lista2->prox;
        }
        atual = atual->prox;
    }

    if (lista1 != NULL) {
        atual->prox = lista1;
    } else {
        atual->prox = lista2;
    }

    return dummy.prox;
}

void imprimir_lista(No *lista) {
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

int main() {

    No *lista1 = criar_no(1);
    lista1->prox = criar_no(3);
    lista1->prox->prox = criar_no(5);

    No *lista2 = criar_no(2);
    lista2->prox = criar_no(4);
    lista2->prox->prox = criar_no(6);

    printf("Lista 1: ");
    imprimir_lista(lista1);
    printf("Lista 2: ");
    imprimir_lista(lista2);

    No *lista_unida = unir_listas_ordenadas(lista1, lista2);
    printf("Lista unida: ");
    imprimir_lista(lista_unida);

    return 0;
}

//Exercicio 21

typedef struct No {
    int valor;
    struct No *prox;
} No;

No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

No* remover_todas_ocorrencias(No *head, int valor) {
    No *atual = head;
    No *anterior = NULL;
    No *temp;
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                
                temp = atual;
                head = atual->prox;
                atual = head;
                free(temp);
            } else {
                
                temp = atual;
                anterior->prox = atual->prox;
                atual = atual->prox;
                free(temp);
            }
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    
    return head;
}

void imprimir_lista(No *lista) {
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

int main() {
    No *lista = criar_no(1);
    lista->prox = criar_no(2);
    lista->prox->prox = criar_no(3);
    lista->prox->prox->prox = criar_no(2);
    lista->prox->prox->prox->prox = criar_no(4);
    lista->prox->prox->prox->prox->prox = criar_no(2);
    lista->prox->prox->prox->prox->prox->prox = criar_no(5);

    printf("Lista original: ");
    imprimir_lista(lista);

    lista = remover_todas_ocorrencias(lista, 2);

    printf("Lista após remoção: ");
    imprimir_lista(lista);

    while (lista != NULL) {
        No *temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}

//Exercicio 22

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No *criar_no(int dado) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

No *encontrar_intersecao(No *lista1, No *lista2) {
    if (lista1 == NULL || lista2 == NULL) return NULL;
    
    No *a = lista1;
    No *b = lista2;
    
    while (a != b) {
        a = a == NULL ? lista2 : a->prox;
        b = b == NULL ? lista1 : b->prox;
    }
    
    return a;
}

void imprimir_lista(No *lista) {
    while (lista != NULL) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    printf("\n");
}

int main() {
  
    No *lista1 = criar_no(1);
    lista1->prox = criar_no(2);
    lista1->prox->prox = criar_no(3);
    lista1->prox->prox->prox = criar_no(4);

  
    No *lista2 = criar_no(5);
    lista2->prox = criar_no(6);
    lista2->prox->prox = lista1->prox->prox; 

    printf("Lista 1: ");
    imprimir_lista(lista1);
    printf("Lista 2: ");
    imprimir_lista(lista2);

    No *intersecao = encontrar_intersecao(lista1, lista2);

    if (intersecao != NULL) {
        printf("Interseção encontrada no nó com valor: %d\n", intersecao->dado);
    } else {
        printf("Não há interseção.\n");
    }

    
    No *temp;
    while (lista1 != intersecao) {
        temp = lista1;
        lista1 = lista1->prox;
        free(temp);
    }
    while (lista2 != NULL) {
        temp = lista2;
        lista2 = lista2->prox;
        if (temp == intersecao) break;
        free(temp);
    }

    return 0;
}

//Exercicio 23

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No *criar_no(int dado) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

No *rotacionar_lista(No *head, int k) {
    if (head == NULL || head->prox == NULL || k == 0) return head;

    No *atual = head;
    int tamanho = 1;
    while (atual->prox != NULL) {
        atual = atual->prox;
        tamanho++;
    }

    k = k % tamanho;
    if (k == 0) return head;

    atual->prox = head;
    atual = head;
    for (int i = 0; i < tamanho - k - 1; i++) {
        atual = atual->prox;
    }

    No *nova_head = atual->prox;
    atual->prox = NULL;
    return nova_head;
}

void imprimir_lista(No *lista) {
    while (lista != NULL) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    printf("\n");
}

void liberar_lista(No *lista) {
    No *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

int main() {
    No *lista = criar_no(1);
    lista->prox = criar_no(2);
    lista->prox->prox = criar_no(3);
    lista->prox->prox->prox = criar_no(4);
    lista->prox->prox->prox->prox = criar_no(5);

    printf("Lista original: ");
    imprimir_lista(lista);

    int k = 2;
    lista = rotacionar_lista(lista, k);

    printf("Lista rotacionada em %d posições: ", k);
    imprimir_lista(lista);

    liberar_lista(lista);

    return 0;
}

//Exercicio 24

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No {
    int valor;
    int min_ate_agora;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

Pilha *criar_pilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha *p, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->min_ate_agora = (p->topo == NULL) ? valor : (valor < p->topo->min_ate_agora ? valor : p->topo->min_ate_agora);
    novo->prox = p->topo;
    p->topo = novo;
}

void pop(Pilha *p) {
    if (p->topo == NULL) return;
    No *temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
}

int top(Pilha *p) {
    if (p->topo == NULL) return INT_MIN;
    return p->topo->valor;
}

int obter_minimo(Pilha *p) {
    if (p->topo == NULL) return INT_MIN;
    return p->topo->min_ate_agora;
}

void liberar_pilha(Pilha *p) {
    while (p->topo != NULL) {
        pop(p);
    }
    free(p);
}

int main() {
    Pilha *p = criar_pilha();
    
    push(p, 5);
    push(p, 3);
    push(p, 8);
    push(p, 2);
    push(p, 4);

    printf("Topo: %d\n", top(p));
    printf("Mínimo: %d\n", obter_minimo(p));
    
    pop(p);
    printf("Topo após pop: %d\n", top(p));
    printf("Mínimo após pop: %d\n", obter_minimo(p));
    
    liberar_pilha(p);
    
    return 0;
}

//Exercicio 25

