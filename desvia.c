/*Escriba un programa en C que calcule la desviacion estandar de una serie de
numeros reales que finaliza con el ingreso del valor cero.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
	float dato;
	struct node* sgte;
}*nodo,TipoDato;

typedef struct{
	nodo primero;
	nodo ultimo;
	float longitud;
}*cola,tipoCola;

cola crearCola(){
	cola queue=(cola)(malloc(sizeof(tipoCola)));
	queue->primero=NULL;
	queue->ultimo=NULL;
	queue->longitud=0;
	return queue;
}

nodo crearnodo(float valor){
	nodo elemento=(nodo)malloc(sizeof(nodo));
	elemento -> dato=valor;
	elemento -> sgte=NULL;
	return elemento;
}

void encolar(float valor,cola queue){
	nodo nuevo=crearnodo(valor);
	if(queue->primero==NULL && queue->ultimo==NULL){
		queue->primero=nuevo;
		queue->ultimo=nuevo;
		nuevo->sgte=NULL;
	}else{
		queue->ultimo->sgte=nuevo;
		queue->ultimo=nuevo;
		nuevo->sgte=NULL;
	}
	queue->longitud+=1.0;
}

float desencolar(cola queue){
	float dato;
	if(queue->primero==queue->ultimo){
		dato=queue->primero->dato;
		queue->primero=NULL;
		queue->ultimo=NULL;
	}else{
		dato=queue->primero->dato;
		queue->primero=queue->primero->sgte;
	}
	queue->longitud-=1.0;
	return dato;
}

float front(cola queue){
	float dato;
	dato=queue->primero->dato;
	return dato;
}

float colaTamano(cola queue){
	return queue->longitud;
}

int colaVacia(cola queue){
	return(queue->primero==NULL);
}

int main(){
    float valor;
	cola a,h;
	a=crearCola(); //Se crean las colas necesarias
	h=crearCola();
	float s,m=0.0,f,z,c,k,x,y=0.0,r=0.0,e;
	scanf("%f",&valor); 
	do{
		encolar(valor,a);
		encolar(valor,h);
		scanf("%f",&valor);
	}while(valor!=0); //Se ingresan valores a analizar
	c=colaTamano(a);
	while(!colaVacia(a)){
		y=desencolar(a);
		r+=y;
	} 
	k=r/c;
	while(!colaVacia(h)){
		y=desencolar(h);
		f+=powf((y-k),2.0);
	}
	s=sqrtf(f/c); //Se hacen los procesos matemáticos necesarios para hallar la desviacion estandar
	printf("%f",s); //Se imprime la desviación
}
