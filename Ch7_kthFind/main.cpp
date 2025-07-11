#include <iostream>
#include <vector>
#include <utility> // pair
#include <map>	   // insert {people 인덱스, 값}
#include <algorithm> // sort

/*
	알고리즘 대표 문제
	- 수를 정렬하고 탐색하기
	- 단순한 방법. 데이터를 정렬시킨다.
	- k번째 작은 수? 왼쪽부터 하나씩 출력
	- k번째 큰 수? 오른쪽부터 하나씩 출력
*/

// 응급 환자 순서를 제공해드립니다. vector<int>
// 먼저 진료해야 하는 환자가 1번부터 시작한다.

// 트리에 저장 방식을 응용해서 가장 큰 수를 찾는 형태를 구현하면 어떨까

void EmergencyExample()
{
	std::vector<int> people = { 10, 5, 9, 6, 4, 1, 8 };
	std::vector<int> answer;
	answer.assign(people.size(), 0);
	std::map<int, int> sheets;

	for (int i = 0; i < people.size(); i++)
	{
		sheets.insert({ people[i], i }); // 위급도 key, 인덱스 second (value)
	}

	// people 값을 정렬.
	
	std::sort(people.begin(), people.end());

	// answer에 들어있는 가장 큰 수
	// int key = sheets.find(answer[answer.size() - ])->first; 
	// sheets에 find한 값의 first 값을 반환
	// answer[key] = 1;

	/*
		Tree 노드 삭제
		Tree 균형이 안잡힌 경우
		Idea1. 트리에 데이터를 넣을 때 균형잡히게 넣으면 되는거 아닌가?
		채워 넣은 다음에 서브트리들이 하나의 규칙을 갖도록 해보자
		Heap : 서브 트리의 부모노드가 가장 큰 수여야 한다.
		가장 위에 있는 노드가 가장 큰 수. maxHeap
		가장 위에 있는 노드가 가장 작은 수. minHeap
		heapify() - 트리를 힙순서로 재정렬하는 코드 함수
		heapSort() = 힙 정렬
	*/
	
	for (int i = 0; i < people.size(); i++) // 7
	{
		auto it = sheets.find(people[people.size() - 1 - i]);
		int index = it->second; // err
		answer[index] = i + 1 ;
	}

	std::cout << "[";
	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << " ";
	}
	std::cout << "]" << std::endl;
}

//void EmergencyExample()
//{
//	std::vector<int> people = { 10, 5, 9, 6, 4, 1, 8 };
//
//
//	std::vector<std::pair<int, int>> answer;
//	//
//	//answer.push_back();// 인덱스 값에 + 1;
//
//	for (int i = 0; i < people.size(); i++)
//	{
//		answer[i].second = people[i];
//	}
//
//	std::cout << "[";
//	for (int i = 0; i < answer.size(); i++)
//	{
//		std::cout << answer[i].first << " ";
//	}
//	std::cout << "]" << std::endl;
//}

int main()
{
	EmergencyExample();
}