#include<cstdio>
#include<iostream>
using namespace std;

struct node
{
	int val;
	int tam;
	node *tope;
};

typedef node *stack;

node *build( int valor)
{
	node *nuevo = new node();
	nuevo -> val = valor;
	nuevo -> tam = 1;
	nuevo -> tope = NULL;
	return nuevo;
}


void push ( stack &origin, int valor)
{
	if( origin == NULL)
	{
		origin = build(valor);
		return;
	}
	node *aux;
	aux = build(valor);
	aux -> tope = origin;
	aux -> tam = origin -> tam +1;
	origin = aux;
	return;
}

bool empty( stack &origin)
{
	return !origin;
} 

void pop ( stack &origin)
{
	if( empty(origin) )
		return;
	stack aux;
	aux = origin;
	origin = aux -> tope;
	delete( aux );
}

int size( stack &origin)
{
	return origin -> tam;
}

int top( stack &origin)
{
	if( empty(origin))
		return -1 << 16;
	return	origin -> val;
}

int main()
{
	stack pila;
	push( pila, 3);
	push( pila, 2);
	push( pila, 5);
	push( pila, 8);
	push( pila, 1);
	push( pila, 4);

	while( !empty(pila) )
	{
		cout<<top(pila)<<" "<<size(pila)<<"\n";
		pop(pila);
	}
	return 0;
}