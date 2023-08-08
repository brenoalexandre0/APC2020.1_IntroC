/*                                                                     matrizDeEstudantes
    S�ntese
    Objetivo : Preencher uma Matriz de Estudantes (struct). Onde cada Estudante possui Nome, Idade e Nota.
    Entrada : Inserir as linhas e as colunas que a matriz possui, e inserir nome, idade e nota dentro.
    Sa�da : Informa��es sobre os estudantes.
------------------------------------------------------------------------------------------------------------------------------------------------------------*/




//Declara��o de bibliotecas.
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>




//Registro de alunos.
typedef struct est{
    char nome[100];
    int idade;
    float nota;
}estudante;




//Declara��o de fun��es.
void Matriz(int *linha, int *coluna);
void Cadastro(int linha, int coluna, estudante aluno[linha][coluna]);
void Imprimir(int linha, int coluna, estudante aluno[linha][coluna]);
void estudanteMaior(int linha, int coluna, estudante aluno[linha][coluna], float *maior);
void maiorNota(float maior);
void estudanteMenor(int linha, int coluna, estudante aluno[linha][coluna], float *menor);
void menorNota(float menor);
void Media(int linha, int coluna, estudante aluno[linha][coluna], float media[linha]);
void maiorMedia(int linha, int coluna, estudante aluno[linha][coluna], float media[linha]);
void menorMedia(int linha, int coluna, estudante aluno[linha][coluna], float media[linha]);
void Notas(int linha, int coluna, estudante aluno[linha][coluna]);




//Fun��o principal.
int main(){
    setlocale(LC_ALL,"Portuguese");

    printf("\n\n                                      Matriz de Estudantes");

    int linha, coluna;

    //Leitura da matriz.
    Matriz(&linha, &coluna);

    //Declara��o do struct.
    estudante aluno[linha][coluna];

    //Cadastro de estudantes.
    Cadastro(linha, coluna, aluno);

    //Informa��es dos estudantes.
    if(linha==0 || coluna==0){
        printf("\7");
        printf("\n\nN�o h� notas para informar.\n\n");
    }else{
        Imprimir(linha, coluna, aluno);
    }

    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento do cadastro de linhas e colunas.
void Matriz(int *linha, int *coluna){
    printf("\n\nInsira a quantidade de linhas: ");
    scanf("%d", &*linha);
    printf("\n\nInsira a quantidade de colunas: ");
    scanf("%d", &*coluna);
    system("cls || clear");
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento do cadastro de estudantes.
void Cadastro (int linha, int coluna, estudante aluno[linha][coluna]){
    for (int cont1=0;cont1<linha;cont1++){
        for (int cont2=0;cont2<coluna;cont2++){
            printf("\n\nInsira o nome do aluno: ");
            getchar();
            scanf("%[^\n]", aluno[cont1][cont2].nome);

            do{
                printf("\n\nInsira a idade do aluno: ");
                scanf("%d", &aluno[cont1][cont2].idade);
                if (aluno[cont1][cont2].idade < 1)
                    printf("\n\n\7S� n�meros a partir de 1. ");
            }while (aluno[cont1][cont2].idade < 1);

            do{
                printf("\n\nInsira a nota do aluno: ");
                scanf("%f", &aluno[cont1][cont2].nota);
                if (aluno[cont1][cont2].nota < 0 || aluno[cont1][cont2].nota > 10)
                    printf("\n\n\7S� n�meros entre 0 e 10. ");
            }while (aluno[cont1][cont2].nota < 0 || aluno[cont1][cont2].nota > 10);

            system("cls || clear");
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento com informa��es dos estudantes.
void Imprimir(int linha, int coluna, estudante aluno[linha][coluna]){
    float maior=0, menor=10, media[linha];

    //Linha e coluna do estudante com a maior nota.
    estudanteMaior(linha, coluna, aluno, &maior);

    //Maior nota.
    maiorNota(maior);

    //Linha e coluna do estudante com a menor nota.
    estudanteMenor(linha, coluna, aluno, &menor);

    //Menor nota.
    menorNota(menor);

    //M�dia das linhas.
    Media(linha, coluna, aluno, media);

    //Linha com a maior m�dia.
    maiorMedia(linha, coluna, aluno, media);

    //Linha com a menor m�dia.
    menorMedia(linha, coluna, aluno, media);

    //Matriz com as notas dos estudantes.
    Notas(linha, coluna, aluno);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento da linha e coluna do estudante com a maior nota.
void estudanteMaior(int linha, int coluna, estudante aluno[linha][coluna], float *maior){
    //Loop para determinar a maior nota.
    for (int cont1=0;cont1<linha;cont1++){
        for (int cont2=0;cont2<coluna;cont2++){
            if (aluno[cont1][cont2].nota > *maior)
                *maior=aluno[cont1][cont2].nota;
        }
    }

    //Loop para imprimir a linha e a coluna do estudante com a maior nota.
    printf("\n\nLinha e coluna do estudante com a maior nota: ");
    for (int cont1=0;cont1<linha;cont1++){
        for (int cont2=0;cont2<coluna;cont2++){
            if (aluno[cont1][cont2].nota == *maior)
                printf("Linha: %d Coluna: %d", cont1+1,cont2+1);
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento da maior nota.
void maiorNota(float maior){
    printf("\n\nMaior nota: %.1f", maior);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento da linha e coluna do estudante com a menor nota.
void estudanteMenor(int linha, int coluna, estudante aluno[linha][coluna], float *menor){
    //Loop para determinar a menor nota.
    for (int cont1=0;cont1<linha;cont1++){
        for (int cont2=0;cont2<coluna;cont2++){
            if (aluno[cont1][cont2].nota < *menor)
                *menor=aluno[cont1][cont2].nota;
        }
    }

    //Loop para imprimir a linha e a coluna do estudante com a menor nota.
    printf("\n\nLinha e coluna do estudante com a menor nota: ");
    for (int cont1=0;cont1<linha;cont1++){
        for (int cont2=0;cont2<coluna;cont2++){
            if (aluno[cont1][cont2].nota == *menor)
                printf("Linha: %d Coluna: %d", cont1+1,cont2+1);
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento da menor nota.
void menorNota(float menor){
    printf("\n\nMenor nota: %.1f", menor);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento das m�dias das linhas.
void Media(int linha, int coluna, estudante aluno[linha][coluna], float media[linha]){
    for (int cont1=0;cont1<linha;cont1++){
        for (int cont2=0;cont2<coluna;cont2++){
            float soma=0;
            soma=soma+aluno[cont1][cont2].nota;
            media[cont1]= media[cont1]+(soma/linha);
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento da linha com a maior m�dia.
void maiorMedia(int linha, int coluna, estudante aluno[linha][coluna], float media[linha]){
    float medmai=0;

    //Loop para determinar a linha com a maior m�dia.
    for (int cont=0;cont<linha;cont++){
        if (media[cont] > medmai)
            medmai=media[cont];
    }

    for (int cont=0;cont<linha;cont++){
        if (media[cont] == medmai)
            printf("\n\nA linha com a maior m�dia �: %d", cont+1);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento da linha com a menor m�dia.
void menorMedia(int linha, int coluna, estudante aluno[linha][coluna], float media [linha]){
    float medmen=10;

    //Loop para determinar a linha com a menor m�dia.
    for (int cont=0;cont<linha;cont++){
        if (media[cont] < medmen)
            medmen=media[cont];

    }

    for (int cont=0;cont<linha;cont++){
        if (media[cont] == medmen)
            printf("\n\nA linha com a menor m�dia �: %d", cont+1);
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Procedimento da matriz com as notas dos estudantes.
void Notas(int linha, int coluna, estudante aluno[linha][coluna]){
    printf("\n\nNotas dos estudantes: \n\n");
    for (int cont1=0;cont1<linha;cont1++){
        for (int cont2=0;cont2<coluna;cont2++){
            printf("%.1f  ", aluno[cont1][cont2].nota);
        }
        printf("\n");
    }
    printf("\n\n");
}
