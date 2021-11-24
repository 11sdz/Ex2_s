#include "my_mat.h"
#include <stdio.h>
#include <limits.h>


//** global variable for nXn rows X col // in this Ex by default initialize it as 10!
int nRowCol = 10;

//** if user pressed B or C he needs to pick 2 vertex between 0<= a,b <10

void choose_a_b(int mat[][nRowCol] ,char func){
    int a=-1 ,b =-1;
    int ans=-1;
    scanf("%d %d",&a,&b);
    // if ((a>=nRowCol) || (b>= nRowCol)){
    //     return; // bad input 
    // }
    if(func=='B'){
        ans=is_there_route(mat ,a ,b); //case it is 'B'
        if(ans==0){
            printf("False\n");
        }else{
            printf("True\n");
        }
    }else{
        ans=is_shortest_route(mat ,a ,b);//case it is 'C'
        printf("%d\n",ans);
    }
}
// main function
// A = get new matrix by user ,
// B = get 2 vertex by user and check if there is path between them (if same vertex False)
// C = get 2 vertex by user and return value of the path between them (if same vertex "-1" and if there isnt path) 
// D = exit main
int main(){
    char func='Z'; // no meaning for Z while loop and program close by D and and call function if user input B or C
    int mat[nRowCol][nRowCol];
    while(func!='D'){
        scanf("%c" , &func);
        if(func=='A') get_matrix(mat);
        else if(func=='B' || func=='C') choose_a_b(mat,func);
    }
}