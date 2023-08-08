#include <stdio.h>
#include <stdlib.h>

void TITULO();
void CADASTRO(int *quant, int num, int *totalinv, int *negativo, int *triplo, int *primo, int *soma, int *maior, int *menor);
int PRIMO (int num);
void MENU(int quant, int totalinv, int negativo, int triplo, int primo, int soma, double media, int maior, int menor);


int main(){

    int quant, num, negativo=0, triplo=0, primo=0, soma=0, maior=0, menor=101, totalinv=0;
    double media=0;

    TITULO();

    scanf("%d", &quant);

    CADASTRO(&quant, num, &totalinv, &negativo, &triplo, &primo, &soma, &maior, &menor);

    system("cls || clear");

    MENU(quant, totalinv, negativo, triplo, primo, soma, media, maior, menor);

    return 0;
}


void TITULO(){
    printf("                                            Comparador de Numeros\n\n");
    printf("Regras:\n");
    printf("Deve ser positivo (>=0);\n");
    printf("Deve ser menor que o triplo da quantidade de numeros que deseja inserir;\n");
    printf("Deve ser um numero nao primo.\n\n");
    printf("Digite a quantidade de numeros que deseja inserir: ");
}


void CADASTRO(int *quant, int num, int *totalinv, int *negativo, int *triplo, int *primo, int *soma, int *maior, int *menor){
    int temp;
    for (temp=1; temp <= *quant; temp++){
        printf("Digite um numero: ");
        scanf("%d", &num);

         while (num < 0 || num >= *quant*3 || PRIMO(num) == 0){
            if (num < 0){
                *totalinv= *totalinv+1;
                *negativo= *negativo+1;
                printf("Voce inseriu um numero negativo! Digite novamente: ");
                scanf("%d", &num);
            }
            if (num == *quant*3){
                *totalinv= *totalinv+1;
                *triplo= *triplo+1;
                printf("Voce inseriu um numero igual ao triplo da quantidade! Digite novamente: ");
                scanf("%d", &num);
            }
            if (num > *quant*3){
                *totalinv= *totalinv+1;
                *triplo= *triplo+1;
                printf("Voce inseriu um numero maior que o triplo da quantidade! Digite novamente: ");
                scanf("%d", &num);
            }
            if (PRIMO (num) >= 0){
                *totalinv= *totalinv+1;
                *primo= *primo+1;
                printf("Voce inseriu um numero primo! Digite novamente: ");
                scanf("%d", &num);
            }
        }

        *soma=*soma+num;
        if (num > *maior){
            *maior= num;
        }
        if (num < *menor){
            *menor= num;
        }
    }

    if (*quant == 0){
        *menor=0;
    }
}


int PRIMO(int num){
    int temp2, p=0;
    for (temp2=2;temp2 <= (num/2);temp2++){
        if (num%temp2 == 0){
            p++;
        break;
        }
    }
    return p;
}


void MENU(int quant, int totalinv, int negativo, int triplo, int primo, int soma, double media, int maior, int menor){
    int menu;

    do{
        printf("1 - Total de numero validos\n");
        printf("2 - Total de tentativas invalidas\n");
        printf("3 - Media\n");
        printf("4 - Maior\n");
        printf("5 - Menor\n");
        printf("6 - Regra mais critica\n");
        printf("7 - Sair\n");
        scanf("%d", &menu);
        system("cls || clear");

        switch (menu){
            case 1:
                printf("\n1 - O total de numeros validos eh: %d\n\n", quant);
            break;

            case 2:
                printf("\n5 - O numero de regras quebradas eh: %d\n\n", totalinv);
            break;

            case 3:
                media= soma/(quant);
                printf("\n2 - A media dos numeros eh: %.2lf\n\n", media);
            break;

            case 4:
                printf("\n3 - O numero maior eh: %d\n\n", maior);
            break;

            case 5:
                printf("\n4 - O numero menor eh: %d\n\n", menor);
            break;

            case 6:
                printf("\nA regra mais critica eh:\n");
                if (quant > 0){
                    if (negativo > triplo && negativo > primo){
                        printf("\nDeve ser positivo (>=0);\n\n");
                    }
                    if (triplo > negativo && triplo > primo){
                        printf("\nDeve ser menor que o triplo da quantidade de numeros que deseja inserir;\n\n");
                    }
                    if (primo > negativo && primo > triplo){
                        printf("\nDeve ser um numero nao primo.\n\n");
                    }
                }
                else{
                        printf("\nNao tem regra mais critica.\n\n");
                }
                break;

            case 7:
                printf("\n");
                printf("                     Tchauuuuu\n");
                printf("\n");
            break;

            default:
                printf("\n");
                printf("Opcao invalida!\n");
                printf("\n");
            break;
        }
    }
    while (menu != 7);
}
