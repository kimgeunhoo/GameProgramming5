#include <iostream>
#include <vector>
#include <algorithm>

/*
	���� ����
	- Ư�� ���� ���ĵ� ��ġ�� �ű�� ���
	- �տ��� ���� �����͸� �����Ѵ�.

*/

void InsertSort(int arr[], int n)
{
	// ��� cycle ���ƾ� �ϳ�?

	for (int i = 1; i < n; i++)
	{
		// ���� key�� ���� �����ΰ�?
		int key = arr[i];

		// key�� ���� key ������ ����� ��
		int j = i - 1;

		while (j >= 0 && arr[j] > key) // j ������ key ���� ���� ��, �ε����� ���� 0���� Ŭ��
		{
			arr[j + 1] = arr[j]; // ������ �����Ϳ� ���� ���� �������� ��ġ�� �����ض�
			j--; // ���� key�� ��ġ
		}

		arr[j + 1] = key;

	}

	

}

void InsertSort(std::vector<int>& nums) // vector�� �����ڸ� ����ؾ� �ҷ�����
{
	// ��� cycle ���ƾ� �ϳ�?
	
	int n = nums.size();

	for (int i = 1; i < n; i++)
	{
		// ���� key�� ���� �����ΰ�?
		int key = nums[i];

		// key ���ʿ� �ִ� ��� �����͵�� ���ؼ� ��ġ�� ã�� ���� �� ��ġ�� ����
		int j = i - 1;

		while (j >= 0 && nums[j] > key) // j�� ���� 0���� ũ�ų� ���� ���� �Ǵ� key�� ���� ���ʿ� �ִ� ������ ���� ����
		{
			// ������ ���ʰ� Ű�� ����ִ� ���� �����ϰ�
			nums[j + 1] = nums[j];
			// index�� �������� �̵��ؼ� ���� ���� �� ���Ѵ�.
			j--;
		}
		// ��ġ�� ã�Ҵٸ� �ش� ��ġ�� key ���� �����Ѵ�. +1 ���ϸ� -1�� ������ �� �ִ�.
		nums[j + 1] = key;
	}

}

/*
	Insert Sort
	���� : ��� ��쿡 ��ġ ������ �߻��ϴ� ���� �ƴ�, while ���ǿ� �ش� �� ���� ��ġ ����(swap)�� �߻��Ѵ�.
	�����̳� �����Ͱ� ���ĵǾ� ���� ���� ���� �ӵ��� ������. "���� ����" ����, nlogN
	����Ŭ : n
	while() 1 ~ n ũ�⸦ ���� �� �ִ�.
	�ּ��� ��� O(n)	���, �־��� ��� (O(n^2))

	���� : ������ �ȵ� ���, n�� ������ ����ؼ� �ð��� �ɸ���.
*/

/*
	log �ð��� �󸶳� ������?
	2^10 = 1024 // �뷫 1000
	2^20 = 2^10 * 2^10 // 1,000,000 �뷫 �鸸
	log2(2^20) = 20;	n��(�鸸 ��) log n �� (20��)

	�ð��� �����ϰ� �ϱ� ���ؼ��� logn���� ǥ���ϴ� ����� ã�´�.
	"���� ����" �˰���
*/

/*
	1 2 3 4 5 6 7 8 9 10	O(n^2) 100

	1 2 3 4 5		= 5^2 = 25
	6 7 8 9 10		= 5^2 = 25	50
*/

#pragma region �� ����

/*
	������ pivot�� ���Ѵ�. ���� ������ ���� �ǹ����� �Ѵ�.
	pivot �ǹ� : ������
	���� ���� �˰���. ������ �ϱ� ���� �����̴�.
	Ư¡ : ���� ���� �˰����� ����ϰ� �ִ�. ����Լ��� �����ȴ�.
	��� O(n* logn) �ð��� ���´�.
	O(n^2) ���� ������� �˰��� ���ϱ�. (����, ����, ����)
	O(n log n) ���� ������� �˰��� ���ϱ�. (��, ����)
*/

/*
	���� ����ϴ°�? data�� ������ 10������ �Ѿ ��, 10�� x 10�� = 10 ~ ���� 0.00001 * 10��
	�������� ������ ���� �� ����Ѵ�.

	���� : ���ĵǾ� �ִ� �����Ϳ��� QuickSort�� ����� ��� O(n^2) �ð��� �ɸ���.
	1 2 3 4 5 �� ��� 1 2 3 4 5�� ��� Ž���Ѵ�. n * n
	�˰��� ������ quickSort �������� �� �ð��� �ʰ��ߴ�.
	���ĵǾ� �ִ� ���̽��� ���� �� ��ȿ�����̴�.
*/

void QuickSort(int data[], int start, int end)
{
	if (start >= end) // �����Ͱ� 1���� ���� ���, ��� �Լ��� ������ ���� ������ return ǥ��
	{
		return;
	}

	int pivot = start;	// ������ �Ǵ� ��
	int i = start + 1;	// ���ʿ��� ������ ��ġ
	int j = end;		// �����ʿ��� ������ ��ġ
	int temp;			// swap ����ϱ� ���� �ӽ� ����

	while (i <= j) //	���� �ε����� ������ �ε����� �߿����� �� ���� �ݺ�
	{
		while (data[i] <= data[pivot]) // �ǹ����� ū ���� ���� �� �� ���� ã�ƶ� (���� �� i�� ��� ����)
		{
			// (���� �� ��� i�� ����)
			i++;
		}
		while (j > start && data[j] >= data[pivot]) // �ǹ����� ���� ���� ���� �� �� ���� �����϶�
		{
			// (j�� ���� �������ִ� �ڵ�)
			j--;
		}
		
		// i > j // ���� �ε����� ������ �ε������� ũ�� (������ ��) �ǹ��� �ִ� ���� j�� ���� ����
		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;

			//std::swap(data[pivot], data[j]);
		}
		else { // �������� �ʾ��� �� // swap ���
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;

			//std::swap(data[i], data[j]);
		}
		
		// ��� �Լ�

		// quicksort(���� ��Ʈ) quicksort(������ ��Ʈ)
		QuickSort(data, start, j - 1);	// ����
		QuickSort(data, j + 1, end);	// ������

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
	
	std::cout << "���� ���� �迭 ����" << std::endl;

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

	std::cout << "�� ���� �迭 ����" << std::endl;
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