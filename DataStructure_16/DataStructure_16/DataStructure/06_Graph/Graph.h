#pragma once

void DoGraph();

class Graph {
public:
	// 생성자
	Graph(int n);
	~Graph();

	// 그래프 출력
	void Print() const;

	// 간선 추가
	void AddEdge(int u, int v);

private:
	int NodeCount;	// 노드 수
	int** Adj;		// 인접 행렬
};