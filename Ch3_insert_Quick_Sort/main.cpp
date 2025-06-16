#include <iostream>
#include <vector>
#include <algorithm>

/*
	삽입 정렬
	- 특정 수를 정렬된 위치로 옮기는 방식
	- 앞에서 부터 데이터를 정렬한다.

*/

void InsertSort(int arr[], int n)
{
	// 몇번 cycle 돌아야 하나?

	for (int i = 1; i < n; i++)
	{
		// 현재 key의 값이 무엇인가?
		int key = arr[i];

		// key의 값과 key 이전의 값들과 비교
		int j = i - 1;

		while (j >= 0 && arr[j] > key) // j 값보다 key 값이 작을 때, 인덱스의 값이 0보다 클때
		{
			arr[j + 1] = arr[j]; // 왼쪽의 데이터와 새로 들어온 데이터의 위치를 변경해라
			j--; // 현재 key의 위치
		}

		arr[j + 1] = key;

	}

	

}

void InsertSort(std::vector<int>& nums) // vector는 참조자를 사용해야 불러와짐
{
	// 몇번 cycle 돌아야 하나?
	
	int n = nums.size();

	for (int i = 1; i < n; i++)
	{
		// 현재 key의 값이 무엇인가?
		int key = nums[i];

		// key 왼쪽에 있는 모든 데이터들과 비교해서 위치를 찾은 다음 그 위치에 삽입
		int j = i - 1;

		while (j >= 0 && nums[j] > key) // j의 값이 0보다 크거나 같을 때만 또는 key의 값이 왼쪽에 있는 값보다 작을 때만
		{
			// 작으면 왼쪽과 키에 들어있는 값을 변경하고
			nums[j + 1] = nums[j];
			// index를 왼쪽으로 이동해서 다음 수와 또 비교한다.
			j--;
		}
		// 위치를 찾았다면 해당 위치를 key 값에 저장한다. +1 안하면 -1에 접근할 수 있다.
		nums[j + 1] = key;
	}

}

/*
	Insert Sort
	장점 : 모든 경우에 위치 변경이 발생하는 것이 아닌, while 조건에 해당 할 때만 위치 변경(swap)이 발생한다.
	컨테이너 데이터가 정렬되어 있을 수록 정렬 속도가 빠르다. "분할 정복" 정렬, nlogN
	사이클 : n
	while() 1 ~ n 크기를 가질 수 있다.
	최선의 경우 O(n)	평균, 최악의 경우 (O(n^2))

	단점 : 정렬이 안된 경우, n의 제곱에 비례해서 시간이 걸린다.
*/

/*
	log 시간이 얼마나 빠를까?
	2^10 = 1024 // 대략 1000
	2^20 = 2^10 * 2^10 // 1,000,000 대략 백만
	log2(2^20) = 20;	n번(백만 번) log n 번 (20번)

	시간을 단축하게 하기 위해서는 logn으로 표현하는 방법을 찾는다.
	"분할 정복" 알고리즘
*/

/*
	1 2 3 4 5 6 7 8 9 10	O(n^2) 100

	1 2 3 4 5		= 5^2 = 25
	6 7 8 9 10		= 5^2 = 25	50
*/

#pragma region 퀵 정렬

/*
	임의의 pivot을 정한다. 가장 왼쪽의 값을 피벗으로 한다.
	pivot 피벗 : 기준점
	분할 정복 알고리즘. 분할을 하기 위한 기준이다.
	특징 : 분할 정복 알고리즘을 사용하고 있다. 재귀함수로 구현된다.
	평균 O(n* logn) 시간을 갖는다.
	O(n^2) 정렬 방식으로 알고리즘 구하기. (버블, 선택, 삽입)
	O(n log n) 정렬 방식으로 알고리즘 구하기. (퀵, 병합)
*/

/*
	언제 사용하는가? data의 갯수가 10만개가 넘어갈 떄, 10만 x 10만 = 10 ~ 몇백억 0.00001 * 10억
	데이터의 개수가 많을 때 사용한다.

	단점 : 정렬되어 있는 데이터에서 QuickSort를 사용할 경우 O(n^2) 시간이 걸린다.
	1 2 3 4 5 이 경우 1 2 3 4 5를 모두 탐색한다. n * n
	알고리즘 문제에 quickSort 구현했을 때 시간이 초과했다.
	정렬되어 있는 케이스를 받을 때 비효율적이다.
*/

void QuickSort(int data[], int start, int end)
{
	if (start >= end) // 데이터가 1개만 있을 경우, 재귀 함수를 끝내기 위한 조건을 return 표현
	{
		return;
	}

	int pivot = start;	// 기준이 되는 값
	int i = start + 1;	// 왼쪽에서 변경할 위치
	int j = end;		// 오른쪽에서 변경할 위치
	int temp;			// swap 사용하기 위한 임시 변수

	while (i <= j) //	왼쪽 인덱스를 오른쪽 인덱스가 추월했을 때 까지 반복
	{
		while (data[i] <= data[pivot]) // 피벗보다 큰 값을 만날 때 그 값을 찾아라 (작을 때 i값 계속 증가)
		{
			// (작을 때 계속 i를 증가)
			i++;
		}
		while (j > start && data[j] >= data[pivot]) // 피벗보다 작은 값을 만날 때 그 값을 선택하라
		{
			// (j의 값을 변경해주는 코드)
			j--;
		}
		
		// i > j // 왼쪽 인덱스가 오른쪽 인덱스보다 크면 (엇갈릴 때) 피벗에 있는 값과 j의 값을 변경
		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;

			//std::swap(data[pivot], data[j]);
		}
		else { // 엇갈리지 않았을 때 // swap 사용
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;

			//std::swap(data[i], data[j]);
		}
		
		// 재귀 함수

		// quicksort(왼쪽 파트) quicksort(오른쪽 파트)
		QuickSort(data, start, j - 1);	// 왼쪽
		QuickSort(data, j + 1, end);	// 오른쪽

	}

}

void QuickSort(std::vector<int>& data, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int pivot = start;
	int i = start + 1;
	int j = end;

	while (i <= j)
	{
		while (data[i] <= data[pivot])
		{
			i++;
		}
		while (j > start && data[j] >= data[pivot])
		{
			j--;
		}

		if (i > j)
		{
			std::swap(data[pivot], data[j]);
		}
		else
		{
			std::swap(data[i], data[j]);
		}

		QuickSort(data, start, j - 1);
		QuickSort(data, j + 1, end);

	}
}

#pragma endregion



int main()
{
	
	std::cout << "삽입 정렬 배열 형식" << std::endl;

	int arr1[10] = { 3, 5, 7, 9, 1, 2, 4, 6, 8, 0 };

	InsertSort(arr1, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr1[i] << " ";
	}

	std::cout << std::endl;

	std::vector<int> nums1 = {3, 6, 5, 2, 1, 0 ,8, 9, 7, 4, 10, 12, 11};

	InsertSort(nums1);

	/*for (int i = 0; i < 13; i++)
	{
		std::cout << nums1[i] << " ";
	}*/
	for (int num : nums1) 
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::cout << "퀵 정렬 배열 형식" << std::endl;
	int arr2[10] = { 3, 5, 7, 9, 1, 2, 4, 6, 8, 0 };
	QuickSort(arr2, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr2[i] << " ";
	}

	std::cout << std::endl;
	std::vector<int> nums2 = { 3, 5, 7, 9, 1, 2, 4, 6, 8, 0 };
	QuickSort(nums2, 0, 9);
	for (int num : nums2)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}