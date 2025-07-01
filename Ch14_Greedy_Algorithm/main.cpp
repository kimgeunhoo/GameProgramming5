#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

/*
	Ž�� �˰��� (Greedy)
	���� Ǯ�� ����� �ϳ�
	������ �ظ� ã�� ���ؼ� ���� ��Ȳ���� ���� �ּ��� ����� ����ؼ� �����ϴ� ���
*/

/*
	1��, 2��, 3��

	���� �Ž����ֱ� ����
	n���� �������θ� �Ž��� ����Ѵ�. ������ ���� 500, 100, 50, 10���� �ִ�.
	�� �� ������ �ּ����� ������ �Ž����ֱ� ���� ������ �ּ� ���� n�� ��ȯ�ϱ�
*/

// 1260���� �������θ� �Ž������ �Ҷ� �ּ� ������ �ַ���?
// ���� ��Ȳ���� ���� �ּ��� �������� (IDEA) (Greedy)
// 500 �� a, 100 b, 50�� c, 10�� d, a b c d ��ȯ
// 500 * 2 + 100 * 2 + 50 + 1 10 * 1 = 2 + 2 + 1 + 1 = 6


int CoinBack(int amount) // amount �Ž����� �� �ݾ�
{
	// amount ������ ������ ��ġ�� ������ �ؾ� �Ѵ�.
	// ��� �������� ����ؼ� a,b,c,d ǥ���ϰ� �� ���� �����غ���

	// totalCount 
	//int coin500 = 0;
	//int coin100 = 0;
	//int coin50 = 0;
	//int coin10 = 0;
	//int temp = 0;
	//coin500 = amount / 500;
	//temp = amount % 500;
	//coin100 = temp / 100;
	//temp = amount % 100;
	//coin50 = temp / 50;
	//temp = amount / 50;
	//coin10 = temp / 10;

	/*
		���� ��ǥ : �ݺ��Ǵ� �κ��� �ݺ������� ǥ���ϸ� �ڵ尡 ���� �� ���� ���ص� �� �ִ�.
		vector<int> �Ž��� �� ���� �����Ѵ�. ����Ǿ� �ִ� ������ ����ؼ� �ݺ����� �ۼ��Ѵ�.
	*/

	/*
		vector int �����ϴ� ���� �ƴ϶�, coin �ڷ����� ���� ǥ���غ���.

	*/

	struct Coin
	{
		int value;
		int count;

		Coin(int _value) : value(_value), count(0) {}
	};

	std::vector<int> coins = {500, 100, 50, 10, 5, 1}; // ������ �����͸� �����Ͻÿ�.

	// CoinWallet �̸����� Coin�� ������ ���ÿ� �߰��غ���
	int totalCount2 = 0;

	std::vector<Coin> coinWallet;
	for (int coin : coins)
	{
		coinWallet.emplace_back(coin);
	}

	for (auto& elem : coinWallet)
	{
		int num = amount / elem.value;
		elem.count = num;
		totalCount2 += num;
		amount = amount % elem.value;
		std::cout << elem.value << "���� �� : " << elem.count << std::endl;
	}

	std::cout << "������ �� ���� : " << totalCount2 << std::endl;

	// �ݵ�� coins �ڷᱸ���� ���� ū ������� ������ �Ǿ��־�� �Ѵ�.
	// ������������ ���Ľ�Ű�� �ڵ�

	//==============================================================

	int totalCount = 0;

	for (int coin : coins)
	{
		int num = amount / coin;
		totalCount += num;
		amount = amount % coin;
		std::cout << coin << "���� �� : " << num << std::endl;
	}

	std::cout << "������ �� ���� : " << totalCount << std::endl;

	//int remain = amount;	// ù ���� �ݾ�

	//int coin500 = remain / 500; // 500�� ����
	//std::cout << "500���� �� : " << coin500 << std::endl;
	//remain = remain - 500 * coin500; // ���� �ݾ�

	//int coin100 = remain / 100;
	//std::cout << "100���� �� : " << coin100 << std::endl;
	//remain = remain - 100 * coin100;

	//int coin50 = remain / 50;
	//std::cout << "50���� �� : " << coin50 << std::endl;
	//remain = remain - 50 * coin50;

	//int coin10 = remain / 10;
	//std::cout << "10���� �� : " << coin10 << std::endl;
	//remain = remain - 10 * coin10;

	//int totalcount = coin500 + coin100 + coin50 + coin10;
	
	return totalCount;

} 


// ȸ�ǽ� ���� ����
// ȸ�ǽ��� �����ϴ� �ð��� ������ �ð��� ������ �����ϵ��� �� ���� n�� �־�����.

// ȸ�ǿ� ����� ���� 5�����, {0,5} {1,3} {2,6} {7,10} {6,9}
// �� ȸ�ǽ��� �ִ�� �����ϴ� ����� ã�ƺ���
// �ִ�� ������ �� ����� �����Ҽ� �ֳ�?
// � ������� ���� �� �ּ����� ���� ������ �� ������?

// ���� 1931 ����

/*
	(1) ���� �ð��� ���� ���� ������ �����Ѵ�.
	(2) ������ �ð��� ���� ���� ������ �����Ѵ�. (ù ��° ���ҷ� ����Ѵ�.)

*/

int meetingCount(int n)
{
	// ���� �ð��� ������ �ð��� �տ� ������ �ڿ� ������ �� ������ �����ؼ� ǥ��
	std::vector<std::pair<int, int>> meeting = { {4, 1}, {5, 3}, {6, 0}, {7, 5}, 
		{8, 3}, {9, 5}, {10, 6}, {11, 8}, {12, 8}, {13, 2}, {14, 12} };

	// ������ �ð� ������ �����Ѵ�. ������ �ð��� key���� first�� ����

	sort(meeting.begin(), meeting.end());

	// ���Ľ�Ű�� �� ���� �����

	for (auto& i : meeting)
	{
		std::cout <<  i.first << ", " << i.second << "||";
	}
	std::cout << std::endl;

	// (������ �ð�, ���� �ð�)
	// count�� 1�� ���������ش�
	// time ���� ȸ�ǿ��� �����ϴ� �ð�
	// ���� ���õ� ȸ���� ������ �ð��� ���߿� ���õ� ȸ���� ���� �ð��� ���Ѵ�.
	// time�� ������ ȸ���� ������ �ð����� �������ָ� �ȴ�.
	std::cout << "���õ� �ð�" << std::endl;
	int count = 1;
	int time = meeting[0].first; // ù��° ������ ������ �ð�.

	for (int i = 1; i < n; i++)
	{
		// ���� ���õ� �ð� [��] ������ �����߿��� ���� �ð�
		if (time <= meeting[i].second) // 
		{
			std::cout <<  meeting[i].first << ", " << meeting[i].second << "||";
			// ���� 1 ����
			count++;
			// time�� ���õ� �ð����� ����
			time = meeting[i].first;		
		}
		
	}
	std::cout << std::endl;
	return count;
}

/*
	���� �ð�, ������ �ð��� '��' ������ ����Ѵ�. 3600 - 1800 = 1800;
	���� �ʸ� �ٽ� '��' '��' '��' �� ��ȯ�ؼ� ����ϴ� �ڵ带 ������.

	[n�� m�� s��] ������ִ� �ڵ� �ۼ�
*/

void FormatTime(int value)
{
	// 2167 -> �� �� �� ��ȯ�ϴ� �ڵ带 �����
	
	// value -> ��, ��, �� ����� ����.
	
	// �ϵ��ڵ� ���
	/*int seconds = 1;
	int minutes = 60;
	int hours = 3600;

	int currentseconds = 0;
	int currentminutes = 0;
	int currenthours = 0;

	currenthours = value / hours;
	value = value % hours;
	currentminutes = value / minutes;
	value = value % minutes;
	currentseconds = value / seconds;
	value = value % seconds;

	std::cout << currenthours << "��" << currentminutes << "��" << currentseconds << "��" << std::endl;*/

	struct TimeV
	{
		int value;
		int count;

		std::string nameformat;

		TimeV(int _value) : value(_value) {}

		void Print()
		{
			std::cout << count << nameformat;
		}

	};

	std::vector<TimeV> times;
	times.emplace_back(3600);
	times.emplace_back(60);
	times.emplace_back(1);

	for (auto& time : times)
	{
		int num = value / time.value;
		time.count = num;
		value %= time.value;
	}

	std::cout << times[0].count << "��" << times[1].count << "��" << times[2].count << "��" << std::endl;

}



int main()
{
	std::cout << "���� �Ž����ֱ� ���� : 1260���� ��ȯ�ϱ�" << std::endl;
	std::cout << "===�����===" << std::endl;
	CoinBack(1268);
	
	std::cout << "\n\nȸ�ǽ� �ִ� ���� ����" << std::endl;
	std::cout << meetingCount(11) << std::endl;

	std::cout << "���� �ð����� ��ȯ�ϴ� ����" << std::endl;
	FormatTime(2167); // 0�� n�� s��

}