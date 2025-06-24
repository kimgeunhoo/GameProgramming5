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

#include <iostream>
#include <vector>
#include <queue>		// queue, priority_queue
#include <utility>		// pair

using namespace std;

// 전사, 마법사, 궁수, 도적, 성직자
// 전사		: 10  5   8   7   6
class Character
{
private:
	string name;
	vector<int> threatLevel;	// threatLevel {10,5,8,7,6}
	int currentTurn;
public:
	Character(string name, vector<int> TL) : 
		name(name), threatLevel(TL), currentTurn(0) {}

	int getCurrentThreat()
	{
		if (threatLevel.size() <= currentTurn)
		{
			throw runtime_error("Out of Range");
		}
		return threatLevel[currentTurn];
	}

	void NextTurn()
	{
		currentTurn++;
	}

	void PrintStat()
	{
		cout << name << "(현재 위협도 : " << getCurrentThreat() << ")" << endl;
	}
};

class Boss
{
public:
	string name;
	int currentTurn;
	priority_queue<int> threatQueue;		// priorty_queue<int, int> IQ;
	Boss(string name) : currentTurn(0) {}

	void clear()
	{
		while (!threatQueue.empty())
		{
			threatQueue.pop();
		}
	}

	void UpdateThreatQueue(vector<Character>& party)
	{
		clear();

		for (auto& character : party)
		{
			int threat = character.getCurrentThreat();
			threatQueue.push(threat);
			character.NextTurn();	// 파티의 모든 캐릭터의 턴을 1 증가시킨다.
		}							// 위협도가 가장 큰 수를 저장
	}

	int findMostThreatCharacter(vector<Character>& party)
	{
		//Character* target = nullptr;

		int MostThreatValue = threatQueue.top();
		
		return MostThreatValue;

	}

	void Attack()
	{
		// target = FindTarget();
		// character.TakeDamage();
	}

};

// maxheap , minheap
// 1. 우선순위 큐를 이용해서 힙 구조를 작성해보기

bool myLess(int a, int b)
{
	return a < b;
}

bool myGreater(int a, int b)
{
	return a > b;
}

// k번째로 작은 수 구하기, k번째로 큰 수 구하기 우선순위 큐를 사용하면 쉽게 표현할 수 있다.
// logN 시간으로 k번째 작은 수를 찾을 수 있다. => (k번째 수를 찾는다, 1:1 대응 N시간으로 코드를 작성하면 시간이 초과되었습니다.)
class MaxHeap
{
private:
	priority_queue<int, vector<int>, less<int>> pq;

public:
	MaxHeap() = default;

	void push(int value)
	{
		pq.push(value);
	}
	bool isEmpty() const
	{
		return pq.empty();
	}
	const int& top() const
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}

		return pq.top();
	}
	int pop()
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}
		int maxValue = pq.top();
		pq.pop();
		return maxValue;
	}
};


class MinHeap // 가장 작은 수가 제일 위에 있는 구조.
{
private:
	priority_queue<int, vector<int>, greater<int>> pq; // 최소값이 제일 위로 올라가는 형태

public:
	MinHeap() = default;

	// push, pop, empty, top (<=extractMax)
	void push(int value) 
	{
		pq.push(value);
	}
	bool isEmpty() const
	{
		return pq.empty();
	}
	const int& top() const		// 저장되어있는 가장 위의 값을 참조한다.
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}

		return pq.top();
	}
	int pop() 
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}
		int minValue = pq.top();
		pq.pop();
		return minValue;
	}	// 복사 한 후에 자료구조에서 삭제
	

};

void findkthExample()
{
	MinHeap myHeap;

	myHeap.push(11);
	myHeap.push(7);
	myHeap.push(5);
	myHeap.push(3);

	cout << "최소 힙의 가장 작은 값 : " << myHeap.top() << endl;

	int k = 3;
	// ?

	// for 반복문을 k로 표현하여 k번째 수를 찾아보기
	cout << endl;
	cout << "k번째 작은 수를 출력하시오" << endl;

	//MaxHeap e

}

void ThreatSystem()
{
	// 1. 등장 캐릭터의 위협도 출력

	Character a("전사", { 1, 2, 3, 4, 5 });
	Character b("도적", { 1,1,1,10,5 });
	Character c("궁수", { 3,6,3,3,3 });
	Character d("마법사", { 0,1,6,6,6 });
	Character e("성직자", { 0,0,10,0,20 });

	std::vector<Character> party;

	party.push_back(a);
	party.push_back(b);
	party.push_back(c);
	party.push_back(d);
	party.push_back(e);

	for (auto& character : party)
	{
		character.PrintStat();
	}

	// 보스가 가장 위협도가 높은 숫자를 찾도록 하시오
	Boss boss("king");
	boss.UpdateThreatQueue(party);	// 첫 번째 턴
	int value = boss.findMostThreatCharacter(party);
	cout << "첫번째 턴에서 위협도가 가장 큰 수치 : " << value << endl;

	boss.UpdateThreatQueue(party);	// 첫 번째 턴
	value = boss.findMostThreatCharacter(party);
	cout << "두번째 턴에서 위협도가 가장 큰 수치 : " << value << endl;

	int nextTurnValue = 3;
	// n번째 턴일 때 각 직업의 위험도 출력
	int currentThreat = 0;
	for (int i = 0; i < nextTurnValue; i++)
	{
		currentThreat += a.getCurrentThreat();
		a.NextTurn();
	}

	cout << "===전사의 3턴 후 위협도 : " << currentThreat << std::endl;
	a.NextTurn();
}

int main()
{
	//findkthExample();
	ThreatSystem();
}