#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	double saldomed, juros; //declaração de variaveis
	int anos, codigo;
	
	printf("===================Sistema Bancario======================\n");
	
	printf("insira o saldo medio anual da sua conta:  "); //recolha de dados
	scanf("%lf", &saldomed);
	
	printf("insira o numero de anos da conta: ");
	scanf("%d", &anos);
	
	printf("insira o tipo de conta inserindo o condigo respectivo: \n 1 - Empresarial Gold \n 2 - Empresarial Silver \n 3 - Particular Gold \n 4 - Particular Silver \n 5 - Outros \n ");
	scanf("%d", &codigo);

	if(codigo!= 1 && codigo!=2 && codigo!=3 && codigo!=4 && codigo!=5){ //condição para verificação do valor do codigo
		printf("Codigo errado\a");
		return 0; }
		
	else if(codigo==1) //seleção do codigo respetivo para o tipo de conta
		printf("\tPor ser uma conta do tipo Empresarial Gold recebera um premio de 150 Euros\n \n");
	else if(codigo==2)
		printf("\tPor ser uma conta do tipo Empresarial Silver recebera um premio de 100 Euros\n \n");
	else if(codigo==3)
		printf("\tPor ser uma conta do tipo Particular Gold receberá um premio de 75 Euros\n \n ");
	else if(codigo==4)
		printf("\tPor ser uma conta do tipo Particular Silver recebera um premio de 40 Euros\n \n");
	else if(codigo==5)	
		printf("\tPor ser uma conta do tipo Outros nao tem direito a premio\n");
	
		if(saldomed>=100000 && anos>=10){ //condição para selecionar conta com direito a bónus de juros 
		
		juros=saldomed*0.01; //calculo do 1% de juros
		printf("\tPor ter um saldo medido anual superior a 100 000 Euros e possuir a conta a mais de 10 anos \n\tTera direito a um bonus em juros de 1 por cento, recebendo assim o bunos de %.1lf euros \n\n", juros);
}
	else {
		printf("\tNao recebera o bonus nos juros \n \n");
	}	
	
	printf("\tA sua conta tem o saldo medio de %.1lf euros e foi criada a %d anos", saldomed, anos); //mostra os dados da conta
	return 0;
}
