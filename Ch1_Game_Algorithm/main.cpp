/*
	게임에서 위치를 표현하는 방법 (2D)
	map 2차원 배열.
	미로 찾기 (maze), AI 존재 탈출구까지 이동하는 코드 작성
*/

#include <iostream>
#include <vector>
#include <Windows.h>

#define SIZE 10

// 0 이동 공간, 1 벽
// 입구를 (x, y) = (1, 0)
// 출구는 (x, y) = (9, 5)
int maze[SIZE][SIZE] =
{
	{1,0,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,1,1,1,1},
	{1,0,1,0,1,0,0,1,0,1},
	{1,0,0,0,0,1,0,1,0,1},
	{1,0,1,1,1,1,0,1,0,1},
	{1,0,1,0,0,0,0,1,0,0},
	{1,0,1,0,1,1,1,1,0,1},
	{1,1,1,0,1,0,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

// maze[y][x]의 값이 0이면 '  ' ■

// 방향 (상, 하, 좌, 우)
// 상 : x의 변화? 0 y의 변화? -1
// 하 : x의 변화? 0 y의 변화? 1
// 좌 : x -2 y 0
// 우 : x 2 y 0

const int dx[4] = { 0,0,-2,2 };

const int dy[4] = { -1,1,0,0 };

struct Monster
{
	int x, y;
	int prev_x, prev_y;
	int step;
	std::vector<int> direction;

	Monster() = default;
	Monster(int x, int y, std::vector<int> direction) : x(x), y(y), direction(direction) 
	{
		prev_x = x;
		prev_y = y;
		step = 0;
	}

};


void GoToXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

int main()
{
	// 이중 반복문 사용
	for (int y = 0; y < SIZE; y++) 
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (maze[y][x] == 1)
			{
				std::cout << "■";
			}
			else if (maze[y][x] == 0)
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}

#pragma region 이동할 길을 미리 만들어 둔다.
	//std::vector<int> direction = {1,1,1,3,3,0,0,3,3,1,3,1,1,1,2,2,2,1,1,1,3,3,3,3,3,0,0,0,3};
	//int sx = 2; int sy = 0;	  // *2
	//GoToXY(sx, sy);
	//

	//int pre_x = sx;
	//int pre_y = sy;

	////direction 숫자를 받아와서 GoToXY 좌표를 변경해보시오

	//for (int i = 0; i < direction.size(); i++)
	//{
	//	// system("cls");
	//	// 비효율적

	//	// pre_x, pre_Y 이전 위치값 저장. "  " 출력해서 잔상 제거
	//	// std::cout << "  ";
	//	// 잔상이 남는 현상 해결
	//	
	//	GoToXY(pre_x, pre_y);
	//	std::cout << "  ";

	//	int dir = direction[i];
	//	sy += dy[dir];
	//	sx += dx[dir];
	//	pre_x = sx;
	//	pre_y = sy;
	//	GoToXY(sx, sy);

	//	std::cout << "○";

	//	Sleep(500);
	//}

#pragma endregion

#pragma region 길을 따라 이동하는 몬스터

// 1. 정해진 길을 따라 몬스터가 차례대로 나오는 코드를 작성해 보세요. (디펜스 게임)

// vector<int> path = {}
	std::vector<int> path = { 1,1,1,3,3,0,0,3,3,1,3,1,1,1,2,2,2,1,1,1,3,3,3,3,3,0,0,0,3 };
	int monster_count = 5; 
	int interval = 2;
	int steps = path.size() + monster_count + interval; // 전체 몬스터의 이동거리
	int sx = 2; int sy = 0;	  // *2

	std::vector<Monster> monsters;

	for (int i = 0; i < steps; i++)
	{
		if (i % interval == 0 && monsters.size() < monster_count)
		{
			monsters.emplace_back(sx, sy, path);
		}

		//direction 숫자를 받아와서 GoToXY 좌표를 변경해보시오

		for (int i = 0; i < monsters.size(); i++)
		{
			Monster& monster = monsters[i];

			if (monster.step >= monster.direction.size()) continue;


			// pre_x, pre_Y 이전 위치값 저장. "  " 출력해서 잔상 제거
			// std::cout << "  ";
			// 잔상이 남는 현상 해결

			GoToXY(monster.prev_x, monster.prev_y);
			std::cout << "  ";

			int dir = monster.direction[monster.step];
			monster.y += dy[dir];
			monster.x += dx[dir];
			monster.prev_x = monster.x;
			monster.prev_y = monster.y;
			monster.step++;


			GoToXY(monster.x, monster.y);

			std::cout << "○";

			Sleep(500);
		}

	}

	

#pragma endregion


// 2. 여러가지 몬스터가 각자의 방향으로 움직이는 코드를 작성

// 3. 맵에 따라서 도착 지점을 자동으로 찾아주는 코드를 작성하기(길찾기 문제, DFS, BFS)


}





