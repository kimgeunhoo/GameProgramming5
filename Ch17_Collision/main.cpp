#include <iostream>
#include <vector>
#include <cmath>		// sqrt
using namespace std;

/*
	�浹 : 
	��	 : �簢���� ����, ���
	bounding box
*/

struct Rectangle
{
	int x;
	int y;
	int width;
	int height;

	Rectangle(int _x, int _y, int _width, int _height)
		: x(_x), y(_y), width(_width), height(_height) {}
};

// ���� 1. �� �簢���� ��ġ�� "��Ĩ�ϴ�" ���
// �׷��� ������ ��ġ�� �ʽ��ϴ� ����ϴ� �Լ� �����

/*
	��ǥ�� ���ϴ� �ڵ� �����ϱ�
	��� �������� ��ġ�� �ʴ��� Ȯ���Ҽ� �ִ���
*/

/*
	AABB �浹
	Axis Aligned Bonding Box
*/

bool collisionCheck(Rectangle r1, Rectangle r2)
{
	
	bool x_overlap = (r1.x + r1.width >= r2.x) && (r1.x <= r2.x + r2.width); 
	// case1. r1 x�� r2 x�� ��ħ

	bool y_overlap = (r1.y + r1.height >= r2.y) && (r2.y <= r2.y + r2.height);
	// case2. r1 y�� r2 y�� ��ħ

	bool IsCollison = x_overlap && y_overlap;

	if (IsCollison) // ��ĥ ��
	{
		cout << "��Ĩ�ϴ�" << endl;
		return true;
	}
	else
	{
		cout << "��ġ�� �ʽ��ϴ�." << endl;
		return false;
	}

}

// ���� �浹
// circle collision check
// �� ���� ����, ������,
// ���� ������ �Ÿ� (distance) d = (��Ÿ����� ���� �̿��ؼ� ���ϱ�)
// d (<, =, >) r1 + r2; �浹���� �Ǵ�

struct Circle
{
	// ����
	double x;
	double y;
	// ������
	double radius;
	// ������

	Circle(double _x, double _y, double _radius) 
		: x(_x), y(_y), radius(_radius) {}
};

// Detection �Լ�, Ŭ����, � ������� �浹 üũ�� �ұ�?

bool circleCheck(Circle c1, Circle c2)
{
	// ����

	double dx = c1.x - c2.x; // ���� ���̿� ���� ����. ������ ���ֱ� ������ ��� ���� ��� x
	double dy = c1.y - c2.y; // �ٸ� Ÿ���� ������ ���ɼ� �־�� �Ѵ�. unsigned ����

	// pow ����ص� �ǳ� ^2�̶� ���� ���ص���
	double distanceSq = (dx * dx) + (dy * dy);

	// 1. �������� ���ϱ�
	// (c1.radius + c2.radius) * (c1.radius + c2.radius);
	// 2. sqrt(distanceSq) - ���� ���� ���� ��

	// case 1. ���� Ŀ���� �����÷ο� ���� ������ ����
	// case 2. ���� Ŀ���� ������ ������ �������� ������ �� ����

	bool isCollision = sqrt(distanceSq) <= (c1.radius + c2.radius);

	if (isCollision)
	{
		cout << "�浹�Ѵ�" << endl;
		return true;
	}
	else 
	{
		cout << "�浹���� �ʴ´�." << endl;
		return false;
	}
}

// ch16 DrawBox ch17�� ��������
// �� �簢�� ��ġ���� Ȯ��
// ���࿡ �� �簢���� ��ġ�� �浹�� ������Ʈ�� �׸��� ���ÿ�

class Bullet
{
	
public:
	Rectangle collider;
	bool	  isCollision;
	Bullet(Rectangle _col)
		: collider(_col), isCollision(false) {}

	void IsCollisionCheck(const Bullet& other)
	{
		if (collisionCheck(collider, other.collider)) // �浹������
		{
			isCollision = true;
		}
		else
		{
			isCollision = false;
		}

		// isCollision�� �� ����
		
	}
};

int main()
{
	Rectangle r1(3, 3, 4, 4);
	Rectangle r2(3, 3, 4, 4);
	
	collisionCheck(r1, r2);

	Circle c1(1, 1, 3);
	Circle c2(8, 8, 2);
	circleCheck(c1, c2);

	// ���� �浹 ��� ����

	Bullet bullet(r1);
	Bullet bullet2(r2);

	bullet.IsCollisionCheck(bullet2);

	if (bullet.isCollision)
	{
		// �׸��� ���ÿ�
		cout << "Not Drawing" << endl;
	}
	else
	{
		cout << "Drawing" << endl;
	}

}

