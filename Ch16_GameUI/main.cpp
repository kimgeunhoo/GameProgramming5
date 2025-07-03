/*
	콘솔 창 색을 변경하는 기능들
	ANSI ESCAPE 문자의 색을 변경하는 기능 만들기
*/


#include <iostream>
#include <Windows.h>
using namespace std;

/*
	목표 : 숫자로 표기를 하는 것이 아니라, 사람이 알아보기 쉽도록 클래스 만들기
	Helper 클래스.
	ex) Color::White , Color::BG_White , Color::UnderLine
*/

// 30 ~ 39 글자색, 40 ~ 44 배경색

class Color
{
public:
	static const string RESET;
	static const string UNDERLINE;

	static const string BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE;
	static const string BG_RED, BG_GREEN, BG_YELLOW, BG_BLUE, BG_MAGENTA, BG_CYAN, BG_WHITE, BG_BLACK;

	static void Print(const string& BG, const string& textColor, const string& message)
	{
		cout << BG << textColor << message << Color::RESET;
	}
};

const string Color::RESET = "\033[0m";
const string Color::UNDERLINE = "\033[4m";

const string Color::BLACK = "\033[30m";
const string Color::RED = "\033[31m";
const string Color::GREEN = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::BLUE = "\033[34m";
const string Color::MAGENTA = "\033[35m";
const string Color::CYAN = "\033[36m";
const string Color::WHITE = "\033[37m";

const string Color::BG_RED = "\033[41m";
const string Color::BG_GREEN = "\033[42m";
const string Color::BG_YELLOW = "\033[43m";
const string Color::BG_BLUE = "\033[44m";
const string Color::BG_MAGENTA = "\033[45m";
const string Color::BG_CYAN = "\033[46m";
const string Color::BG_WHITE = "\033[47m";
const string Color::BG_BLACK = "";

void PrintMenu()
{
	cout << "====== 메뉴 ======" << endl;
	Color::Print(Color::BG_BLUE, Color::WHITE, "1. ");

	cout << "새로운 게임" << endl;
	Color::Print(Color::BG_WHITE, Color::CYAN, "2. ");
	cout << "게임 불러오기" << endl;
	Color::Print(Color::BG_WHITE, Color::CYAN, "3. ");
	cout << "설정" << endl;
	Color::Print(Color::BG_WHITE, Color::CYAN, "4. ");
	cout << "종료" << endl;

}

void PrintProgressBar(int current, int total, int width = 30)
{
	float progress = (float)current / total; // c 방식
	int filled = (int)(width * progress);

	for (int i = 0; i < filled; i++)
	{
		cout << Color::GREEN << "■";
	}

	for (int i = filled; i < width; i++)
	{
		cout << Color::WHITE << "■";
	}

	cout << Color::RESET << (int)(progress * 100) << "%";
}

void LoadingAnimation()
{

	cout << "로딩 진행 현황" << endl;
	for (int i = 0; i < 20; i++)
	{
		PrintProgressBar(i, 20);
		cout << endl;
		cout.flush();
		Sleep(100);
	}

	// vector 자료구조에 진행현황을 그림으로 저장했다가 갱신하는 방식을 써야 로딩화면 구현
}

void DrawBox()	// 가로, 세로
{
	/*
		상자는 위, 중간 아래 부분으로 구분이 된다.
		반복문을 이용해서 표현해보기.
	*/

	cout << Color::BG_CYAN << "+---------+" << Color::RESET << endl;
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << "         ";
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << endl;
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << "         ";
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << endl;
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << "         ";
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << endl;
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << "         ";
	Color::Print(Color::BG_CYAN, Color::WHITE, "|");
	cout << endl;
	cout << Color::BG_CYAN << "+---------+" << Color::RESET << endl;
}


int main()
{
	cout << Color::BG_WHITE << "글자" << Color::RESET << endl;
	cout << Color::BG_CYAN << "Blue" << Color::RESET << endl;
	cout << Color::UNDERLINE << "밑줄" << Color::RESET << endl;

	// 노란색 글자에 밑줄이 그어진 문자
	// 흰색 배경에 노란색 글자

	cout << Color::BG_BLUE << Color::GREEN << "=== TITLE ===" << Color::RESET << endl;

	Color::Print(Color::BG_CYAN, Color::WHITE, "=== TITLE ===");
	std::cout << std::endl;

	// 로딩바,	메뉴 표시,  UI 표현
	PrintMenu();
	// 제목 - Color 클래스를 사용해서
	// 1. 게임 시작, 
	// 2. 게임 종료

	//LoadingAnimation();
	DrawBox();
}