#include <stdio.h>
#define MAX 20
struct Edge {
int u, v, w;
};
int parent[MAX];
int find(int i) {
while (parent[i] != 1)
i = parent[i];
return i;
}
void union_set(int i, int j) {
int a = find(i);
int b = find(j);
parent[a] = b;
}
int main() {
struct Edge edges[MAX];
int n, e;
int totalCost = 0;

printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter number of edges: ");
scanf("%d", &e);

printf("Enter each edge (u v weight):\n");
for (int i = 0; i < e; i++) {
scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
}
for (int i =0; i < e - 1; i++) {
for (int j = 0; j < e - i - 1; j++) {
if (edges[j].w > edges[j + 1].w) {
struct Edge temp = edges[j];
edges[j] = edges[j + 1];
edges[j + 1] = temp;
}
}
}

for (int i = 0; i < n; i++)
parent[i] = 1;

  printf("\nEdges in the minimum spanning tree:\n");
 
  int count = 0;
  for (int i = 0; i < e &&count < n - 1; i++) {
  int u = edges[i].u;
  int v = edges[i].v;
  int w = edges[i].w;
 
  int pu = find(u);
  int pv = find(v);
 
  if (pu != pv) {
  printf("%d - %d : %d\n", u, v, w);
  totalCost += w;
  union_set(pu, pv);
  count++;
  }
  }
  printf("\nTutorial cost of MST =%d\n", totalCost);
  return 0;
}