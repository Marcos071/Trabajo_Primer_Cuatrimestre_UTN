#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int CantMinima, CantMaxima;
	int NumeroAleatorio, Comienza;
	int Usuario, auxiliar, Computadora;
	
	printf("\t\t\t\t\tWarCoin - Guerra de Monedas");
	printf("\n\t\t\t\t\n----------------------------");
	
	printf("\n\nPor favor ingrese la cantidad minima de monedas que se pueden sacar: ");
	scanf("%d", &CantMinima);
	printf("\nPor favor ingrese la cantidad maxima de monedas que se pueden sacar: ");
	scanf("%d", &CantMaxima);
	
	srand(time(NULL));	
	NumeroAleatorio= 10 + rand()%(50-10+1);
	
	printf("\nLa cantidad inicial de monedas en la pila es: %d", NumeroAleatorio);
	printf("\n---------------------------------------------------"); 
	
	Comienza= 1 + rand()%(2-1+1); 
	
	if(Comienza==1)		
	{
		printf("\n\nInicia la partida el usuario"); 	
	}
	
	if(Comienza==2)		
	{
		printf("\n\nInicia la partida la computadora");
	}
	
	do{
		
		if(Comienza==1)
		{
			printf("\n\nIngresa la cantidad de monedas que deseas sacar: ");
			scanf("%d", &Usuario);
			
			if(Usuario >= CantMinima && Usuario <=CantMaxima)
			{
				NumeroAleatorio= NumeroAleatorio-Usuario;
				printf("\n\nQuedan %d monedas", NumeroAleatorio);
				auxiliar=2;
			}
			else 
			{
				printf("\n\nERROR: se deben sacar entre %d y %d monedas. Volver a intentar!!!!", CantMinima, CantMaxima);
				auxiliar=1;
			}
			
			if(NumeroAleatorio<CantMinima)
			{
				printf("\n\nEL USUARIO GANA!!");
				printf("\n\nPuntaje obtenido: 5");
			}

		}
		
		if(Comienza==2)
		{
			Computadora= CantMinima + rand()%(CantMaxima-CantMinima+1);
		
			NumeroAleatorio= NumeroAleatorio-Computadora;
			
			auxiliar=1;
			
			printf("\n\nLa computadora saco %d monedas", Computadora);
			printf("\n\nQuedan %d monedas", NumeroAleatorio);
			
			if(NumeroAleatorio<CantMinima)
			{
				printf("\n\nLA COMPUTADORA GANA!!");
				printf("\n\nPuntaje obtenido: 0");
			}
		}
		
		Comienza=auxiliar;
					
	}while(NumeroAleatorio>=CantMinima);
	
	printf("\n\n");
	system("pause");

}




