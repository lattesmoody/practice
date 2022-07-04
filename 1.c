#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h> // memset 함수를 사용하기 위해 선언한 함수
#include <string.h> //strtok 함수를 사용하기 위해 선언한 함수
#include <stdlib.h> // malloc,atoi 함수를 사용하기 위해 선언한 함수
#define No_of_Vertex 7

typedef struct Adj_mat_struct {
	int adj_mat[No_of_Vertex][No_of_Vertex];
} Adj_mat_struct;

typedef struct G_node
{
	int vertex;
	struct G_node* link;
} G_node;


G_node * adj_list[No_of_Vertex];


int visited_dfs[No_of_Vertex]; // Graph_dfs 함수를 위한 전역 변수 
int visited_bfs[No_of_Vertex]; // Graph_bfs 함수를 위한 전역 변수 

void print_adj_mat(Adj_mat_struct mat, int n)
{

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", mat.adj_mat[i][j]);
		}
		printf("\n");
	}
}

Adj_mat_struct Adj_create() {
	Adj_mat_struct mat;
	memset(&mat, 0, sizeof(Adj_mat_struct));
	FILE* fp;

	fp = fopen("test.txt", "r");
	char buffer[100];

	int lineCount = 1;
	printf("파일 열기 성공 여부: ");
	if (fp == NULL) {
		printf("파일열기 실패\n");
	}
	else {
		printf("파일열기 성공\n");
	}
	int Adj_mat[No_of_Vertex][No_of_Vertex] = { {0} };
	int i = 0;
	int j = 0;
	
	while (!feof(fp)) {
		int count = 0;
		fgets(buffer, sizeof(buffer), fp);
		char* ptr = strtok(buffer, ",");
		
		while (ptr != NULL) {
			
			if (count == 0) {
				i = atoi(ptr);
				count++;
			}
			else {
				j = atoi(ptr);
				count--;
			}
			
			ptr = strtok(NULL, ",");
		}
		mat.adj_mat[i][j] = 1;
		mat.adj_mat[j][i] = 1;
		//printf("%d %d ,%2d\n", i, j, mat.adj_mat[i][j]);
	}
	fclose(fp);
	return mat;
}

void Adj_degree(Adj_mat_struct mat, int n) // 인접행렬에서 각 정점의 차수 계산 (Adj_degree)
{
	for (int i = 0; i <= n - 1; i++) {
		int degree = 0;
		for (int j = 0; j <= n - 1; j++) {
			degree = degree + mat.adj_mat[i][j];
		}
		printf("정점 %d의 차수: %d\n", i, degree);
	}

}


G_node* Adj_insert(G_node * List, int i, int j)
{
	G_node* node;
	node = (G_node*)malloc(sizeof(G_node));
	node->vertex = j;
	node->link = adj_list[i];
	adj_list[i] = node;
	return adj_list;
}


// 그래프 초기화 
void init(G_node* List)
{

	int v;
	for (v = 0; v < No_of_Vertex; v++)
		adj_list[v] = NULL;
}
G_node* Adjmat2list_for_dfs(Adj_mat_struct mat, int n)
{
	G_node* List;
	List = (G_node*)malloc(sizeof(G_node));
	init(List);
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= n - 1; j++) {
			if (mat.adj_mat[i][j] == 1)
			{
				Adj_insert(List, i, j);
			}
		}
	}
	return List;
}
G_node* Adjmat2list_for_bfs(Adj_mat_struct mat, int n)
{
	G_node* List;
	List = (G_node*)malloc(sizeof(G_node));
	init(List);
	for (int i = 0; i <= n - 1; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (mat.adj_mat[i][j] == 1)
			{
				Adj_insert(List, i, j);
			}
		}
	}
	return List;
}
void print_adj_list(G_node* List,int n) {
	for (int i = 0; i < n; i++) {
		G_node* p = adj_list[i];
		printf("정점 %d의 인접 리스트", i);
		while (p != NULL) {
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

void Graph_dfs(G_node* List, int v)
{
	G_node* w = adj_list[v];
	visited_dfs[v] = 1;   		// 정점 v의 방문 표시 
	printf("정점 %d -> ", v);		// 방문한 정점 출력
	while (w != NULL) {// 인접 정점 탐색 
		int temp = w->vertex;
		if (!visited_dfs[temp])
			Graph_dfs(List, w->vertex); //정점 w에서 DFS 새로 시작
		w = w->link;
	}
}



// 구조체 선언(Queue)
#define MAX_QUEUE_SIZE 7

int queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;


// 큐 초기화 함수 Queue_init
void Queue_init() {
	front = 0;
	rear = 0;
}

// 큐 공백 상태 검출 함수 Queue_empty
int Queue_empty() {
	if (front == rear) {
		return 1;
	}
	else {
		return 0;
	}
}

// 큐 포화 상태 검출 함수 Queue_full
int Queue_full() {
	return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

// 큐 삽입 함수 Queue_enqueue
void Queue_enqueue(int item) {
	if (Queue_full())
		printf("큐가 포화상태입니다.\n");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = item;

}

// 큐 삭제 함수 Queue_dequeue
int Queue_dequeue() {
	if (Queue_empty())
		printf("큐가 비어있습니다.\n");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

void Graph_bfs(G_node* List, int v) {
	G_node* w;
	Queue_init();
	visited_bfs[v] = 1;
	printf("정점 %d ->", v);
	Queue_enqueue(v);
	while (!Queue_empty()) {
		v = Queue_dequeue();
		w = adj_list[v];
		while (w != NULL) {
			if (visited_bfs[w->vertex] == 0) {
				visited_bfs[w->vertex] = 1;
				printf(" 정점 %d ->", w->vertex);
				Queue_enqueue(w->vertex);

			}
			w = w->link;
		}
		
	}
}


int main()
{
	Adj_mat_struct mat;
	memset(&mat, 0, sizeof(Adj_mat_struct));
	G_node* g_for_dfs;
	g_for_dfs = (G_node*)malloc(sizeof(G_node));
	G_node* g_for_bfs;
	g_for_bfs = (G_node*)malloc(sizeof(G_node));
	printf("2-1. 1. 텍스트 파일에서 간선 정보를 읽어온 결과\n");
	mat = Adj_create();
	printf("\n2-2. 텍스트에서 불러온 인접행렬 구성 결과\n");
	print_adj_mat(mat, 7);
	printf("\n3. 인접행렬을 사용하여 각 정점의 차수 계산 결과\n");
	Adj_degree(mat, 7);
	g_for_dfs = Adjmat2list_for_dfs(mat, 7);
	g_for_bfs = Adjmat2list_for_bfs(mat, 7);
	printf("\n4-1. 인접행렬을 인접리스트로 변환한 결과(깊이 우선 탐색 전용 인접리스트)\n");
	print_adj_list(g_for_dfs, 7);
	printf("\n4-2. 인접행렬을 인접리스트로 변환한 결과(너비 우선 탐색 전용 인접리스트)\n");
	print_adj_list(g_for_bfs, 7);
	printf("\n5. 인접리스트를 사용한 깊이 우선 탐색 (Graph_dfs)\n");
	Graph_dfs(g_for_dfs, 0);
	printf("\n");
	printf("\n6. 인접리스트를 사용한 너비 우선 탐색 (Graph_bfs) \n");
	Graph_bfs(g_for_bfs, 0);
	printf("\n");
	return 0;
}