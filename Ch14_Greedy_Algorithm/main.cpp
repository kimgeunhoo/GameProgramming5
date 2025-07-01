#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

/*
	탐욕 알고리즘 (Greedy)
	문제 풀이 방식의 하나
	최적의 해를 찾기 위해서 현재 상황에서 가장 최선의 방법을 계속해서 선택하는 방식
*/

/*
	1번, 2번, 3번

	동전 거슬러주기 문제
	n원을 동전으로만 거슬러 줘야한다. 동전의 종류 500, 100, 50, 10원이 있다.
	이 때 동전을 최소한의 갯수로 거슬러주기 위한 동전의 최소 갯수 n을 반환하기
*/

// 1260원을 동전으로만 거슬러줘야 할때 최소 동전을 주려면?
// 현재 상황에서 가장 최선을 선택하자 (IDEA) (Greedy)
// 500 원 a, 100 b, 50원 c, 10원 d, a b c d 반환
// 500 * 2 + 100 * 2 + 50 + 1 10 * 1 = 2 + 2 + 1 + 1 = 6


int CoinBack(int amount) // amount 거슬러야 할 금액
{
	// amount 각각에 정해진 수치로 분할을 해야 한다.
	// 몫과 나머지를 사용해서 a,b,c,d 표현하고 그 값을 리턴해보기

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
		도전 목표 : 반복되는 부분을 반복문으로 표현하면 코드가 조금 더 쉽게 이해될 수 있다.
		vector<int> 거슬러 줄 돈을 저정한다. 저장되어 있는 동전을 사용해서 반복문을 작성한다.
	*/

	/*
		vector int 저장하는 것이 아니라, coin 자료형을 만들어서 표현해보기.

	*/

	struct Coin
	{
		int value;
		int count;

		Coin(int _value) : value(_value), count(0) {}
	};

	std::vector<int> coins = {500, 100, 50, 10, 5, 1}; // 여기의 데이터만 변경하시오.

	// CoinWallet 이름으로 Coin을 생성과 동시에 추가해보기
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
		std::cout << elem.value << "원의 수 : " << elem.count << std::endl;
	}

	std::cout << "동전의 총 갯수 : " << totalCount2 << std::endl;

	// 반드시 coins 자료구조는 값이 큰 순서대로 정렬이 되어있어야 한다.
	// 내림차순으로 정렬시키는 코드

	//==============================================================

	int totalCount = 0;

	for (int coin : coins)
	{
		int num = amount / coin;
		totalCount += num;
		amount = amount % coin;
		std::cout << coin << "원의 수 : " << num << std::endl;
	}

	std::cout << "동전의 총 갯수 : " << totalCount << std::endl;

	//int remain = amount;	// 첫 시작 금액

	//int coin500 = remain / 500; // 500원 갯수
	//std::cout << "500원의 수 : " << coin500 << std::endl;
	//remain = remain - 500 * coin500; // 남은 금액

	//int coin100 = remain / 100;
	//std::cout << "100원의 수 : " << coin100 << std::endl;
	//remain = remain - 100 * coin100;

	//int coin50 = remain / 50;
	//std::cout << "50원의 수 : " << coin50 << std::endl;
	//remain = remain - 50 * coin50;

	//int coin10 = remain / 10;
	//std::cout << "10원의 수 : " << coin10 << std::endl;
	//remain = remain - 10 * coin10;

	//int totalcount = coin500 + coin100 + coin50 + coin10;
	
	return totalCount;

} 


// 회의실 배정 문제
// 회의실이 시작하는 시간과 끝나는 시간을 쌍으로 저장하도록 두 수가 n개 주어진다.

// 회의에 예약된 수가 5개라면, {0,5} {1,3} {2,6} {7,10} {6,9}
// 이 회의실을 최대로 배정하는 방법을 찾아보기
// 최대로 배정할 때 몇개까지 배정할수 있나?
// 어떤 방식으로 했을 때 최선으로 방을 배정할 수 있을까?

// 백준 1931 문제

/*
	(1) 시작 시간이 가장 작은 순으로 정렬한다.
	(2) 끝나는 시간이 가장 작은 순으로 정렬한다. (첫 번째 원소로 사용한다.)

*/

int meetingCount(int n)
{
	// 시작 시간과 끝나는 시간을 앞에 넣을지 뒤에 넣을지 그 이유를 생각해서 표현
	std::vector<std::pair<int, int>> meeting = { {4, 1}, {5, 3}, {6, 0}, {7, 5}, 
		{8, 3}, {9, 5}, {10, 6}, {11, 8}, {12, 8}, {13, 2}, {14, 12} };

	// 끝나는 시간 순으로 정렬한다. 끝나는 시간은 key값을 first에 저장

	sort(meeting.begin(), meeting.end());

	// 정렬시키고 난 후의 결과값

	for (auto& i : meeting)
	{
		std::cout <<  i.first << ", " << i.second << "||";
	}
	std::cout << std::endl;

	// (끝나는 시간, 시작 시간)
	// count를 1씩 증가시켜준다
	// time 현재 회의에서 시작하는 시간
	// 현재 선택된 회의의 끝나는 시간과 나중에 선택된 회의의 시작 시간을 비교한다.
	// time을 선택한 회의의 끝나는 시간으로 변경해주면 된다.
	std::cout << "선택된 시간" << std::endl;
	int count = 1;
	int time = meeting[0].first; // 첫번째 일정에 끝나는 시간.

	for (int i = 1; i < n; i++)
	{
		// 현재 선택된 시간 [비교] 나머지 원소중에서 시작 시간
		if (time <= meeting[i].second) // 
		{
			std::cout <<  meeting[i].first << ", " << meeting[i].second << "||";
			// 갯수 1 증가
			count++;
			// time을 선택된 시간으로 갱신
			time = meeting[i].first;		
		}
		
	}
	std::cout << std::endl;
	return count;
}

/*
	시작 시간, 끝나는 시간을 '초' 단위로 계산한다. 3600 - 1800 = 1800;
	계산된 초를 다시 '시' '분' '초' 로 변환해서 출력하는 코드를 만들어보기.

	[n시 m분 s초] 만들어주는 코드 작성
*/

void FormatTime(int value)
{
	// 2167 -> 시 분 초 변환하는 코드를 만들기
	
	// value -> 시, 분, 초 나누어서 저장.
	
	// 하드코딩 방식
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

	std::cout << currenthours << "시" << currentminutes << "분" << currentseconds << "초" << std::endl;*/

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

	std::cout << times[0].count << "시" << times[1].count << "분" << times[2].count << "초" << std::endl;

}



int main()
{
	std::cout << "동전 거슬러주기 문제 : 1260원을 반환하기" << std::endl;
	std::cout << "===결과값===" << std::endl;
	CoinBack(1268);
	
	std::cout << "\n\n회의실 최대 갯수 문제" << std::endl;
	std::cout << meetingCount(11) << std::endl;

	std::cout << "값을 시간으로 변환하는 문제" << std::endl;
	FormatTime(2167); // 0시 n분 s초

}