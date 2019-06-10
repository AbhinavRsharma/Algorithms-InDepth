#include<stdio.h>
#include<stdlib.h>
char t = '.'+1;
int n, m, k;           // condsidering 2 cases::: 1st no neigh.. 2nd no unvisited neigh..

void remov(char* maze, int i, int j){
	maze[m*i+j] = t;
	int flag=0;
	if(i+1<n)
		if(maze[m*(i+1)+j]=='.'+'.'+1-t){
			remov(maze, i+1, j);
			flag =1;
		}
	if(j+1<m)
		if(maze[m*i+j+1]=='.'+'.'+1-t){
			remov(maze, i, j+1);
			flag =1;
		}
	if(i-1>=0)
		if(maze[m*(i-1)+j]=='.'+'.'+1-t){
			remov(maze, i-1, j);
			flag =1;
		}
	if(j-1>=0)
		if(maze[m*i+j-1]=='.'+'.'+1-t){
			remov(maze, i, j-1);
			flag =1;
		}

	if((!flag) && k){
		maze[i*m+j] = 'X';
		k--;
	}

}

int main(){	
	scanf("%d %d %d\n",&n, &m, &k);
    char* maze = (char*)malloc(n*m*sizeof(char));
	
	int i1, j1;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
            scanf("%c",&maze[i*m+j]);
			if(maze[m*i+j]=='.'){
				i1 = i;
				j1 = j;
			}
        }
        scanf("\n");
    }

	while(k>0){
		remov(maze, i1, j1);
		t = '.'+'.'+1-t;
	}

	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
            printf("%c",maze[i*m+j]);
        }
		printf("\n");
    }

	return 0;	
}
