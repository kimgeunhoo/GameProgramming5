#include <iostream>
#include <vector>
#include <algorithm>

/*
	nums 배열에는 테스트 케이스가 들어온다.
	nums vector에 1,3,7,9,,,, 랜덤 정수가 들어온다.
	이 숫자를 오름차순으로 정렬하기. 그 정렬값을 answer에 저장해서 반환하기
*/

/*
	코드를 평가할 수 있다 = 더 좋은 알고리즘 코드가 존재한다.
	시간 복잡도, 공간 복잡도,
	최선 : 코드 빠르고 공간 적게 사용하는 코드.
	시간이 빠르면 공간이 복잡하고, 시간이 느리면 공간을 덜 사용하는 경우가 많다.
*/

/*
	O(1), (log n) (n) (n^2)

	가장 큰 차수만 신경 쓴다.   (n^2 + 2n + 1)

	1000n		n^2 + 1

	1000		2

	n의 크기 1		10			100 1000 1000,00O
	O(1)     1		 1			  1    1        1
	O(log n) 0		 1		      2    3        6      
	O(n)     1		 10         100 1000 1000,000
	O(n^2)   1

	정리: 대부분의 알고리즘 문제는 테스트 케이스가 많은 경우를 상정한다.
*/

/*
	시간 복잡도인데 왜 실행 시간을 비교하는 것이 아니라 실행 횟수를 비교하나?
	- 환경에 따라 결과값이 달라진다.
	- 실행 횟수를 식으로 만들어서 가장 큰 차수로 비교하자.
	- O(n) Big Oh(빅오) 표기법

*/

#pragma region 시간 복잡도 계산하기

void Test1()
{
	// 1 ~ 5까지의 숫자를 전부 더한 값을 출력
	// for 반복 사용해서 sum에 저장

	int sum = 0;	// int 타입 sum의 값에 0을 할당. 실행 1번.

	int n = 0;

	std::cin >> n;		// n은 크기가 정해지지 않았다.

	for (int i = 1; i < 6; i++)
	{
		sum += i; // n번 실행된다.
	}

	// 52 코드의 실행 횟수 : n + 3

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum += i * j; // n * n 번 실행
		}
	}

	// 64 코드의 실행 횟수 : n^2 + n + 3

}

#pragma endregion


std::vector<int> solution(std::vector<int> nums)
{
	std::vector<int> answer;
	std::sort(nums.begin(), nums.end());	// STL 구현되어 있는 정렬을 사용하겟다.
	answer = nums;
	return answer;
}

// 정렬되어 있지 않은 숫자를 배열로 받아와서 그 수를 정렬하는 함수를 만들기

// 버블 정렬, 선택 정렬, 삽입 정렬

#pragma region 버블 정렬

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 구현은 간단하지만 시간은 오래 걸린다.
void Bubble_sort(int arr[], int n) // 시간복잡도는 n^ 이다
{
	// 사이클이 몇번 돌아야 하는가?
	for (int i = 0; i < n - 1; i++) // n - 1번 (3)
	{
		for (int j = 0; j < n - 1 - i; j++) // j, i, 3번을 표현하려면
		{
			// swap 조건 정의
			if (arr[j] > arr[j + 1]) // 왼쪽 원소 바로 뒤의 값보다 크면 값을 변경
			{
				// swap을 실행
				std::swap(arr[j], arr[j + 1]); // (n-1) * (n - i - 1) 만큼 실행

			}
		}
		
	}

	// 사이클 마다 무엇을 해야 하는가?
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	// 1. 배열 요소끼리 비교를 한다.
	// 2. (k번째) (k+1) 큰 경우에 배열 요소를 변경한다.
}

// vector.size()

// 시간 복잡도 : O(n^2)
// 최선, 최악, 평균
// 버블 정렬	: 최선(O(n)), 최악(O(n^2)), 평균(O(n^2))

void Bubble_sort(std::vector<int> nums)
{
	int size = nums.size();

	// 사이클이 몇번 돌아야 하는가?
	for (int i = 0; i < size - 1; i++) { // 자신과는 비교를 안해도 되서 -1.
		for (int j = 0; j < size - 1 - i; j++) // 각 사이클 마다 비교하는 횟수, 사이클 마다 줄어든다.
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
	// 사이클 마다 무엇을 해야 하는가?


	// 1. 배열 요소끼리 비교를 한다.
	// 2. (k번째) (k+1) 큰 경우에 배열 요소를 변경한다.
}

#pragma endregion

#pragma region 선택 정렬

// 가장 작은 수를 선택,
// 맨 앞에 보내는 방법으로 정렬한다
// 사이클마다 가장 작은 수가 저장된 위치를 찾아야 한다.

// 시간 복잡도: O(n^2), O(n)

// Min()함수. 전체 배열 중 가장 작은 값을 반환하는 함수.

void Selection_sort(int arr[], int n)
{
	// 몇 번 사이클을 돌아야 하나?
	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		// arr[j]의 값과, 가장 작은 값(Index) arr[min]
		for (int j = i + 1; j < n; j++)
		{
			// swap arr값, arr[min]
			if (arr[min_idx] > arr[j]) // arr[min_idx]		arr[j] 비교해서 작으면 최소값
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

#pragma region 삽입 정렬

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

	std::cout << "\n 버블 정렬 코드 예시" << std::endl;

	int n = 6;
	int arr1[6] = { 3,4,6,9,1,2 };
	
	Bubble_sort(arr1, 6);

	std::cout << "\n 버블 정렬 코드 예시2" << std::endl;
	std::vector<int> arr2 = { 3,5,1,2,4 };
	Bubble_sort(arr2);

	std::cout << "\n 선택 정렬 코드 예시1" << std::endl;
	int arr3[5] = { 3,4,6,1,2 };
	Selection_sort(arr3, 5);

	std::cout << "\n 선택 정렬 코드 예시2" << std::endl;
	std::vector<int> arr4 = { 3,5,1,2,4 };
	Selection_sort(arr4);
}

