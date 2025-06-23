/*
	0. k번째 문제 찾기 오류 수정, delete temp 삭제하기
	1. Heap 특정한 규칙을 갖고 있는 자료구조 직접 구현하기
	2. k번째 존재하는 수를 더 빨리 찾을 수 있다. -> 게임 예제
*/

// k번째 숫자 찾기

// 1. vector, array 숫자를 정렬시킨 후에 가장 크거나 (작은) 수를 찾는다. (정렬 알고리즘 시간)
// 2. 전체 갯수가 n개가 있으면 n 1번 비교를 해야한다.					 (모든 경우의 수를 탐색, 완전 탐색)
// 3. 시간 logN이 걸리는 방법이 없을까? 
// (-> 데이터의 수가 백만개 이상(처리해야 할 데이터가 많으면) 일 때 어떻게 해야 하나?)
// 만약 처리해야 할 데이터가 적으면, (10 ~ 1)


// Tree ( 편향적으로 데이터가 저장될 경우 효율적이지 않다. )
// 1. 단점을 해결하기 위한 방법으로 트리 형태로 균형 잡히게 데이터를 넣어본다. (트리를 차례대로 정리한다. 완전 이진 트리)
// 2. root 방향으로 가장 큰 수 (가장 작은 수)를 저장하도록 규칙을 설정한다.
// 위의 규칙을 갖는 자료구조 힙(Heap) 이라고 부른다. maxHeap, minHeap

// MaxHeap 구현을 보고 MinHeap 따로 구현해보기 (자습용)

#include <iostream>
#include <queue>
#include <algorithm>

void PriorityQueue()
{
	std::priority_queue<int> pq;

	// heap 자료구조로 만들어진 클래스이다.
}

class MaxHeap
{
private:
	struct Node
	{
		int value;
		Node* leftNode;
		Node* rightNode;
		Node* parentNode;

		Node(int val) : value(val), leftNode(nullptr), rightNode(nullptr), parentNode(nullptr) {}
	};

	Node* root;
	int size;

	/*
		(*node).value
		node->value
	*/

	/*
		부모 노드를 기준으로 큰 녀석을 바꾸면 안되는가?
		heap의 특징은 데이터가 들어올 때 heap의 성질을 만족하고 있다고 가정.
		새로 들어온 녀석만 규칙에 맞도록 수정
	*/

	void heapifyup(Node* node) // 새로 추가된 노드 node
	{ 
		// node의 부모 노드를 포인터로 가리키고 있다. node->parentNode->value	node->value

		// while (1번 조건 && 2번 조건)
		// 1. 추가된 노드와 부모 노드의 값을 비교하는 코드를 만들기, 새로 추가된 노드가 더 클 때
		// 2. 새로 추가된 노드의 부모 노드가 존재하면 계속 실행

		// node -> parentNode 없을때

		while (node->value > node->parentNode->value && node->parentNode != nullptr) // 변경을 하기 위한 조건
		{
			// 알고리즘 헤더를 추가해준 다음에, 부모 노드와 자기 노드를 swap한다. (value를 swap)
			// swap 후에 node를 부모 노드와 변경해준다.( 부모 노드를 가리키고 있는 것을 변경한다.)

			std::swap(node->value , node->parentNode->value);
			node = node->parentNode;
			
		}

	}

	Node* findLastNode()	// 노드를 삭제할 때 규칙 1을 만족기키기 위해서 가장 마지막 노드를 찾는다.
	{
		if (!root) { return nullptr; } // 데이터가 1개도 없는 경우 실행 x

		std::queue<Node*> q;
		q.push(root);
		Node* lastNode = nullptr;
		while (!q.empty())
		{	
			lastNode = q.front();
			q.pop();
			if (lastNode->leftNode)
			{
				q.push(lastNode->leftNode);
			}
			if (lastNode->rightNode)
			{
				q.push(lastNode->rightNode);
			}
		}

		return lastNode;
	}

	void heapifydown(Node* node)
	{
		// 루트에 올린 마지막 노드를 그 자식 노드(왼쪽, 오른쪽) 중에서 큰 값과 교체한다.
		// 자식의 왼쪽, 오른쪽 노드보다 자기가 더 크거나, 더 이상 자식이 없을 때 까지 반복한다.

		while (node)
		{
			Node* largest = node; // 현재 노드가 제일 크다. (가정)

			if (node->leftNode&& node->leftNode->value > largest->value)
			{
				largest = node->leftNode;
			}

			if (node->rightNode && node->rightNode->value > largest->value)
			{
				largest = node->rightNode;
			}

			// 왼쪽과 오른쪽 중에서 큰 수로 바뀐다.
			if (largest == node)
			{
				break;
			}

			std::swap(node->value, largest->value);
			node = largest;
		}

	}

	void deleteNode(Node* node)
	{
		if (!node){ return; }

		deleteNode(node->leftNode);
		deleteNode(node->rightNode);
		delete node;
	}

public:

	MaxHeap() : root(nullptr), size(0) {}

	void insert(int value)
	{
		Node* newNode = new Node(value);

		if (!root) // 데이터가 0개일 경우, 새로 들어온 데이터가 루트가 된다.
		{
			root = newNode;
			size = 1;
			return;
		}

		// 루트가 존재할 경우, 규칙 1을 따라서 순서대로 노드가 저장될 수 있게 조건을 작성하시오
		// 왼쪽에 데이터가 없으면 -> 왼쪽에 데이터 넣기
		// 왼쪽에 데이터가 있으면 -> 오른쪽에 데이터 넣기
		
		std::queue<Node*> q; // FIFO
		q.push(root);

		while (!q.empty()) // q(데이터)가 있을때만 반복
		{
			Node* currentNode = q.front();
			q.pop();

			if (!currentNode->leftNode) // 왼쪽에 데이터가 없으면 -> 왼쪽에 데이터 넣기
			{
				currentNode->leftNode = newNode;	// 현재 노드의 왼쪽 자식에 새로운 데이터를 넣었다
				newNode->parentNode = currentNode;	// 자식의 부모를 설정해 준다.
				break;
			}

			if (!currentNode->rightNode) // 오른쪽에 데이터가 없을 때 -> 오른쪽에 데이터 넣기
			{
				currentNode->rightNode = newNode;
				newNode->parentNode = currentNode;
				break;
			}

			// root에 더이상 연결된 노드가 없을때 까지 반복하기 위해 연결된 노드들을 추가해주는 코드
			q.push(currentNode->leftNode);
			q.push(currentNode->rightNode);
		}

		size++;
		heapifyup(newNode);
		// 현재 들어간 노드와, 그 부모의 노드를 비교하기 위해서 큰 수를 위쪽으로 보내기
		// heapifyup
		

	}

	int extractMax() // 최대값을 제거하라. front, pop
	{
		if (!root) { return - 1; } // -1 리턴은 에러가 있다고 알림

		int maxValue = root->value;

		if (size == 1)			// 1개만 있을 때는 1개를 없애고 최대값을 변환한다.
		{
			delete root;
			root = nullptr;
			size = 0;
			return maxValue;
		}

		// 1. 마지막 노드를 찾으시오
		Node* lastNode = findLastNode();
		if (!lastNode) { return -2; } // if -1 root 갯수가 0개인 에러, -2 마지막 노드를 찾는 코드가 에러가 있다.

		// 2. 마지막 노드를 root 노드로 이동시킨 후 다시 heap 성질을 갖도록 정리
		root->value = lastNode->value; // 제일 밑에 있는 노드를 가리킴, 현재 root 에는 마지막 값이 들어있다.
		
		// 지우기 위해서 가리키고 있는 가장 마지막 노드
		if (lastNode->parentNode)
		{
			// lastNode의 값은 root로 올라갔으니까 현재 lastNode에 있는 주소를 nullptr로 바꾸기
			if (lastNode->parentNode->leftNode == lastNode) // 마지막 노드가 부모노드 왼쪽에 있는 경우
			{
				lastNode->parentNode->leftNode = nullptr;
			}
			else // 마지막 노드가 부모 노드의 오른쪽에 있는경우 
			{
				lastNode->parentNode->rightNode = nullptr;
			}
		}
		
		delete lastNode;
		size--;
		heapifydown(root);	//

		return maxValue;
	}
};

/*
	RPG게임 보스레이드 5인파티 전사, 도적, 궁수, 마법사, 성직자
	각각의 직업들은 스킬을 사용할 때마다 보스 어그로가 증가한다.
	총 5번의 보스 공격마다 누구를 우선적으로 공격하는지 찾는 로직 작성
	이 때, 보스가 특정 직업을 공격할 때마다 그 직업의 어그로는 0으로 초기화 된다.
				1턴		2턴		3턴		4턴		5턴
	전사	:	10		5		8		7		6		(강력하거나, 위협적인 스킬일 수록 그 수치가 높다.)
	도적	:
	궁수	:
	마법사	:
	성직자	:

	[보스의 스킬을 결정하는 로직]
	보스 : 파티 중에서 누가 가장 위협적인가? 누가 가장 덜 위험한가? (도발수치)

	(1) n개의 직업마다 우선순위를 비교 가장 큰 순위를 출력한다.
	(2) Heap 자료구조를 사용해서 k번째 순위를 찾는다.

	- 갯수가 적으면 1번 방식이 효율적
	- 2번을 사용해랴하는 보스가 찾아야 할 우선 순위 대상이 많으면 많을수록 2번 방식이 효율적이다.
*/

int main() 
{
	MaxHeap mHeap;

	std::cout << "가장 큰 수를 찾는 Heap 데이터 입력" << std::endl;

	mHeap.insert(7);
	mHeap.insert(3);
	mHeap.insert(5);
	mHeap.insert(11);

	std::cout << "가장 큰 수를 반환하고 다시 Heap 정렬하는 예제" << std::endl;
	int maxValue = mHeap.extractMax(); // 1번째 큰 수
	int kthValue;
	for (int i = 0; i < 2; i++)
	{
		kthValue = mHeap.extractMax(); // 2번째로 큰 수 kthValue 저장된다.
	}

	// k번째로 큰 수를 찾아라.
}