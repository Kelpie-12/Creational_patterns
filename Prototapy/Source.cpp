#include <iostream>
#include <map>
#include <string>
#include <memory>
using namespace std;
#define delimiter "\n-------------------------\n"
class Player
{	
public:
	virtual Player* clone()const = 0;
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
	Player* clone()const override
	{
		return new Car_Player(*this);
	}
};

class Bike_Player: public Player
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
	Player* clone()const override
	{
		return new Bike_Player(*this);
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
	std::map<Player_Type, Player*> players;
public:
	Player_Factory()
	{
		players[Car] = new Car_Player("BMW", 735);
		players[Bike] = new Bike_Player("H&D", 200);
	}
	~Player_Factory()
	{
		delete players[Car];
		delete players[Bike];
	}
	Player* Create_Player(Player_Type type)
	{
		return players[type]->clone();
	}
};


//#define Problem
#define Solution
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

	Player_Factory factory;	
	cout << delimiter << endl;

	Player* car_player = factory.Create_Player(Car);
	car_player->print();
	cout << delimiter << endl;

	Player* bike_player = factory.Create_Player(Bike);
	bike_player->print();
	cout << delimiter << endl;
	delete bike_player;
	delete car_player;
	cout << delimiter << endl;
}