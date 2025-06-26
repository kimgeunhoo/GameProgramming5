
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

/*
	1. DFS
	  - �׷����� ��� ������ �Ǿ� �ִ°�? connected Graph
	  - �ٽ� ���̵�� : �׷��� (��, ��)
	  - ���� ������ �����Ǿ� �ִ�.
	  - ���࿡ �� ���̿� ����� ���� ���ٸ� ��ȸ�ϸ鼭 ���� ���� ������ ������Ű�� ��� ��,
	  ���� ���� �ٸ��� ���� ���̴�.
*/

using namespace std;

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
			{
				DFS(i);
			}
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

	// ��� �׷����� ����Ǿ� �ֳ�?

	void dfsCount(int& count, int startV)
	{
		// DFS - stack
		visited[startV] = true;
		count++;

		for(int e : adj[startV])
		{
			if (!visited[e])
			{
				visited[e] = true;
				dfsCount(count, e);
			}
		}

	}

	bool IsConnected(int startV)
	{
		// visited
		fill(visited.begin(), visited.end(), false);

		int count = 0;
		// DFS ��ȸ�ϸ鼭 ��� ��ſ� count ���� �������Ѷ�
		dfsCount(count, startV);
		return count == V;
	}

	void CheckGraphIsConnected()
	{

		if (IsConnected(0))
		{
			cout << "��� �׷����� ����Ǿ� �ֽ��ϴ�." << endl;
		}
		else
		{
			cout << "������� ���� �׷����� �����մϴ�." << endl;
			cout << "-1";
		}
	}

	// ��� ã�� ( �ּ��� �Ÿ��� ã�� ���� ) - BFS, ���ͽ�Ʈ��(����� ���� �� ���� ã�� ���), ����
	// start - end

	vector<int> refindPath(vector<int>& parent, int start, int end)
	{
		vector<int> path;

		if (parent[end] == -1 && start != end) // parent -1�� �ʱ�ȭ. ������ ���Ѵ�? ���� ��ã�Ҵ�.
		{
			return path; // ��ΰ� ���� �����͸� ��ȯ
		}

		int current = end;
		while (current != -1)
		{
			path.insert(path.begin(), current);
			current = parent[current];
		}

		return path;
	}

	vector<int> findShortestPath(int start, int end)
	{
		if (start == end) { return { start }; }

		fill(visited.begin(), visited.end(), false);

		vector<int> parent(V, -1);	 // ��ǥ ���������� �迭�� �����Ѵ�.
		vector<int> distance(V, -1); // ����� �Ÿ��� �����ϴ� �迭
		queue<int> q;
		q.push(start);
		visited[start] = true;
		distance[start] = 0;

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			// while ���� ���� �ؾ��ϴ� ����. ( ���� ��尡 ��ǥ ������ �������� �� )
			if (end == c) break;

			// ���� ��������
			for (int e : adj[c])
			{
				if (!visited[e])
				{
					visited[e] = true;
					q.push(e);
					parent[e] = c;
					distance[e] = distance[c] + 1;
				}
			}
		}
		return refindPath(parent, start, end);
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
	g.CheckGraphIsConnected();
	
	vector<int> temp = g.findShortestPath(0, 5);

	cout << "0���� 5�� �̵��ϴ� �ּ� �Ÿ�" << endl;
	for (auto& e : temp)
	{
		cout << "->" << e;
	}

}


