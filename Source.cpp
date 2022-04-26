#include <iostream>
#include <string>
#include <vector>

class Musicans {
protected:
	std::string fullName{""};
public:
	std::string fullName(std::string fullName) {
		return fullName;
	}
	void takePlace() {
		std::cout << "Сел на стул." << std::endl;
	}
};

class WildInstrumentPlayer :public Musicans {
public:
	WildInstrumentPlayer(std::string fullName){};
	void takePlace() {
		std::cout << getSpec() << " взял дудку" << std::endl;
		Musicans::takePlace();
	}
	std::string getSpec() {
		std::string spec = "Wild player";
		return spec;
	}
};

class Fleita :public WildInstrumentPlayer {
public:
	Fleita(std::string name) :WildInstrumentPlayer(name) {};
	void play() {
		std::cout << "Дудит" << std::endl;
	}
	void repetice() {
		play();
	}
	std::string getSpec() {
		return "Fleita";
	}
};

class Orchestre {
	std::vector <Fleita*> fleitist;
};

int main()
{
	setlocale(LC_ALL, "rus");
	return 0;
}
