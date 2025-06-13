#include <iostream>
#include <vector>
#include <algorithm>

/*
	nums �迭���� �׽�Ʈ ���̽��� ���´�.
	nums vector�� 1,3,7,9,,,, ���� ������ ���´�.
	�� ���ڸ� ������������ �����ϱ�. �� ���İ��� answer�� �����ؼ� ��ȯ�ϱ�
*/

/*
	�ڵ带 ���� �� �ִ� = �� ���� �˰��� �ڵ尡 �����Ѵ�.
	�ð� ���⵵, ���� ���⵵,
	�ּ� : �ڵ� ������ ���� ���� ����ϴ� �ڵ�.
	�ð��� ������ ������ �����ϰ�, �ð��� ������ ������ �� ����ϴ� ��찡 ����.
*/

/*
	O(1), (log n) (n) (n^2)

	���� ū ������ �Ű� ����.   (n^2 + 2n + 1)

	1000n		n^2 + 1

	1000		2

	n�� ũ�� 1		10			100 1000 1000,00O
	O(1)     1		 1			  1    1        1
	O(log n) 0		 1		      2    3        6      
	O(n)     1		 10         100 1000 1000,000
	O(n^2)   1

	����: ��κ��� �˰��� ������ �׽�Ʈ ���̽��� ���� ��츦 �����Ѵ�.
*/

/*
	�ð� ���⵵�ε� �� ���� �ð��� ���ϴ� ���� �ƴ϶� ���� Ƚ���� ���ϳ�?
	- ȯ�濡 ���� ������� �޶�����.
	- ���� Ƚ���� ������ ���� ���� ū ������ ������.
	- O(n) Big Oh(���) ǥ���

*/

#pragma region �ð� ���⵵ ����ϱ�

void Test1()
{
	// 1 ~ 5������ ���ڸ� ���� ���� ���� ���
	// for �ݺ� ����ؼ� sum�� ����

	int sum = 0;	// int Ÿ�� sum�� ���� 0�� �Ҵ�. ���� 1��.

	int n = 0;

	std::cin >> n;		// n�� ũ�Ⱑ �������� �ʾҴ�.

	for (int i = 1; i < 6; i++)
	{
		sum += i; // n�� ����ȴ�.
	}

	// 52 �ڵ��� ���� Ƚ�� : n + 3

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum += i * j; // n * n �� ����
		}
	}

	// 64 �ڵ��� ���� Ƚ�� : n^2 + n + 3

}

#pragma endregion


std::vector<int> solution(std::vector<int> nums)
{
	std::vector<int> answer;
	std::sort(nums.begin(), nums.end());	// STL �����Ǿ� �ִ� ������ ����ϰٴ�.
	answer = nums;
	return answer;
}

// ���ĵǾ� ���� ���� ���ڸ� �迭�� �޾ƿͼ� �� ���� �����ϴ� �Լ��� �����

// ���� ����, ���� ����, ���� ����

#pragma region ���� ����

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ������ ���������� �ð��� ���� �ɸ���.
void Bubble_sort(int arr[], int n) // �ð����⵵�� n^ �̴�
{
	// ����Ŭ�� ��� ���ƾ� �ϴ°�?
	for (int i = 0; i < n - 1; i++) // n - 1�� (3)
	{
		for (int j = 0; j < n - 1 - i; j++) // j, i, 3���� ǥ���Ϸ���
		{
			// swap ���� ����
			if (arr[j] > arr[j + 1]) // ���� ���� �ٷ� ���� ������ ũ�� ���� ����
			{
				// swap�� ����
				std::swap(arr[j], arr[j + 1]); // (n-1) * (n - i - 1) ��ŭ ����

			}
		}
		
	}

	// ����Ŭ ���� ������ �ؾ� �ϴ°�?
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	// 1. �迭 ��ҳ��� �񱳸� �Ѵ�.
	// 2. (k��°) (k+1) ū ��쿡 �迭 ��Ҹ� �����Ѵ�.
}

// vector.size()

// �ð� ���⵵ : O(n^2)
// �ּ�, �־�, ���
// ���� ����	: �ּ�(O(n)), �־�(O(n^2)), ���(O(n^2))

void Bubble_sort(std::vector<int> nums)
{
	int size = nums.size();

	// ����Ŭ�� ��� ���ƾ� �ϴ°�?
	for (int i = 0; i < size - 1; i++) { // �ڽŰ��� �񱳸� ���ص� �Ǽ� -1.
		for (int j = 0; j < size - 1 - i; j++) // �� ����Ŭ ���� ���ϴ� Ƚ��, ����Ŭ ���� �پ���.
		{

			if (nums[j] > nums[j+1])
			{
				std::swap(nums[j], nums[j + 1]);
			}
			
		}
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << nums[i] << " ";
	}

	std::cout << std::endl;
	// ����Ŭ ���� ������ �ؾ� �ϴ°�?


	// 1. �迭 ��ҳ��� �񱳸� �Ѵ�.
	// 2. (k��°) (k+1) ū ��쿡 �迭 ��Ҹ� �����Ѵ�.
}

#pragma endregion

#pragma region ���� ����

// ���� ���� ���� ����,
// �� �տ� ������ ������� �����Ѵ�
// ����Ŭ���� ���� ���� ���� ����� ��ġ�� ã�ƾ� �Ѵ�.

// �ð� ���⵵: O(n^2), O(n)

// Min()�Լ�. ��ü �迭 �� ���� ���� ���� ��ȯ�ϴ� �Լ�.

void Selection_sort(int arr[], int n)
{
	// �� �� ����Ŭ�� ���ƾ� �ϳ�?
	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		// arr[j]�� ����, ���� ���� ��(Index) arr[min]
		for (int j = i + 1; j < n; j++)
		{
			// swap arr��, arr[min]
			if (arr[min_idx] > arr[j]) // arr[min_idx]		arr[j] ���ؼ� ������ �ּҰ�
			{
				min_idx = j;
			}
		}

		if (i != min_idx)
		{
			std::swap(arr[i], arr[min_idx]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void Selection_sort(std::vector<int> nums)
{
	int size = nums.size();

	for (int i = 0; i < size - 1; i++)
	{
		int min_idx = i;
		for (int j = i+1; j < size; j++)
		{
			if (nums[min_idx] > nums[j])
			{
				min_idx = j;
			}
		}
		if (i != min_idx)
		{
			std::swap(nums[i], nums[min_idx]);
		}
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << nums[i] << " ";
	}

	std::cout << std::endl;

}

#pragma endregion

#pragma region ���� ����

void Insert_sort()
{

}

#pragma endregion


void Execute()
{
	std::vector<int> nums = { 1,2,6,3,5,4 };

	auto v = solution(nums);

	for (auto& elem : v)
	{
		std::cout << elem << " ";
	}

	std::cout << std::endl;
}

int main()
{
	//Execute();
	//Test1();

	std::cout << "\n ���� ���� �ڵ� ����" << std::endl;

	int n = 6;
	int arr1[6] = { 3,4,6,9,1,2 };
	
	Bubble_sort(arr1, 6);

	std::cout << "\n ���� ���� �ڵ� ����2" << std::endl;
	std::vector<int> arr2 = { 3,5,1,2,4 };
	Bubble_sort(arr2);

	std::cout << "\n ���� ���� �ڵ� ����1" << std::endl;
	int arr3[5] = { 3,4,6,1,2 };
	Selection_sort(arr3, 5);

	std::cout << "\n ���� ���� �ڵ� ����2" << std::endl;
	std::vector<int> arr4 = { 3,5,1,2,4 };
	Selection_sort(arr4);
}

