#include <stdio.h>
#include <stdlib.h>

void llenarGuiones(char b[], int cant);
void visualizarPalabra(char b[], int cant);
int jugar(char a[], char b[], int cant, char letra, int &intentos);

main(){
	int n, intentos = 0;
	char x;
	
	printf("ingrese cuantas letras tiene la palabra\n");
	scanf("%d", &n);
	int faltan = n;
	char palabra[n];
	char guiones[n];
	
	for(int i=0; i<n; i++){
		_flushall();
		printf("ingrese la letra %d: \n", i+1);
		scanf("%c", &palabra[i]);
		if (palabra[i] >= 'a' && palabra[i]<='z') palabra[i] = palabra[i] - 32;
	}
	llenarGuiones(guiones, n);	
	while (intentos < 10){
		system("cls");	
		visualizarPalabra(guiones, n);
		_flushall();
		printf("\ningrese una letra para adivinar la palabra: (intento n: %d)\n", intentos+1);
		scanf("%c", &x);
		if (x >= 'a' && x<='z') x = x - 32;
		if (x<'A' || x > 'Z'){
		  printf("caracter no valido\n");
		  system("pause");
		} 
		else faltan = jugar(palabra, guiones, n, x, intentos);
		if (faltan == 0){
			printf("Usted a ganado!!!!");
			break;
		}
	}
	
	if (intentos == 10) printf("usted perdio: 0 puntos\n");
	else printf("%d puntos", 50-(2*intentos));
}


void llenarGuiones(char b[], int cant){
	for (int i=0; i<cant; i++){
		b[i] = '_';
	}
}

void visualizarPalabra(char b[], int cant){
	for (int i=0; i<cant; i++){
		printf("%c ", b[i]);
	}
}

int jugar(char a[], char b[], int cant, char letra, int &intentos){
	int restan = 0;
	bool acerto = false;
	for(int i=0; i< cant; i++){
		if (a[i] == letra){
			b[i] = letra;	
			acerto = true;
		} 
		if (b[i] == '_') restan++;
	}
	if (!acerto) intentos++;
	return restan;
}
