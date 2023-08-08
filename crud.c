/*                                             sistemaDeGer�nciaDeClubeEsportivo
    S�ntese
    Objetivo : Cadastrar associados e dependentes de um clube esportivo e gerenci�-los;
    Entrada : Associados, onde em cada um dever� envolver: identificador, nome, idade, e at� tr�s dependentes;
    Sa�da : Gerenciar as informa��es inseridas.
------------------------------------------------------------------------------------------------------------------------------------------------------------*/




//Declara��o de bibliotecas.
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




//Registro do(s) dependente(s).
typedef struct Dependente{
    char nome[20];
    int  idade;
}Dependente;




//Registro do(s) associados(s).
typedef struct Associado{
    int  id;
    char nome[20];
    int  idade;
    int qtdDep;
    Dependente dep[3];
    bool natacao;
    bool futsal;
    bool tenis;
}Associado;




//Declara��o de fun��es e procedimentos.
void menu1();
void caso1(int *quantA, Associado ass[*quantA]);
bool Natacao(char modalidade);
bool Futsal(char modalidade);
bool Tenis(char modalidade);
void caso2(int quantA, Associado ass[quantA]);
void caso3(int quantA, Associado ass[quantA]);
void menu2();
void caso4(int quantA, Associado ass[quantA]);
void caso5(int quantA, Associado ass[quantA]);
void caso6(int quantA, Associado ass[quantA]);
void caso7();




//Fun��o principal.
int main(){
    setlocale(LC_ALL,"Portuguese");
    char escolha, confirma;
    int quantA=0, maisAula=0;

    do{
        menu1();
        printf("Escolha uma op��o: ");
        scanf(" %c", &escolha);
        setbuf(stdin, NULL);
        system("cls || clear");

        //Menu de op��es.
        switch (escolha){
            //Declara��o do registro.
            Associado ass[200];
            //Op��o para cadastrar associado(s).
            case '1':
                caso1(&quantA, ass);
                system("cls || clear");
            break;
            //Op��o para cadastrar dependente(s).
            case '2':
                if (quantA == 0){
                    printf("\n\n\7                                        N�o h� associados para cadastrar dependentes.\n\n\n");
                }else{
                    caso2(quantA, ass);
                }
                printf("\n\nDigite qualquer tecla para voltar ao menu:");
                scanf(" %c", &confirma);
                setbuf(stdin, NULL);
                system("cls || clear");
            break;
            //Op��o para listar associado(s).
            case '3':
                if (quantA == 0){
                    printf("\n\n\7                                        N�o h� associados para listar.\n\n\n");
                }else{
                    caso3(quantA,ass);
                }
                printf("\n\nDigite qualquer tecla para voltar ao menu:");
                scanf(" %c", &confirma);
                setbuf(stdin, NULL);
                system("cls || clear");
            break;
            //Op��o para listar associado(s) por modalidade.
            case '4':
                if (quantA == 0){
                    printf("\n\n\7                                        N�o h� associados para listar.\n\n\n");
                }else{
                    caso4(quantA, ass);
                }
            break;
            //Op��o para pesquisar associado(s).
            case '5':
                if (quantA == 0){
                    printf("\n\n\7                                        N�o h� associados para pesquisar.\n\n\n");
                }else{
                    caso5(quantA, ass);
                }
                printf("\n\nDigite qualquer tecla para voltar ao menu:");
                scanf(" %c", &confirma);
                setbuf(stdin, NULL);
                system("cls || clear");
            break;
            //Op��o para gerar relat�rio de associado(s).
            case '6':
                if (quantA == 0){
                    printf("\n\n\7                                        N�o h� associados para gerar relat�rio.\n\n\n");
                }else{
                    caso6(quantA, ass);
                }
                printf("\n\nDigite qualquer tecla para voltar ao menu:");
                scanf(" %c", &confirma);
                setbuf(stdin, NULL);
                system("cls || clear");
            break;
            //Op��o para finalizar o programa.
            case '7':
                caso7();
            break;
            //Op��o caso nenhuma outra op��o seja escolhida.
            default:
                printf("\n\n\7                                        Op��o inv�lida.\n\n\n");
            break;
        }
    }while (escolha != '7');

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para imprimir o menu.
void menu1(){
    printf("                                        Sistema de Ger�ncia de Clube Esportivo");
    printf("\n\n1. Cadastrar associado");
    printf("\n2. Cadastrar dependente");
    printf("\n3. Listar associados");
    printf("\n4. Listar associados por modalidade");
    printf("\n5. Pesquisar associados");
    printf("\n6. Gerar relat�rio de associados");
    printf("\n7. Finalizar Programa\n\n");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para cadastrar associado(s).
void caso1(int *quantA, Associado ass[*quantA]){
    char modalidade;
    int existe;

    do{
        printf("\nDigite o identificador: ");
        do{
            scanf("%d", &ass[*quantA].id);
            if (ass[*quantA].id < 1)
                printf("\n\7Apenas caracteres positivos.");
            for(int cont=0; cont<*quantA; cont++){
                if (ass[cont].id == ass[*quantA].id){
                    printf("\n\7Este identificador j� existe. Digite outro.");
                    existe=ass[cont].id;
                }
            }
        }while(ass[*quantA].id < 1 || existe == ass[*quantA].id);

        printf("\nDigite o nome: ");
        do{
            getchar();
            scanf("%[^\n]", ass[*quantA].nome);
            if (strlen(ass[*quantA].nome) > 20)
                printf("\n\7Apenas 20 caracteres.");
        }while(strlen(ass[*quantA].nome) > 20);

        printf("\nDigite a idade: ");
        do{
            scanf("%d", &ass[*quantA].idade);
            if (ass[*quantA].idade < 1)
                printf("\n\7Apenas n�meros positivos a partir de 1.");
        }while(ass[*quantA].idade < 1);

        //Definir se o associado faz aula de nata��o ou n�o.
        ass[*quantA].natacao= Natacao(modalidade);

        //Definir se o associado faz aula de futsal ou n�o.
        ass[*quantA].futsal= Futsal(modalidade);

        //Definir se o associado faz aula de tenis ou n�o.
        ass[*quantA].tenis= Tenis(modalidade);

        printf("\nSe deseja continuar a cadastrar, digite 's''/''S''\n");
        scanf(" %c", &modalidade);
        setbuf(stdin, NULL);

        //Contador para trocar o registro de posi��o e acumular cadastros.
        (*quantA)++;

    }while(modalidade == 's' || modalidade == 'S');
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Fun��o para decidir se o associado faz nata��o.
bool Natacao(char modalidade){
    printf("\nRealiza alguma aula de nata��o?(Sim=''s''/''S'' N�o=''n''/''N'')");

    do{
        scanf(" %c", &modalidade);
        setbuf(stdin, NULL);
        if (modalidade == 's' || modalidade == 'S')
            return true;
        if (modalidade == 'n' || modalidade == 'N')
            return false;
        if (modalidade != 's' && modalidade != 'S' && modalidade != 'n' && modalidade != 'N')
            printf("\n\7Use apenas ''s''/''S'' - ''n''/''N''.");
    }while(modalidade != 's' && modalidade != 'S' && modalidade != 'n' && modalidade != 'N');
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Fun��o para decidir se o associado faz futsal.
bool Futsal(char modalidade){
    printf("\nRealiza alguma aula de futsal?(Sim=''s''/''S'' N�o=''n''/''N'')");

    do{
        scanf(" %c", &modalidade);
        setbuf(stdin, NULL);
        if (modalidade == 's' || modalidade == 'S')
            return true;
        if (modalidade == 'n' || modalidade == 'N')
            return false;
        if (modalidade != 's' && modalidade != 'S' && modalidade != 'n' && modalidade != 'N')
            printf("\n\7Use apenas ''s'' - ''S''/''n''/''N''.");
    }while(modalidade != 's' && modalidade != 'S' && modalidade != 'n' && modalidade != 'N');
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Fun��o para decidir se o associado faz t�nis.
bool Tenis(char modalidade){
    printf("\nRealiza alguma aula de t�nis?(Sim=''s''/''S'' N�o=''n''/''N'')");

    do{
        scanf(" %c", &modalidade);
        setbuf(stdin, NULL);
        if (modalidade == 's' || modalidade == 'S')
            return true;
        if (modalidade == 'n' || modalidade == 'N')
            return false;
        if (modalidade != 's' && modalidade != 'S' && modalidade != 'n' && modalidade != 'N')
            printf("\n\7Use apenas ''s'' - ''S''/''n''/''N''.");
    }while(modalidade != 's' && modalidade != 'S' && modalidade != 'n' && modalidade != 'N');
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para cadastrar os dependentes.
void caso2(int quantA, Associado ass[quantA]){
    int procura, existe=0;
    char continua;

    do{
        do{
            printf("\nDigite o identificador do associado: ");
            scanf("%d", &procura);
            if (procura < 1)
                printf("\n\7Apenas caracteres positivos.");
        }while(procura < 1);

        //Loop para descobrir se o identificador existe e igualar a v�riavel "procura" a posi��o do associado desejado.
        for(int cont=0; cont<quantA; cont++){
            if (procura==ass[cont].id){
                procura=cont;
                existe++;
            }
        }

        if(existe == 0)
            printf("\n\7Este identificador n�o existe.");

        if(ass[procura].qtdDep == 3)
            printf("\n\7O n�mero m�ximo de dependentes foi alcan�ado.");
    }while(existe == 0 || ass[procura].qtdDep == 3);

    do{
        printf("\nAssociado: %s\n", ass[procura].nome);
        printf("\nQuantidade de dependentes atuais: %d\n", ass[procura].qtdDep);

        do{
            printf("\nDigite o nome: ");
            getchar();
            scanf("%[^\n]", ass[procura].dep[ass[procura].qtdDep].nome);
            if (strlen(ass[procura].dep[ass[procura].qtdDep].nome) > 20)
                printf("\n\7Apenas 20 caracteres.");
        }while(strlen(ass[procura].dep[ass[procura].qtdDep].nome) > 20);

        do{
            printf("\nDigite a idade: ");
            scanf("%d", &ass[procura].dep[ass[procura].qtdDep].idade);
            if (ass[procura].dep[ass[procura].qtdDep].idade < 1)
                printf("\n\7Apenas n�meros positivos a partir de 1.");
        }while(ass[procura].dep[ass[procura].qtdDep].idade < 1);

        ass[procura].qtdDep++;

        if (ass[procura].qtdDep == 3)
            break;

        printf("\nSe deseja continuar a cadastrar, digite 's''/''S''\n");
        scanf(" %c", &continua);
        setbuf(stdin, NULL);
        system("cls || clear");
    }while(continua == 's' || continua == 'S');

    if(ass[procura].qtdDep == 3)
        printf("\n\7O n�mero m�ximo de dependentes foi alcan�ado.");

    printf("\n\nIdentificador: %d - Associado: %s\n", ass[procura].id, ass[procura].nome);

    for(int cont=0; cont<ass[procura].qtdDep; cont++){
        printf("\n%s - %d\n\n", ass[procura].dep[cont].nome,ass[procura].dep[cont].idade);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para imprimir os associados cadastrados.
void caso3(int quantA, Associado ass[quantA]){
    for(int cont1=0; cont1<quantA; cont1++){
        printf("\n\n%d - %s - %d - %d - ", ass[cont1].id, ass[cont1].nome, ass[cont1].idade, ass[cont1].qtdDep);
        if(ass[cont1].natacao){
            printf("Faz nata��o - ");
        }
        else{
            printf("N�o faz nata��o - ");
        }
         if(ass[cont1].futsal){
            printf("Faz futsal - ");
        }
        else{
            printf("N�o faz futsal - ");
        }
        if(ass[cont1].tenis){
            printf("Faz t�nis\n\n");
        }
        else{
            printf("N�o faz t�nis\n\n");
        }
    }

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para imprimir o menu do caso 4.
void menu2(){
    printf("                                        Lista de associados por modalidade");
    printf("\n\n1. Nata��o");
    printf("\n\n2. Futsal");
    printf("\n\n3. T�nis");
    printf("\n\n4. Voltar para o menu principal\n\n");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para listar associados por modalidade.
void caso4(int quantA, Associado ass[quantA]){
    char escolha;

    do{
        menu2();
        printf("Escolha uma op��o: ");
        scanf(" %c", &escolha);
        setbuf(stdin, NULL);
        system("cls || clear");

        //Menu de op��es.
        switch(escolha){
            //Op��o para listar associado(s) que faz(em) aula de nata��o.
            case '1':
                printf("\n\n                                        Nata��o\n");
                for(int cont=0; cont<quantA; cont++){
                    if (ass[cont].natacao)
                        printf("\n\n%d - %s\n", ass[cont].id, ass[cont].nome);
                }
            break;
            //Op��o para listar associado(s) que faz(em) aula de futsal.
            case '2':
                printf("\n\n                                        Futsal\n");
                for(int cont=0; cont<quantA; cont++){
                    if (ass[cont].futsal)
                        printf("\n\n%d - %s\n", ass[cont].id, ass[cont].nome);
                }
            break;
            //Op��o para listar associado(s) que faz(em) aula de t�nis.
            case '3':
                printf("\n\n                                        T�nis\n");
                for(int cont=0; cont<quantA; cont++){
                    if (ass[cont].tenis)
                        printf("\n\n%d - %s\n", ass[cont].id, ass[cont].nome);
                }
            break;
            //Op��o para finalizar o programa.
            case '4':
            break;
            //Op��o caso nenhuma outra op��o seja escolhida.
            default:
                printf("\n\n\7                                        Op��o inv�lida.\n\n\n");
            break;
        }
    }while(escolha != '4');
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para pesquisar associado(s).
void caso5(int quantA, Associado ass[quantA]){
    char nome[20];
    int existe=0, aula=0;
    float mensal=0;

    do{
        do{
            printf("\nDigite o nome: ");
            scanf("%[^\n]", nome);
            getchar();
            if (strlen(nome) > 20)
                printf("\n\7Apenas 20 caracteres.");
        }while(strlen(nome) > 20);

        for(int cont=0; cont < quantA; cont++){
            if(strcmp(ass[cont].nome, nome) == 0)
                existe++;
        }

        if(existe == 0)
            printf("\n\7Este associado n�o existe.");
    }while(existe == 0);

    //La�o de repeti��o para calcular informa��es sobre o associado desejado e imprimi-las.
    for(int cont1=0; cont1 < quantA; cont1++){
        if(strcmp(ass[cont1].nome, nome) == 0){
            if (ass[cont1].natacao){
                aula++;
                mensal=mensal+30;
            }
            if (ass[cont1].futsal){
                aula++;
                mensal=mensal+30;
            }
            if (ass[cont1].tenis){
                aula++;
                mensal=mensal+30;
            }

            mensal=mensal+100+(ass[cont1].qtdDep*50);

            printf("\n\n%d - %s - %d - %d - %d - R$%.2f", ass[cont1].id, ass[cont1].nome, ass[cont1].idade, ass[cont1].qtdDep, aula, mensal);
        }
    }

    printf("\n\n");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para gerar relat�rios de associado(s).
void caso6(int quantA, Associado ass[quantA]){
    printf("\n\nN�mero total de associados cadastrados %d", quantA);

    int totaldep=0, aulanat=0, aulafut=0, aulaten=0, aula=0, maisAula=0;
    float totalmen=0, mensal=0, maiorV=0;

    //La�o de repeti��o para calcular as informa��es para gerar relat�rios de associado(s).
    for(int cont=0; cont < quantA; cont++){
        totaldep=totaldep+ass[cont].qtdDep;

        aula=0;
        if (ass[cont].natacao){
            aulanat++;
            totalmen=totalmen+30;
            mensal=mensal+30;
            aula++;
        }
        if (ass[cont].futsal){
            aulafut++;
            totalmen=totalmen+ 30;
            mensal=mensal+30;
            aula++;
        }
        if (ass[cont].tenis){
            aulaten++;
            totalmen=totalmen+30;
            mensal=mensal+30;
            aula++;
        }

        totalmen= totalmen + 100 + (ass[cont].qtdDep*50);

        mensal= mensal + 100 + (ass[cont].qtdDep*50);

        if(mensal>maiorV)
            maiorV=mensal;

        if(aula>maisAula)
            maisAula=aula;
    }

    printf("\n\nN�mero total de dependentes cadastrados: %d", totaldep);

    printf("\n\nN�mero de associados que fazem aula de Nata��o: %d", aulanat);

    printf("\n\nN�mero de associados que fazem aula de Futsal: %d", aulafut);

    printf("\n\nN�mero de associados que fazem aula de T�nis: %d", aulaten);

    printf("\n\nValor total de todas as mensalidades dos associados: R$%.2f", totalmen);

    printf("\n\nValor m�dio das mensalidades dos associados: R$%.2f", totalmen/quantA);

    printf("\n\nValor de mensalidade mais alto pago por um associado: R$%.2f", maiorV);

    //La�o de repeti��o para calcular qual/quais associado(s) fazem mais aulas.
    for(int cont=0; cont < quantA; cont++){
        aula=0;

        if (ass[cont].natacao)
            aula++;
        if (ass[cont].futsal)
            aula++;
        if (ass[cont].tenis)
            aula++;

        if(aula == maisAula)
            printf("\n\nNome do(s) associado(s) que fazem mais aulas: %s\n\n", ass[cont].nome);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento para imprimir a despedida ao usu�rio.
void caso7(){
    printf("\n                                        Tchau! Tenha um feliz natal e pr�spero ano novo! :)\n");
}
