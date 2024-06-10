#include <iostream>
#include <map>
#include <string>
#include <memory>
using namespace std;
#define delimiter "\n-------------------------\n"
class Player
{
public:
	virtual unique_ptr<Player> clone()const = 0;
	//Player(const string name, int id) :name(name), id(id){}
	virtual ~Player() {}
	virtual void print()const = 0;
	/*{
		cout << this<< "\t" << name << "\t" << id << endl;
	}*/

};

class Car_Player :public Player
{
	string name;
	int id;
public:
	Car_Player(const string& name, int id) :name(name), id(id)
	{
		cout << "Car_constractor\t" << this << endl;
	}
	~Car_Player()
	{
		cout << "Car_destractor\t" << this << endl;
	}
	void print()const override
	{
		cout << this << "\t" << name << "\t" << id << endl;
	}
	unique_ptr<Player> clone()const override
	{
		return make_unique< Car_Player>(*this);
	}
};

class Bike_Player : public Player
{
public:
	Bike_Player(const string& name, int id) :name(name), id(id)
	{
		cout << "Bike_constractor\t" << this << endl;
	}
	~Bike_Player()
	{
		cout << "Bike_destractor\t" << this << endl;
	}
	void print()const override
	{
		cout << this << "\t" << name << "\t" << id << endl;
	}
	unique_ptr<Player> clone()const override
	{
		return make_unique< Bike_Player>(*this);
	}

private:
	string name;
	int id;
};

enum Player_Type
{
	Car,
	Bike
};
class Player_Factory
{
	static std::map<Player_Type, unique_ptr<Player>> players;


	static void Init();
	/*{
		if (players.find(Car) == players.end())
			players[Car] = make_unique< Car_Player>(Car_Player("BMW", 735));
		if (players.find(Bike) == players.end())
			players[Bike] = make_unique< Bike_Player>(Bike_Player("H&D", 200));
	}*/
	/*~Player_Factory()
	{
		delete players[Car];
		delete players[Bike];
	}*/
public:
	static unique_ptr<Player> Create_Player(Player_Type type)
	{
		Init();
		return players[type]->clone();
	}
};
void Player_Factory::Init()
{
	if (players.find(Car) == players.end())
		players[Car] = make_unique< Car_Player>(Car_Player("BMW", 735));
	if (players.find(Bike) == players.end())
		players[Bike] = make_unique< Bike_Player>(Bike_Player("H&D", 200));
}
//#define Problem
#define Solution
//#define Solution1

void main()
{
	setlocale(LC_ALL, "");
#ifdef Problem
	const Player car_player_template("Car player", 100);
	const Player bike_player_template("Bike player", 200);
	car_player_template.print();
	bike_player_template.print();

	Player car_player = car_player_template;
	car_player.print();

	Player bike_player = bike_player_template;
	bike_player.print();
#endif // Problem

#ifdef Solution1
	Player_Factory factory;
	cout << delimiter << endl;

	unique_ptr<Player> car_player = factory.Create_Player(Car);
	car_player->print();
	cout << delimiter << endl;

	unique_ptr<Player> bike_player = factory.Create_Player(Bike);
	bike_player->print();
	/*cout << delimiter << endl;
	delete bike_player;
	delete car_player;*/

	cout << delimiter << endl;
#endif //Solution1

	std::unique_ptr<Player> car_player = Player_Factory::Create_Player(Car);
	car_player->print();
	cout << delimiter << endl;
	std::unique_ptr<Player> bike_player = Player_Factory::Create_Player(Bike);
	bike_player->print();
	cout << delimiter << endl;
}