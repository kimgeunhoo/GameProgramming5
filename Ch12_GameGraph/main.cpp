#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*
	1. 그래프
	2. 위치를 표현하는 코드. (x, y) (x,y,z) + 노드 정보(이름, 아이디)
*/

class Spire // Spire 만들어 보고 싶다
{
	struct Node
	{
		int x, y;
		int id;
		string name;
		// 시작, 일반, 엘리트, 보스, 상점, 휴식, 이벤트

		Node(string _name, int _id, int _x, int _y) : name(_name), id(_id), x(_x), y(_y) {}
	};

	// 가변 배열 (vector) 노두룰 저장하는 컨테이너 선언
private:
	vector<Node> nodes;
	vector<vector<int>> adj; // 인접 행렬 (각 점이 어디에 연결되어 있는지 저장하는 컨테이너)
	vector<bool> visited;
	int nodeCount;

	const int CONSOLEHEIGHT = 40;
	const int CONSOLEWIDTH = 80;

public:
	Spire() : nodeCount(0) {}

	void addNode(string _name, int x = 0, int y = 0)	// id와 nodeCount 일치하게 만든다.
	{
		nodes.emplace_back(_name, nodeCount, x, y);		// nodes 컨테이너 데이터를 추가한다.
		adj.push_back(vector<int>());					// 노드를 추가할 때 인접행렬의 공간 생성
		visited.push_back(false);						// 방문 체크 공간을 생성
		nodeCount++;									// 노드 숫자 증가
	}

	void addEdge(int start, int end)
	{
		adj[start].push_back(end);	// 방향이 있는 그래프이기 때문에 역순으로 연결은 하지 않는다.
	}

	void printGraph()
	{
		for (int i = 0; i < nodeCount; i++)
		{

			cout << "노드 : " << i << "(" << nodes[i].name << ")" << endl;
			cout << "연결된 노드 : ";

			if (adj[i].empty())
			{
				cout << "없음 ";
			}
			else
			{
				for (int j = 0; j < adj[i].size(); j++)
				{
					cout << adj[i][j] << "(" << nodes[adj[i][j]].name << ")" << endl;

					if (j < adj[i].size() - 1)
					{
						cout << ", ";
					}
				}
				
			}
			cout << endl;
			
		}
	}


	vector<int> refindPath(vector<int>& parent, int start, int end)
	{
		vector<int> path;

		if (parent[end] == -1 && start != end) // parent -1로 초기화. 접근을 못한다? 길을 못찾았다.
		{
			return path; // 경로가 없는 데이터를 반환
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

		vector<int> parent(nodeCount, -1);	 // 목표 지점까지의 배열을 저장한다.
		vector<int> distance(nodeCount, -1); // 노드의 거리를 저장하는 배열
		queue<int> q;
		q.push(start);
		visited[start] = true;
		distance[start] = 0;

		while (!q.empty())
		{
			int c = q.front();
			q.pop();

			// while 강제 종료 해야하는 조건. ( 현재 노드가 목표 지점에 도달했을 때 )
			if (end == c) break;

			// 도착 안했을때
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

	// 그래프를 그래픽으로 표현하는 코드
	private:

		void calculateNodePos()	// 추가해주는 노드들을 레벨별로 좌표를 설정하는 코드
		{
			if (nodeCount == 0) return;

			vector<vector<int>> levels;		// 던전의 층을 저장하는 컨테이너
			vector<bool> processed(nodeCount, false);			// 방문한 노드를 기록

			levels.push_back({0}); // 시작지점 : 0층은 항상 0이다.
			processed[0] = true;   // 시작지점은 방문했다.

			int currentLevel = 0;
			while (currentLevel < levels.size()) // 각 층의 방의 갯수를 측정하는 코드
			{
				vector<int> nextLevel;

				for (int node : levels[currentLevel])
				{
					for (int neighbor : adj[node])
					{
						if (!processed[neighbor])
						{
							nextLevel.push_back(neighbor);
							processed[neighbor] = true;
						}
					}
					if (!nextLevel.empty())
					{
						levels.push_back(nextLevel);
					}
					currentLevel++; // 다음 층 계산하기
				}
				
			}

			//  모든 층의 레벨을 계산했으면, 각 노드가 몇 층에 있고, 몇번째에 있는지 기록이 된다.

			for (int level = 0; level < levels.size(); level++) // 0층 ~ 마지막 층 반복
			{
				int nodeLevel = levels[level].size();	// 각 층의 방의 갯수
				int spacing = CONSOLEWIDTH / (nodeLevel + 1);		// const ConsoleWIDTH = 80

				for (int i = 0; i <nodeLevel; i++)		// 
				{
					int nodeId = levels[level][i];		// n층 n번째 노드 = id
					nodes[nodeId].x = spacing * (i + 1);// i가 0부터 시작하기 때문에 1 더함
					nodes[nodeId].y = level * 2 + 2;	// 각 층의 여백 크기를 설정
				}
			}

		}
		void DrawCircle(vector<vector<char>>& screen, int x, int y)
		{
			screen[y][x] = '0';
		}
		void DrawLine(vector<vector<char>>& screen, int x1, int y1, int x2, int y2)
		{
			int dx = abs(x2 - x1);
			int	dy = abs(y2 - y1);

			int sx = (x1 < x2) ? 1 : -1;
			int sy = (y1 < y2) ? 1 : -1;

			int err = dx - dy;

			int x = x1;
			int y = y1;

			while (true)
			{
				if (x >= 0 && x <= CONSOLEWIDTH && y >= 0 && y < CONSOLEHEIGHT)
				{
					if (screen[y][x] == ' ')
					{
						screen[y][x] = '-';
					}
					if (x == x2 && y == y2) // x,y 좌표가 목표지점에 도달햇을 때 반복을 그만둔다.
					{
						break;
					}

					int e2 = 2 * err;
					if (e2 > -dy)
					{
						err -= dy;
						x += sx;
					}
					if (e2 < dx)
					{
						err += dx;
						y += sy;
					}

				}
			}

		}	// 점수 사이의 픽셀 선을 그리는 알고리즘 Bresenham
		void DrawEdge(vector<vector<char>>& screen)
		{
			for (int i = 0; i < nodeCount; i++)
			{
				for(int neighbor : adj[i])
				{
					DrawLine(screen, nodes[i].x, nodes[i].y, nodes[neighbor].x, nodes[neighbor].y);
				}
			}
		}
		void DrawNode(vector<vector<char>>& screen)
		{
			for (int i = 0; i < nodeCount; i++)
			{
				DrawCircle(screen, nodes[i].x, nodes[i].y);
			}
		}
		void printScreen(vector<vector<char>>& screen)
		{
			cout << endl;
			for (int y = 0; y < CONSOLEHEIGHT; y++)
			{
				for (int x = 0; x < CONSOLEWIDTH; x++)
				{
					cout << screen[y][x];
				}
				cout << endl;
			}
			cout << endl;
		}

	public:
		void drawGraph()
		{
			vector<vector<char>> screen(CONSOLEHEIGHT, vector<char>(CONSOLEWIDTH, ' '));

			calculateNodePos();
			DrawEdge(screen);			// 선을 먼저 그리고
			DrawNode(screen);				// 선 위에 점을 그린다. 
			printScreen(screen);
		}
};

int main()
{
	Spire spire;

	cout << "슬레이 더 스파이어의 맵 노드 구현 " << endl;

	spire.addNode("시작");			// 0
	spire.addNode("1층 전투방");	// 1
	spire.addNode("1층 전투방");	// 2
	spire.addNode("1층 전투방");	// 3
	spire.addNode("1층 전투방");	// 4
	spire.addNode("1층 전투방");	// 5

	spire.addNode("2층 엘리트 전투방");	// 6
	spire.addNode("2층 전투방");		// 7
	spire.addNode("2층 전투방");		// 8
	spire.addNode("2층 이벤트방");		// 9
	spire.addNode("2층 휴식방");		// 10

	spire.addNode("3층 전투방");		// 11
	spire.addNode("3층 이벤트방");		// 12
	spire.addNode("3층 휴식방");		// 13
	spire.addNode("3층 이벤트방");		// 14

	spire.addNode("4층 휴식방");		// 15
	spire.addNode("5층 보스방");		// 16

	///// 노드들의 선 정의

	// 하드코딩 버전
	
	// 0 ~ 1층
	spire.addEdge(0, 1); // 가장 왼쪽부터 표현하거나, 층별로 해도 된다.
	spire.addEdge(0, 2); 
	spire.addEdge(0, 3);
	spire.addEdge(0, 4);
	spire.addEdge(0, 5);

	// 1 ~ 2층
	spire.addEdge(1, 6); 
	spire.addEdge(2, 7);
	spire.addEdge(3, 8);
	spire.addEdge(4, 9);
	spire.addEdge(5, 10);

	// 2 ~ 3층
	spire.addEdge(6, 11); 
	spire.addEdge(7, 12);
	spire.addEdge(8, 12);
	spire.addEdge(9, 13);
	spire.addEdge(10, 14);

	// 3 ~ 4층
	spire.addEdge(11, 15); 
	spire.addEdge(12, 15);
	spire.addEdge(13, 15);
	spire.addEdge(14, 15);

	// 4 ~ 5층
	spire.addEdge(15, 16);

	spire.printGraph();
	spire.drawGraph();

	vector<int> temp = spire.findShortestPath(0, 16);

	for (auto& e : temp)
	{
		cout << e << " -> ";
	}

	// rand 함수로 구현해본다면?

}