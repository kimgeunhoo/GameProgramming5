/*
	1. 아이디어를 어떤 방식으로 결정했는가?
	2. 자료구조를 어떤 것으로 선택했는지 이유를 생각해보기
*/

#include <iostream>
#include <algorithm>
#include <vector>

#pragma region Q1
// ATM 문제. 백준 11399번. ATM에 사람들이 줄을 서고 있다. 
// n명의 사람이 모두 기다린 시간이 최소의 시간이 되려면
// 어떻게 해야하나? 그리고 그 시간은 몇초인지 값을 출력하기

/*
	int -> "people" "client" ( 기다리는 사람 순서, 사용해야 할 시간, 점수 등 )
*/

void Solve1()
{
	struct Client
	{
		int waitId; // 기다리는 순서
		int waitTime;	// 사용 시간

		Client(int waitId, int waitTime)
			: waitId(waitId), waitTime(waitTime) {}
	};

	std::cout << "====== ATM 문제 풀이 =======" << std::endl;

	int n = 5;		   // 총 인원 수
	int totalTime = 0; // 모든 인원이 기다린 시간
	// 각각의 인원 수가 기다리는 시간을 여러 개 저장해야 한다. -> 자료구조 -> vector<int>
	// 1. vector<int> waitTimeTable; 문제의 예제를 추가해보기
	// 3, 1, 4, 3, 2
	// 2. 문제의 풀이 방식을 선택해보기

	std::vector<int> waitTimeTable;

	waitTimeTable.push_back(3);
	waitTimeTable.push_back(1);
	waitTimeTable.push_back(4);
	waitTimeTable.push_back(3);
	waitTimeTable.push_back(2);

	std::vector<int> clients(waitTimeTable.size(), -1);

	// client들이 기다린 시간을 측정해야 한다.
	// 주어진 데이터 대로 줄을 선다면
	// 아이디어 : 값이 적은 순으로 데이터를 정렬시킨다. (greedy Algorithm)
	// 정렬 시킨 후 반복적으로 더해준다.
	
	// clients들의 시간을 적은 값으로 정렬해 주기
	// DP(동적계획법) : 반복문 + 자료구조 bottom - up
	std::sort(waitTimeTable.begin(), waitTimeTable.end());

	// 1. 처음 사용하는 사람.
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

	// 주어진 데이터대로 줄을 선다면?

	std::cout << n << "명의 사람들이 모두 기다리는 시간이 최소가 되는 시간은 " << totalTime << std::endl;

}
#pragma endregion

#pragma region Q2
// 배낭에 물건 담기 문제. 백준 12865번. 물건이 N개 담을 수 있는 무게 K개가 주어진다. 
// 최대의 가치를 저장할 수 있는 값은 얼마인가?
// 무게를 최대한 담았을 때 최대의 가치를 저장할 때의 값을 출력

void Solve2()
{
	// 4개의 물건이 들어온다. 각각의 물건에는 무게와 가치가 표현되고 있다.
	// k의 무게만큼 배낭 안에 최대한으로 물건을 담을 때, 가치가 가장 크도록 저장하는 방법을 구현

	// 1. n = 4, k = 7, [6, 13] [4, 8] [3, 6] [5, 12] 데이터로 표현해보기
	// 2. 아이디어 : 가장 가치있는 물건들만 담기 위해서 어떻게 해야하는가?
	struct Product
	{
		int weight;
		int value;

		Product(int weight, int value) : weight(weight), value(value){}
	};

	std::cout << "\n========= 배낭 문제 풀이 ===========" << std::endl;

	int n = 4; int k = 7;

	std::vector<std::pair<int, int>> items{ {6, 13}, {4, 8}, {3, 6}, {5, 12} };
	std::vector<int> weight;
	
	// 무게별 가치 평가
	// 배낭이 1일 때 최대로 담을 수 있는 가치?

	std::vector<int> dp(k+1, 0); // dp[0] ~ dp[7]

	// 무게 0일 때? 각 무게에서 최대로 담을 수 있도록 무게별 최고 가치를 갱신
	//dp[0] = 0;
	//dp[1] = 0;
	//dp[2] = 0;
	//dp[3] = 6;
	//dp[4] = 8; // 이전 무게의 가치 + 새로 담을 수 있는 가치		하나의 가치 비교
	//dp[5] = 12;
	//dp[6] = 13;
	//dp[7] = 0;	 // 6 + 1 : 13, 5 + 2 : 12, 4 + 3 : 14, 가장 가치가 큰 케이스

	for (int i = 0; i < 4; i++)
	{
		int weight = items[i].first; // 무게
		int value = items[i].second; // 가치

		for (int w = k; w >= weight; w--) // 7kg, 6
		{
			dp[w] = std::max(dp[w], dp[w - weight] + value);
		}

	}

	std::cout << "가방의 무게가 7까지 담을 수 있을 때 최대 가치 : " << dp[7] << std::endl;

}
#pragma endregion

// 인벤토리 - 무게 시스템. User 편의성을 위한 코드. 아이템 중에서 가장 가치있는 아이템을 강조하는 코드 만들기

// 이름을 클래스로 만들기 -> Item 클래스, 무게라는 가치가 포함되도록 만들기
// 아이템 저장하는 컨테이너, 인벤토리, 무게가 존재하는 인벤토리 구현

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

class InventoryW // ItemW 자료형을 컨테이너로 저장
{
private:
	std::vector<ItemW> Items;
	int maxWeight;
	int currentWeight;
public:
	// 생성자
	InventoryW(int max) : maxWeight(max), currentWeight(0) {}

	// 아이템 추가

	void AddItem(const ItemW& addItem)
	{
		if (CheckWeight(addItem))
		{
			Items.push_back(addItem);
			currentWeight += addItem.GetWeight();
		}
	}

	// 최대 무게보다 아이템의 총 무게가 무거우면 false, true

	bool CheckWeight(const ItemW& addItem)
	{
		return maxWeight < currentWeight + addItem.GetWeight();
	}

	/*
		1. 선택한 아이템 들 중에서 가장 큰 가치, 실제로 선택한 아이템들 (자료구조)
		-> 반환값을 pair< T1, T2 >
	*/

	std::pair<int, std::vector<ItemW>> findBestItem(int targetWeight, std::vector<ItemW>& selectableItems)
	{
		// 현재 아이템의 무게에 새로운 아이템 조합을 가져올 때 그 아이템을 저장할 컨테이너 선언

		std::vector<int> dp(targetWeight + 1, 0);

		// selectableItems 들어있는 무게. weight
		// selectableItems 들어있는 가치. value

		std::vector<std::vector<bool>> selected(selectableItems.size(), std::vector<bool>(targetWeight + 1, false));

		for (int i = 0; i < selectableItems.size(); i++)
		{
			int weight = selectableItems[i].GetWeight();
			int value = selectableItems[i].GetValue();
			for (int w = targetWeight; w >= weight; w--)
			{
				/*
					해당 코드 구현
				*/

				if (dp[w-weight] + value > dp[w])	// 새로 들어온 아이템 + 기존 무게 전체무게보다 클 때만
				{
					dp[w] = dp[w - weight] + value;
					selected[i][w] = true;
				}
				

			}
		}

		// 계산한 최적의 조합을 역산해서 다시 vector 저장하는 코드
		// while(weight - 무게) 

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
	// 인벤토리 생성 후 호출, 4개의 아이템을 이 배낭에 저장. 
	// 최대 무게가 7이고, 아이템을 4개 생성

	InventoryW inventory(7);

	//6, 4, 3, 5
	ItemW A("A", 6, 13);
	ItemW B("B", 4, 8);
	ItemW C("C", 3, 6);
	ItemW D("D", 5, 11);

	std::vector<ItemW> selectableTable{ A, B, C, D };

	std::pair<int,std::vector<ItemW>> bestItems = inventory.findBestItem(7, selectableTable);

	std::cout << "주어진 아이템의 최대 가치 : " << bestItems.first << std::endl;
	std::vector<ItemW> ItemC = bestItems.second;


	int i = 0;

	// 인벤토리에 아이템을 넣는 코드를 최선의 아이템을 인벤토리에 추가하도록 수정해보기
	/*inventory.AddItem(A);
	inventory.AddItem(B);*/

	for (auto& item : ItemC)
	{
		i++;
		std::cout << i << "번째 아이템 이름 : " << item.GetName() 
			<< ", 무게 : " << item.GetWeight() 
			<< ", 가치 : " << item.GetValue() << std::endl;
		// 유저가 허락했을 때 실행하시오 if ( 유저 입력 코드 )
		inventory.AddItem(item);
	}

	/*std::cout << "주어진 아이템의 최대 가치 : " << 
		inventory.findBestItem(7, selectableTable) << std::endl;*/
	

	int index = 0;

	for (auto& item : inventory.GetInventory())
	{
		index++;
		std::cout << index << "번째" << item.GetName() << ", 무게 : " << item.GetWeight()
			<< ", 가치 : " << item.GetValue() << std::endl;
	}

}


int main()
{
	Solve1();
	Solve2();
	InventoryWeightSystem();
}
