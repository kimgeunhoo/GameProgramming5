/*
	���ӿ��� ��ġ�� ǥ���ϴ� ��� (2D)
	map 2���� �迭.
	�̷� ã�� (maze), AI ���� Ż�ⱸ���� �̵��ϴ� �ڵ� �ۼ�
*/

#include <iostream>
#include <vector>
#include <Windows.h>

#define SIZE 10

// 0 �̵� ����, 1 ��
// �Ա��� (x, y) = (1, 0)
// �ⱸ�� (x, y) = (9, 5)
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

// maze[y][x]�� ���� 0�̸� '  ' ��

// ���� (��, ��, ��, ��)
// �� : x�� ��ȭ? 0 y�� ��ȭ? -1
// �� : x�� ��ȭ? 0 y�� ��ȭ? 1
// �� : x -2 y 0
// �� : x 2 y 0

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
	// ���� �ݺ��� ���
	for (int y = 0; y < SIZE; y++) 
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (maze[y][x] == 1)
			{
				std::cout << "��";
			}
			else if (maze[y][x] == 0)
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}

#pragma region �̵��� ���� �̸� ����� �д�.
	//std::vector<int> direction = {1,1,1,3,3,0,0,3,3,1,3,1,1,1,2,2,2,1,1,1,3,3,3,3,3,0,0,0,3};
	//int sx = 2; int sy = 0;	  // *2
	//GoToXY(sx, sy);
	//

	//int pre_x = sx;
	//int pre_y = sy;

	////direction ���ڸ� �޾ƿͼ� GoToXY ��ǥ�� �����غ��ÿ�

	//for (int i = 0; i < direction.size(); i++)
	//{
	//	// system("cls");
	//	// ��ȿ����

	//	// pre_x, pre_Y ���� ��ġ�� ����. "  " ����ؼ� �ܻ� ����
	//	// std::cout << "  ";
	//	// �ܻ��� ���� ���� �ذ�
	//	
	//	GoToXY(pre_x, pre_y);
	//	std::cout << "  ";

	//	int dir = direction[i];
	//	sy += dy[dir];
	//	sx += dx[dir];
	//	pre_x = sx;
	//	pre_y = sy;
	//	GoToXY(sx, sy);

	//	std::cout << "��";

	//	Sleep(500);
	//}

#pragma endregion

#pragma region ���� ���� �̵��ϴ� ����

// 1. ������ ���� ���� ���Ͱ� ���ʴ�� ������ �ڵ带 �ۼ��� ������. (���潺 ����)

// vector<int> path = {}
	std::vector<int> path = { 1,1,1,3,3,0,0,3,3,1,3,1,1,1,2,2,2,1,1,1,3,3,3,3,3,0,0,0,3 };
	int monster_count = 5; 
	int interval = 2;
	int steps = path.size() + monster_count + interval; // ��ü ������ �̵��Ÿ�
	int sx = 2; int sy = 0;	  // *2

	std::vector<Monster> monsters;

	for (int i = 0; i < steps; i++)
	{
		if (i % interval == 0 && monsters.size() < monster_count)
		{
			monsters.emplace_back(sx, sy, path);
		}

		//direction ���ڸ� �޾ƿͼ� GoToXY ��ǥ�� �����غ��ÿ�

		for (int i = 0; i < monsters.size(); i++)
		{
			Monster& monster = monsters[i];

			if (monster.step >= monster.direction.size()) continue;


			// pre_x, pre_Y ���� ��ġ�� ����. "  " ����ؼ� �ܻ� ����
			// std::cout << "  ";
			// �ܻ��� ���� ���� �ذ�

			GoToXY(monster.prev_x, monster.prev_y);
			std::cout << "  ";

			int dir = monster.direction[monster.step];
			monster.y += dy[dir];
			monster.x += dx[dir];
			monster.prev_x = monster.x;
			monster.prev_y = monster.y;
			monster.step++;


			GoToXY(monster.x, monster.y);

			std::cout << "��";

			Sleep(500);
		}

	}

	

#pragma endregion


// 2. �������� ���Ͱ� ������ �������� �����̴� �ڵ带 �ۼ�

// 3. �ʿ� ���� ���� ������ �ڵ����� ã���ִ� �ڵ带 �ۼ��ϱ�(��ã�� ����, DFS, BFS)


}





