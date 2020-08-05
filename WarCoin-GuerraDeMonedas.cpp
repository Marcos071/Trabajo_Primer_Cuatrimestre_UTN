#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{
	int CantMinima, CantMaxima;
	int NumeroAleatorio, Comienza;
	
	printf("\nPor favor ingrese la cantidad minima de monedas que se pueden sacar: ");
	scanf("%d", &CantMinima);
	printf("\nPor favor ingrese la cantidad maxima de monedas que se pueden sacar: ");
	scanf("%d", &CantMaxima);
	
	srand(time(NULL));	
	NumeroAleatorio= 10 + rand()%(50-10+1);
	
	printf("La cantidad inicial de monedas en la pila es: %d", NumeroAleatorio); 
	
	Comienza= 1 + rand()%(2-1+1); 
	
	if(Comienza==1)		
	{
		printf("\nInicia la partida el usuario"); 	
	}
	if(Comienza==2)		
	{
		printf("\nInicia la partida la computadora");
	}
	do{
		
		if(Comienza==1)
		{
			printf("\nIngresa la cantidad de monedas que deseas sacar:");
			scanf("%d", &Usuario);
			
			if(Usuario >= CantMinima && Usuario<=CantMaxima)
			{
				NumeroAleatorio= NumeroAleatorio-Usuario;
				printf("\nQuedan %d monedas", NumeroAleatorio);
				auxiliar=2;
			}
			else 
			{
				printf("\nERROR: se deben sacar entre %d y %d monedas. Volver a intentar!!!!", CantMinima, CantMaxima);
				auxiliar=1;
			}
			
			if(NumeroAleatorio<CantMinima)
			{
				printf("\nEL USUARIO GANA!!");
				printf("\nPuntaje obtenido: 5");
			}
		}
					
	}while(NumeroAleatorio>=CantMinima);

}
