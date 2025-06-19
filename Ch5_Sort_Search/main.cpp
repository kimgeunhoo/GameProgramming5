#include <iostream>
#include <vector>

/*
	���� �پ��� ������� ���� ����.
	�� ������ �ؾ��ϴ°�?
	���ο� ������(Item) �����̳� �߰��� ��, ���ĵǾ� �ִ� ���·� ������ �Ǵ� ��찡 �ִ�.
*/

/*
	Ž�� : �����̳� �ȿ� �����Ͱ� �ִ��� ������ ã�´�.
	Ž���� ���α׷��� �ڵ�� �ѹ� �����غ���.
	(1) �տ��� ���� �����͸� ���ؼ� �ִ��� ������ Ȯ��
		- ���� Ž�� ���(linear search)
	(2) ���� Ž�� (binary search)
		- �����̳ʰ� ���ĵǾ� ���� �� �߾Ӱ��� �������� �����͸� ����� ã�� ���
*/

/*
	���� Ž���� ��쿡�� �ּ��� ���(best case) 0(1) �ð��� �ɸ��� �־��� ���(worst case) n �ð��� �ɸ���.
	��� O(n) �ð��� �ɸ���. �������� ������ �鸸�� �Ѿ�� ��ȿ�����̴�.
	"���� ���� �˰���" : ������ ����� ���� ������ �ذ��ϴ� ������� ������ Ǭ��.
*/

#include <utility>

/*
	std::pair<int, Ŭ�����̸�>
	std::pair<int, std::string> data;

	std::vector<std::pair<int, std::string>> data;
	// pairŸ�� �����ϴ� ���
	data.push_back({0, "AAA"});		0 ~ 5
	// �ش��ϴ� �ε����� ������ �� �ε����� ����Ǿ� �ִ� ���ڸ� ����ϴ� �ڵ带 �����

	// ������ ID�� ������ ���� ������ ����. ������ ������ ID�� �������� �ش� ������ ����(�г���)��
	// �˻��ϴ� ����� �����ϱ�
*/

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

template<typename T1, typename T2>
struct myPair
{
	T1 first;
	T2 second;
	// ���� ����, �̵�, ������ �����ε�...

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
	// ��ü ������ �ݺ��ؼ�	 for �ݺ���
	for (int i = 0; i < n; i++)
	{
		// arr[0] arr[1] ... arr[n]
		// target�� ���� �����Ͱ� �����ϸ�  ���ǹ�
		if (arr[i] == target)
		{
			std::cout << "�ش��ϴ� �����͸� : " << target << " �� ã�ҽ��ϴ�.";
			return;
		}

	}
	
	std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
}


void LinearSearch(std::vector<int>& arr, int target)
{
	int n = arr.size();
	// ��ü ������ �ݺ��ؼ�	 for �ݺ���
	for (int i = 0; i < n; i++)
	{
		// arr[0] arr[1] ... arr[n]
		// target�� ���� �����Ͱ� �����ϸ�  ���ǹ�
		if (arr[i] == target)
		{
			std::cout << "�ش��ϴ� �����͸� : " << target << " �� ã�ҽ��ϴ�.";
			return;
		}

	}

	std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
}


// iterator ������� ������ ���� Ž��

void BinarySearch(int arr[], int n, int target)
{
	// int mid = (left + right) / 2		    - 20�� + 20�� = �����÷ο� �߻�
	// int mid = left + (right - left) / 2  - ���ʿ��� ���������� ���� �Ÿ� /2 �����ش�. �� �ĺ��ٴ� �����ϴ�.

	int i = 0;		// ����
	int j = n - 1;	// ������
	

	while (i <= j) // ����, ������
	{
		int mid = i + (j - i) / 2; // ���� �������� �߾Ӱ��� �����Ѵ�.
		// ���� mid���� target ���� ��

		if (arr[mid] == target)	// target ã�� ��� : ������ ã��
		{
			std::cout << "�ش��ϴ� �����͸� : " << target << " �� ã�ҽ��ϴ�.";
			return;
		}
		else if (arr[mid] > target)	// target ������� : ���ʿ��� �ٽ� ã���ÿ�
		{
			j = mid - 1;	// mid�� �������� ��� j �� �ٲ�� �ϳ�
		}
		else		// target ū ���
		{
			i = mid + 1;	// ���� i�� mid�� �������� ��� �ٲ�� �ϳ�?
		}
	
	}

	std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;

}

void BinarySearch(std::vector<int>& arr, int target)
{
	// int mid = (left + right) / 2		    - 20�� + 20�� = �����÷ο� �߻�
	// int mid = left + (right - left) / 2  - ���ʿ��� ���������� ���� �Ÿ� /2 �����ش�. �� �ĺ��ٴ� �����ϴ�.
	int n = arr.size();

	int i = 0;		// ����
	int j = n - 1;	// ������
	

	while (i <= j) // ����, ������
	{
		int mid = i + (j - i) / 2; // ���� �������� �߾Ӱ��� �����Ѵ�.
		// ���� mid���� target ���� ��

		if (arr[mid] == target)	// target ã�� ��� : ������ ã��
		{
			std::cout << "�ش��ϴ� �����͸� : " << target << " �� ã�ҽ��ϴ�.";
			return;
		}
		else if (arr[mid] > target)	// target ������� : ���ʿ��� �ٽ� ã���ÿ�
		{
			j = mid - 1;	// mid�� �������� ��� j �� �ٲ�� �ϳ�
		}
		else		// target ū ���
		{
			i = mid + 1;	// ���� i�� mid�� �������� ��� �ٲ�� �ϳ�?
		}

	}

	std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;

}

// ����Լ� ������� ������ ���� Ž��
void BinarySearchByRecursive(int arr[], int n, int target, int left, int right)
{
	// ����Լ��� Ż���� �� �ִ� ����
	if (left > right)
	{
		std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
		return;
	}

	int mid = left + (right - left) / 2;

	if (arr[mid] == target)
	{
		std::cout << "�ش��ϴ� �����͸� : " << target << " �� ã�ҽ��ϴ�.";
		return;
	}
	else if (arr[mid] > target) // ���ʿ� �ִ�. (right = mid - 1) 
	{
		BinarySearchByRecursive(arr, n, target, left, mid - 1);
	}
	else // �����ʿ� �ִ�. (left = mid + 1)
	{
		BinarySearchByRecursive(arr, n, target, mid + 1, right);
	}

	// �ڱ� �ڽ��� �Լ��� ȣ���Ͻÿ�

	//if (arr[mid] == target)	// target ã�� ��� : ������ ã��
	//{
	//	std::cout << "�ش��ϴ� �����͸� : " << target << " �� ã�ҽ��ϴ�.";
	//	return;
	//}
	//else if (arr[mid] > target)	// target ������� : ���ʿ��� �ٽ� ã���ÿ�
	//{
	//	j = mid - 1;	// mid�� �������� ��� j �� �ٲ�� �ϳ�
	//}
	//else		// target ū ���
	//{
	//	i = mid + 1;	// ���� i�� mid�� �������� ��� �ٲ�� �ϳ�?
	//}

}


void Example()
{
	// pair ������ �ϳ��� ǥ���ϴ� ���. key�� value ���� �����ؼ� �����ϴ� ���.
	// ������ �����ε�. Ŭ���� �񱳸� ������.
	// ������ ID - 7C3A3X30F282D

	std::vector<std::pair<int, std::string>> data;

	std::pair<int, std::string> a = { 1, "AAA" };
	data.push_back({ 0, "AAA" });
	data.push_back(a);
	data.push_back(std::make_pair(2, "CCC"));
	data.push_back({ 3, "DDD" });
	data.push_back({ 4, "EEE" });

	// ���� Ž��, ���� Ž���� ����ؼ� ������� ã���ÿ�.

	// Ÿ���� �ٸ��� ������ �ش��ϴ� Ÿ������ �ٽ� ����� ��� �Ѵ�.

	std::vector<int> temp;
	for (int i = 0; i < data.size(); i++)
	{
		temp.push_back(data[i].first);
	}

	/*
		== �˰��� ���� ==
		1. ��ȯ���� bool Ÿ������ �����غ���
		2. LinearSearch(vector<int> -> vector<pair<int, string>> �������� �����غ���
		3. UserId�� ����ؼ� ������ �г����� ����ϴ� �ڵ带 �ϼ��غ���
	*/

	LinearSearch(temp, 4); // ���� �����Ѵٸ�
	std::cout << "�����Ͱ� �����մϴ�. : (" << data[4].second << ")" << std::endl;

}

// class UserDataManager

bool UserDataSearch(std::vector<std::pair<int, std::string>> data, int userID)
{
	// Ž�� �Լ� + pair Ŭ���� �ߺ��ؼ� �ڵ� ǥ���� �����Ѱ�?
	// ���� Ž��
	for (int i = 0; i < data.size(); i++)
	{
		if ( data[i].first == userID)
		{
			std::cout << "�г��� : "  << data[i].second << std::endl;
			return true;
		}
	}

	std::cout << "���� ���̵� �ش��ϴ� �����Ͱ� �����ϴ�." << std::endl;
	return false;
}

int main()
{
	std::cout << "���� ���̵�� �г��� �˻��ϱ� ����" << std::endl;
	std::vector<std::pair<int, std::string>> data3;
	data3.push_back({ 0,"AAA" });
	data3.push_back({ 1,"BBB" });
	data3.push_back({ 2,"CCC" });
	data3.push_back({ 3,"DDD" });

	if (UserDataSearch(data3, 3)) // �ش��ϴ� ���� ���̵� �����Ѵٸ�
	{
		data3[3].second = "EEE";
		// ������ �ؾ� �ϳ�? data3[3] -> �����ϴ� �ڵ带 �ۼ��� �� �ִ�.
		// �г����� �����Ͻÿ�. // ��й�ȣ�� �Է��ϰ� �ش� �г������� �α����Ѵ�.

	}
	UserDataSearch(data3, 3);


	std::cout << "\n�迭�� �����ϴ� ���� Ž��" << std::endl;
	int arr[5] = {0, 5, 1, 3, 2};
	LinearSearch(arr, 5, 2);

	std::cout << "\n���ͷ� ������ ���� Ž��" << std::endl;
	std::vector<int> data = { 0, 5, 1, 3, 2 };
	LinearSearch(data, 3);

	std::cout << "\n�迭�� �����ϴ� ���� Ž��" << std::endl;
	int arr2[5] = { 0, 1, 2, 3, 5 };
	BinarySearch(arr2, 5, 2);

	std::cout << "\n���ͷ� ������ ���� Ž��" << std::endl;
	std::vector<int> data2 = { 0, 1, 2, 3, 5 };
	BinarySearch(data2, 5);

	std::cout << "\n�迭�� ������ ��� ��� ���� Ž��" << std::endl;
	int arr3[5] = { 0, 5, 1, 3, 2 };
	BinarySearchByRecursive(arr3, 5, 2, 0, 4);

	Example();
}