#include <stdio.h>
#include <stdlib.h>
#define MaxNum 10000
 
typedef struct
{
    int fromvex, tovex;
    int weight;
} Edge;
typedef Edge *EdgeNode;
int n;
int arcnum;
 
void CreatMatrix(int GA[n+1][n+1])
{
    int i, j, k, e;
 
 
 
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j)
            {
                GA[i][j]=0;
            }
            else
            {
                GA[i][j]=MaxNum;
            }
        }
    }
 
    printf ("Por favor ingrese la información del borde, en forma de punto de inicio, punto final y peso: \ n");
 
    for(k=1; k<=arcnum; k++)
    {
        scanf("%d,%d,%d",&i,&j,&e);
        GA[i][j]=e;
        GA[j][i]=e;
    }
 
}
 
void InitEdge(EdgeNode GE,int m)
{
    int i;
    for(i=1; i<=m; i++)
    {
        GE[i].weight=0;
    }
}
 
 
void GetEdgeSet(int GA[n+1][n+1],EdgeNode GE)
{
    int i, j, k = 1;
    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(GA[i][j] !=0 && GA[i][j] != MaxNum)
            {
                GE[k].fromvex = i;
                GE[k].tovex = j;
                GE[k].weight = GA[i][j];
                k++;
            }
        }
    }
}
 
 
void SortEdge(EdgeNode GE,int m)
{
    int i,j,k;
    Edge temp;
    for(i=1; i<m; i++)
    {
        k=i;
        for(j=i+1; j<=m; j++)
        {
            if(GE[k].weight > GE[j].weight)
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp = GE[i];
            GE[i]=GE[k];
            GE[k]=temp;
        }
    }
}
 
 
void Prim(int GA[n+1][n+1],EdgeNode T)
{
    int i,j,k,min,u,m,w;
    Edge temp;
 
    k=1;
    for(i=1; i<=n; i++)
    {
        if(i!=1)
        {
            T[k].fromvex=1;
            T[k].tovex=i;
            T[k].weight=GA[1][i];
            k++;
        }
    }
 
    for(k=1; k<n; k++)
    {
        min=MaxNum;
        m=k;
        for(j=k; j<n; j++)
        {
            if(T[j].weight<min)
            {
                min=T[j].weight;
                m=j;
            }
        }
 
        temp=T[k];
        T[k]=T[m];
        T[m]=temp;
 
        j=T[k].tovex;
 
        for(i=k+1; i<n; i++)
        {
            u=T[i].tovex;
            w=GA[j][u];
            if(w<T[i].weight)
            {
                T[i].weight=w;
                T[i].fromvex=j;
            }
        }
    }
}
 
 
void OutEdge(EdgeNode GE,int e)
{
    int i;
         printf ("La salida mínima del árbol de expansión en forma de punto de inicio, punto final y peso es: \ n");
    for(i=1; i<=e; i++)
    {
        printf("%d,%d,%d\n",GE[i].fromvex,GE[i].tovex,GE[i].weight);
    }
 
}
 
int main()
{
 
         printf ("Por favor ingrese el número de vértices:");
    scanf("%d",&n);
 
         printf ("Por favor ingrese el número de lados:");
    scanf("%d", &arcnum);
 
    int GA[n+1][n+1];
    Edge GE[n*(n-1)/2], T[n];
 
    CreatMatrix(GA);
 
    InitEdge(GE,arcnum);
    GetEdgeSet(GA,GE);
    SortEdge(GE,arcnum);
    Prim(GA,T);
    printf("\n");
    OutEdge(T,n-1);
 
    system("pause");
    return 0;
}
