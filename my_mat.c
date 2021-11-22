#include<math.h>
#include<limits.h>
#include<stdio.h>
typedef enum bool {
	True=1,
	False=0
	}bool;


//**************************
// because the graphs is not directed then the matrix is symmetric 
// therefor we can run on almost half of the variables in the matrix
//**************************


// *** global FLAG ***
// meaning if we run Floyd-warshall we dont need to run it again so flag will be true
// if we get new matrix by user flag will be False

bool flag=False; 

void floyd_warshall(int[][10],int,int);
int get_min(int,int);

//initialize new matrix
void get_matrix (int mat[][10] , int row , int col){
	int x=-1;
	for(int i=0; i < row ; i+=1){
		for(int j=0; j< col; j+=1){
				scanf("%d",&x);
				*mat[i*col+j] *=x;
				*mat[j*col+i] *=x;
				//* if x=0 then no route between 2 vertex so we initialize it to be infinity
				//** if i==j then it is the same vertex and get value of 0
				if((x==0) && (i!=j)){
					*mat[i*col+j]=INT_MAX;
					*mat[j*col+i]=INT_MAX;
				}
		}
	}
	
	flag=False;
}

 //return if there is a route from a to b
 int is_there_route(int mat[][10],int row, int col, int a ,int b){
	 int answer;
	 if(flag==False){
		 floyd_warshall(mat,row,col);
		 flag=True;
	 }
	answer=*mat[a*col+b];
	if(answer==-1){
		return False;
	}else{
		return True;
	}
		
 }

//return the shortest route from a to b (by value)
int is_shortest_route (int mat[][10],int row ,int col, int a, int b){
	int answer;
	if(flag==False){
 		 floyd_warshall(mat,row,col);
		 flag=True;
	}
	return answer=*mat[a*col+b];

}


//returning minimum value
int get_min(int x, int y){
	return (x<y) ? x : y;
}

//floyd_warshall algo https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
void floyd_warshall(int mat[][10],int row ,int col){
	for(int k=0;k<10;k+=1){
		for(int i=0;i<10;i+=1){
			for(int j=0;j<10;j+=1){
				int i_to_j=*mat[i*col+j];
				int i_to_k=*mat[i*col+k];
				int k_to_j=*mat[k*col+j];
				*mat[i*col+j]=get_min(i_to_j , i_to_k + k_to_j);
			}
		}
	}
	for(int i=0;i<10;i+=1){
		for(int j=0;j<10;j+=1){
			if(i==j){
				*mat[i*col+j]=0;
			}
			int finalize=*mat[i*col+j];
			if(finalize==INT_MAX){
				*mat[i*col+j]=-1;
			}
		}
	}

}