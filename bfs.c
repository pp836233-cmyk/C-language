#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int queue[MAX];
int front = -1, rear = -1;


void enqueue (int value) {
	if (rear == MAX -1) {
		printf("Queue is full\n");
		return;
	}
	if (front == -1)
	    front = 0;
	rear++;
	queue[rear] = value;
}

int dequeue() {
	if (front == -1 || front > rear )
	    return -1;
	int value = queue [front];
	front++;
	return value ;
}

void BFS(int adj [MAX] [MAX], int visited[MAX], int start, int n)
{
	int i, current;
	enqueue (start);
	visited [start] = 1;
	
	 printf("BFS Traversal:");
	 while (front <= rear) {
	 	current = dequeue();
	 	printf("%d", current);
	 	
	 	for (i = 0; i < n; i++) {
	 	     if (adj[current] [i] ==1 && visited[i] ==0) {
	 	     	enqueue(i);
	 	     	visited[i] =1;
			  }
		 }
	 }
}

int main () {
	int adj [MAX] [MAX];
	int visited [MAX] ={0};
	int n,i,j,start;
	
	printf("Enter number of vertices:");
	scanf("%d", &n);
	
	printf("Enter adjacency matrix (%d x %d):\n", n, n);
	for(i = 0; i< n; j++)
	    for (j= 0; j < n; j++)
	        scanf("%d", &adj [i] [j]);
	        
	 printf("Enter starting vertex (0 to %d):",n-1);
	 scanf("%d", &start);
	 
	 BFS(adj, visited, start, n);
	 
	 return 0;
 }