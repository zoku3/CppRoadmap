// HelloCpp.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>

	//xをminval～maxvalに収めて返す
int Clamp(int x, int minval, int maxval)
{
	if (x < minval) return minval;
	if (x > maxval) return maxval;
	return x;
}

int main()
{
	//名前入力
	std::string name;
	std::cout << "名前を入力: ";
	std::getline(std::cin, name);
	std::cout << "こんにちは, " << name << "!\n";

	//足し算
	int a = 0, b = 0;
	std::cout << "整数aを入力: ";
	std::cin >> a;
	std::cout << "整数a :" << a << "\n";
	std::cout << "整数bを入力";
	std::cin >> b;
	std::cout << "整数b ;" << b << "\n";
	std::cout << "a + b = " << (a + b) << "\n";
	std::cout << "a - b = " << (a - b) << "\n";
	std::cout << "a * b = " << (a * b) << "\n";
	std::cout << "a / b = " << (a / b) << "\n";
	std::cout << "a % b = " << (a % b) << "\n";
	//c:clamp
	int x = 0;
	std::cout << "Xを入力（０～１００に収める）: ";
	std::cin >> x;
	std::cout << "Clamp結果　＝　" << Clamp(x, 0, 100) << "\n";

	return 0;
	
}