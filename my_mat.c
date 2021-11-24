#include<math.h>
#include<limits.h>
#include<stdio.h>
typedef enum bool {
	True=1,
	False=0
	}bool;



bool flag =False;

// *** global FLAG ***
// if we get new matrix by user reset flag to False , if function Floyd-warshall has been called on this matrix True
// if floyd-warshall algo already run we save some running time if another function has been called
// if we run floyd-warshall twice will get same result

int extern nRowCol;

// *** global nXn rows X col ***

void floyd_warshall(int[][nRowCol]);
int get_min(int,int);

//initialize new matrix
void get_matrix (int mat[][nRowCol] ){
	int x=-1;
	for(int i=0; i < nRowCol ; i+=1){
		for(int j=0; j< nRowCol; j+=1){
				scanf("%d",&x);
				*mat[i*nRowCol+j]=x;
				//* if x=0 then no route between 2 vertex so we initialize it to be -1 (we look as like in infinity in floyd algo below)
				//** if i==j then it is the same vertex and get value of 0
				if((x==0) && (i!=j)){
					*mat[i*nRowCol+j]=-1;
				}
		}
	}
	flag=False;
}

 //return if there is a route from a to b
 int is_there_route(int mat[][nRowCol], int a ,int b){
	 if(a==b){
		 return False;
	 }
	 int answer;
	 if(flag==False){
		 floyd_warshall(mat);
		 flag=True;
	 }
	answer=*mat[a*nRowCol+b];
	if(answer==-1){
		return False;
	}else{
		return True;
	}
		
 }

//return the shortest route from a to b (by value)
int is_shortest_route (int mat[][nRowCol], int a ,int b){
	if(a==b){
		return -1;
	}
	int answer;
	if(flag==False){
 		 floyd_warshall( mat);
		 flag=True;
	}
	return answer=*mat[a*nRowCol+b];

}


//return min{x,y}
int get_min(int x, int y){
	if(x<y){
		return x;
	}else{
		return y;
	}
}

//floyd_warshall algo https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
void floyd_warshall(int mat[][nRowCol]){
	for(int k=0;k<nRowCol;k+=1){
		for(int i=0;i<nRowCol;i+=1){
			for(int j=0;j<nRowCol;j+=1){
				int i_to_j=*mat[i*nRowCol+j];
				int i_to_k=*mat[i*nRowCol+k];
				int k_to_j=*mat[k*nRowCol+j];
					if( (i_to_j==-1) && (i_to_k==-1) ){
						*mat[i*nRowCol+j]=-1;
						*mat[j*nRowCol+i]=-1;
					}
					else if( (i_to_j==-1) && ((i_to_k!=-1) && (k_to_j!=-1))){
						*mat[i*nRowCol+j]=i_to_k+k_to_j;
						*mat[j*nRowCol+i]=i_to_k+k_to_j;
					}else if(i_to_j!=-1 && (i_to_k==-1 || k_to_j==-1)){
						*mat[i*nRowCol+j]=i_to_j;
						*mat[j*nRowCol+i]=i_to_j;
					}else if(i_to_j!=-1 && i_to_k!=-1 && k_to_j!=-1){
						int ans=get_min(i_to_j , i_to_k + k_to_j);
						*mat[i*nRowCol+j]=ans;
						*mat[j*nRowCol+i]=ans;
					}
			}
		}
	}
}