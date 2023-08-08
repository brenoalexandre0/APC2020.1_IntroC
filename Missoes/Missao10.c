/*              gerenciadorDeString
    S�ntese
    Objetivo : Inserir uma string e gerenci�-la;
    Entrada : Um conjunto de caracteres;
    Sa�da : Uma string.                                     */


//Declara��o de bibliotecas.
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Declara��o de fun��es.
void Menu();
void caso1(char texto[]);
void caso2(char texto[]);
void caso3(char texto[]);
void caso4(char texto[]);
void Linha();
void caso5(char texto[]);


//Fun��o principal.
int main(){
    setlocale(LC_ALL,"Portuguese");
    char texto[10]={'\0'}, opcao;

    do{
        Menu();
        printf("Escolha uma op��o: ");
        scanf("%c", &opcao);
        setbuf(stdin, NULL);
        system("cls || clear");

        //Menu de op��es a serem executadas.
        switch (opcao){
            case '1':
                caso1(texto);
            break;
            case '2':
                if (texto[0] == '\0'){
                    printf("\n\n\7                                      N�o h� string para imprimir.");
                }
                else{
                    caso2(texto);
                }
            break;
            case '3':
                if (texto[0] == '\0'){
                    printf("\n\n\7                                      N�o h� string para imprimir.");
                }
                else{
                    caso3(texto);
                }
            break;
            case '4':
                if (texto[0] == '\0'){
                    printf("\n\n\7                                      N�o h� string para validar.");
                }
                else{
                    caso4(texto);
                }
            break;
            case '5':
                if (texto[0] == '\0'){
                    printf("\n\n\7                                      N�o h� string para modificar.");
                }
                else{
                    caso5(texto);
                }
            break;
            case '6':
                printf("\n\n                                      Tchauuuu");
            break;
            default:
                printf("\n\n\7                                      Op��o inv�lida.");
            break;
        }
    }while (opcao != 6);

    return 0;
}


//Fun��o que imprime o menu de op��es.
void Menu(){
    printf("\n\n1 - Testar string");
    printf("\n2 - Imprimir string");
    printf("\n3 - Imprimir de tr�s pra frente");
    printf("\n4 - Validar string");
    printf("\n5 - Modificar string");
    printf("\n6 - Sair\n\n");
}


//Fun��o que l� a string.
void caso1(char texto[]){
    printf("Digite a string: ");
    scanf("%[^\n]", texto);
    getchar();
    system("cls || clear");
}


//Fun��o que imprime a string e a quantidade de caracteres.
void caso2(char texto[]){
    int tam;

    tam=strlen(texto);

    printf("\n                                      A string �: |%s|, %d caracteres", texto,tam);
}


//Fun��o que imprime a string de tr�s pra frente.
void caso3(char texto[]){
    printf("\n                                      |%s| de tr�s pra frente �: ", texto);
    strrev(texto);
    printf("|%s|", texto);
    strrev(texto);
}


//Fun��o que confere se a string � v�lida.
void caso4(char texto[]){
    printf("\nPara a string ser v�lida, tem que seguir os crit�rios:");
    printf("\n\n- A string deve ter, pelo menos, 10 caracteres;");
    printf("\n- A string n�o pode conter n�meros ou caracteres especiais, apenas letras min�sculas;");
    printf("\n- A primeira letra da string sempre deve ser uma vogal.\n\n");

    int tam2, inv=0;

    tam2=strlen(texto);

    for(int temp=0; temp < tam2; temp++){
        //Confere se tem algum n�mero na posi��o atual.
        if(isdigit(texto[temp])){
            inv++;
        }
        //Confere se tem algum espa�o na posi��o atual.
        if(isspace(texto[temp])){
            inv++;
        }
        //Confere se tem algum caractere especial na posi��o atual.
        if(ispunct(texto[temp])){
            inv++;
        }
        //Confere se tem alguma letra mai�scula na posi��o atual.
        if(isupper(texto[temp])){
            inv++;
        }
    }

    char vogal[6]={'a','e','i','o','u'};
    int vog=0;

    //Confere se tem alguma vogal na primeira posi��o.
    for (int temp2=0; temp2 < 6; temp2++){
        if (texto[0] == vogal[temp2]){
            vog++;
        }
    }

    Linha();

    if(tam2 < 10 || inv > 0 || vog == 0){
        printf("\n\n                                      A string |%s| n�o � v�lida.", texto);
    }
    else{
        printf("\n\n                                      A string |%s| � v�lida.", texto);
    }
}

//Fun��o para imprimir uma linha de caracteres.
void Linha(){
    for(int temp3=0; temp3 <= 119; temp3++){
        printf("~");
    }
}


//Fun��o para substituir um caractere da string.
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

    //Confere se o caractere "antigo" est� na string. Se sim, ele substitu�do pelo caractere "novo".
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
        printf("\n\n\7                                      Caractere n�o encontrado na string. |%s|", texto);
    }
}
