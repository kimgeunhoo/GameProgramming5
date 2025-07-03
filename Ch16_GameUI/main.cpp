/*
	�ܼ� â ���� �����ϴ� ��ɵ�
	ANSI ESCAPE ������ ���� �����ϴ� ��� �����
*/


#include <iostream>
#include <Windows.h>
using namespace std;

/*
	��ǥ : ���ڷ� ǥ�⸦ �ϴ� ���� �ƴ϶�, ����� �˾ƺ��� ������ Ŭ���� �����
	Helper Ŭ����.
	ex) Color::White , Color::BG_White , Color::UnderLine
*/

// 30 ~ 39 ���ڻ�, 40 ~ 44 ����

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
	cout << "====== �޴� ======" << endl;
	Color::Print(Color::BG_BLUE, Color::WHITE, "1. ");

	cout << "���ο� ����" << endl;
	Color::Print(Color::BG_WHITE, Color::CYAN, "2. ");
	cout << "���� �ҷ�����" << endl;
	Color::Print(Color::BG_WHITE, Color::CYAN, "3. ");
	cout << "����" << endl;
	Color::Print(Color::BG_WHITE, Color::CYAN, "4. ");
	cout << "����" << endl;

}

void PrintProgressBar(int current, int total, int width = 30)
{
	float progress = (float)current / total; // c ���
	int filled = (int)(width * progress);

	for (int i = 0; i < filled; i++)
	{
		cout << Color::GREEN << "��";
	}

	for (int i = filled; i < width; i++)
	{
		cout << Color::WHITE << "��";
	}

	cout << Color::RESET << (int)(progress * 100) << "%";
}

void LoadingAnimation()
{

	cout << "�ε� ���� ��Ȳ" << endl;
	for (int i = 0; i < 20; i++)
	{
		PrintProgressBar(i, 20);
		cout << endl;
		cout.flush();
		Sleep(100);
	}

	// vector �ڷᱸ���� ������Ȳ�� �׸����� �����ߴٰ� �����ϴ� ����� ��� �ε�ȭ�� ����
}

void DrawBox()	// ����, ����
{
	/*
		���ڴ� ��, �߰� �Ʒ� �κ����� ������ �ȴ�.
		�ݺ����� �̿��ؼ� ǥ���غ���.
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
	cout << Color::BG_WHITE << "����" << Color::RESET << endl;
	cout << Color::BG_CYAN << "Blue" << Color::RESET << endl;
	cout << Color::UNDERLINE << "����" << Color::RESET << endl;

	// ����� ���ڿ� ������ �׾��� ����
	// ��� ��濡 ����� ����

	cout << Color::BG_BLUE << Color::GREEN << "=== TITLE ===" << Color::RESET << endl;

	Color::Print(Color::BG_CYAN, Color::WHITE, "=== TITLE ===");
	std::cout << std::endl;

	// �ε���,	�޴� ǥ��,  UI ǥ��
	PrintMenu();
	// ���� - Color Ŭ������ ����ؼ�
	// 1. ���� ����, 
	// 2. ���� ����

	//LoadingAnimation();
	DrawBox();
}