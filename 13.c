#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef enum bool{
    false,
    true,
}bool;

typedef struct data{
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
    int segundos;
}Data;

typedef struct leitura{
	float ruido;
	Data data;
	int codigoLeitura;
}Leitura;

typedef struct Sensor{
    int codigoSensor;
	char zona[20];
    bool ativo;
    Leitura leituras[20];
    int	numeroLeituras;
}Sensor;

int insereSensor(Sensor *Sensores, int n){
	
	Sensor s;
	
	printf("============Inserir Novos sensores=================== \n Para sair insira stop na zona \n\n");
	printf(" Zonas : \n Norte - Sul - Este - Oeste \n\n");
	
	printf(" Insira a Zona do sensor : ");
    scanf("%s", s.zona);
    
    while(stricmp(s.zona, "stop")!=0){
    	
    	//sensor ativo
    	s.ativo= true;
    	
    	s.numeroLeituras=0;
    	
    	//codigo sensor
    	s.codigoSensor=n+1;
    	
		printf(" Codigo do sensor inserido: %d \n", s.codigoSensor);
    	printf(" ============ Novo sensor inserido! =================== \n");
    
    	//copia para a posiçao do array
		Sensores[n]=s;
		
		//incrementa
		n++;
		
		printf("\n Insira a Zona do sensor : ");
    	scanf("%s", s.zona);   	   	
	}
	
	return n;
}
void eliminaSensor(Sensor *Sensores, int n){
	int i, elimina;
	
	printf(" \n==========Eliminar Sensores======= \n");
	
	for(i=0;i<n;i++){
	
		if(Sensores[i].ativo==1){
		printf(" \n==========Sensor codigo %d======= \n", Sensores[i].codigoSensor);
		printf(" Zona do sensor %s \n", Sensores[i].zona);
		}
	}
	
	printf(" \n Insira o codigo do sensor que deseja eliminar:");
	scanf("%d", &elimina);
		
	Sensores[elimina-1].ativo= false;
	printf(" Sensor codigo %d desativo",Sensores[elimina-1].codigoSensor);
	
}
int recolheLeituras(Sensor *Sensores, int numeroLeiturasT,int numSensores){
	int i,n=0, codigo;
	Sensor s;
	
	printf(" ---------------------Inserir Leituras----------------- \n Quando concluido inserir -1\n");
	for(i=0;i<numSensores;i++){
		
		if(Sensores[i].ativo==1){
		printf(" \n==========Sensor codigo %d======= \n", Sensores[i].codigoSensor);
		printf(" Zona do sensor %s \n", Sensores[i].zona);
		}
	}
	
	printf("\n Insira o Codigo do sensor que efectou a leitura : ");
    scanf("%d", &codigo);
    
    while(codigo !=-1 ){	
     s=Sensores[codigo-1];
    
    printf(" Insira o ruido registado : ");
    scanf("%f", &s.leituras[Sensores[codigo-1].numeroLeituras].ruido);    
	printf(" Insira o dia : ");
    scanf("%d", &s.leituras[Sensores[codigo-1].numeroLeituras].data.dia);    
    printf(" Insira o mes : ");
    scanf("%d", &s.leituras[Sensores[codigo-1].numeroLeituras].data.mes);    
    printf(" Insira o ano : ");
    scanf("%d", &s.leituras[Sensores[codigo-1].numeroLeituras].data.ano);
	printf(" Insira a hora : ");
    scanf("%d", &s.leituras[Sensores[codigo-1].numeroLeituras].data.hora);
    printf(" Insira os minutos: ");
    scanf("%d", &s.leituras[Sensores[codigo-1].numeroLeituras].data.minutos);
    printf(" Insira os segundos: ");
    scanf("%d", &s.leituras[Sensores[codigo-1].numeroLeituras].data.segundos);
    
    
    
    s.leituras[Sensores[codigo-1].numeroLeituras].codigoLeitura=n+1;
    printf(" Leitura inserida codigo da leitura : %d \n", s.leituras[Sensores[codigo-1].numeroLeituras].codigoLeitura);
    
    s.numeroLeituras=Sensores[codigo-1].numeroLeituras+1;
    
    numeroLeiturasT++;
  	Sensores[codigo-1]=s;
	
	n++;
		
	printf("\n Insira o Codigo do sensor que efectou a leitura : ");
    scanf("%d", &codigo);	
	}
	
	return numeroLeiturasT;
}
void mostraLeituras(Sensor *Sensores, int n, int numeroLeiturasT){
	int i,j;
	
	printf("============Leituras==================="); 
	
	if(numeroLeiturasT>0){		
		for(i=0; i<=n;i++){

			for(j=0;j<Sensores[i].numeroLeituras;j++){
				
				if(Sensores[i].ativo==1){
					
				printf("\n Sensor: %d \n",Sensores[i].codigoSensor);
				printf(" Zona:  %s\n",Sensores[i].zona);								
				printf(" Codigo da leitura: %d Ruido %.3f\n",Sensores[i].leituras[j].codigoLeitura,Sensores[i].leituras[j].ruido);
				printf(" %d/%d/%d  ", Sensores[i].leituras[j].data.dia,Sensores[i].leituras[j].data.mes, Sensores[i].leituras[j].data.ano);
				printf("  %d:%d:%d ", Sensores[i].leituras[j].data.hora,Sensores[i].leituras[j].data.minutos,Sensores[i].leituras[j].data.segundos);
				printf("\n=======================================\n"); 
				}
			}
		}
	}
	
	else{
		printf("\n=========Nao foram intruduzidas leituras======= ");
	}
}
void leitura_minima_maxima_media(Sensor *Sensores, int n, int numeroLeiturasT){
	int	i,j,contador=0;
	float leituraMin=999, leituraMax=0, soma,media;
	
	printf("============Leituras==================="); 	
	
	if(numeroLeiturasT>0){		
		for(i=0; i<=n;i++){

			for(j=0;j<Sensores[i].numeroLeituras;j++){
				
				if(Sensores[i].ativo==1){
		
				contador++;	
				soma=soma+Sensores[i].leituras[j].ruido;
				
				if(Sensores[i].leituras[j].ruido<leituraMin){
					leituraMin=Sensores[i].leituras[j].ruido;
				}
				if(Sensores[i].leituras[j].ruido>leituraMax){
					leituraMax=Sensores[i].leituras[j].ruido;
				}
				
				}
			}
		}
		media=(float)soma/contador;
		printf("\n Leitura Minima: %.3f\n Leitura Maxima: %.3f\n Media Leituras da biblioteca: %.3f\n",leituraMin, leituraMax,media);
	}
	else{
		printf("\n=========Nao foram intruduzidas leituras======= ");
	}
}
void ordenar(float *ruido,int k){

	float aux;
	int i,j;
	
	for (i=0; i<k; i++){
        for (j=i+1; j<k; j++){
            
            if (ruido[i]<ruido[j]){
                aux = ruido[i];
                ruido[i] = ruido[j];
                ruido[j] = aux;
            }
        }
    }
}
void pesquisar(Sensor *Sensores, int n, int numeroLeiturasT){
	int i,j,k=0,l, dia, mes, ano;
	char zona[20];
	float ruido[20];

	printf("============Pesquisar==================="); 		
	if(numeroLeiturasT>0){
		
		printf("\n Insira a zona pertendida: ");
		scanf("%s", zona);
		printf(" Insira o dia pretendido: ");
		scanf("%d", &dia);	
		printf(" Insira o mes pretendido: ");
		scanf("%d", &mes);	
		printf(" Insira o ano pretendido: ");
		scanf("%d", &ano);	
			
		for(i=0; i<=n;i++){
			
			if(strcmp(zona, Sensores[i].zona)==0){
				for(j=0;j<Sensores[i].numeroLeituras;j++){
				
					if(Sensores[i].ativo==1){
				
						if(dia == Sensores[i].leituras[j].data.dia && mes == Sensores[i].leituras[j].data.mes && ano ==Sensores[i].leituras[j].data.ano){
							ruido[k]=Sensores[i].leituras[j].ruido;
							k++;
						}
					}
				}	
			
			}
		}
		
		ordenar(ruido,k);
		
		for(l=0;l<k;l++){
			printf(" Leitura de ruido: %f \n",ruido[l]);
		}
		
				
	}
	
	else{
		printf("\n=========Nao foram intruduzidas leituras======= ");
	}
}
void mediaSensor(Sensor *Sensores, int n, int numeroLeiturasT){
	
	int i,j, num_sul=0,num_norte=0, num_este=0, num_oeste=0;
	float leitura_sul, leitura_norte=0, leitura_este, leitura_oeste;
	
	printf("==================Media por Zona===========");
		
	if(numeroLeiturasT>0){		
		for(i=0; i<=n;i++){

			for(j=0;j<Sensores[i].numeroLeituras;j++){
				if(Sensores[i].ativo==1){
	
					if(strcmp(Sensores[i].zona,"sul")==0){
						leitura_sul+=Sensores[i].leituras[j].ruido;
						num_sul++;
					}
					else if(strcmp(Sensores[i].zona,"norte")==0){
						leitura_norte+=Sensores[i].leituras[j].ruido;
						num_norte++;
					}
					else if(strcmp(Sensores[i].zona,"este")==0){
						leitura_este+=Sensores[i].leituras[j].ruido;
						num_este++;
					}
					else if(strcmp(Sensores[i].zona,"oeste")==0){
						leitura_oeste+=Sensores[i].leituras[j].ruido;
						num_oeste++;
					}
				}
			}
				
		}
		if(num_norte>0){
		printf("\n Media Zona Norte: %.3f",leitura_norte/(float)num_norte);	
		}
		if(num_sul>0){
		printf("\n Media Zona Sul: %.3f",leitura_sul/(float)num_sul);	
		}
		if(num_este>0){
		printf("\n Media Zona Este: %.3f",leitura_este/(float)num_este);	
		}
		if(num_oeste>0){
		printf("\n Media Zona Oeste: %.3f",leitura_oeste/(float)num_oeste);	
		}
	}
	else{
		printf(" Nao foram intruduzidas leituras");
	}
}
int main(int argc, char *argv[]) {
	int n=0, menu, numLeiturasTotal=0;
	Sensor Sensores[50];

do{
	
	system("cls");
	
	puts("=======================================================");	
	puts("--------------------    SENSORES   --------------------");
	puts(" Inserir sensor:----------1");
	puts(" Eliminar sensor:---------2");
	puts(" Inserir Leituras:--------3");
	puts(" Lista Leituras:----------4");
	puts(" Estatisticas Leituras:---5");
	puts(" Pesquisar Leituras:------6");
	puts(" Media por Zona:----------7");
	puts(" Sair:--------------------8");
	puts("=======================================================");
	puts("=======================================================");

	printf(" Insira uma opcao: ");
	scanf("%d", &menu);
	
	switch(menu){
		case 1:
			system("cls");
			n=insereSensor(Sensores,n);
			break;
			
		case 2:
			system("cls");
			eliminaSensor(Sensores, n);
			break;
						
		case 3:
			system("cls");
			numLeiturasTotal=recolheLeituras(Sensores, numLeiturasTotal,n);
			break;
			
		case 4: 
			system("cls");
			mostraLeituras(Sensores, n,numLeiturasTotal);
			getchar();	
			break;
			
		case 5:
			system("cls");
			leitura_minima_maxima_media(Sensores,n, numLeiturasTotal);
			getchar();
			break;
			
		case 6:
			system("cls");
			pesquisar(Sensores,n,numLeiturasTotal);
			getchar();
			break;
			
		case 7:
			system("cls");
			mediaSensor(Sensores,n,numLeiturasTotal);
			getchar();
			break;	
			}
		
		getchar();		
	}while(menu !=8);

	return 0;
}
