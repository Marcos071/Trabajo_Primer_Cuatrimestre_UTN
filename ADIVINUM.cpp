#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void separar(int Numero, int &d1, int &d2, int &d3, int &d4);

main()
{
	int NumeroAleatorio, d1, d2, d3, d4;
	int NumeroIngresado, n1, n2, n3, n4;
	int NumPosCorrect, NumPosIncorrect, A=0;
	int NumeroCorrecto=0, Puntaje=10;
	
	srand(time(NULL));
	
	do{
	
		NumeroAleatorio = 1000 + rand()% (9999-1000+1);	
		
		separar(NumeroAleatorio, d1, d2, d3, d4);
			
	}while(d1 == d2 || d1 == d3 || d1 == d4 || d2 == d3 || d2 == d4 || d3 == d4 ||
			d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0);
			printf("\nJugaremos con numeros de 4 cifras");
	printf("\nIngrese un numero de 4 cifras (el numero secreto no lleva 0 ni digitos repetidos)");
	
	for(int i=0; i<10; i++)
	{
		printf("\nIntento %d: ", i+1);
		scanf("%d", &NumeroIngresado);
		
		if(NumeroIngresado > 1000 && NumeroIngresado < 9999)
		{
			separar(NumeroIngresado, n1, n2, n3, n4);
			A = verificar(NumeroIngresado, n1, n2, n3, n4, d1, d2, d3, d4, NumPosCorrect, 
			NumPosIncorrect, NumeroCorrecto);
			if(A == 0) i= i-1;
			else
			{
				printf("\nCantidad de numeros en la posicion correcta: %d", NumPosCorrect);
				printf("\nCantidad de numeros en la posicion incorrecta: %d", NumPosIncorrect);
				NumPosCorrect=0;
				NumPosIncorrect=0;
			}
		}
		else
		{
			printf("\nEl numero debe tener 4 cifras. Vuelva a intentarlo!");
			i= i-1;
		} 
		
		if (NumeroCorrecto == 1)
		{
			printf("\nFelicitaciones! Acertaste el numero. Puntaje obtenido = %d", Puntaje);
			return 0;
		}
		
		Puntaje-=1;
	}
	
	printf("El numero secreto era %d, %d, %d, %d", d1, d2, d3, d4);
}

}

void separar(int Numero, int &d1, int &d2, int &d3, int &d4)
{
	d4 = Numero % 10;
	Numero = (Numero - d4) / 10;
	d3 = Numero % 10;
	Numero = (Numero - d3) / 10;
	d2 = Numero % 10;
	Numero = (Numero - d2) / 10;
	d1 = Numero;
}




