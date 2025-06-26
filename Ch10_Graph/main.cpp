/*
	1. 정렬 (데이터 순서대로 나열)
	2. 탐색 (데이터의 수정 및 삭제)
	
	- vector 정렬 시키고 이진 탐색
	- Tree 자요 구조, 이진 검색 트리
	- Heap ( STL에 우선순위 큐 priority_queue )

	- Graph 탐색.
*/

/*
	자료구조에서의 그래프
	- 점(vertex)과 간선(edge)으로 표현한 자료구조.
	- <기준>
	1. 방향(Direction)이 존재하는가 안하는가?
	2. 순환(Cycle)이 존재하는가?
	3. 가중치(weight)가 존재하는가?

	Tree : DAG(방향이 존재, ACycle 순환이 없는, Graph 그래프)
*/

/*
	그래프를 어떻게 표현할 것인가?
	1. 2차원 배열 (Matrix 방식)
	2. 각 정점에서 연결된 데이터를 자료구조 표현하는 방식
*/
#include <iostream>
#include <vector>
#include <stack>		// DFS - stack 표현한다.	LIFO
#include <queue>		// BFS - queue 표현한다.	FIFO

using namespace std;

/*
	그래프를 Matric로 표현했을 때 실제로 어떻게 점과 선이 연결되어 있는지 알 수 있다.
	  A B C D
	A 0 1 1 1
	B 1 0 1 1
	C 1 1 0 0
	D 1 1 0 0
*/

/*
	A :(연결된 데이터) B - C - D
	B : A - C - D
	C : A - B
	D : A - B
*/

/*
	프로그래밍으로 그래프를 표현할 수 있다.
	연결되어 있는 그래프를 탐색 하는 방법?
	[1] 깊이 우선 탐색 (Depth First Search)
	[2] 너비 우선 탐색 (Breadth First Search)
*/

/*
	[자유 주제]
	게임 속에서 점과 선으로 연결되어 있는 이미지 찾기
	점과 선을 그래프로 표현하는 것을 아무 주제나 선택 후 실행
*/

/*
	그래프의 탐색 방법 (순회)
	- DFS 깊이 우선 탐색
	  - Stack 구현	-	세로 상자
	- BFS 너비 우선 탐색
	  - Queue 구현	-	가로 상자
*/

/*
	언제 DFS와 BFS를 사용할 수 있는가?
	- (1) 그래프를 탐색할 때 쉽게 구현할 수 있는 것을 선택하기, 둘다 사용 가능
	- (2) DFS - 그래프가 순회를 하고 있는지 파악할 때
	- (3) BFS - 특정 위치까지 최소의 거리로 도달하는 방법을 구할 때

*/

class Graph
{
private:
	int V; // 점의 갯수, vertex (도시, 노드)
	//int[y][x] map; 
	vector<vector<int>> adj; // 각 점에서 인접한 점을 저장하는 2차원 배열, adjacentMatrix

	vector<bool> visited;	 // 한번 지나간 길은 봤다(들럿다)

	void DFS(int v)
	{
		// v 방문, visited = true
		visited[v] = true;
		cout << v << " ";

		for (auto& i : adj[v])
		{
			// adj B, C, D ("B")->DFS 실행, 재귀 방식.
			if (visited[i] == false) // 만약 방문을 했다면 DFS 실행 x
			{ DFS(i);}
				// DFS(B) -> DFS(C) -> DFS(D)
		}
	}

	void DFSIter(int v) // Iterater 방식
	{
		// 방문한 점은 true로 변환

		// 재귀 함수 방식을 사용하지 않고, 반복문으로 표현.
		stack<int> stack;
		stack.push(v);	
		while (!stack.empty())
		{
			int cVertex = stack.top();
			stack.pop();

			// stack : 데이터를 삽입 후, 가장 마지막에 들어온 데이터를 먼저 실행하라.
			// 반복문, 역순으로 데이터를 실행하게 만들어 준다.
			if (visited[cVertex] == false)
			{
				visited[cVertex] = true;
				cout << cVertex << " ";
			}

			// 이웃 노드
			for (int i = adj[cVertex].size() - 1; i >= 0; i--)
			{
				int neighbor = adj[cVertex][i];
				if (visited[neighbor] == false)
				{
					stack.push(neighbor);
				}
			}
		}

		// for() <- iterative 주소, 시작 주소 ~ 끝 주소.  reverseIterative
		// for(int i=0; i < v.size(); i++)
		// v[i] ,	list[i]		list(0 + 3)


	}

	void BFSIter(int start)
	{
		queue<int> q;
		visited[start] = true;
		q.push(start);			// 그래프의 시작 노드를 삽입

		while (!q.empty()) 
		{
			int c = q.front();
			q.pop();

			cout << c << " ";

			// c에 연결되어 있는 노드를 접근하는 코드 adj[c]

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
		// 1. 재귀 함수의 탈출 조건을 작성 ( q가 empty 일떄 )
		if (q.empty()) { return; }
		
		// BFS 반복방식의 코드를 여기에 가져와보세요.

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
	// 생성자. 점의 갯수, 2차원 배열을 V의 갯수만큼 모두 0으로 초기화
	Graph(int vertices) : V(vertices), adj(vertices) 
	{
		adj.resize(V);
		visited.resize(V, false);
	}

	void addEdge(int u, int v) // 쌍방향, 단방향 연결
	{
		adj[u].push_back(v);	//u가 1, v가 2 1번점에 연결된 값 : 2
		adj[v].push_back(u);	
	}

	void PrintGraph()
	{
		for (int i = 0; i < V; i++)
		{
			cout << "정점 " << i << "의 인접한 리스트 : ";
			for (auto& elem : adj[i])
			{
				cout << " ->" << elem;
			}
			cout << endl;
		}
	}

	void DFSTraverse(int startV)
	{
		// 방문한 경험을 리셋시킨다.
		fill(visited.begin(), visited.end(), false);
		cout << "DFS 탐색 결과 (시작 지점 : " << startV << ")";
		DFS(startV);
		cout << endl;
	}

	void DFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);
		cout << "DFS Iterative 방식 탐색 결과 (시작 지점 : " << startV << ")";
		DFSIter(startV);
		cout << endl;
	}

	void BFSIterTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false); // 방문 경험을 초기화 하는 코드
		cout << "BFS Iterative 방식 탐색 결과 (시작 지점 : " << startV << ")";
		BFSIter(startV);
		cout << endl;
	}

	void BFSTraverse(int startV)
	{
		fill(visited.begin(), visited.end(), false);
		cout << "BFS 탐색 결과 (시작 지점 : " << startV << ")";
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
	GraphMatrix(int v) : V(v), adj(v, vector<int>(v, 0)) {}  // v * v 2차원 배열을 0으로 초기화

	void addEdge(int u, int v)
	{
		adj[u][v] = 1;	// 단방향
		adj[v][u] = 1; 
	}

	void PrintGraph()
	{
		cout << "인접 행렬" << endl;
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