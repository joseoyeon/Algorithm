#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
#include <limits.h> 
#include <stdbool.h> 

#define V 100 

int minKey(int key[], bool mstSet[]) // 최소 값이랑 연결 안된거
{
	// Initialize min value 
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min) // 연결이 안되어 있는데 min 값이다. 
			min = key[v], min_index = v; 

	return min_index;
}

void printMST(int parent[], int n, int graph[V][V])
{
	int sum = 0;
	printf("Edge Weight\n");
	for (int i = 1; i < V; i++)
	{
		printf("%d to %d, cost : %d \n", i, parent[i], graph[i][parent[i]]);
		sum += graph[i][parent[i]];
	}
	printf("Total is %d", sum);
		
}

void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];  // 최소 경로 값 저장하는 배열
	bool mstSet[V]; // 점 연결 여부 
    int sum,d=0;
// 초기화 값
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false; 

	key[0] = 0; 
	parent[0] = -1;

//최소 값 찾아서 점 넣어주기 과정 
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, mstSet); // 일단 연결 안 된 것중에 최소 값 찾아서 넣기 

		mstSet[u] = true;  // 그룹에 포함 시킨다. 

		for (int v = 0; v < V; v++){
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
// 점 추가가 안 되어 있고 연결이 되어 있으며 이미 추가 된 점보다 짧은 거리라면 추가하다.
				{parent[v] = u, key[v] = graph[u][v];}
	    }
         printf("%d to %d, cost : %d \n", d, parent[d], graph[d][parent[d]]);
		        sum += graph[d][parent[d]];
    }

	//printMST(parent, V, graph);
}
 
int main()
{

	FILE *fp;
	char buffer[100 * V];
	char *ptr;
	int graph[V][V];
	int i = 0, j = 0;
	int cost_sum = 0;

	fp = fopen("./quiz.csv", "r");

	if (fp == NULL)
	{
		puts("file open failed!!");

		return;
	}

	for (i = 0; i < V; i++)
	{
		fgets(buffer, 100 * V, fp);
		ptr = strtok(buffer, ",");
		j = 0;

		while (ptr != NULL)
		{
			graph[i][j] = atof(ptr);
			ptr = strtok(NULL, ",");
			j++;
		}
	}

	fclose(fp);

	primMST(graph);
	return 0;
}