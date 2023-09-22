#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Tarefas 250


typedef struct {
    char descricao[100];

} Tarefa;

// FILA
typedef struct {
    Tarefa tarefas[Tarefas];
    int frente;
    int fundo;
} FilaTarefas;

// PILHA
typedef struct {
    Tarefa tarefas[Tarefas];
    int topo;
} PilhaTarefasPrioritarias;

// INICIAR FILA
void inicializarFila(FilaTarefas *fila) {
    fila->frente = -1;
    fila->fundo = -1;
}

// PILHA VAZIA
int filaEstaVazia(FilaTarefas *fila) {
    return (fila->frente == -1);
}

// ADD TAREFA NA FILA
void adicionarTarefaNaFila(FilaTarefas *fila, const char *descricao) {
    if (fila->fundo == Tarefas - 1) {
        printf("A fila de tarefas gerais esta cheia.\n");
        return;
    }

    
    if (fila->frente == -1) {
        fila->frente = 0;
    }
    fila->fundo++;
    strcpy(fila->tarefas[fila->fundo].descricao, descricao);
}

// REMOVER TAREFA
void removerTarefaDaFila(FilaTarefas *fila) {
    if (filaEstaVazia(fila)) {
        printf("Nao existe tarefas para remover na fila de tarefas.\n");
        return;
    }

  
    if (fila->frente == fila->fundo) {
        fila->frente = -1;
        fila->fundo = -1;
    } else {
        fila->frente++;
    }
}

// INICIA PILHA
void inicializarPilha(PilhaTarefasPrioritarias *pilha) {
    pilha->topo = -1;
}

// PILHA VAZIA
int pilhaEstaVazia(PilhaTarefasPrioritarias *pilha) {
    return (pilha->topo == -1);
}

// ADD TAREFA NA PILHA
void adicionarTarefaNaPilha(PilhaTarefasPrioritarias *pilha, const char *descricao) {
    if (pilha->topo == Tarefas - 1) {
        printf("A pilha de alta prioridade esta cheia.\n");
        return;
    }

   
    pilha->topo++;
    strcpy(pilha->tarefas[pilha->topo].descricao, descricao);
}

// REMOVE TAREFA PILHA
void removerTarefaDaPilha(PilhaTarefasPrioritarias *pilha) {
    if (pilhaEstaVazia(pilha)) {
        printf("Não existe tarefas para remover na pilha de prioridades.\n");
        return;
    }


    pilha->topo--;
}


void imprimirTarefasNaFila(FilaTarefas *fila) {
    printf("Tarefas gerais:\n");
    for (int i = fila->frente; i <= fila->fundo; i++) {
        printf("Tarefa: %s\n", fila->tarefas[i].descricao);
    }
}


void imprimirTarefasNaPilha(PilhaTarefasPrioritarias *pilha) {
    printf("Tarefas de alta prioridade:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("Tarefa: %s\n", pilha->tarefas[i].descricao);
    }
}

int main() {
    FilaTarefas fila;
    inicializarFila(&fila);

    PilhaTarefasPrioritarias pilhaPrioritaria;
    inicializarPilha(&pilhaPrioritaria);

    char descricaoTarefa[100];
    char continuar;

    do {
        printf("Digite a descricao da tarefa: ");
        scanf(" %[^\n]", descricaoTarefa);

        printf("Esta tarefa sera de alta prioridade? (S/N): ");
        scanf(" %c", &continuar);

        if (continuar == 'S' || continuar == 's') {
            adicionarTarefaNaPilha(&pilhaPrioritaria, descricaoTarefa);
        } else {
            adicionarTarefaNaFila(&fila, descricaoTarefa);
        }

        printf("Deseja adicionar outra tarefa? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    printf("\n");
    imprimirTarefasNaFila(&fila);
    printf("\n");
    imprimirTarefasNaPilha(&pilhaPrioritaria);

    // REMOVE TAREFAS
    printf("\nDeseja remover uma tarefa? (S/N): ");
    scanf(" %c", &continuar);

    if (continuar == 'S' || continuar == 's') {
        char tipoRemocao;
        printf("Remover de qual pilha? (F - Fila / P - Pilha): ");
        scanf(" %c", &tipoRemocao);

        if (tipoRemocao == 'F' || tipoRemocao == 'f') {
            removerTarefaDaFila(&fila);
        } else if (tipoRemocao == 'P' || tipoRemocao == 'p') {
            removerTarefaDaPilha(&pilhaPrioritaria);
        } else {
            printf("Opcao de remocao invalida.\n");
        }
    }

    printf("\nList de tarefas depois da remocao:\n");
    imprimirTarefasNaFila(&fila);
    printf("\n");
    imprimirTarefasNaPilha(&pilhaPrioritaria);

    return 0;
}

