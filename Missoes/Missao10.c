/*              gerenciadorDeString
    Síntese
    Objetivo : Inserir uma string e gerenciá-la;
    Entrada : Um conjunto de caracteres;
    Saída : Uma string.                                     */


//Declaração de bibliotecas.
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Declaração de funções.
void Menu();
void caso1(char texto[]);
void caso2(char texto[]);
void caso3(char texto[]);
void caso4(char texto[]);
void Linha();
void caso5(char texto[]);


//Função principal.
int main(){
    setlocale(LC_ALL,"Portuguese");
    char texto[10]={'\0'}, opcao;

    do{
        Menu();
        printf("Escolha uma opção: ");
        scanf("%c", &opcao);
        setbuf(stdin, NULL);
        system("cls || clear");

        //Menu de opções a serem executadas.
        switch (opcao){
            case '1':
                caso1(texto);
            break;
            case '2':
                if (texto[0] == '\0'){
                    printf("\n\n\7                                      Não há string para imprimir.");
                }
                else{
                    caso2(texto);
                }
            break;
            case '3':
                if (texto[0] == '\0'){
                    printf("\n\n\7                                      Não há string para imprimir.");
                }
                else{
                    caso3(texto);
                }
            break;
            case '4':
                if (texto[0] == '\0'){
                    printf("\n\n\7                                      Não há string para validar.");
                }
                else{
                    caso4(texto);
                }
            break;
            case '5':
                if (texto[0] == '\0'){
                    printf("\n\n\7                                      Não há string para modificar.");
                }
                else{
                    caso5(texto);
                }
            break;
            case '6':
                printf("\n\n                                      Tchauuuu");
            break;
            default:
                printf("\n\n\7                                      Opção inválida.");
            break;
        }
    }while (opcao != 6);

    return 0;
}


//Função que imprime o menu de opções.
void Menu(){
    printf("\n\n1 - Testar string");
    printf("\n2 - Imprimir string");
    printf("\n3 - Imprimir de trás pra frente");
    printf("\n4 - Validar string");
    printf("\n5 - Modificar string");
    printf("\n6 - Sair\n\n");
}


//Função que lê a string.
void caso1(char texto[]){
    printf("Digite a string: ");
    scanf("%[^\n]", texto);
    getchar();
    system("cls || clear");
}


//Função que imprime a string e a quantidade de caracteres.
void caso2(char texto[]){
    int tam;

    tam=strlen(texto);

    printf("\n                                      A string é: |%s|, %d caracteres", texto,tam);
}


//Função que imprime a string de trás pra frente.
void caso3(char texto[]){
    printf("\n                                      |%s| de trás pra frente é: ", texto);
    strrev(texto);
    printf("|%s|", texto);
    strrev(texto);
}


//Função que confere se a string é válida.
void caso4(char texto[]){
    printf("\nPara a string ser válida, tem que seguir os critérios:");
    printf("\n\n- A string deve ter, pelo menos, 10 caracteres;");
    printf("\n- A string não pode conter números ou caracteres especiais, apenas letras minúsculas;");
    printf("\n- A primeira letra da string sempre deve ser uma vogal.\n\n");

    int tam2, inv=0;

    tam2=strlen(texto);

    for(int temp=0; temp < tam2; temp++){
        //Confere se tem algum número na posição atual.
        if(isdigit(texto[temp])){
            inv++;
        }
        //Confere se tem algum espaço na posição atual.
        if(isspace(texto[temp])){
            inv++;
        }
        //Confere se tem algum caractere especial na posição atual.
        if(ispunct(texto[temp])){
            inv++;
        }
        //Confere se tem alguma letra maiúscula na posição atual.
        if(isupper(texto[temp])){
            inv++;
        }
    }

    char vogal[6]={'a','e','i','o','u'};
    int vog=0;

    //Confere se tem alguma vogal na primeira posição.
    for (int temp2=0; temp2 < 6; temp2++){
        if (texto[0] == vogal[temp2]){
            vog++;
        }
    }

    Linha();

    if(tam2 < 10 || inv > 0 || vog == 0){
        printf("\n\n                                      A string |%s| não é válida.", texto);
    }
    else{
        printf("\n\n                                      A string |%s| é válida.", texto);
    }
}

//Função para imprimir uma linha de caracteres.
void Linha(){
    for(int temp3=0; temp3 <= 119; temp3++){
        printf("~");
    }
}


//Função para substituir um caractere da string.
void caso5(char texto[]){
    printf("\n\n                                      |%s|", texto);
    printf("\n\nSelecione um caractere para substituir: ");

    char antigo, novo;

    scanf("%c", &antigo);
    setbuf(stdin, NULL);
    printf("\n\nDigite o novo caractere: ");
    scanf("%c", &novo);
    setbuf(stdin, NULL);

    int tam3, cont=0;
    tam3=strlen(texto);

    //Confere se o caractere "antigo" está na string. Se sim, ele substituído pelo caractere "novo".
    for (int temp4=0; temp4 < tam3; temp4++){
        if (texto[temp4] == antigo){
            texto[temp4]=novo;
            cont++;
        }
    }

    system("cls || clear");

    if(cont > 0){
        printf("\n\n                                      A nova string: |%s|", texto);
    }
    else{
        printf("\n\n\7                                      Caractere não encontrado na string. |%s|", texto);
    }
}
