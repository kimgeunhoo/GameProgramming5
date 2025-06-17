
/*
	어떻게 코드를 구현해야 하나?
*/

/*
	병합 정렬
	핵심 개념 : 일단 나눠라, 절반씩 나누어서 1개가 될 때 까지
				나누어진 것끼리 정렬해서 합친다.
*/

/*
	나눈다 = mergesort
	합친다 = merge
*/

/*
	삽입 정렬
	장점 : 정렬되어 있을수록 빠르다
	단점 : n의 크기가 크면 클수록 비효율적이다. 
	100만 데이터 이하, 정렬되어 있는 편향(biased)이 있을 때 사용하면 장점이 있다.

	퀵 정렬
	장점 : 대중적으로 많이 사용한다. STL sort
		   대부분의 경우에 n logn 시간을 보장한다.
	단점 : worst case에 O(n^2)
	개선한 퀵 sort, pivot - 맨 왼쪽. 알고리즘 추가하여 개선됨(논문)

	병합 정렬
	장점 : 평균적으로 nlogn 시간 보장한다.
	단점 : sorted 저장을 위한 배열을 사용하기 때문에 추가적인 메모리를 사용한다.

	algorithm 헤더 sort(begin(),end());의 원리를 배웠다고 생각해 보자
*/

#include "mergesort.h"


int main()
{
	std::cout << "\n병합 정렬 배열" << std::endl;

	int arr[6] = { 3,2,5,1,4,8 };
	MergeSort(arr, 6, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << "\n병합 정렬 vector 버전" << std::endl;

}

