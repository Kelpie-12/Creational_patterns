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
	virtual ~Player() {}
	virtual void print()const = 0;
};

class Car_Player :public Player
{
	string name;
	int id;
public:
	Car_Player(const string& name, int id) :name(name), id(id)
	{
		std::cout << "Car_constractor\t\t" << this << endl;
	}
	~Car_Player()override
	{
		std::cout << "Car_destractor\t" << this << endl;
	}
	void print()const override
	{
		std::cout << this << "\t" << name << "\t" << id << endl;
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
		std::cout << "Bike_constractor\t" << this << endl;
	}
	~Bike_Player()override
	{
		std::cout << "Bike_destractor\t" << this << endl;
	}
	void print()const override
	{
		std::cout << this << "\t" << name << "\t" << id << endl;
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
	static map<Player_Type, unique_ptr<Player>> players;	
	using Map = std::map<Player_Type, unique_ptr<Player>>;
	static Map GenMap();
public:
	static unique_ptr<Player> Create_Player(Player_Type type);
};

//#define Problem
//#define Solution
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

	std::cout << delimiter << endl;
	std::unique_ptr<Player>  car_player = Player_Factory::Create_Player(Car);
	car_player->print();
	std::cout << delimiter << endl;
	std::unique_ptr<Player> bike_player = Player_Factory::Create_Player(Bike);
	bike_player->print();
	std::cout << delimiter << endl;

}


map<Player_Type, unique_ptr<Player>> Player_Factory::players= Player_Factory::GenMap();

unique_ptr<Player> Player_Factory::Create_Player(Player_Type type)
{
	return players[type]->clone();
}

Player_Factory::Map Player_Factory::GenMap()
{
	Map m;
	m.emplace(Car, std::unique_ptr<Car_Player>(new Car_Player{ "BMW", 735 }));
	m.emplace(Bike, std::unique_ptr< Bike_Player>(new Bike_Player("H&D", 200)));
	return m;
}
