#pragma once
#include <iostream>
#include <vector>
#include <algorithm> 

void Merge(int arr[], int n, int left, int mid, int right)
{
	// 1. ���ĵ� �����͸� ���� ������ �迭 ������ �����մϴ�.	(sorted Array ���� �迭)

	std::vector<int> sorted;// ���ʰ� �������� ���ؼ� ���Ľ�Ų ���� ������ �ӽ� �����̳�
	sorted.assign(n, 0);	// n���� ������ �����Ͱ� 0���� �ʱ�ȭ�� �����迭�� ����
	int i = left;			// ���ʿ��� �����ϴ� index ��ȣ
	int j = mid + 1;			// �����ʿ��� �����ϴ� index ��ȣ
	int k = left;			// ���ĵ� �ε��������� ���� ù��° �ε��� ��ȣ

	// 2. arr �迭 �ȿ� ����ִ� �� left �ε��� ���� right �ε��� �� ���� ���� sorted �ֱ�
	// left ���� ���, right ���� ���

	while (i <= mid && j <= right) //		���� �Ǵ� �����ʿ� �ε����� �ϳ��� ���� ���� ���� ����
	{
		if (arr[i] <= arr[j])
		{
			sorted[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			sorted[k] = arr[j];
			j++;
			k++;
		}
	}

	// 3. i�� ������ ��, j�� ������ �� �������� ���� ä���

	if (i > mid) // i�� �� ����� ���, ���� �ε����� j�� ���� ���
	{
		for (int t = j; t <= right; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= mid; t++)
		{
			sorted[k] = arr[t];
			k++;
		}
	}

	// 4. sorted ���� ���ĵ� ����. arr ���� �����Ϳ� ���ĵ� �����͸� �Ű� �ش�.
	for (int t = left; t <= right; t++)
	{
		arr[t] = sorted[t];
	}


}

void MergeSort(int arr[], int n, int left, int right)
{
	// ��������� MergeSort

	// ���ʺκ� MergerSort
	// �����ʺκ� MergeSort

	// Merge

	if (left < right) // ���� left == right ����? ���Ұ� 1���̴�.
	{
		int mid = (left + right) / 2; // left, right ����ؼ� ����
		MergeSort(arr, n, left, mid); // ���� �κ�
		MergeSort(arr, n, mid + 1, right); // ������ �κ�

		Merge(arr, n, left, mid, right);
	}

}