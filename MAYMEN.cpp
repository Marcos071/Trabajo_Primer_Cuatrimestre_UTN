#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int NumeroSecreto, NumeroIngresado, Puntaje=10;
	int inicio=1, limite=999;
	
	srand(time(NULL));
	NumeroSecreto = 1+rand()%(999-1+1);
	
	printf("\t\t\tEste juego consiste en adivinar un numero que se genera automaticamente");
	printf("\n\n* Tiene 10 intentos *");
	
	printf("\n\nPor favor ingrese un numero del 1 al 999: ");
		
		
		for(int i=0; i<10; i++)
		{
			
			
			printf("\nIntento %d: ", i+1);
			scanf("%d", &NumeroIngresado);
			if(NumeroIngresado>0 && NumeroIngresado<1000)
			{
				if (NumeroSecreto < NumeroIngresado)
				{
					printf("El numero secreto es menor y se encuentra entre %d y %d", inicio, NumeroIngresado-1);
					limite=NumeroIngresado-1;
				}
			
				if (NumeroSecreto > NumeroIngresado)
				{
					printf("El numero secreto es mayor y se encuentra entre %d y %d", NumeroIngresado+1, limite);
					inicio=NumeroIngresado+1;
				}
				
				if(NumeroSecreto != NumeroIngresado)
				{
					Puntaje= Puntaje-1;
				}
			
				if(NumeroSecreto == NumeroIngresado)
				{
					printf("\nAcertaste!");
					printf("Puntaje obtenido : %d", Puntaje);
					return 0;
				}
			}
			else
			printf("\nEl numero debe estar entre 1 y 999");
		}
		
		if(NumeroSecreto != NumeroIngresado)
		{
			printf("\n\nPerdiste");
			printf("\n\nEl numero secreto era: %d", NumeroSecreto);
		}

}









