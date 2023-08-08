#include <stdio.h>
#include <stdlib.h>

int main(void){

    int menu, temp, quant, num, soma=0, maior=0, menor=101, totalinv=0;
    double media=0;

    printf("Comparador de Numeros\n");
    printf("Digite a quantidade de numeros que deseja inserir: ");
    scanf("%d", &quant);

    printf("Digite um numero de 0 a 100, nao multiplo de 3: ");

    for (temp=1; temp <= quant; temp++){
        printf("Digite um numero de 0 a 100, nao multiplo de 3: ");
        scanf("%d", &num);

        while (num < 0 || num > 100 || num%3 == 0){
            if (num < 0) {
                printf("Voce inseriu um numero negativo! Digite Novamente: ");
                scanf("%d", &num);
                totalinv++;
            }

            if (num > 100) {
                printf("Voce inseriu um numero maior que 100! Digite Novamente: ");
                scanf("%d", &num);
                totalinv++;
            }

            if (num%3 == 0) {
                printf("Voce inseriu um numero multiplo de 3! Digite Novamente: ");
                scanf("%d", &num);
                totalinv++;
            }
        }

        soma=soma + num;
        if (num > maior)
        maior= num;
        if (num < menor)
        menor= num;

    }

    if (quant == 0)
        menor=0;

    system("cls || clear");

    do{
        printf("1 - Total\n");
        printf("2 - Media\n");
        printf("3 - Maior\n");
        printf("4 - Menor\n");
        printf("5 - Numero de regras quebradas\n");
        printf("6 - Sair\n");
        scanf("%d", &menu);
        system("cls || clear");

        switch (menu){
            case 1:
            printf("\n");
            printf("1 - O total de numeros e: %d\n", quant);
            printf("\n");
            break;

            case 2:
            media= soma/quant;
            printf("\n");
            printf("2 - A media dos numeros e: %.2lf\n", media);
            printf("\n");
            break;

            case 3:
            printf("\n");
            printf("3 - O numero maior e: %d\n", maior);
            printf("\n");
            break;

            case 4:
            printf("\n");
            printf("4 - O numero menor e: %d\n", menor);
            printf("\n");
            break;

            case 5:
            printf("\n");
            printf("5 - O numero de regras quebradas e: %d\n", totalinv);
            printf("\n");
            break;

            case 6:
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
    while (menu != 6);
}
