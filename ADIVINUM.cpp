#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void separar(int Numero, int &d1, int &d2, int &d3, int &d4);

main()
{
	int NumeroAleatorio, d1, d2, d3, d4;
	
	srand(time(NULL));
	
	do{
	
		NumeroAleatorio = 1000 + rand()% (9999-1000+1);	
		
		separar(NumeroAleatorio, d1, d2, d3, d4);
			
	}while(d1 == d2 || d1 == d3 || d1 == d4 || d2 == d3 || d2 == d4 || d3 == d4 ||
			d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0);
			
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




