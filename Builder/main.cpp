#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
#define delimiter "\n-------------------------\n"
class computer
{
public:
	computer()
	{
		cout << "Construktor";
	}
	computer
	(
		const std::string& type,
		const std::string& mb,
		const std::string& cpu,
		const std::string& ram,
		const std::string& disk,
		const std::string& gpu,
		const std::string& psu,
		const std::string& cooler,
		const std::string& chassis
	)
	{
		set_type(type);
		set_mb(mb);
		set_cpu(cpu);
		set_ram(ram);
		set_disk(disk);
		set_gpu(gpu);
		set_psu(psu);
		set_cooler(cooler);
		set_chassis(chassis);
		this->on = false;
		cout << "Assembly done" << endl;
	}
	~computer()
	{
		cout << "Disassembled" << endl;
	}

	void set_type(const std::string& type)
	{
		this->type = type;
	}
	void set_mb(const std::string& mb)
	{
		this->mb = mb;
	}
	void set_cpu(const std::string& cpu)
	{
		this->cpu = cpu;
	}
	void set_ram(const std::string& ram)
	{
		this->ram = ram;
	}
	void set_disk(const std::string& disk)
	{
		this->disk = disk;
	}
	void set_gpu(const std::string& gpu)
	{
		this->gpu = gpu;
	}
	void set_psu(const std::string& psu)
	{
		this->psu = psu;
	}
	void set_cooler(const std::string& cooler)
	{
		this->cooler = cooler;
	}
	void set_chassis(const std::string& chassis)
	{
		this->chassis = chassis;
	}
	void power_button()
	{
		this->on = !on;
		if (this->on)
		{
			cout << "Загрузка Windows, ждите...." << endl;
			Sleep(500);
			cout << "Ващ рабочий стол" << endl;
			Sleep(500);
			this->info();
		}
		else
		{
			cout << "Завершение работы" << endl;
			Sleep(500);
		}
	}
	void info()const
	{
		cout << "Свойства системы: " << endl;
		cout << get_type() << endl;
		cout << get_mb() << endl;
		cout << get_cpu() << endl;
		cout << get_ram() << endl;
		cout << get_disk() << endl;
		cout << get_gpu() << endl;
		cout << get_psu() << endl;
		cout << get_cooler() << endl;
		cout << get_chassis() << endl;
	}
	std::string get_type() const { return this->type; }
	std::string get_mb() const { return this->mb; }
	std::string get_cpu() const { return this->cpu; }
	std::string get_ram() const { return this->ram; }
	std::string get_disk() const { return this->disk; }
	std::string get_gpu()const { return this->gpu; }
	std::string get_psu() const { return this->psu; }
	std::string get_cooler() const { return this->cooler; }
	std::string get_chassis() const { return this->chassis; }
	bool get_on() const { return this->on; }
private:
	std::string type;
	std::string mb;
	std::string cpu;
	std::string ram;
	std::string disk;
	std::string gpu;
	std::string psu;
	std::string cooler;
	std::string chassis;
	bool on;
};
class Computer_Biuilder
{
protected:
	computer* comp;
public:
	Computer_Biuilder()
	{
		this->comp = new computer();
	}
	computer* get_computer()
	{
		return comp;
	}
	virtual ~Computer_Biuilder()
	{
		delete this->comp;
	}
	virtual void set_type() = 0;
	virtual void set_mb() = 0;
	virtual void set_cpu() = 0;
	virtual void set_ram() = 0;
	virtual void set_disk() = 0;
	virtual void set_gpu() = 0;
	virtual void set_psu() = 0;
	virtual void set_cooler() = 0;
	virtual void set_chassis() = 0;
};

class Office_Computer_Builder :public Computer_Biuilder
{
public:
	void set_type() override
	{
		comp->set_type("Офисный компьютер");
	}
	void set_mb()override
	{
		comp->set_mb("MSI H610");
	}
	void set_cpu()override
	{
		comp->set_cpu("intel celeron g - 6900");
	}
	void set_ram()override
	{
		comp->set_ram("silicon power 8 gb DDR-4");
	}
	void set_disk()override
	{
		comp->set_disk("kingston a400");
	}
	void set_gpu() override
	{
		comp->set_gpu("Intel HD Graphics");
	}
	void set_psu() override
	{
		comp->set_psu("chieftec 500w");
	}
	void set_cooler() override
	{
		comp->set_cooler("Stock inteel cooler");
	}
	void set_chassis()override
	{
		comp->set_chassis("Deepcool miniTower");
	}

};
class Developer_Computer_Builder :public Computer_Biuilder
{
public:
	void set_type() override
	{
		comp->set_type("Компьютер разработчика");
	}
	void set_mb()override
	{
		comp->set_mb("Asus rog");
	}
	void set_cpu()override
	{
		comp->set_cpu("Intel core i-9");
	}
	void set_ram()override
	{
		comp->set_ram("Corsair Dominator 64 gb DDR5");
	}
	void set_disk()override
	{
		comp->set_disk("Samsung 970 Pro m2 4000gb");
	}
	void set_gpu() override
	{
		comp->set_gpu("GeForce 4900ti");
	}
	void set_psu() override
	{
		comp->set_psu("Seasonic 1600w");
	}
	void set_cooler() override
	{
		comp->set_cooler("Zalman cnps-20 x");
	}
	void set_chassis()override
	{
		comp->set_chassis("Thermaltake Divider");
	}
};
class Sysadmin
{
	Computer_Biuilder* builder;
public:
	Sysadmin() :builder(nullptr) {}

	void assembly_computer(Computer_Biuilder* builder)
	{
		this->builder = builder;
		builder->set_type();
		builder->set_mb();
		builder->set_cpu();
		builder->set_ram();
		builder->set_disk();
		builder->set_gpu();
		builder->set_psu();
		builder->set_cooler();
		builder->set_chassis();
	}
	void turn_on_the_computer()
	{
		if (this->builder)
		{
			builder->get_computer()->power_button();
		}
		else
		{
			cout << "Средства на сборку не были собраны" << endl;
		}
	}
};
//#define Problem
#define Solution
void main()
{
	setlocale(LC_ALL, "");
#ifdef Problem
	computer cheap_computer("Бюджетный компьютер", "MSI H610", "intel celeron g-6900", "silicon power 8 gb DDR-4", "kingston a400", "Intel HD Graphics", "chieftec 500w", "Stock inteel cooler", "Deepcool miniTower");
	cout << delimiter << endl;
	cheap_computer.power_button();
	cout << delimiter << endl;
	computer game_dev("Компьютер разработчика", "Asus rog", "Intel core i-9", "Corsair Dominator 64 gb DDR5", "Samsung 970 Pro m2 4000gb", "GeForce 4900ti", "Seasonic 1600w", "Zalman cnps-20 x", "Thermaltake Divider ");
	cout << delimiter << endl;
	game_dev.power_button();
	cout << delimiter << endl;
#endif // Problem
#ifdef Solution
	Sysadmin nice_guy;
	Office_Computer_Builder computer_for_director;
	nice_guy.assembly_computer(&computer_for_director);
	nice_guy.turn_on_the_computer();
#endif // Solution


}