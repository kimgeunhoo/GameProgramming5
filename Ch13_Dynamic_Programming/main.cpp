/*
	Ch_13 DP
	Dynamic Programming (���� ��ȹ��)

	[�ڷ���, Ŭ����(�Լ�), ������, �ڷᱸ��] 
	�˰��� ����, �Ƿ�. �ڵ带 �ۼ��ϴ� �ɷ��� ���ϱ� ���� ����
	���α׷��� ������ �� ������ �ִ°�? (���� �Ƿ�)

*/

/*
	�˰��� ���� ����
	- ����, Ž��, Ʈ�� ��ȸ, �׷��� ��ȸ, Ž��(DFS, BFS)
	- ������ȹ��, �׸��� �˰���, ���� Ž��...
	������ Ǫ�� �ذ� ���̵� �������� ������ ��
*/

/*
	DP ����
	- ���������� ��ȹ�� �����.
	- �ߺ��Ǵ� ������ �� ���� ����ؼ� �ذ��ϰ� �ʹ�.
	- �޸𸮿� ����� �ؼ� ����ϰڴ�.
*/

// 1. �Ǻ���ġ ����
// 1 ,2 ,3, 5, 8, 13, 21 ......
// index
// 0, 1, 2, 3, 4, 5 , 6

#include <iostream>
#include <vector>

int Fibonacci(int n)
{
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }
	
	// �ݺ���, ��� �Լ�
	

	//

	return Fibonacci(n - 1) + Fibonacci(n - 2);	
}

/*
	�� ��� ����� �Ǻ���ġ ������ ���� �ɸ���?
	n�� ���ڰ� Ŀ���� Ŀ������ Fibonacci�Լ��� ��� ����ȴ�.
	��� �Լ��� ����ϸ� n�� Ŀ���� Ŀ������ ���ÿ� �޸𸮰� ���δ�. => ���� �����÷ο� �߻�
	�ߺ��� �߻��ϴ� ������ �ذ��ϱ� ���� �޸� ������ Ȯ���ؼ� ������ �صξ��ٰ� ����ϰڴ�.(�޸����̼�)

*/

/*
	���� ��ȹ���� ���� ��Ŀ��� 
	Top - doen ��� : ��� ���
	bottom - up ��� : �ݺ��� : �����̳� ����
*/

int FiboDP(int n)	// bottom - up	(�ݺ���, �����̳�)
{
	if (n <= 1) { return n; }

	// �����͸� ������ �����̳� �����
	// n�� (n + 1)
	std::vector<int> vec; // int �����ϴ� ���� �迭 ����, �迭 �� ������ 0

	std::vector<int> dp(n + 1, 0); // n���� �� ������ �ִ� �迭 ���� ����
	
	// bottom - up ������ dp[n]���� �����ϱ� ���ؼ� dp[0] ~ dp[n] ä�� ������ ��

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
		// dp�� ���� �̹� �����Ѵٸ�. -1 �� �ƴϸ�
		// ����Լ� return ����, �Ʒ��� �ڱ��ڽ� �Լ��� �����Ѵ�.
		if (dp[n] != -1)
		{
			return dp[n];
		}

		dp[n] = FiboRecur(n - 1) + FiboRecur(n - 2);

		return dp[n];
	}
};

/*
	��� ������ ����

	����� �����µ�, 1��ܸ� �����ų� 2����� �ѹ��� �����ų�. �ΰ��� ������� ����� ���� �� �ִ�.
	��ܿ��� ������ ���� ���� �����ϴµ�, 3��° ����� �ö󰡱� ���ؼ��� �ΰ��� ����� ����
	���� ���, 2��° ����� �ö󰡴� ����� �ΰ��� ��� ���� (1 + 1) (2)
	�̶� ���� �ּ����� ������� n�� ����� ������ ����� �����غ���
	�ٽ� ���̵�� : n��° ����� �ּ������� �ö�� �Ѵ�. 1ĭ�� ���� �� vs 2ĭ�� ���� �� ���� �� �־�� �Ѵ�.
*/

/*
	����� ������ ����� ���� ���ϱ�.
	2��° ����� �ö󰡱� ���� ��� : (1,1), (2) = 2 n��° ����� ������ ���� ����� ���� ��ȯ�ϴ� �ڵ� �ۼ�
	CountStep(1) = 1;
	CountStep(2) = 2;
*/

/*
	cache : ĳ��(�ӽ÷� ����� ������ ����)
	�ߺ��Ǵ� ������ ���� �� �����͸� �����ؼ� ����ϸ� ������ ����� �� �ִ�.
	�޸� ������ ����ؾ��Ѵ�. "ĳ��" : ����ȭ ��� �� �ϳ��̴�.(�ð��� Ȯ�� ����)
*/

/*
	���� ������ ������ Dp�� Ǯ��޶�� ���� �����ʴ´�
	��� ������ ���� ������ ���� ������ DP�� Ǯ��� �ϰڱ��� ��� �ؾ���
	(1) �� ���丶�� Ű������� ���� - "�ּ�", "�����ϰ�" -> �ð� �ʰ� ����. ex) ����Լ�
	(2) ���⹮�� ���� - �������� ������ Ǯ��°�.
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

	std::unordered_map<int, int> exps; // �ؽø� �̿��� �ڷᱸ��, Ž������ �ſ� ������. ������ ���� ����Ǵ� �����̳�.
	std::unordered_map<int, int> damage;

	//std::unordered_map<int, UserData> exps; // �ؽø� �̿��� �ڷᱸ��, Ž������ �ſ� ������. ������ ���� ����Ǵ� �����̳�.
	//std::unordered_map<int, UserData> damage;
public:

	int CalculateDamage(int level)
	{
		// �Ʒ� �ڵ� �����ؼ� �����
		
		// �̹� �����Ͱ� �����ϸ� �ش� �����͸� �����ͼ� ���
		if (damage.find(level) != damage.end())
		{
			std::cout << "ĳ�ÿ��� ������ ������ (������ : " << level << ") : " << damage[level] << std::endl;
			return damage[level];
		}

		// �װ� �ƴ϶�� ������ �̿��ؼ� �����͸� �����ϰ� ���

		int Ndamage = level * 5 + level % 10;
		damage[level] = Ndamage;
		return Ndamage;
	}

	int CalculateExp(int level)
	{
		// 5���� ���� �ʿ��� ����ġ	1 -> 2, 2 -> 3, 3 -> 4, 4 -> 5....

		if (exps.find(level) != exps.end())
		{
			std::cout << "ĳ�ÿ��� �����͸� ������ (���� : " << level << ") : " << exps[level] << std::endl;
			return exps[level];
		}
		
		// ���ӿ��� ���� �� �ʿ��� ����ġ�� ���ϴ� ����.
		// y = x^2 + 2x + 1;

		int exp = level * (level + 100); // 101, 204
		exps[level] = exp;
		return exp;

	}
};

int CountStep(int n) // Bottom-up ������� ����
{
	if (n <= 1) { return 1; }

	std::vector<int> dp(n + 1, -1); // n+1 �ϴ� ������ dp[6] 0���� �������� �� 7��° ������ ����ؾ� ��


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
	std::cout << "=====�Ǻ���ġ ��� ����=====" << std::endl;

	std::cout << "����� : " << Fibonacci(6) << std::endl;
	
	std::cout << "�Ǻ���ġ�� 25��° ���ڸ� ����غ��� : " << Fibonacci(25) << std::endl;
	// ��� ������� �����ϸ� �ð� �ʰ��� �߻��Ѵ�.

	std::cout << "=====�Ǻ���ġ DP bottom ����=====" << std::endl;

	std::cout << "����� : " << FiboDP(6) << std::endl;

	std::cout << "�Ǻ���ġ DP Top-down ����" << std::endl;

	FiboRecursive fibo(6);
	std::cout << "����� : " << fibo.FiboRecur(6) << std::endl;

	std::cout << "��� ������ ����� �� ���" << std::endl;
	
	std::cout << "n��° ����� ������ ���� �ʿ��� ����� �� : "<< CountStep(6) << std::endl;

	std::cout << "���� ĳ�� ������ ����" << std::endl;

	GameCache gameCache;

	std::cout << "1���� ����ġ: " << gameCache.CalculateExp(1) << std::endl;
	std::cout << "1���� ����ġ: " << gameCache.CalculateExp(1) << std::endl;

	std::cout << "1���� ������: " << gameCache.CalculateDamage(1) << std::endl;
	std::cout << "1���� ������: " << gameCache.CalculateDamage(1) << std::endl;
}