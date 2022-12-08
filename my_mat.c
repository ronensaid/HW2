#include<stdio.h>
#include"my_mat.h"
#define INFINITE 1000000000
#define mat_size 10




int mat[mat_size][mat_size];

//the function that gets values from the user 
void func1(){
    for (int i=0;i<mat_size;i++){
        for (int j=0;j<mat_size;j++){
            scanf("%d",&mat[i][j]);
            if (mat[i][j]==0&&i!=j){
                mat[i][j]=INFINITE;
            }
            else if (i==j)
                mat[i][j]=0;
        }
    }
}
//A function that returns the shortest path between two vertices (i and j)
//The function uses Floyd warshall Algorithm 
int func3 (int i , int j)
{
    if (i==j){
        return -1;
    }
    
    int check[mat_size][mat_size];
  
    
    for (int i = 0; i < mat_size; i++)
        for (int j = 0; j < mat_size; j++)
            check[i][j] = mat[i][j];
  
   
    for (int k = 0; k < mat_size; k++)
    {
        
        for (int i = 0; i < mat_size; i++)
        {
            for (int j = 0; j < mat_size; j++)
            {
                
                if (check[i][k] + check[k][j] < check[i][j])
                    check[i][j] = check[i][k] + check[k][j];
            }
        }
    }
    if (check[i][j]!=0 && check[i][j]!=INFINITE){
        return check[i][j];
    }
    return -1;

}

//A function that returns if there is a path between two vertices (1=True,0=False)
int func2(int i,int j){
    if (func3(i,j)!=-1){
        return 1;
}
    return 0;
}