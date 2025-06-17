#pragma once
#include <iostream>
#include <vector>
#include <algorithm> 

void Merge(int arr[], int n, int left, int mid, int right)
{
	// 1. 정렬된 데이터를 따로 저장할 배열 공간을 정의합니다.	(sorted Array 정렬 배열)

	std::vector<int> sorted;// 왼쪽과 오른쪽을 비교해서 정렬시킨 값을 저장할 임시 컨테이너
	sorted.assign(n, 0);	// n개의 공간에 데이터가 0으로 초기화된 가변배열을 선언
	int i = left;			// 왼쪽에서 시작하는 index 번호
	int j = mid + 1;			// 오른쪽에서 시작하는 index 번호
	int k = left;			// 정렬된 인덱스에서의 가장 첫번째 인덱스 번호

	// 2. arr 배열 안에 들어있는 값 left 인덱스 값과 right 인덱스 비교 작은 값을 sorted 넣기
	// left 작은 경우, right 작은 경우

	while (i <= mid && j <= right) //		왼쪽 또는 오른쪽에 인덱스가 하나라도 남아 있을 때만 실행
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

	// 3. i가 남았을 때, j가 남았을 때 나머지를 가득 채우기

	if (i > mid) // i를 다 사용한 경우, 남은 인덱스가 j만 있을 경우
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

	// 4. sorted 현재 정렬된 상태. arr 원본 데이터에 정렬된 데이터를 옮겨 준다.
	for (int t = left; t <= right; t++)
	{
		arr[t] = sorted[t];
	}


}

void MergeSort(int arr[], int n, int left, int right)
{
	// 재귀적으로 MergeSort

	// 왼쪽부분 MergerSort
	// 오른쪽부분 MergeSort

	// Merge

	if (left < right) // 만약 left == right 같다? 원소가 1개이다.
	{
		int mid = (left + right) / 2; // left, right 사용해서 정의
		MergeSort(arr, n, left, mid); // 왼쪽 부분
		MergeSort(arr, n, mid + 1, right); // 오른쪽 부분

		Merge(arr, n, left, mid, right);
	}

}