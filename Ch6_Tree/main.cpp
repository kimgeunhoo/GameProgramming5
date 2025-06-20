/*
	★★★ 탐색과 자료구조 연관해서 생각해보기 ★★★
	- vector	: 선형 탐색, 이진 탐색
	  - 조건 : 사용하는 컨테이너가 정렬이 되어 있어야 한다.
		- 사용 중인 컨테이너의 특징 : 임의의 값을 바로 접근할수 있다.
		시작 값이 아닌 랜덤한 값을 수정할때 비효율적이다.

	- list		: 랜덤한 값의 수정을 즉시 할 수 있다.
	  - mid index의 값과 target 비교
		- 0 -> mid 순차적으로 탐색 후 mid 값을 반환한다.

	단점 :logN 시간을 확보했지만, 사용하기 위한 자료구조가 적합하지 않다.
	연관 컨테이너 : set, map // 트리 구조로 구현이 되어있다.

*/

/*
	Tree 자료구조
	데이터를 어떻게 저장하는 형태인가?
	노드 형태로 데이터를 저장한다. Value, 연결되어 있는 Node 주소를 저장한다.
*/

/*
	Tree 순회 방법 : 순서대로 Tree를 읽는 방법

	전위 순회 pre-order		: NLR	읽는 방식
	중위 순회 in-order		: LNR	읽는 방식
	후위 순회 post-order	: LRN	읽는 방식
*/

/*
	BST (Binary Search Tree) 이진 검색 트리
	- 자기 자신, 왼쪽, 오른쪽을 저장하는 노드를 가진다.
	- Node 기준으로 왼쪽과 오른쪽의 값을 비교할 수 있다.
	- 작은 값을 왼쪽으로 큰 값을 오른쪽으로 저장을 하면 규칙성을 갖는다.
	- 특정한 규칙을 갖는 클래스를 만들어서 데이터를 출력해본다.
*/

/*
	순차 컨테이너 방식의 단점 - 탐색 및 수정이 효율적이지 않나.
	연관 컨테이너 - "Tree 자료 구조"
	"BST" - 이진 검색 알고리즘으로 자료구조를 표현한 것
	단점 : 트리가 한 쪽으로 편향된 경우 O(n) 시간만큼 걸린다.
*/

/*
	트리 자료구조의 용어
	노드: (값(value), 왼쪽 노드 주소, 오른쪽 노드 주소) 트리의 기본 요소를 저장하는 데이터 단위
	부모 노드 : 하위의 노드와 직접 연결된 노드
	자식 노드 : 부모 노드의 하위에 직접 연결된 노드
	루트 노드 : 트리의 최상위에 있는 노드(부모가 없음)
	조상 노드 : 특정 노드에서 루트까지의 경로에 있는 모든 노드들
	후손 노드 : 특정 노드의 모든 자식들을 포함한 노드들

	- 알고리즘 트리 코드 구현 시 사용되는 용어 - 
	레벨(level) : 루트로부터의 거리를 뜻한다. 루트는 0을 반환한다.
	높이		: 트리에서 가장 깊은 레벨을 뜻한다.
	깊이		: 특정 노드에서 루트까지의 길이를 뜻한다.
	서브 트리	: 트리 내부에 후손들로 구성된 또다른 트리.

*/

//template<typename T1, typename T2>
struct Node
{
	int value;
	Node* leftNode;
	Node* rightNode;

	Node(int val) : value(val), leftNode(nullptr), rightNode(nullptr) {}

};

#include <iostream>
#include <vector>

// 트리로 만들어진 노드가 문제로 주어진다. 전위 순회로 출력했을 때의 결과를 작성하시오. 
// NLR 읽을수 있나?

#pragma region 트리 순회하는 방식
class Tree
{
public:
	void preOrder(Node* root)  // 재귀 방식으로 만든다
	{
		if (root == nullptr) { return; } // 재귀 탈출 조건

		std::cout << root->value << " "; // N
		preOrder(root->leftNode);		 // L에 있는 노드에 가서 preOrder 실행
		preOrder(root->rightNode);		 // R에 있는 노드에 가서 postOrder 실행

	}
	void inOrder(Node* root)
	{
		if (root == nullptr) { return; } // 재귀 탈출 조건

		inOrder(root->leftNode);
		std::cout << root->value << " ";
		inOrder(root->rightNode);
	}
	void postOrder(Node* root)
	{
		if (root == nullptr) { return; } // 재귀 탈출 조건

		postOrder(root->leftNode);
		postOrder(root->rightNode);
		std::cout << root->value << " ";
	}

};

#pragma endregion

#pragma region 노드 직접 연결
void NodeConnect()
{
	//             [4]
	//       [2]          [6]
	//   [9]     [7]  [1]

	Node* root = new Node(4);
	root->leftNode = new Node(2);
	root->leftNode->leftNode = new Node(9);
	root->leftNode->rightNode = new Node(7);
	root->rightNode = new Node(6);
	root->rightNode->leftNode = new Node(1);

	std::cout << "트리를 전위 순회로 출력" << std::endl;
	Tree tree;
	tree.preOrder(root);

	std::cout << "\n트리를 중위 순회로 출력" << std::endl;
	tree.inOrder(root);

	std::cout << "\n트리를 후위 순회로 출력" << std::endl;
	tree.postOrder(root);
}
#pragma endregion

#pragma region BST 구현

// root 에서 부터 데이터를 삽입한다.
// root 보가 insert 값이 작으면 왼쪽으로 크면 오른쪽으로 저장
// 모든 데이터를 저장 후 중위순회 방식으로 데이터를 읽으면 오름차순으로 데이터가 정렬된다.

class BST
{
private:
	Node* root;

	Node* insert(Node* node,int value)
	{
		// 데이터가 0개 일 때
		if (node == nullptr)
		{
			return new Node(value);
		}

		// node 작으면? 왼쪽, 크면? 오른쪽
		if (node->value > value)
		{
			node->leftNode = insert(node->leftNode, value);
		}
		else if (node->value < value)
		{
			node->rightNode = insert(node->rightNode, value);
		}

		return node;

	}

	Node* findMin(Node* node)
	{
		if (node == nullptr || node->leftNode == nullptr)
		{
			return node;
		}

		return findMin(node->leftNode);
	}

	Node* findMax(Node* node)
	{
		if (node == nullptr || node->rightNode == nullptr)
		{
			return node;
		}

		return findMax(node->rightNode);
	}

	Node* deleteNode(Node* node, int target) // 삭제. 데이터를 찾은 다음에, 있으면 지운다.
	{
		if (node == nullptr) { return nullptr; }


		if (node->value > target) // 왼쪽 노드로 이동
		{
			node->leftNode = deleteNode(node->leftNode, target);
		}
		else if (node->value < target) // 오른쪽 노드로 이동
		{
			node->rightNode = deleteNode(node->rightNode, target);
		}
		else // 지울 노드를 찾았을 때, 노드를 삭제
		{
			// 찾았다. 삭제한다.
			/*if (node->leftNode == nullptr && node->rightNode == nullptr);
			if (node->leftNode == nullptr);
			if (node->rightNode == nullptr);*/

			if (node->leftNode == nullptr || node->rightNode == nullptr)
			{
				Node* temp = node->leftNode != nullptr ? node->leftNode : node->rightNode; // 왼쪽, 오른쪽 체크

				if (temp == nullptr) // 자식이 없는 경우
				{
					temp = node;
					node = nullptr;
				}
				else
				{
					node = temp;
				}

			}
			else // 자식이 둘인 경우
			{
				// 오른쪽에서 가장 작은 값을 찾겠다. findMin()

				Node* temp = findMin(node->rightNode);
				node->value = temp->value;
				node->rightNode = deleteNode(node->rightNode, temp->value);
			}
		}	

		return node;

	}

	void inOrder(Node* node)
	{
		if (node == nullptr) { return; }

		inOrder(node->leftNode);			//L
		std::cout << node->value << " ";	//N
		inOrder(node->rightNode);			//R
	}

public:
	// 생성자 만들때 nullptr 자동 처리가 안되어 작성한 코드
	BST()
	{
		root = nullptr;
	}

	void insert(int value)
	{
		root = insert(root, value);
	}

	// 중위 순회로 root를 읽는 코드 작성
	void inOrder()
	{
		inOrder(root);			
	}

	void DeleteNode(int value)
	{
		root = deleteNode(root, value);
	}

};
	// std::cout << "\n이진 검색 트리 데이터 입력 예시" BST bst bst.insert(4,3,5,1,2,6)

#pragma endregion



int main()
{
	NodeConnect();

	std::cout << "\n이진 검색 트리 데이터 입력 예시" << std::endl;

	BST bst;
	bst.insert(4);
	bst.insert(3);
	bst.insert(5);
	bst.inOrder();
	std::cout << "\n이진 검색 트리 데이터 입력 예시" << std::endl;
	bst.insert(1);
	bst.insert(2);
	bst.insert(6);
	bst.inOrder();

	std::cout << "\n데이터 삭제" << std::endl;
	bst.DeleteNode(4);
	bst.inOrder();

}