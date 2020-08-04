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
	
}
