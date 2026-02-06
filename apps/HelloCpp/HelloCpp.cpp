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

//生存確認
static bool IsAlive(const Character& c)
{
	return c.hp > 0;
}

static void Damage(int& hp, int amout)
{
	hp -= amout;
	if (hp < 0) hp = 0;
}

//hpをamout分だけ回復させる maxHpを超えるならmaxHpにする
static void Heals(int& hp, int amout, int maxHp)
{
	hp += amout;
	if (maxHp < hp) hp = maxHp;
}

static void Attack(const Character& attacker, Character& defender)
{
	//ログを出す
	std::cout << attacker.name << "attaks" << attacker.atk << "\n";
	Damage(defender.hp, attacker.atk);
}

int main()
{
	Character player{ "kagi", 100, 100, 20, 30, 10 };
	Character enemy{ "zoku", 200, 100, 10, 30, 10 };

	std::cout << "==== Battle Start===\n";
	PrintStatus(player);
	PrintStatus(enemy);
	std::cout << "----------------------\n";

	int turn = 1;
	//どちらかが倒れるまでやる
	while (IsAlive(player) && IsAlive(enemy))
	{
		std::cout << "[Turn " << turn << "]\n";

		// 1) プレイヤー攻撃
		Attack(player, enemy);
		PrintStatus(enemy);

		// 敵が倒れたらここで終了
		if (!IsAlive(enemy))
		{
			std::cout << enemy.name << " defeated!\n";
			break;
		}

		// 2) 敵の反撃
		Attack(enemy, player);
		PrintStatus(player);

		// プレイヤーが倒れたらここで終了
		if (!IsAlive(player))
		{
			std::cout << player.name << " defeated!\n";
			break;
		}



		//回復
		std::cout << player.name << "heals 50!\n";
		Heals(player.hp, 50, player.maxHp);
		PrintStatus(player);

		turn++;
	}

	std::cout << "===== Battle End =========\n";
	return 0;
}


