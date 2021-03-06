#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 5

////// nao sei se entendi certo, mas acho que éra pra usar as listas para criar um programa

//fiz o programa de um hospital, onde quando as pessoas chegam elas sao ordenadas por ordem de chegada,
//porem se uma pessoa esta mais doente que as outras ela passa na frente
//considerando a inclementaçao no inicio como paciente urgente e a no fim como paciente normal

struct tp_lista
{
    int frente, tras;
    int pessoa[MAXTAM];
} lista;


int lista_vazia()
{

    if (0 == lista.tras)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int lista_cheia()
{

    if (lista.tras == MAXTAM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push_inicio(int e)
{
    if (lista_cheia() == 1)
    {
        return printf("\nLista Cheia\n");
    }
    else
    {
        int i;
        int aux[lista.tras];
        for (i = 0; i < lista.tras; i++)
        {
            aux[i] = lista.pessoa[i];
        }
        lista.pessoa[0] = e;
        lista.tras++;
        for (i = 1; i < lista.tras; i++)
        {
            lista.pessoa[i] = aux[i - 1];
        }
    }
}

int push_fim(int e)
{
    if (lista_cheia() == 1)
    {
        return printf("\nLista Cheia\n");
    }
    else
    {
        lista.pessoa[lista.tras] = e;
        lista.tras++;
    }
}

int pop_inicio()
{
    if (lista_vazia() == 1)
    {
        return printf("\nLista Vazia\n");
    }
    else
    {
        int i;
        int aux[lista.tras];
        for (i = 1; i < lista.tras; i++)
        {
            aux[i] = lista.pessoa[i];
            lista.pessoa[i - 1] = aux[i];
        }
        lista.tras--;
    }
}

int pop_fim()
{
    if (lista_vazia() == 1)
    {
        return printf("\nLista Vazia\n");
    }
    else
    {
        lista.pessoa[lista.tras] = NULL;
        lista.tras--;
    }
}

int print_list()
{
    printf("Lista ");
    int i;
    for (i = 0; i < lista.tras; i++)
    {
        printf(" - %d", lista.pessoa[i]);
    }
    printf("\n");
}

void inserir(int ops)
{
    int n;
    printf("digite o numero numero:");
    fflush(stdin);
    scanf("%d", &n);
    getchar();
    if (ops == 1)
    {
        push_inicio(n);
    }
    else if (ops == 2)
    {
        push_fim(n);
    }
    else
    {
        printf("\nNumero invalido\n");
    }
    ///(ops == 1) ? push_inicio(n) : push_fim(n);
    print_list();
}
void remover(int ops)
{
    if (ops == 1)
    {
        pop_inicio();
    }
    else if (ops == 2)
    {
        pop_fim();
    }
    else
    {
        printf("\nNumero invalido\n");
    }
    //(ops == 1) ? pop_inicio() : pop_fim();
    print_list();
}

int main()
{
    int ops, menu;

    printf("........Hospital Sao Luiz..........\n\n");
    do
    {
        printf("..............Lista Pacientes.............\n");
        printf("                   menu\n");
        printf("          [1]Entrada Paciente\n          [2]Saida Paciente\n             [3]Desligar\n");
        printf("..........................................\n\n");
        fflush(stdin);
        scanf("%d", &menu);// escolhe uma das opçoes
        getchar();
        switch (menu)
        {
        case 1:///// entrada ou pu
            printf("Entrada Paciente.....\nStatus:  [1]Urgente [2]Comun\n");
            fflush(stdin);
            scanf("%d", &ops);
            getchar();
            inserir(ops);
            break;

        case 2:
            printf("Saida Paciente.....\nStatus:  [1]Faleceu [2]Desistiu");
            fflush(stdin);
            scanf("%d", &ops);
            getchar();
            remover(ops);
            break;

        case 3:
            printf("\nEncerrando o programa......\n");
            break;
        default:
            printf("\n........................\n");
            printf("\n erro: Opçao invalida!!!\n");
            printf("\n........................\n");
            break;
        }
    } while (menu != 3);
}