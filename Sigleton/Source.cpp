#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Human
{
	static Human* instance ;
	string last_name;
	string first_name;
	tm birth_date;
	Human()
	{
		cout << "Construtor: \t" << endl;
	}

public:
	const string& get_last_name()const
	{
		return this->last_name;
	}
	const string& get_first_name()const
	{
		return this->first_name;
	}
	const tm& get_birth_date()const
	{
		return this->birth_date;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_birth_date(int year,int mon,int day)
	{
		this->birth_date.tm_year = year - 1900;
		this->birth_date.tm_mon = mon - 1;
		this->birth_date.tm_mday = day;
	}
	~Human()
	{
		cout << "\nDestructor: \t" << endl;
	}
	static Human* get_instance()
	{
		if (instance==nullptr)
		{
			instance = new Human();
		}
		return instance;
	}
	void print()const
	{
		time_t timer;
		time(&timer);
		tm* current_time = localtime(&timer) ;
		unsigned int age=current_time->tm_year - birth_date.tm_year;
		if (current_time->tm_yday<birth_date.tm_yday)
		{
			age--;
		}
		cout << last_name << " " << first_name << " " << age;
	}
};
 Human* Human::instance = nullptr;


void main()
{
	setlocale(LC_ALL, "");
	Human* main = Human::get_instance();
	main->set_last_name("Vercettyy");
	main->set_first_name("Tommy");
	main->set_birth_date(1991,9,6);
	main->print();
}