
#include <string.h>

#include <conio.h>

#include <stdio.h>

#include <stdlib.h>

#include <locale.h>


//Definimos o dado heterogêneo que representará CARRO
typedef struct carro

{

   int cod;

   char marca [20];

   char modelo [20];

   int ano;

   char placa[10];

} Carro;

 
// Definimos o tipo e tamanho do ARRAY.
Carro car[10];

// Struct que nos auxiliará a cadastrar carro por ordem crescente do ano
Carro car_aux[10];
 
int main(int argc, char** argv) {

    setlocale(LC_ALL,"portuguese");

	// Variáveis a serem manipuladas nos Loops.
    int i;
    int operacao;
    int ano;
    int j;
    char modelo[20];
    
    int x;
    int y;

    j=0;
    ano=0;
    i=0;
    car[i].cod = 0;

    // Inicializando valores padrão
    strcpy(car[i].marca,"NULL");
    strcpy(car[i].modelo,"NULL");
    strcpy(car[i].placa,"NULL");
    car[i].ano = 0;

    // Loop do MENU. Esse menu de opção sempre irá aparecer enquanto o usuário não escolher sair.
    do {

        printf("\n Operações:");
        printf("\n 1. Cadastrar veículo");
        printf("\n 2. Listar Veículo");
        printf("\n 3. Pesquisar um modelo");
        printf("\n 4. Mostrar a partir de um ano");
        printf("\n 5. Sair");

        printf("\n \n Escolha uma opção: ");

        scanf("%d",&operacao);

		// a partir da escolha do usuário, podemos enfim efetuar as operações propostas.
        switch(operacao){

            case 1:
				if (car[i].cod<=9) {

                    car[i].cod=i;

                	printf("\n Marca do veículo:");

                    scanf("%s",&car[i].marca);

                	printf("\n Modelo do veículo:");

                    scanf("%s",&car[i].modelo);

                    printf("\n Placa do veículo:");

                    scanf("%s",&car[i].placa);

                    printf("\n Ano do veículo:");

                    scanf("%d",&car[i].ano);

                    i=i+1;
                    
                    // Verifica se o índice é maior que zero e, consequentemente, se o array de carros tem mais de uma posição
                    if(i > 0){
                    	int count;
                    	int count2;
                    	
                    	// loops pegam um em um e vai comparando
						for(count = 0; count < i; count++){
							for(count2 = 0; count2 < i; count2++){
								if(car[count].ano < car[count2].ano){
									car_aux[0] = car[count]; 
									
									car[count] = car[count2];
									car[count2] = car_aux[0];
								}	
							}
						}
					}
                    
                } else {
                    printf("\n Não é possível cadastrar mais de 10!");
                }

                break;

            case 2:
            	
				for(x = 0; x < i; x++) {

                    printf("\n A marca do veículo é: %s",car[x].marca);

                    printf("\n O modelo do veículo é: %s",car[x].modelo);

                	printf("\n O ano do veículo é: %d",car[x].ano);

                    printf("\n A placa do veículo é: %s",car[x].placa);

                    printf("\n\n =================================== \n \n");

            	}

                break;

    		case 3:

                printf("\n   Modelo para pesquisar:");

                scanf("%s",&modelo);

            	for (x=0; x<i; x++) {

                	if (strcmp(car[x].modelo,strlwr(modelo)) == 0) {

                        printf("\n A marca do veículo é: %s",car[x].marca);

                        printf("\n O modelo do veículo é: %s",car[x].modelo);

                        printf("\n O ano do veículo é: %d",car[x].ano);

                        printf("\n A placa do veículo é: %s",car[x].placa);

                    	printf("\n\n =================================== \n \n");

                        j++;

                	}
				}

                if (j==0) {

                    printf("\n Não existe o modelo %s \n\n",modelo);

                } else {

                	j=0;

        		}

                break;

                                                                              

            case 4:

                printf("\n     Ano do veículo para procurarmos:");

                scanf("%d",&ano);

                for (x=0; x<i; x++) {

                	if (car[x].ano == ano) {

                        printf("\n A marca do veículo é: %s",car[x].marca);

                    	printf("\n O modelo do veículo é: %s",car[x].modelo);

                    	printf("\n O ano do veículo é: %d",car[x].ano);

                        printf("\n A placa do veículo é: %s",car[x].placa);

                    	printf("\n\n =================================== \n \n");

                        j++;

                    }
				}

                if (j==0) {
                	printf("\n NÃO FOI ENCONTRADO VEÍCULOS DE %d \n\n",ano);
                } else {
                    j=0;
                }

                break;

        	default:
				printf("\n Opção não existe");

                break;

        }
	} while (operacao !=5 && i<=9);

    if (i==9) {

        printf("\n \n LIMITE DE VEÍCULOS ALCANÇADO! \n \n \n");

    }

    for (y=0; y<i; y++) {

        printf("\n A marca do veículo é: %s",car[y].marca);

        printf("\n O modelo do veículo é: %s",car[y].modelo);

        printf("\n O ano do veículo é: %d",car[y].ano);

        printf("\n A placa do veículo é: %s",car[y].placa);

        printf("\n\n =================================== \n \n");

    }

               
	return 0;

}