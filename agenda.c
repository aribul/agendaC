#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char inicial;
	int dni;
	int edad;
} s_persona;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int cant_personas = 10, i, max_edad = 0, sum_25 = 0;
	char iniciar_busqueda;
	int dni_busqueda;
	char nueva_busqueda;
	int encontrado = 0;
	s_persona vec_persona[cant_personas];
	
	printf("Ingrese 10 personas a su agenda \n");
	
	for(i=0 ; i < cant_personas ; i=i+1){
			
		
		printf("Ingrese inicial de la persona N° %d \n", i+1);
		scanf(" %c", &vec_persona[i].inicial);
			
		do {
			printf("Ingrese dni de la persona N°%d (debe ser mayor a 0) \n", i+1);
			scanf("%d", &vec_persona[i].dni);
		} while (vec_persona[i].dni <= 0);
		
		
		do {
			printf("Ingrese edad de la persona N°%d (debe ser igual o mayor a 0) \n", i+1);
			scanf("%d", &vec_persona[i].edad);
		} while (vec_persona[i].dni < 0);
		
		
		if(vec_persona[i].edad > max_edad){ //calcula la persona mas grande
			
			max_edad = vec_persona[i].edad;
			
		}
		
		if(vec_persona[i].edad > 25){ //calcula la cantidad de personas mayores a 25 años
			
			sum_25 = sum_25 + 1;
			
		}
		
	}
	
	
	printf("La persona mas grande de la agenda tiene %i anios\n", max_edad);
	printf("La cantidad de personas con mas de 25 anios en la agendad son: %i \n", sum_25);
	
	//busqueda por dni
	printf("Desea iniciar una busqueda en su agenda? Ingrese S para iniciar o N para terminar \n");
	scanf(" %c", &iniciar_busqueda);
	
	while (iniciar_busqueda == 's' || iniciar_busqueda == 'S'){
		 	
			printf("Ingrese el DNI a buscar \n");
			encontrado = 0;
		 	scanf("%d", &dni_busqueda);
		 	
		 	for(i=0 ; i < cant_personas ; i=i+1){
		 		
		 		if(dni_busqueda == vec_persona[i].dni){
		 			
		 			printf("Los datos de la persona buscada son: \n");
		 			printf("Inicial: %c \n", vec_persona[i].inicial);
		 			printf("DNI: %i \n", vec_persona[i].dni);
		 			printf("Edad: %i \n", vec_persona[i].edad);
		 			encontrado = 1;
		 			break;
		 					
				}
				
			}
			if(encontrado == 0){
				printf("EL DNI INGRESADO NO FUE ENCONTRADO \n");
			}
			printf("Desea realizar otra busqueda? \n");
			scanf(" %c", &iniciar_busqueda);		
		}			
	
	return 0;
}
