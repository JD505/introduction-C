#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	int pessoa1, pessoa2, pessoa3, pessoa4, pessoa5, soma=0; //declaração de variaveis
	
	printf("=============================Idades =======================\n");	
	
	printf("Insira a idade da primeira pessoa: \n");    //recolher as idades introduzidas pelo utilizador
	scanf("%d", &pessoa1);
	
	printf("Insira a idade da segunda pessoa: \n");
	scanf("%d", &pessoa2);
	
	printf("Insira a idade da terceira pessoa: \n");
	scanf("%d", &pessoa3);
	
	printf("Insira a idade da quarta pessoa: \n");
	scanf("%d", &pessoa4);
	
	printf("Insira a idade da quinta pessoa: \n");
	scanf("%d", &pessoa5);


	if (pessoa1>20)        //recolher as idades das pessoas com mais de 20 anos
		soma =soma+ pessoa1;
		
		if (pessoa2>20){
		soma = pessoa2+soma;}
		
		if (pessoa3>20){
		soma= pessoa3+soma;}
		
		if (pessoa4>20){
		soma= pessoa4+soma;}
		
		if (pessoa5>20){
		soma= pessoa5+soma;}

	
	 if(soma<=0) {           // condição caso não haja maiores de 20 
	printf("\n Nao existem pessoas com mais de 20 anos"); // mostra que nao existem pessoas com mais de 20 anos
	}

	else
	printf("\n Soma das idades superiores a 20 anos: %d", soma);	//mostrar o valor da soma das idades superiores a 21 anos
	
	
	printf(" \n Media das idades: %.2f", (pessoa1+pessoa2+pessoa3+pessoa4+pessoa5)/(float)5);	//mostrar a media das idades das 5 pessoas

	return 0;
}

