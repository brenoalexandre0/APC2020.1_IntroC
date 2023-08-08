#include <stdio.h>
#include <stdlib.h>

void MENU();
void CASO1(int num[], int *quant);
void CASO2(int num[], int quant);
void CASO3(int num[], int quant);
void CASO4(int num[], int *quant);
void CASO5(int num[], int quant);


int main(){
    int escolha, num[200], quant=0;

    MENU();

    do{
        printf("\nEscolha uma opcao: ");
        scanf("%d", &escolha);
        system("cls || clear");
        MENU();

        switch (escolha) {
            case 1:
                CASO1(num, &quant);
            break;
            case 2:
                CASO2(num, quant);
            break;
            case 3:
                CASO3(num, quant);
            break;
            case 4:
                CASO4(num, &quant);
            break;
            case 5:
                CASO5(num, quant);
            break;
            case 6:
                printf("\n                         Tchauuuuuuuuu\n");
            break;
            default:
                printf("\n\7Opcao invalida.\n");
            break;
        }
    }while (escolha != 6);

    return 0;
}


void MENU(){
    printf("\n1 - Inserir numero");
    printf("\n2 - Listar numeros");
    printf("\n3 - Editar posicao");
    printf("\n4 - Excluir posicao");
    printf("\n5 - Listar numeros maiores que a media");
    printf("\n6 - Sair\n");
}


void CASO1(int num[], int *quant){

    printf("\nDigite um numero: ");
    scanf("%d", &num[*quant]);
    (*quant)++;
}


void CASO2(int num[], int quant){
    if (quant == 0){
        printf("\n\7Nao ha numeros para listar.\n");
    }
    else{
        printf("\n");
        for (int temp=0;temp < quant; temp++){
            printf("\nPosicao |%d| - Valor |%d| ", temp,num[temp]);
        }
        printf("\n");
    }
}


void CASO3(int num[], int quant){
    int pos;

    if (quant == 0){
        printf("\n\7Nao ha numeros para editar.\n");
    }
    else{
        printf("\nDigite a posicao do vetor. Caso queira voltar, insira um numero negativo: ");
        scanf("%d", &pos);
        if (pos >= 0){
            printf("\nDigite o numero substituto: ");
            scanf("%d", &num[pos]);
        }
    }
}


void CASO4(int num[], int *quant){
    int pos2;

    if (*quant == 0){
        printf("\n\7Nao ha numeros para excluir.\n");
    }
    else{
        printf("\nDigite a posicao do vetor para excluir. Caso queira voltar, insira um numero negativo: ");
        scanf("%d", &pos2);
        if (pos2 >= 0){
            for (pos2;pos2 < *quant; pos2++){
                num[pos2]=num[pos2+1];
            }
            (*quant)--;
        }
    }
}


void CASO5(int num[], int quant){
    double soma;
    double media;

    if (quant == 0){
        printf("\n\7Nao ha numeros para fazer media.\n");
    }
    else{
        for(int temp2=0; temp2 < quant; temp2++){
            soma=soma+num[temp2];
        }

        media= soma/quant;

        for (int pos3=0;pos3 < quant; pos3++){
            if (num[pos3] > media){
               printf("Numeros maiores que a media dos numeros do vetor: %d\n", num[pos3]);
            }
        }
    }
}
