#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int visited[MAX];
int graph [MAX] [MAX];
int n;


void DFS(int vertex)  {
	printf("%d", vertex);
	visited[vertex] = 1;
	
	
	for (int i = 0; i < n; i++){
		if (graph[vertex] [i] == 1 && !visited[i]){
			DFS(i);
		}
	}
}

int main() {
	int i, j, start;
	
	printf("Enter number of vertices:");
	scanf("%d", &n);
	
	printf("Enter the adjacency matrix: \n");
	for (i=0; i<n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d",&graph[i] [j]);
		}
	}

    for (i = 0; i < n; i++) {
    	visited[i] = 0;
	}
    
    printf("Enter the  starting vertex (0 to %d): " , n - 1);
    scanf("%d", &start);
    
    printf("Depth First Search traversal:");
    DFS(start);
    
    printf("\n");
    
    return 0;
}