#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menu, im_par;
    float altura, peso;
    double n1, n2;

    printf(" 1 - Informacoes\n 2 - Calcular IMC\n 3 - Par ou Impar\n 4 - Multiplicacao\n 5 - Divisao\n 6 - Sair\n");
    scanf("%d", &menu);
    system("cls");
    switch (menu)
        {
        case 1:
            printf("\n");
            printf("Breno Alexandre Soares Garcia - 20/0035703 - 1 Semestre");
            printf("\n\n\n\n\n\n\n\n");
        break;
        case 2:
            printf("\n");
            printf("Calcular IMC\n");
            printf("Digite o peso: ");
            scanf("%f", &peso);
            printf("Digite a altura: ");
            scanf("%f", &altura);
            printf("\n");
            printf("O IMC e: %.1f", peso/(altura*altura));
            printf("\n\n\n\n\n\n\n\n");
        break;
        case 3:
            printf("\n");
            printf("Par ou Impar\n");
            printf("Digite um numero: ");
            scanf("%d", &im_par);
            im_par= im_par%2;
            printf("\n");
            if (im_par == 0)
                printf("Este numero e par.");
            else
                printf("Este numero e impar.");
            printf("\n\n\n\n\n\n\n\n");
        break;
        case 4:
            printf("\n");
            printf("Multiplicacao\n");
            printf("Digite o primeiro numero: ");
            scanf("%lf", &n1);
            printf("Digite o segundo numero: ");
            scanf("%lf", &n2);
            printf("\n");
            printf("O produto e: %lf", n1*n2);
            printf("\n\n\n\n\n\n\n\n");
        break;
        case 5:
            printf("\n");
            printf("Divisao - Nao digite ''0''\n");
            printf("Digite o primeiro numero: ");
            scanf("%lf", &n1);
            printf("Digite o segundo numero: ");
            scanf("%lf", &n2);
            printf("\n");
            if (n2 != 0) {
                printf("O quociente e: %lf", n1/n2);
            }
            else {
                printf("Numero invalido.\7\n");
            break;
            }
            printf("\n\n\n\n\n\n\n\n");
        break;
        case 6:
            printf("\n");
            printf("                           Tchauuuuuuuuuu\n");
            printf("\n\n\n\n\n\n\n\n");
        }
    return 0;
}
