#include <iostream>
#include <vector>

/*
	정렬 다양한 방법으로 직접 구현.
	왜 정렬을 해야하는가?
	새로운 아이템(Item) 컨테이너 추가될 때, 정렬되어 있는 상태로 저장이 되는 경우가 있다.
*/

/*
	탐색 : 컨테이너 안에 데이터가 있는지 없는지 찾는다.
	탐색을 프로그래밍 코드로 한번 구현해보자.
	(1) 앞에서 부터 데이터를 비교해서 있는지 없는지 확인
		- 선형 탐색 방법(linear search)
	(2) 이진 탐색 (binary search)
		- 컨테이너가 정렬되어 있을 때 중앙값을 기준으로 데이터를 나누어서 찾는 방법
*/

/*
	선형 탐색의 경우에는 최선의 경우(best case) 0(1) 시간이 걸리고 최악의 경우(worst case) n 시간이 걸린다.
	평균 O(n) 시간이 걸린다. 데이터의 갯수가 백만을 넘어가면 비효율적이다.
	"분할 정복 알고리즘" : 범위를 나누어서 작은 범위를 해결하는 방식으로 문제를 푼다.
*/

#include <utility>

/*
	std::pair<int, 클래스이름>
	std::pair<int, std::string> data;

	std::vector<std::pair<int, std::string>> data;
	// pair타입 선언하는 방법
	data.push_back({0, "AAA"});		0 ~ 5
	// 해당하는 인덱스가 있으면 그 인덱스에 저장되어 있는 문자를 출력하는 코드를 만들기

	// 유저의 ID에 유저가 가진 정보를 저장. 서버에 유저의 ID를 기준으로 해당 유저의 정보(닉네임)를
	// 검색하는 기능을 구현하기
*/

template<typename T1, typename T2>
struct myPair
{
	T1 first;
	T2 second;
	// 페어끼리 복사, 이동, 연산자 오버로딩...

};

class Item
{
	int price;
	bool operator<(const Item& other)
	{
		return price < other.price;
	}
};


void LinearSearch(int arr[], int n, int target)
{
	// 전체 갯수를 반복해서	 for 반복문
	for (int i = 0; i < n; i++)
	{
		// arr[0] arr[1] ... arr[n]
		// target과 같은 데이터가 존재하면  조건문
		if (arr[i] == target)
		{
			std::cout << "해당하는 데이터를 : " << target << " 를 찾았습니다.";
			return;
		}

	}
	
	std::cout << "데이터를 찾지 못했습니다." << std::endl;
}


void LinearSearch(std::vector<int>& arr, int target)
{
	int n = arr.size();
	// 전체 갯수를 반복해서	 for 반복문
	for (int i = 0; i < n; i++)
	{
		// arr[0] arr[1] ... arr[n]
		// target과 같은 데이터가 존재하면  조건문
		if (arr[i] == target)
		{
			std::cout << "해당하는 데이터를 : " << target << " 를 찾았습니다.";
			return;
		}

	}

	std::cout << "데이터를 찾지 못했습니다." << std::endl;
}


// iterator 방식으로 구현한 이진 탐색

void BinarySearch(int arr[], int n, int target)
{
	// int mid = (left + right) / 2		    - 20억 + 20억 = 오버플로우 발생
	// int mid = left + (right - left) / 2  - 왼쪽에서 오른쪽으로 가는 거리 /2 더해준다. 위 식보다는 안전하다.

	int i = 0;		// 왼쪽
	int j = n - 1;	// 오른쪽
	

	while (i <= j) // 왼쪽, 오른쪽
	{
		int mid = i + (j - i) / 2; // 루프 돌때마다 중앙값을 변경한다.
		// 현재 mid값과 target 값을 비교

		if (arr[mid] == target)	// target 찾은 경우 : 데이터 찾음
		{
			std::cout << "해당하는 데이터를 : " << target << " 를 찾았습니다.";
			return;
		}
		else if (arr[mid] > target)	// target 작은경우 : 왼쪽에서 다시 찾으시오
		{
			j = mid - 1;	// mid의 기준으로 어떻게 j 를 바꿔야 하나
		}
		else		// target 큰 경우
		{
			i = mid + 1;	// 왼쪽 i가 mid의 기준으로 어떻게 바꿔야 하나?
		}
	
	}

	std::cout << "데이터를 찾지 못했습니다." << std::endl;

}

void BinarySearch(std::vector<int>& arr, int target)
{
	// int mid = (left + right) / 2		    - 20억 + 20억 = 오버플로우 발생
	// int mid = left + (right - left) / 2  - 왼쪽에서 오른쪽으로 가는 거리 /2 더해준다. 위 식보다는 안전하다.
	int n = arr.size();

	int i = 0;		// 왼쪽
	int j = n - 1;	// 오른쪽
	

	while (i <= j) // 왼쪽, 오른쪽
	{
		int mid = i + (j - i) / 2; // 루프 돌때마다 중앙값을 변경한다.
		// 현재 mid값과 target 값을 비교

		if (arr[mid] == target)	// target 찾은 경우 : 데이터 찾음
		{
			std::cout << "해당하는 데이터를 : " << target << " 를 찾았습니다.";
			return;
		}
		else if (arr[mid] > target)	// target 작은경우 : 왼쪽에서 다시 찾으시오
		{
			j = mid - 1;	// mid의 기준으로 어떻게 j 를 바꿔야 하나
		}
		else		// target 큰 경우
		{
			i = mid + 1;	// 왼쪽 i가 mid의 기준으로 어떻게 바꿔야 하나?
		}

	}

	std::cout << "데이터를 찾지 못했습니다." << std::endl;

}

// 재귀함수 방식으로 구현한 이진 탐색
void BinarySearchByRecursive(int arr[], int n, int target, int left, int right)
{
	// 재귀함수를 탈출할 수 있는 조건
	if (left > right)
	{
		std::cout << "데이터를 찾지 못했습니다." << std::endl;
		return;
	}

	int mid = left + (right - left) / 2;

	if (arr[mid] == target)
	{
		std::cout << "해당하는 데이터를 : " << target << " 를 찾았습니다.";
		return;
	}
	else if (arr[mid] > target) // 왼쪽에 있다. (right = mid - 1) 
	{
		BinarySearchByRecursive(arr, n, target, left, mid - 1);
	}
	else // 오른쪽에 있다. (left = mid + 1)
	{
		BinarySearchByRecursive(arr, n, target, mid + 1, right);
	}

	// 자기 자신의 함수를 호출하시오

	//if (arr[mid] == target)	// target 찾은 경우 : 데이터 찾음
	//{
	//	std::cout << "해당하는 데이터를 : " << target << " 를 찾았습니다.";
	//	return;
	//}
	//else if (arr[mid] > target)	// target 작은경우 : 왼쪽에서 다시 찾으시오
	//{
	//	j = mid - 1;	// mid의 기준으로 어떻게 j 를 바꿔야 하나
	//}
	//else		// target 큰 경우
	//{
	//	i = mid + 1;	// 왼쪽 i가 mid의 기준으로 어떻게 바꿔야 하나?
	//}

}


void Example()
{
	// pair 데이터 하나를 표현하는 방식. key와 value 값을 구분해서 저장하는 방식.
	// 연산자 오버로딩. 클래스 비교를 재정의.
	// 유저의 ID - 7C3A3X30F282D

	std::vector<std::pair<int, std::string>> data;

	std::pair<int, std::string> a = { 1, "AAA" };
	data.push_back({ 0, "AAA" });
	data.push_back(a);
	data.push_back(std::make_pair(2, "CCC"));
	data.push_back({ 3, "DDD" });
	data.push_back({ 4, "EEE" });

	// 선형 탐색, 이진 탐색을 사용해서 결과값을 찾으시오.

	// 타입이 다르기 때문에 해당하는 타입으로 다시 만들어 줘야 한다.

	std::vector<int> temp;
	for (int i = 0; i < data.size(); i++)
	{
		temp.push_back(data[i].first);
	}

	/*
		== 알고리즘 문제 ==
		1. 반환값을 bool 타입으로 변경해보기
		2. LinearSearch(vector<int> -> vector<pair<int, string>> 버전으로 변경해보기
		3. UserId를 사용해서 유저의 닉네임을 출력하는 코드를 완성해보기
	*/

	LinearSearch(temp, 4); // 값이 존재한다면
	std::cout << "데이터가 존재합니다. : (" << data[4].second << ")" << std::endl;

}

// class UserDataManager

void UserDataSearch(std::vector<std::pair<int, std::string>> data, int userID)
{

}

int main()
{
	std::cout << "\n배열로 구현하는 선형 탐색" << std::endl;
	int arr[5] = {0, 5, 1, 3, 2};
	LinearSearch(arr, 5, 2);

	std::cout << "\n벡터로 구현한 선형 탐색" << std::endl;
	std::vector<int> data = { 0, 5, 1, 3, 2 };
	LinearSearch(data, 3);

	std::cout << "\n배열로 구현하는 이진 탐색" << std::endl;
	int arr2[5] = { 0, 1, 2, 3, 5 };
	BinarySearch(arr2, 5, 2);

	std::cout << "\n벡터로 구현한 이진 탐색" << std::endl;
	std::vector<int> data2 = { 0, 1, 2, 3, 5 };
	BinarySearch(data2, 5);

	std::cout << "\n배열로 구현한 재귀 방식 이진 탐색" << std::endl;
	int arr3[5] = { 0, 5, 1, 3, 2 };
	BinarySearchByRecursive(arr3, 5, 2, 0, 4);

	Example();
}