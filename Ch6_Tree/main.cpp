/*
	�ڡڡ� Ž���� �ڷᱸ�� �����ؼ� �����غ��� �ڡڡ�
	- vector	: ���� Ž��, ���� Ž��
	  - ���� : ����ϴ� �����̳ʰ� ������ �Ǿ� �־�� �Ѵ�.
		- ��� ���� �����̳��� Ư¡ : ������ ���� �ٷ� �����Ҽ� �ִ�.
		���� ���� �ƴ� ������ ���� �����Ҷ� ��ȿ�����̴�.

	- list		: ������ ���� ������ ��� �� �� �ִ�.
	  - mid index�� ���� target ��
		- 0 -> mid ���������� Ž�� �� mid ���� ��ȯ�Ѵ�.

	���� :logN �ð��� Ȯ��������, ����ϱ� ���� �ڷᱸ���� �������� �ʴ�.
	���� �����̳� : set, map // Ʈ�� ������ ������ �Ǿ��ִ�.

*/

/*
	Tree �ڷᱸ��
	�����͸� ��� �����ϴ� �����ΰ�?
	��� ���·� �����͸� �����Ѵ�. Value, ����Ǿ� �ִ� Node �ּҸ� �����Ѵ�.
*/

/*
	Tree ��ȸ ��� : ������� Tree�� �д� ���

	���� ��ȸ pre-order		: NLR	�д� ���
	���� ��ȸ in-order		: LNR	�д� ���
	���� ��ȸ post-order	: LRN	�д� ���
*/

/*
	BST (Binary Search Tree) ���� �˻� Ʈ��
	- �ڱ� �ڽ�, ����, �������� �����ϴ� ��带 ������.
	- Node �������� ���ʰ� �������� ���� ���� �� �ִ�.
	- ���� ���� �������� ū ���� ���������� ������ �ϸ� ��Ģ���� ���´�.
	- Ư���� ��Ģ�� ���� Ŭ������ ���� �����͸� ����غ���.
*/

/*
	���� �����̳� ����� ���� - Ž�� �� ������ ȿ�������� �ʳ�.
	���� �����̳� - "Tree �ڷ� ����"
	"BST" - ���� �˻� �˰������� �ڷᱸ���� ǥ���� ��
	���� : Ʈ���� �� ������ ����� ��� O(n) �ð���ŭ �ɸ���.
*/

template<typename T1, typename T2>
struct Node
{
	int value;
	Node* leftNode;
	Node* rightNode;

	Node(int val) : value(val), leftNode(nullptr), rightNode(nullptr) {}

};

#include <iostream>
#include <vector>

// Ʈ���� ������� ��尡 ������ �־�����. ���� ��ȸ�� ������� ���� ����� �ۼ��Ͻÿ�. 
// NLR ������ �ֳ�?

#pragma region Ʈ�� ��ȸ�ϴ� ���
class Tree
{
public:
	void preOrder(Node* root)  // ��� ������� �����
	{
		if (root == nullptr) { return; } // ��� Ż�� ����

		std::cout << root->value << " "; // N
		preOrder(root->leftNode);		 // L�� �ִ� ��忡 ���� preOrder ����
		preOrder(root->rightNode);		 // R�� �ִ� ��忡 ���� postOrder ����

	}
	void inOrder(Node* root)
	{
		if (root == nullptr) { return; } // ��� Ż�� ����

		inOrder(root->leftNode);
		std::cout << root->value << " ";
		inOrder(root->rightNode);
	}
	void postOrder(Node* root)
	{
		if (root == nullptr) { return; } // ��� Ż�� ����

		postOrder(root->leftNode);
		postOrder(root->rightNode);
		std::cout << root->value << " ";
	}

};

#pragma endregion

#pragma region ��� ���� ����
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

	std::cout << "Ʈ���� ���� ��ȸ�� ���" << std::endl;
	Tree tree;
	tree.preOrder(root);

	std::cout << "\nƮ���� ���� ��ȸ�� ���" << std::endl;
	tree.inOrder(root);

	std::cout << "\nƮ���� ���� ��ȸ�� ���" << std::endl;
	tree.postOrder(root);
}
#pragma endregion

#pragma region BST ����

// root ���� ���� �����͸� �����Ѵ�.
// root ���� insert ���� ������ �������� ũ�� ���������� ����
// ��� �����͸� ���� �� ������ȸ ������� �����͸� ������ ������������ �����Ͱ� ���ĵȴ�.

class BST
{
private:
	Node* root;

	Node* insert(Node* node,int value)
	{
		// �����Ͱ� 0�� �� ��
		if (node == nullptr)
		{
			return new Node(value);
		}

		// node ������? ����, ũ��? ������
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

	void inOrder(Node* node)
	{
		if (node == nullptr) { return; }

		inOrder(node->leftNode);			//L
		std::cout << node->value << " ";	//N
		inOrder(node->rightNode);			//R
	}

public:
	// ������ ���鶧 nullptr �ڵ� ó���� �ȵǾ� �ۼ��� �ڵ�
	BST()
	{
		root = nullptr;
	}

	void insert(int value)
	{
		root = insert(root, value);
	}

	// ���� ��ȸ�� root�� �д� �ڵ� �ۼ�
	void inOrder()
	{
		inOrder(root);			
	}


};
	// std::cout << "\n���� �˻� Ʈ�� ������ �Է� ����" BST bst bst.insert(4,3,5,1,2,6)

#pragma endregion



int main()
{
	NodeConnect();

	std::cout << "\n���� �˻� Ʈ�� ������ �Է� ����" << std::endl;

	BST bst;
	bst.insert(4);
	bst.insert(3);
	bst.insert(5);
	bst.inOrder();
	std::cout << "\n���� �˻� Ʈ�� ������ �Է� ����" << std::endl;
	bst.insert(1);
	bst.insert(2);
	bst.insert(6);
	bst.inOrder();
}