#pragma once

void DoGraph();

class Graph {
public:
	// ������
	Graph(int n);
	~Graph();

	// �׷��� ���
	void Print() const;

	// ���� �߰�
	void AddEdge(int u, int v);

private:
	int NodeCount;	// ��� ��
	int** Adj;		// ���� ���
};