#include <stdio.h>

#define MAX 10
#define INF 9999


void  prims(int graph [MAX] [MAX], int n) {
	int visited[MAX] = {0};
	int edges = 0, totalCost = 0;
	
	 visited[0] =1;
	 
	 printf("Edges in the minimum Spanning Tree:\n");
	 
	while (edges < n -1) {
	    int min= INF;
	    int u = -1, v = -1;
	    
	    
	    for (int i =0; i < n; i++) {
		   if (visited[i]) {
		      for (int j = 0; j < n; j++) {
			    if(!visited[j] && graph[i] [j] < min) {
				   min = graph [i] [j];
				   u =i;
				   v =j;
		      }
	       }
		}
	}
    printf("%d -%d : %d\n",u,v,graph[u] [v]);
    visited[v] = 1;
    totalCost += graph[u] [v];
    edges++;
}
    printf("total cost of MST = %d\n", totalCost);
}
int main() {
	int graph [MAX] [MAX];
	int n;
	printf("Enter number of vertices:");
	scanf("%d", &n);
	printf("Enter the cost adjacency matrix (%d x %d): \n", n,n);
	for (int i = 0; i <n; i++) {
	  for(int j = 0; j < n; j++) {
	  	scanf("%d", &graph[i] [j]);
	  	if (graph [i][j] == 0)
	  	graph[i][j] =INF;
	  	
		}
	}
                
    prims (graph, n);
    return 0;
}
