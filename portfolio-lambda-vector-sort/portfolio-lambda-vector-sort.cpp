#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iomanip>

class Player {
	friend std::ostream& operator<<(std::ostream& os, const Player& rhs);             //overloaded insertion operator<< friend
private:
	std::string name;
	int age;
	double xp;

public:
	Player(std::string name = "", int age = 0, double xp = 0.0) : name{name}, age{age}, xp{xp} {};                  //overloaded constructor
	Player(const Player& p) : name{ p.name }, age{ p.age }, xp{ p.xp } {}                         //copy constructor
	~Player() = default;                                                              //default destrcutor
	void set_name(std::string name) { this->name = name; }
	std::string get_name() const { return name; }
	void set_age(int age) { this->age = age; }
	int get_age()const { return age; }
	void set_xp(double xp) { this->xp = xp; }
	double get_xp() const { return xp; }
};

std::ostream& operator<<(std::ostream& os, const Player& rhs) {                        //overloaded insertion operator code
	os << std::setw(15) << std::left << "[Person: " << std::setw(15) << std::right << rhs.name << ", " << rhs.age << ", " << rhs.xp << "]" << std::endl;
	return os;
};

class Person {
	friend std::ostream& operator<<(std::ostream& os, const Person& rhs);             //overloaded insertion operator<< friend
private:
	std::string name;
	int age;
public:
	Person(std::string name, int age) : name{ name }, age{ age } {};                  //overloaded constructor
	Person(const Person& p) : name{ p.name }, age{ p.age } {}                         //copy constructor
	~Person() = default;                                                              //default destrcutor
	void set_name(std::string name) { this->name = name; }
	std::string get_name() const { return name; }
	void set_age(int age) { this->age = age; }
	int get_age()const { return age; }
};

std::ostream& operator<<(std::ostream& os, const Person& rhs) {                        //overloaded insertion operator code
	os << std::setw(15) << std::left << "[Person: " << std::setw(15) << std::right << rhs.name << ", " << rhs.age << "]" << std::endl;
	return os;
};

void display(const std::vector<Player>& v) {
	for (auto i : v) {
		std::cout << i;
	}
	std::cout << std::endl;
}

int main() {
	std::cout << std::setw(33) << std::left << std::setfill('-') << "\n" << std::endl;
	std::vector <Player> player_names{
		{}, {"Jennifer", 34},{"Samantha", 32, 10.3},{"Elizabeth",56 }, {"Gandalf", 400, 1989.9}
	};
	display(player_names);
	player_names.emplace_back(Player{ "Jenny",18 });
	player_names.insert(player_names.begin(), Player{ "Gollom", 600, 17.66 });
	std::cout << std::setw(33) << std::left << std::setfill('-') << "\n" << std::endl;
	display(player_names);
	std::cout << std::setw(33) << std::left << std::setfill('-') << "\n" << std::endl;
	std::cout << "Lambda Expression, to sort alphabetically by name." << std::endl;
	std::sort(begin(player_names), end(player_names), [](const Player& p1, const Player& p2) { //lambada expression
		return p1.get_name() < p2.get_name();
		});
	display(player_names);
	std::cout << std::setw(33) << std::left << std::setfill('-') << "\n" << std::endl;
	std::cout << "Lambda Expression, to sort by age." << std::endl;
	std::sort(begin(player_names), end(player_names), [](const Player& p1, const Player& p2) { //lambada expression
		return p1.get_age() < p2.get_age();
		});
	display(player_names);
	std::cout << "\n=====Lambda for Vector Sorting=====" << std::endl << std::endl;            //Lambda std::sort & std::for_each
	std::vector <Person> account_names{                                                //vector
		{"Jenny", 34},{"Sam", 32},{"John",56 }
	};
	account_names.emplace_back(Person{ "Sarah",18 });                //emplace_back Person objects to vector
	std::sort(begin(account_names), end(account_names), [](const Person& p1, const Person& p2) {
		return p1.get_name() < p2.get_name();
		});
	std::for_each(begin(account_names), end(account_names), [](const Person& p) {
		std::cout << p << std::endl;
		});

	return 0;
}