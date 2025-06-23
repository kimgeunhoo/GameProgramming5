/*
	0. k��° ���� ã�� ���� ����, delete temp �����ϱ�
	1. Heap Ư���� ��Ģ�� ���� �ִ� �ڷᱸ�� ���� �����ϱ�
	2. k��° �����ϴ� ���� �� ���� ã�� �� �ִ�. -> ���� ����
*/

// k��° ���� ã��

// 1. vector, array ���ڸ� ���Ľ�Ų �Ŀ� ���� ũ�ų� (����) ���� ã�´�. (���� �˰��� �ð�)
// 2. ��ü ������ n���� ������ n 1�� �񱳸� �ؾ��Ѵ�.					 (��� ����� ���� Ž��, ���� Ž��)
// 3. �ð� logN�� �ɸ��� ����� ������? 
// (-> �������� ���� �鸸�� �̻�(ó���ؾ� �� �����Ͱ� ������) �� �� ��� �ؾ� �ϳ�?)
// ���� ó���ؾ� �� �����Ͱ� ������, (10 ~ 1)


// Tree ( ���������� �����Ͱ� ����� ��� ȿ�������� �ʴ�. )
// 1. ������ �ذ��ϱ� ���� ������� Ʈ�� ���·� ���� ������ �����͸� �־��. (Ʈ���� ���ʴ�� �����Ѵ�. ���� ���� Ʈ��)
// 2. root �������� ���� ū �� (���� ���� ��)�� �����ϵ��� ��Ģ�� �����Ѵ�.
// ���� ��Ģ�� ���� �ڷᱸ�� ��(Heap) �̶�� �θ���. maxHeap, minHeap

// MaxHeap ������ ���� MinHeap ���� �����غ��� (�ڽ���)

#include <iostream>
#include <queue>
#include <algorithm>

void PriorityQueue()
{
	std::priority_queue<int> pq;

	// heap �ڷᱸ���� ������� Ŭ�����̴�.
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
		�θ� ��带 �������� ū �༮�� �ٲٸ� �ȵǴ°�?
		heap�� Ư¡�� �����Ͱ� ���� �� heap�� ������ �����ϰ� �ִٰ� ����.
		���� ���� �༮�� ��Ģ�� �µ��� ����
	*/

	void heapifyup(Node* node) // ���� �߰��� ��� node
	{ 
		// node�� �θ� ��带 �����ͷ� ����Ű�� �ִ�. node->parentNode->value	node->value

		// while (1�� ���� && 2�� ����)
		// 1. �߰��� ���� �θ� ����� ���� ���ϴ� �ڵ带 �����, ���� �߰��� ��尡 �� Ŭ ��
		// 2. ���� �߰��� ����� �θ� ��尡 �����ϸ� ��� ����

		// node -> parentNode ������

		while (node->value > node->parentNode->value && node->parentNode != nullptr) // ������ �ϱ� ���� ����
		{
			// �˰��� ����� �߰����� ������, �θ� ���� �ڱ� ��带 swap�Ѵ�. (value�� swap)
			// swap �Ŀ� node�� �θ� ���� �������ش�.( �θ� ��带 ����Ű�� �ִ� ���� �����Ѵ�.)

			std::swap(node->value , node->parentNode->value);
			node = node->parentNode;
			
		}

	}

	Node* findLastNode()	// ��带 ������ �� ��Ģ 1�� ������Ű�� ���ؼ� ���� ������ ��带 ã�´�.
	{
		if (!root) { return nullptr; } // �����Ͱ� 1���� ���� ��� ���� x

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
		// ��Ʈ�� �ø� ������ ��带 �� �ڽ� ���(����, ������) �߿��� ū ���� ��ü�Ѵ�.
		// �ڽ��� ����, ������ ��庸�� �ڱⰡ �� ũ�ų�, �� �̻� �ڽ��� ���� �� ���� �ݺ��Ѵ�.

		while (node)
		{
			Node* largest = node; // ���� ��尡 ���� ũ��. (����)

			if (node->leftNode&& node->leftNode->value > largest->value)
			{
				largest = node->leftNode;
			}

			if (node->rightNode && node->rightNode->value > largest->value)
			{
				largest = node->rightNode;
			}

			// ���ʰ� ������ �߿��� ū ���� �ٲ��.
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

		if (!root) // �����Ͱ� 0���� ���, ���� ���� �����Ͱ� ��Ʈ�� �ȴ�.
		{
			root = newNode;
			size = 1;
			return;
		}

		// ��Ʈ�� ������ ���, ��Ģ 1�� ���� ������� ��尡 ����� �� �ְ� ������ �ۼ��Ͻÿ�
		// ���ʿ� �����Ͱ� ������ -> ���ʿ� ������ �ֱ�
		// ���ʿ� �����Ͱ� ������ -> �����ʿ� ������ �ֱ�
		
		std::queue<Node*> q; // FIFO
		q.push(root);

		while (!q.empty()) // q(������)�� �������� �ݺ�
		{
			Node* currentNode = q.front();
			q.pop();

			if (!currentNode->leftNode) // ���ʿ� �����Ͱ� ������ -> ���ʿ� ������ �ֱ�
			{
				currentNode->leftNode = newNode;	// ���� ����� ���� �ڽĿ� ���ο� �����͸� �־���
				newNode->parentNode = currentNode;	// �ڽ��� �θ� ������ �ش�.
				break;
			}

			if (!currentNode->rightNode) // �����ʿ� �����Ͱ� ���� �� -> �����ʿ� ������ �ֱ�
			{
				currentNode->rightNode = newNode;
				newNode->parentNode = currentNode;
				break;
			}

			// root�� ���̻� ����� ��尡 ������ ���� �ݺ��ϱ� ���� ����� ������ �߰����ִ� �ڵ�
			q.push(currentNode->leftNode);
			q.push(currentNode->rightNode);
		}

		size++;
		heapifyup(newNode);
		// ���� �� ����, �� �θ��� ��带 ���ϱ� ���ؼ� ū ���� �������� ������
		// heapifyup
		

	}

	int extractMax() // �ִ밪�� �����϶�. front, pop
	{
		if (!root) { return - 1; } // -1 ������ ������ �ִٰ� �˸�

		int maxValue = root->value;

		if (size == 1)			// 1���� ���� ���� 1���� ���ְ� �ִ밪�� ��ȯ�Ѵ�.
		{
			delete root;
			root = nullptr;
			size = 0;
			return maxValue;
		}

		// 1. ������ ��带 ã���ÿ�
		Node* lastNode = findLastNode();
		if (!lastNode) { return -2; } // if -1 root ������ 0���� ����, -2 ������ ��带 ã�� �ڵ尡 ������ �ִ�.

		// 2. ������ ��带 root ���� �̵���Ų �� �ٽ� heap ������ ������ ����
		root->value = lastNode->value; // ���� �ؿ� �ִ� ��带 ����Ŵ, ���� root ���� ������ ���� ����ִ�.
		
		// ����� ���ؼ� ����Ű�� �ִ� ���� ������ ���
		if (lastNode->parentNode)
		{
			// lastNode�� ���� root�� �ö����ϱ� ���� lastNode�� �ִ� �ּҸ� nullptr�� �ٲٱ�
			if (lastNode->parentNode->leftNode == lastNode) // ������ ��尡 �θ��� ���ʿ� �ִ� ���
			{
				lastNode->parentNode->leftNode = nullptr;
			}
			else // ������ ��尡 �θ� ����� �����ʿ� �ִ°�� 
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
	RPG���� �������̵� 5����Ƽ ����, ����, �ü�, ������, ������
	������ �������� ��ų�� ����� ������ ���� ��׷ΰ� �����Ѵ�.
	�� 5���� ���� ���ݸ��� ������ �켱������ �����ϴ��� ã�� ���� �ۼ�
	�� ��, ������ Ư�� ������ ������ ������ �� ������ ��׷δ� 0���� �ʱ�ȭ �ȴ�.
				1��		2��		3��		4��		5��
	����	:	10		5		8		7		6		(�����ϰų�, �������� ��ų�� ���� �� ��ġ�� ����.)
	����	:
	�ü�	:
	������	:
	������	:

	[������ ��ų�� �����ϴ� ����]
	���� : ��Ƽ �߿��� ���� ���� �������ΰ�? ���� ���� �� �����Ѱ�? (���߼�ġ)

	(1) n���� �������� �켱������ �� ���� ū ������ ����Ѵ�.
	(2) Heap �ڷᱸ���� ����ؼ� k��° ������ ã�´�.

	- ������ ������ 1�� ����� ȿ����
	- 2���� ����ط��ϴ� ������ ã�ƾ� �� �켱 ���� ����� ������ �������� 2�� ����� ȿ�����̴�.
*/

int main() 
{
	MaxHeap mHeap;

	std::cout << "���� ū ���� ã�� Heap ������ �Է�" << std::endl;

	mHeap.insert(7);
	mHeap.insert(3);
	mHeap.insert(5);
	mHeap.insert(11);

	std::cout << "���� ū ���� ��ȯ�ϰ� �ٽ� Heap �����ϴ� ����" << std::endl;
	int maxValue = mHeap.extractMax(); // 1��° ū ��
	int kthValue;
	for (int i = 0; i < 2; i++)
	{
		kthValue = mHeap.extractMax(); // 2��°�� ū �� kthValue ����ȴ�.
	}

	// k��°�� ū ���� ã�ƶ�.
}