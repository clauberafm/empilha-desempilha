#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 3

//Para a estruturacao das pilhas	
typedef struct node1 {
    int number;
    struct node1 *next;
}p1;

typedef struct node2{
    int number;
    struct node2 *next;
} p2;

void inserir_p();
void retirar_p();
void exibe();
char return_color();
void menu();

//MENU de opcoes
void menu(){
    printf("\n");
	printf("\n");
	printf("|==================================|");
    printf("\n| Selecione uma das opcoes abaixo: |\n");
    printf("|==================================|");
    printf("\n");
 	printf("\n1 - Empilhar pratos\n"); 
 	printf("2 - Desempilhar pratos\n"); 
 	printf("3 - Sair\n\n"); 
}

int main() {
	
	//Processos de empilhamento e desempilhamento
    p1 *topo1 = NULL;
    p2 *topo2 = NULL;
    int operacao;
    menu();
    scanf("%1d", &operacao);
    while (operacao >= 0 && operacao <3) {
        switch (operacao){
            case 1:
                if (topo1 == NULL) {            
                    printf("\nPilha 1 em processo de empilhamento: \n");
                    inserir_p(&topo1, 1);
                    inserir_p(&topo1, 2);
                    inserir_p(&topo1, 3);
                    inserir_p(&topo1, 4);
                    inserir_p(&topo1, 5);
                    exibe(topo1);
                    printf("\nEmpilhamento realizado com sucesso! \n");
                    break;
                } else {
                    printf("\nPilha 1 totalmente cheia!\n");
                    break;
                }
            case 2:
                printf("\nPilha 1 em processo de desempilhamento: ");
                while (topo1 != NULL) {
                    inserir_p(&topo2, topo1->number);
                    exibe(topo1);
                    retirar_p(&topo1);
                }
                printf("\nPilha 1 completamente vazia!\n");
                printf("\nPilha 2: ");
                exibe(topo2);
                break;
        }
        menu();
        scanf("%d", &operacao);
    };
    return 0;
}

// Uso da função MALLOC para realizar a alocacao
void inserir_p(p1 *topo1[], int number)
{
    p1 *novo = (p1 *)malloc(sizeof(p1));
    novo->number = number;
    novo->next = *topo1;
    *topo1 = novo;
}

void retirar_p(p1 *topo1[])
{
    p1 *aux = *topo1;
    *topo1 = (*topo1)->next;
    printf("\nDesempilhando");
    return_color(aux->number);
    printf("\n");
    free(aux);
}

void exibe(p1 *topo1)
{
    p1 *aux = topo1;
    while (aux != NULL)
    {
        printf("\n%d", aux->number);
        return_color(aux->number);
        aux = aux->next;
    }
    printf("\n");
    
}

//Indicacao dos pratos como cores
char return_color(int number) {
    char color[10];
    switch (number) {
        case 1:
            strcpy(color, "Vermelho");
            break;
        case 2:
            strcpy(color, "Verde");
            break;
        case 3:
            strcpy(color, "Azul");
            break;
        case 4:
            strcpy(color, "Branco");
            break;
        case 5:
            strcpy(color, "Laranja");
            break;
        default:
            break;
    }
    printf(" Prato %s", color);
}
