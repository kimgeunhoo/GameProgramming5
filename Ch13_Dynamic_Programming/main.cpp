/*
	Ch_13 DP
	Dynamic Programming (동적 계획법)

	[자료형, 클래스(함수), 포인터, 자료구조] 
	알고리즘 시험, 실력. 코드를 작성하는 능력을 평가하기 위한 시험
	프로그래밍 사고력을 잘 가지고 있는가? (기초 실력)

*/

/*
	알고리즘 기출 문제
	- 정렬, 탐색, 트리 순회, 그래프 순회, 탐색(DFS, BFS)
	- 동적계획법, 그리디 알고리즘, 완전 탐색...
	문제를 푸는 해결 아이디어를 개념으로 정의한 것
*/

/*
	DP 개념
	- 절차적으로 계획을 세운다.
	- 중복되는 문제를 한 번만 사용해서 해결하고 싶다.
	- 메모리에 기억을 해서 사용하겠다.
*/

// 1. 피보나치 구현
// 1 ,2 ,3, 5, 8, 13, 21 ......
// index
// 0, 1, 2, 3, 4, 5 , 6

#include <iostream>
#include <vector>

int Fibonacci(int n)
{
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	
	// 반복문, 재귀 함수
	

	//

	return Fibonacci(n - 1) + Fibonacci(n - 2);	
}

/*
	왜 재귀 방식의 피보나치 구현이 오래 걸릴까?
	n의 숫자가 커지면 커질수록 Fibonacci함수가 계속 실행된다.
	재귀 함수를 사용하면 n이 커지면 커질수록 스택에 메모리가 쌓인다. => 스택 오버플로우 발생
	중복이 발생하는 문제를 해결하기 위해 메모리 공간을 확보해서 저장을 해두었다가 사용하겠다.(메모리제이션)

*/

/*
	동적 계획법의 구현 방식에는 
	Top - doen 방식 : 재귀 방식
	bottom - up 방식 : 반복문 : 컨테이너 구현
*/

int FiboDP(int n)	// bottom - up	(반복문, 컨테이너)
{
	if (n <= 1) { return n; }

	// 데이터를 저장할 컨테이너 만들기
	// n개 (n + 1)
	std::vector<int> vec; // int 가정하는 가변 배열 선언, 배열 내 데이터 0

	std::vector<int> dp(n + 1, 0); // n개의 빈 공간이 있는 배열 만들어서 생성
	
	// bottom - up 목적은 dp[n]까지 도달하기 위해서 dp[0] ~ dp[n] 채워 나가는 것

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

class FiboRecursive	// Top - down
{
private:
	std::vector<int> dp;

public:
	FiboRecursive(int n)
	{
		dp.resize(n + 1, -1);
		dp[0] = 0;
		dp[1] = 1;

	}

	int FiboRecur(int n)
	{
		// dp에 값이 이미 존재한다면. -1 이 아니면
		// 재귀함수 return 실행, 아래에 자기자신 함수를 실행한다.
		if (dp[n] != -1)
		{
			return dp[n];
		}

		dp[n] = FiboRecur(n - 1) + FiboRecur(n - 2);

		return dp[n];
	}
};

/*
	계단 오르기 문제

	계단을 오르는데, 1계단만 오르거나 2계단을 한번에 오르거나. 두가지 방식으로 계단을 오를 수 있다.
	계단에는 오르기 위한 값이 존재하는데, 3번째 계단을 올라가기 위해서는 두가지 방식이 존재
	예를 들어, 2번째 계단을 올라가는 방식은 두가지 방식 존재 (1 + 1) (2)
	이때 가장 최소한의 비용으로 n의 계단을 오르는 방법을 구현해보기
	핵심 아이디어 : n번째 계단을 최소한으로 올라야 한다. 1칸씩 오를 때 vs 2칸씩 오를 때 비교할 수 있어야 한다.
*/

/*
	계단을 오르는 경우의 수를 구하기.
	2번째 계단을 올라가기 위한 방법 : (1,1), (2) = 2 n번째 계단을 오르기 위한 경우의 수를 반환하는 코드 작성
	CountStep(1) = 1;
	CountStep(2) = 2;
*/

/*
	cache : 캐시(임시로 저장된 데이터 더미)
	중복되는 사항이 있을 때 데이터를 저장해서 사용하면 빠르게 사용할 수 있다.
	메모리 공간을 사용해야한다. "캐싱" : 최적화 방법 중 하나이다.(시간을 확보 가능)
*/

/*
	시험 문제로 나오면 Dp로 풀어달라는 말은 하지않는다
	계단 문제를 읽은 다음에 다음 문제가 DP로 풀어야 하겠구나 사고를 해야함
	(1) 각 개념마다 키워드들이 존재 - "최소", "저렴하게" -> 시간 초과 함정. ex) 재귀함수
	(2) 기출문제 존재 - 경험으로 문제를 풀어보는것.
*/
#include <unordered_map>

class GameCache
{
private:

	struct UserData
	{
		int level;
		int exps;
		int damage;
	};

	std::unordered_map<int, int> exps; // 해시를 이용한 자료구조, 탐색에서 매우 빠르다. 순서가 없이 저장되는 컨테이너.
	std::unordered_map<int, int> damage;

	//std::unordered_map<int, UserData> exps; // 해시를 이용한 자료구조, 탐색에서 매우 빠르다. 순서가 없이 저장되는 컨테이너.
	//std::unordered_map<int, UserData> damage;
public:

	int CalculateDamage(int level)
	{
		// 아래 코드 참고해서 만들기
		
		// 이미 데이터가 존재하면 해당 데이터를 가져와서 사용
		if (damage.find(level) != damage.end())
		{
			std::cout << "캐시에서 데이터 가져옴 (데미지 : " << level << ") : " << damage[level] << std::endl;
			return damage[level];
		}

		// 그게 아니라면 계산식을 이용해서 데이터를 저장하고 출력

		int Ndamage = level * 5 + level % 10;
		damage[level] = Ndamage;
		return Ndamage;
	}

	int CalculateExp(int level)
	{
		// 5레벨 까지 필요한 경험치	1 -> 2, 2 -> 3, 3 -> 4, 4 -> 5....

		if (exps.find(level) != exps.end())
		{
			std::cout << "캐시에서 데이터를 가져옴 (레벨 : " << level << ") : " << exps[level] << std::endl;
			return exps[level];
		}
		
		// 게임에서 레벨 당 필요한 경험치를 구하는 공식.
		// y = x^2 + 2x + 1;

		int exp = level * (level + 100); // 101, 204
		exps[level] = exp;
		return exp;

	}
};

int CountStep(int n) // Bottom-up 방식으로 구현
{
	if (n <= 1) { return 1; }

	std::vector<int> dp(n + 1, -1); // n+1 하는 이유는 dp[6] 0부터 시작했을 때 7번째 데이터 사용해야 함


	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];

}

int main()
{
	std::cout << "=====피보나치 재귀 구현=====" << std::endl;

	std::cout << "결과값 : " << Fibonacci(6) << std::endl;
	
	std::cout << "피보나치의 25번째 숫자를 출력해보기 : " << Fibonacci(25) << std::endl;
	// 재귀 방식으로 구현하면 시간 초과가 발생한다.

	std::cout << "=====피보나치 DP bottom 구현=====" << std::endl;

	std::cout << "결과값 : " << FiboDP(6) << std::endl;

	std::cout << "피보나치 DP Top-down 구현" << std::endl;

	FiboRecursive fibo(6);
	std::cout << "결과값 : " << fibo.FiboRecur(6) << std::endl;

	std::cout << "계단 오르기 경우의 수 출력" << std::endl;
	
	std::cout << "n번째 계단을 오르기 위해 필요한 경우의 수 : "<< CountStep(6) << std::endl;

	std::cout << "게임 캐싱 데이터 예제" << std::endl;

	GameCache gameCache;

	std::cout << "1레벨 경험치: " << gameCache.CalculateExp(1) << std::endl;
	std::cout << "1레벨 경험치: " << gameCache.CalculateExp(1) << std::endl;

	std::cout << "1레벨 데미지: " << gameCache.CalculateDamage(1) << std::endl;
	std::cout << "1레벨 데미지: " << gameCache.CalculateDamage(1) << std::endl;
}