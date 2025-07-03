/*
	1. ���̵� � ������� �����ߴ°�?
	2. �ڷᱸ���� � ������ �����ߴ��� ������ �����غ���
*/

#include <iostream>
#include <algorithm>
#include <vector>

#pragma region Q1
// ATM ����. ���� 11399��. ATM�� ������� ���� ���� �ִ�. 
// n���� ����� ��� ��ٸ� �ð��� �ּ��� �ð��� �Ƿ���
// ��� �ؾ��ϳ�? �׸��� �� �ð��� �������� ���� ����ϱ�

/*
	int -> "people" "client" ( ��ٸ��� ��� ����, ����ؾ� �� �ð�, ���� �� )
*/

void Solve1()
{
	struct Client
	{
		int waitId; // ��ٸ��� ����
		int waitTime;	// ��� �ð�

		Client(int waitId, int waitTime)
			: waitId(waitId), waitTime(waitTime) {}
	};

	std::cout << "====== ATM ���� Ǯ�� =======" << std::endl;

	int n = 5;		   // �� �ο� ��
	int totalTime = 0; // ��� �ο��� ��ٸ� �ð�
	// ������ �ο� ���� ��ٸ��� �ð��� ���� �� �����ؾ� �Ѵ�. -> �ڷᱸ�� -> vector<int>
	// 1. vector<int> waitTimeTable; ������ ������ �߰��غ���
	// 3, 1, 4, 3, 2
	// 2. ������ Ǯ�� ����� �����غ���

	std::vector<int> waitTimeTable;

	waitTimeTable.push_back(3);
	waitTimeTable.push_back(1);
	waitTimeTable.push_back(4);
	waitTimeTable.push_back(3);
	waitTimeTable.push_back(2);

	std::vector<int> clients(waitTimeTable.size(), -1);

	// client���� ��ٸ� �ð��� �����ؾ� �Ѵ�.
	// �־��� ������ ��� ���� ���ٸ�
	// ���̵�� : ���� ���� ������ �����͸� ���Ľ�Ų��. (greedy Algorithm)
	// ���� ��Ų �� �ݺ������� �����ش�.
	
	// clients���� �ð��� ���� ������ ������ �ֱ�
	// DP(������ȹ��) : �ݺ��� + �ڷᱸ�� bottom - up
	std::sort(waitTimeTable.begin(), waitTimeTable.end());

	// 1. ó�� ����ϴ� ���.
	clients[0] = waitTimeTable[0];

	for (int i = 1; i < waitTimeTable.size(); i++)
	{
		clients[i] = clients[i - 1] + waitTimeTable[i];		
		
	}
	
	//clients[1] = clients[0] + waitTimeTable[i];
	//clients[2] = clients[1] + 4;
	//clients[3] = clients[2] + 3;

	for (int t : clients)
	{
		totalTime += t;
	}

	// �־��� �����ʹ�� ���� ���ٸ�?

	std::cout << n << "���� ������� ��� ��ٸ��� �ð��� �ּҰ� �Ǵ� �ð��� " << totalTime << std::endl;

}
#pragma endregion

#pragma region Q2
// �賶�� ���� ��� ����. ���� 12865��. ������ N�� ���� �� �ִ� ���� K���� �־�����. 
// �ִ��� ��ġ�� ������ �� �ִ� ���� ���ΰ�?
// ���Ը� �ִ��� ����� �� �ִ��� ��ġ�� ������ ���� ���� ���

void Solve2()
{
	// 4���� ������ ���´�. ������ ���ǿ��� ���Կ� ��ġ�� ǥ���ǰ� �ִ�.
	// k�� ���Ը�ŭ �賶 �ȿ� �ִ������� ������ ���� ��, ��ġ�� ���� ũ���� �����ϴ� ����� ����

	// 1. n = 4, k = 7, [6, 13] [4, 8] [3, 6] [5, 12] �����ͷ� ǥ���غ���
	// 2. ���̵�� : ���� ��ġ�ִ� ���ǵ鸸 ��� ���ؼ� ��� �ؾ��ϴ°�?
	struct Product
	{
		int weight;
		int value;

		Product(int weight, int value) : weight(weight), value(value){}
	};

	std::cout << "\n========= �賶 ���� Ǯ�� ===========" << std::endl;

	int n = 4; int k = 7;

	std::vector<std::pair<int, int>> items{ {6, 13}, {4, 8}, {3, 6}, {5, 12} };
	std::vector<int> weight;
	
	// ���Ժ� ��ġ ��
	// �賶�� 1�� �� �ִ�� ���� �� �ִ� ��ġ?

	std::vector<int> dp(k+1, 0); // dp[0] ~ dp[7]

	// ���� 0�� ��? �� ���Կ��� �ִ�� ���� �� �ֵ��� ���Ժ� �ְ� ��ġ�� ����
	//dp[0] = 0;
	//dp[1] = 0;
	//dp[2] = 0;
	//dp[3] = 6;
	//dp[4] = 8; // ���� ������ ��ġ + ���� ���� �� �ִ� ��ġ		�ϳ��� ��ġ ��
	//dp[5] = 12;
	//dp[6] = 13;
	//dp[7] = 0;	 // 6 + 1 : 13, 5 + 2 : 12, 4 + 3 : 14, ���� ��ġ�� ū ���̽�

	for (int i = 0; i < 4; i++)
	{
		int weight = items[i].first; // ����
		int value = items[i].second; // ��ġ

		for (int w = k; w >= weight; w--) // 7kg, 6
		{
			dp[w] = std::max(dp[w], dp[w - weight] + value);
		}

	}

	std::cout << "������ ���԰� 7���� ���� �� ���� �� �ִ� ��ġ : " << dp[7] << std::endl;

}
#pragma endregion

// �κ��丮 - ���� �ý���. User ���Ǽ��� ���� �ڵ�. ������ �߿��� ���� ��ġ�ִ� �������� �����ϴ� �ڵ� �����

// �̸��� Ŭ������ ����� -> Item Ŭ����, ���Զ�� ��ġ�� ���Եǵ��� �����
// ������ �����ϴ� �����̳�, �κ��丮, ���԰� �����ϴ� �κ��丮 ����

class ItemW
{
	std::string name;
	int weight;
	int value;
public:
	ItemW(std::string _name, int _weight, int _value) : name(_name), weight(_weight), value(_value) {}

	int GetWeight() const { return weight; }
	int GetValue() const { return value; }
	std::string GetName() const { return name; }
};

class InventoryW // ItemW �ڷ����� �����̳ʷ� ����
{
private:
	std::vector<ItemW> Items;
	int maxWeight;
	int currentWeight;
public:
	// ������
	InventoryW(int max) : maxWeight(max), currentWeight(0) {}

	// ������ �߰�

	void AddItem(const ItemW& addItem)
	{
		if (CheckWeight(addItem))
		{
			Items.push_back(addItem);
			currentWeight += addItem.GetWeight();
		}
	}

	// �ִ� ���Ժ��� �������� �� ���԰� ���ſ�� false, true

	bool CheckWeight(const ItemW& addItem)
	{
		return maxWeight < currentWeight + addItem.GetWeight();
	}

	/*
		1. ������ ������ �� �߿��� ���� ū ��ġ, ������ ������ �����۵� (�ڷᱸ��)
		-> ��ȯ���� pair< T1, T2 >
	*/

	std::pair<int, std::vector<ItemW>> findBestItem(int targetWeight, std::vector<ItemW>& selectableItems)
	{
		// ���� �������� ���Կ� ���ο� ������ ������ ������ �� �� �������� ������ �����̳� ����

		std::vector<int> dp(targetWeight + 1, 0);

		// selectableItems ����ִ� ����. weight
		// selectableItems ����ִ� ��ġ. value

		std::vector<std::vector<bool>> selected(selectableItems.size(), std::vector<bool>(targetWeight + 1, false));

		for (int i = 0; i < selectableItems.size(); i++)
		{
			int weight = selectableItems[i].GetWeight();
			int value = selectableItems[i].GetValue();
			for (int w = targetWeight; w >= weight; w--)
			{
				/*
					�ش� �ڵ� ����
				*/

				if (dp[w-weight] + value > dp[w])	// ���� ���� ������ + ���� ���� ��ü���Ժ��� Ŭ ����
				{
					dp[w] = dp[w - weight] + value;
					selected[i][w] = true;
				}
				

			}
		}

		// ����� ������ ������ �����ؼ� �ٽ� vector �����ϴ� �ڵ�
		// while(weight - ����) 

		std::vector<ItemW> bestItems;
		int w = targetWeight;

		for (int i = selectableItems.size() - 1; i >= 0 && w > 0; i--)
		{
			if (selected[i][w])
			{
				bestItems.push_back(selectableItems[i]);
				w -= selectableItems[i].GetWeight();
			}
		}


		return std::make_pair(dp[targetWeight], bestItems);

	}

	std::vector<ItemW>& GetInventory() { return Items; }
};

void InventoryWeightSystem()
{
	// �κ��丮 ���� �� ȣ��, 4���� �������� �� �賶�� ����. 
	// �ִ� ���԰� 7�̰�, �������� 4�� ����

	InventoryW inventory(7);

	//6, 4, 3, 5
	ItemW A("A", 6, 13);
	ItemW B("B", 4, 8);
	ItemW C("C", 3, 6);
	ItemW D("D", 5, 11);

	std::vector<ItemW> selectableTable{ A, B, C, D };

	std::pair<int,std::vector<ItemW>> bestItems = inventory.findBestItem(7, selectableTable);

	std::cout << "�־��� �������� �ִ� ��ġ : " << bestItems.first << std::endl;
	std::vector<ItemW> ItemC = bestItems.second;


	int i = 0;

	// �κ��丮�� �������� �ִ� �ڵ带 �ּ��� �������� �κ��丮�� �߰��ϵ��� �����غ���
	/*inventory.AddItem(A);
	inventory.AddItem(B);*/

	for (auto& item : ItemC)
	{
		i++;
		std::cout << i << "��° ������ �̸� : " << item.GetName() 
			<< ", ���� : " << item.GetWeight() 
			<< ", ��ġ : " << item.GetValue() << std::endl;
		// ������ ������� �� �����Ͻÿ� if ( ���� �Է� �ڵ� )
		inventory.AddItem(item);
	}

	/*std::cout << "�־��� �������� �ִ� ��ġ : " << 
		inventory.findBestItem(7, selectableTable) << std::endl;*/
	

	int index = 0;

	for (auto& item : inventory.GetInventory())
	{
		index++;
		std::cout << index << "��°" << item.GetName() << ", ���� : " << item.GetWeight()
			<< ", ��ġ : " << item.GetValue() << std::endl;
	}

}


int main()
{
	Solve1();
	Solve2();
	InventoryWeightSystem();
}
