#include <iostream>
#include <vector>
#include <cmath>		// sqrt
using namespace std;

/*
	충돌 : 
	면	 : 사각형의 넓이, 경계
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

// 문제 1. 두 사각형이 겹치면 "겹칩니다" 출력
// 그렇지 않으면 겹치지 않습니다 출력하는 함수 만들기

/*
	좌표를 비교하는 코드 구현하기
	몇개를 비교했을때 겹치지 않는지 확인할수 있는지
*/

/*
	AABB 충돌
	Axis Aligned Bonding Box
*/

bool collisionCheck(Rectangle r1, Rectangle r2)
{
	
	bool x_overlap = (r1.x + r1.width >= r2.x) && (r1.x <= r2.x + r2.width); 
	// case1. r1 x와 r2 x가 겹침

	bool y_overlap = (r1.y + r1.height >= r2.y) && (r2.y <= r2.y + r2.height);
	// case2. r1 y와 r2 y가 겹침

	bool IsCollison = x_overlap && y_overlap;

	if (IsCollison) // 겹칠 떄
	{
		cout << "겹칩니다" << endl;
		return true;
	}
	else
	{
		cout << "겹치지 않습니다." << endl;
		return false;
	}

}

// 구형 충돌
// circle collision check
// 두 원의 원점, 반지름,
// 원점 사이의 거리 (distance) d = (피타고라스의 정리 이용해서 구하기)
// d (<, =, >) r1 + r2; 충돌여부 판단

struct Circle
{
	// 원점
	double x;
	double y;
	// 반지름
	double radius;
	// 생성자

	Circle(double _x, double _y, double _radius) 
		: x(_x), y(_y), radius(_radius) {}
};

// Detection 함수, 클래스, 어떤 방식으로 충돌 체크를 할까?

bool circleCheck(Circle c1, Circle c2)
{
	// 조건

	double dx = c1.x - c2.x; // 가로 길이와 세로 길이. 제곱을 해주기 때문에 양수 음수 상관 x
	double dy = c1.y - c2.y; // 다만 타입이 음수가 사용될수 있어야 한다. unsigned 못씀

	// pow 사용해도 되나 ^2이라 굳이 안해도댐
	double distanceSq = (dx * dx) + (dy * dy);

	// 1. 제곱끼리 비교하기
	// (c1.radius + c2.radius) * (c1.radius + c2.radius);
	// 2. sqrt(distanceSq) - 제곱 안한 수를 비교

	// case 1. 값이 커지면 오버플로우 터질 위험이 높음
	// case 2. 값이 커지진 않으나 연산이 많아져서 느려질 수 있음

	bool isCollision = sqrt(distanceSq) <= (c1.radius + c2.radius);

	if (isCollision)
	{
		cout << "충돌한다" << endl;
		return true;
	}
	else 
	{
		cout << "충돌하지 않는다." << endl;
		return false;
	}
}

// ch16 DrawBox ch17에 가져오기
// 두 사각형 겹치는지 확인
// 만약에 두 사각형이 겹치면 충돌한 오브젝트를 그리지 마시오

class Bullet
{
	
public:
	Rectangle collider;
	bool	  isCollision;
	Bullet(Rectangle _col)
		: collider(_col), isCollision(false) {}

	void IsCollisionCheck(const Bullet& other)
	{
		if (collisionCheck(collider, other.collider)) // 충돌했을때
		{
			isCollision = true;
		}
		else
		{
			isCollision = false;
		}

		// isCollision의 값 변경
		
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

	// 게임 충돌 사용 예시

	Bullet bullet(r1);
	Bullet bullet2(r2);

	bullet.IsCollisionCheck(bullet2);

	if (bullet.isCollision)
	{
		// 그리지 마시오
		cout << "Not Drawing" << endl;
	}
	else
	{
		cout << "Drawing" << endl;
	}

}

