#include "my_mat.h"
#include <stdio.h>
#include <limits.h>

void choose_a_b(int mat[][10] ,int row ,int col ,char func){
    int a=-1 ,b =-1;
    int ans=-1;
    scanf("%d %d",&a,&b);
    if(func=='B'){
        ans=is_there_route(mat, row ,col ,a ,b);
        if(ans==0){
            printf("False\n");
        }else{
            printf("True\n");
        }
    }else{
        ans=is_shortest_route(mat ,row ,col ,a ,b);
        printf("%d\n",ans);
    }
}

int main(){
    char func='Q';
    int row=10 , col=10;
    int mat[row][col];
    while(func!='D'){
        scanf("%c" , &func);
        
        if(func=='A') get_matrix(mat ,row ,col);
        else if(func=='B' || func=='C') choose_a_b(mat,row,col,func);
    }
}