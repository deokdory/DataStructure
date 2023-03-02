#include "Graph.h"
#include "pch.h"

void DoGraph() {
	int node, edge;
	std::cout << "node ���� : "; std::cin >> node;
	std::cout << "edge ���� : "; std::cin >> edge;

	// ��� ���� n�� �׷����� �ʱ�ȭ�ϰ�, �Է¹��� �׷��� ������ ���� �߰�
	Graph* graph = new Graph(node);

	int u, v;
	for (int i = 0; i < edge; i++)
	{
		std::cout << "���� ���� ��� 2�� �Է� : ";
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

	// ���� ��ĵ��� ������ ���� ������ ���� �Ҵ�
	Adj = new int* [NodeCount];

	// ���� ��� �ʱ�ȭ
	for (int i = 0; i < NodeCount; i++)
	{
		//�� �ึ�� ���� ũ�Ⱑ NodeCount�� ���� �迭 ���� �Ҵ�
		Adj[i] = new int[NodeCount];

		// �� ���� ��� ���Ҹ� 0���� �ʱ�ȭ
		memset(Adj[i], 0, sizeof(int) * NodeCount);
		// memset : Ư���� ���� �޸𸮿� ä�� �� ����ϴ� �Լ�
	}
}

Graph::~Graph() {
	for (int i = 0; i < NodeCount; i++) {
		delete[] Adj[i];
	} delete[] Adj;
}

void Graph::Print() const {
	std::cout << "�׷��� ���" << std::endl;
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
