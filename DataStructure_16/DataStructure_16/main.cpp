#include "pch.h"
#include "main.h"

int main() {
	while (true) {

		cout << "1. Data Structure\t2. Algorithm : " << endl;
		int n;
		cin >> n;

		clear;

		switch (n)
		{
		case 1:
		{
			cout << "1. Linked List\t2. Stack" << endl;

			int m;
			cin >> m;

			DataStructure(m);
		}
		case 2:
		{
			cout << "" << endl;

			int m;
			cin >> m;

			Algorithm(m);

		}
		default: continue;
		}

		return 0;
	}
}

void DataStructure(int m)
{
	clear;
	switch (m)
	{
	case LINKED_LIST:
	{
		LinkedList();
		return;
	}
	case STACK:
	{

		return;
	}
	default: return;
	}
}

void Algorithm(int m)
{
	clear;
	switch (m) {

	default: return;
	}
}
