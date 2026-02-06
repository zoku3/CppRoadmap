#include <iostream>
#include <string>

//day1
//キャラデータの作成
//表示
//

struct Character
{
	std::string name;
	int hp;
	int maxHp;
	int atk;
	int sp;
	int spd;
};

static void PrintStatus(const Character& c)
{
	//const& コピーせず表示するだけ
	std::cout << c.name
		<< " HP: " << c.hp << "/" << c.maxHp
		<< "  SP: " << c.sp
		<< "  ATK: " << c.atk
		<< "  SPD: " << c.spd
		<< "\n";
}

static bool IsAlive(const Character& c)
{
	return c.hp > 0;
}

int main()
{
	Character player{ "kagi", 100, 100, 20, 30, 10 };
	Character enemy{ "zoku", 200, 100, 10, 30, 10 };

	std::cout << "==== Battle Start===\n";
	PrintStatus(player);
	PrintStatus(enemy);
	std::cout << "----------------------\n";

	//戦闘ループの型を作る
	int turn = 1;
	while (IsAlive(player) && IsAlive(enemy) && turn <= 1)
	{
		std::cout << "ダメージ処理は次回";

		std::cout << "------------------\n";
		turn++;
	}

	std::cout << "=======END======\n";
	return 0;
}



