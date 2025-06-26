/*
	1. ���� (������ ������� ����)
	2. Ž�� (�������� ���� �� ����)
	
	- vector ���� ��Ű�� ���� Ž��
	- Tree �ڿ� ����, ���� �˻� Ʈ��
	- Heap ( STL�� �켱���� ť priority_queue )

	- Graph Ž��.
*/

/*
	�ڷᱸ�������� �׷���
	- ��(vertex)�� ����(edge)���� ǥ���� �ڷᱸ��.
	- <����>
	1. ����(Direction)�� �����ϴ°� ���ϴ°�?
	2. ��ȯ(Cycle)�� �����ϴ°�?
	3. ����ġ(weight)�� �����ϴ°�?

	Tree : DAG(������ ����, ACycle ��ȯ�� ����, Graph �׷���)
*/

/*
	�׷����� ��� ǥ���� ���ΰ�?
	1. 2���� �迭 (Matrix ���)
	2. �� �������� ����� �����͸� �ڷᱸ�� ǥ���ϴ� ���
*/
#include <iostream>
#include <vector>
#include <stack>		// DFS - stack ǥ���Ѵ�.	LIFO
#include <queue>		// BFS - queue ǥ���Ѵ�.	FIFO

using namespace std;

/*
	�׷����� Matric�� ǥ������ �� ������ ��� ���� ���� ����Ǿ� �ִ��� �� �� �ִ�.
	  A B C D
	A 0 1 1 1
	B 1 0 1 1
	C 1 1 0 0
	D 1 1 0 0
*/

/*
	A :(����� ������) B - C - D
	B : A - C - D
	C : A - B
	D : A - B
*/

/*
	���α׷������� �׷����� ǥ���� �� �ִ�.
	����Ǿ� �ִ� �׷����� Ž�� �ϴ� ���?
	[1] ���� �켱 Ž�� (Depth First Search)
	[2] �ʺ� �켱 Ž�� (Breadth First Search)
*/

/*
	[���� ����]
	���� �ӿ��� ���� ������ ����Ǿ� �ִ� �̹��� ã��
	���� ���� �׷����� ǥ���ϴ� ���� �ƹ� ������ ���� �� ����
*/

/*
	�׷����� Ž�� ��� (��ȸ)
	- DFS ���� �켱 Ž��
	  - Stack ����	-	���� ����
	- BFS �ʺ� �켱 Ž��
	  - Queue ����	-	���� ����
*/

/*
	���� DFS�� BFS�� ����� �� �ִ°�?
	- (1) �׷����� Ž���� �� ���� ������ �� �ִ� ���� �����ϱ�, �Ѵ� ��� ����
	- (2) DFS - �׷����� ��ȸ�� �ϰ� �ִ��� �ľ��� ��
	- (3) BFS - Ư�� ��ġ���� �ּ��� �Ÿ��� �����ϴ� ����� ���� ��

*/

class Graph
{
private:
	int V; // ���� ����, vertex (����, ���)
	//int[y][x] map; 
	vector<vector<int>> adj; // �� ������ ������ ���� �����ϴ� 2���� �迭, adjacentMatrix

	vector<bool> visited;	 // �ѹ� ������ ���� �ô�(�鷵��)

	void DFS(int v)
	{
		// v �湮, visited = true
		visited[v] = true;
		cout << v << " ";

		for (auto& i : adj[v])
		{
			// adj B, C, D ("B")->DFS ����, ��� ���.
			if (visited[i] == false) // ���� �湮�� �ߴٸ� DFS ���� x
			{ DFS(i);}
				// DFS(B) -> DFS(C) -> DFS(D)
		}
	}

	void DFSIter(int v) // Iterater ���
	{
		// �湮�� ���� true�� ��ȯ

		// ��� �Լ� ����� ������� �ʰ�, �ݺ������� ǥ��.
		stack<int> stack;
		stack.push(v);	
		while (!stack.empty())
		{
			int cVertex = stack.top();
			stack.pop();

			// stack : �����͸� ���� ��, ���� �������� ���� �����͸� ���� �����϶�.
			// �ݺ���, �������� �����͸� �����ϰ� ����� �ش�.
			if (visited[cVertex] == false)
			{
				visited[cVertex] = true;
				cout << cVertex << " ";
			}

			// �̿� ���
			for (int i = adj[cVertex].size() - 1; i >= 0; i--)
			{
				int neighbor = adj[cVertex][i];
				if (visited[neighbor] == false)
				{
					stack.push(neighbor);
				}
			}
		}

		// for() <- iterative �ּ�, ���� �ּ� ~ �� �ּ�.  reverseIterative
		// for(int i=0; i < v.size(); i++)
		// v[i] ,	list[i]		list(0 + 3)


	}

	void BFSIter(int start)
	{
		queue<int> q;
		visited[start] = true;
		q.push(start);			// �׷����� ���� ��带 ����

		while (!q.empty()) 
		{
			int c = q.front();
			q.pop();

			cout << c << " ";

			// c�� ����Ǿ� �ִ� ��带 �����ϴ� �ڵ� adj[c]

			for (auto& e : adj[c])
			{
				if (visited[e] == false) 
				{
					visited[e] = true;
					q.push(e);
				}
				
			}
			
		}

	}

	void BFSRecursive(queue<int>& q)
	{
		// 1. ��� �Լ��� Ż�� ������ �ۼ� ( q�� empty �ϋ� )
		if (q.empty()) { return; }
		
		// BFS �ݺ������ �ڵ带 ���⿡ �����ͺ�����.

		// front, pop, push
		int c = q.front();
		q.pop();
		cout << c << " ";

		for (auto& e : adj[c])
		{
			if (!visited[e])
			{
				visited[e] = true;
				q.push(e);
			}
		}

		BFSRecursive(q);
	}

	void BFS(int start)
	{
		queue<int> q;
		q.push(start);
		visited[start] = true;
		BFSRecursive(q);
	}

public:
	// ������. ���� ����, 2���� �迭�� V�� ������ŭ ��� 0���� �ʱ�ȭ
	Graph(int vertices) : V(vertices), adj(vertices) 
	{
		adj.resize(V);
		visited.resize(V, false);
	}

	void addEdge(int u, int v) // �ֹ���, �ܹ��� ����
	{
		adj[u].push_back(v);	//u�� 1, v�� 2 1������ ����� �� : 2
		adj[v].push_back(u);	
	}

	void PrintGraph()
	{
		for (int i = 0; i < V; i++)
		{
			cout << "���� " << i << "�� ������ ����Ʈ : ";
			for (auto& elem : adj[i])
			{
				cout << " ->" << elem;
			}
			cout << endl;
		}
	}

	void DFSTraverse(int startV)
	{
		// �湮�� ������ ���½�Ų��.
		fill(visited.begin(), visited.end(), false);
		cout << "DFS Ž�� ��� (���� ���� : " << startV << ")";
		DFS(startV);
		cout << endl;
	}

	void DFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);
		cout << "DFS Iterative ��� Ž�� ��� (���� ���� : " << startV << ")";
		DFSIter(startV);
		cout << endl;
	}

	void BFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false); // �湮 ������ �ʱ�ȭ �ϴ� �ڵ�
		cout << "BFS Iterative ��� Ž�� ��� (���� ���� : " << startV << ")";
		BFSIter(startV);
		cout << endl;
	}

	void BFSTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);
		cout << "BFS Ž�� ��� (���� ���� : " << startV << ")";
		BFS(startV);
		cout << endl;
	}
};

class GraphMatrix
{
private:
	int V;
	vector<vector<int>> adj;

public:
	GraphMatrix(int v) : V(v), adj(v, vector<int>(v, 0)) {}  // v * v 2���� �迭�� 0���� �ʱ�ȭ

	void addEdge(int u, int v)
	{
		adj[u][v] = 1;	// �ܹ���
		adj[v][u] = 1; 
	}

	void PrintGraph()
	{
		cout << "���� ���" << endl;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}

};


int main()
{
	Graph g(6);	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.DFSTraverse(3);
	g.DFSIterTraverse(3);
	g.BFSIterTraverse(0);
	g.BFSTraverse(4);
	g.PrintGraph();

	GraphMatrix gm(4);
	gm.addEdge(0, 1);
	gm.addEdge(0, 2);
	gm.addEdge(0, 3);
	gm.addEdge(1, 2);
	gm.addEdge(1, 3);

	gm.PrintGraph();

	Graph graph(7);
	graph.addEdge(0, 1);
	graph.addEdge(0, 4);
	graph.addEdge(0, 5);
	graph.addEdge(1, 2);
	graph.addEdge(1, 4);
	graph.addEdge(2, 3);
	graph.addEdge(2, 5);
	graph.addEdge(4, 5);
	graph.addEdge(4, 6);

	graph.PrintGraph();
	
}