/// esta implementacion es en base a la solucion del problema Union-Pertenencia de OMEGAUP
// https://omegaup.com/arena/problem/Union-pertenencia#problems
// autor: JosepHy

#include<iostream>
using namespace std;

const int MAXN = 100002;
int root[MAXN];

void inicializar(int arr[], int n) /// funcion inicializadora
{
    for(int c = 0; c<=n; c++)
        arr[c] = c;
    return;
}

int f_find(int x)  /// funcion find(x) con optimizacion por compresion
{
    if( root[x] != x)
        return root[x] = f_find(root[x]);
    else
        return x;
}

void f_union(int x, int y ) /// funcion union(x,y) conecta un conjunto x a un conjunto y
{
    int a = f_find(x), b = f_find(y);
    root[a] = b;
    return;
}

bool pertenencia(int x, int y ) /// funcion de pertenencia, nos retorna un true si un vertice x pertenece a un conjunto y
{
    if( f_find(x) == f_find(y) )
        return true;
    return false;
}

int size(int x ) 
{
    return -root[find(x)];   
}

int n;
int m;
char opcion;
int x,y;

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    inicializar(root,n);
    for(int c = 0; c<m; c++ )
    {
        cin>>opcion>>x>>y;
        if(opcion == 'U')
            f_union(x,y);
        else
            cout<<pertenencia(x,y)<<"\n";
    }
}
