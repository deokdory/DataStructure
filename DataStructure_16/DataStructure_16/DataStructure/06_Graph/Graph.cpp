#include "Graph.h"
#include "pch.h"

void DoGraph() {
	int node, edge;
	std::cout << "node 개수 : "; std::cin >> node;
	std::cout << "edge 개수 : "; std::cin >> edge;

	// 노드 수가 n인 그래프를 초기화하고, 입력받은 그래프 정보로 간선 추가
	Graph* graph = new Graph(node);

	int u, v;
	for (int i = 0; i < edge; i++)
	{
		std::cout << "서로 이을 노드 2개 입력 : ";
		std::cin >> u >> v;
		graph->AddEdge(u, v);
	}

	graph->Print();

	std::cout << std::endl;

	delete graph;

	Pause;
	return;
}

Graph::Graph(int n)
	: NodeCount(n) {

	// 인접 행렬들을 저장할 이중 포인터 동적 할당
	Adj = new int* [NodeCount];

	// 인접 행렬 초기화
	for (int i = 0; i < NodeCount; i++)
	{
		//각 행마다 열의 크기가 NodeCount인 정수 배열 동적 할당
		Adj[i] = new int[NodeCount];

		// 각 행의 모든 원소를 0으로 초기화
		memset(Adj[i], 0, sizeof(int) * NodeCount);
		// memset : 특정한 값을 메모리에 채울 때 사용하는 함수
	}
}

Graph::~Graph() {
	for (int i = 0; i < NodeCount; i++) {
		delete[] Adj[i];
	} delete[] Adj;
}

void Graph::Print() const {
	std::cout << "그래프 출력" << std::endl;
	for (int u = 0; u < NodeCount; u++)
	{
		std::cout << u << ": ";
		for (int v = 0; v < NodeCount; v++) {
			if (Adj[u][v]) {
				std::cout << v << " ";
			}
		} std::cout << std::endl;
	}
}

void Graph::AddEdge(int u, int v) {
	Adj[u][v] = 1;
	Adj[v][u] = 1;
}
