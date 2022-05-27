#include <iostream>
#include <string>
#include <vector>


class Musicans {
protected:
	std::string m_name;
	std::string m_surname;
	std::string m_profession;
public:
	Musicans(std::string name, std::string surname, std::string profession) :
		m_name(name), m_surname(surname), m_profession(profession) {
	}
	
	void print() {
		std::cout << m_name << " " << m_surname << " is " << m_profession << std::endl;
	}

	virtual void take_place() {
		std::cout << "on the base" << std::endl;
	}

	virtual void rehearsal() {
		std::cout << "Is up to play" << std::endl;
	}

	virtual void play() {
		std::cout << "Is starting to play on" << std::endl;
	}
};

class Conductor :public Musicans {
public:
	Conductor(std::string m_name = "", std::string m_surmname = "", std::string m_profession = "") :
		Musicans(m_name, m_surmname, m_profession) {
	}

	void play() {
		std::cout << " is starting to conduct" << std::endl;
	}

	void rehearsal() {
		std::cout << "Attention please!" << std::endl;
	}
};

class String :public Musicans {
public:
	String(std::string m_name = "", std::string m_surmname = "", std::string m_profession = "") :
		Musicans(m_name, m_surname, m_profession) {
	}

	void play_strart() {
		std::cout << " takes the ";
	}
	void play_end() {
		std::cout << "in his hands and puts his hand on the strings." << std::endl;
	}
};

class Wind :public Musicans {
public:
	Wind(std::string m_name = "", std::string m_surmname = "", std::string m_profession = "") :
		Musicans(m_name, m_surname, m_profession) {
	}
	void play_strart() {
		std::cout << " takes the ";
	}
	void play_end() {
		std::cout << "in his hands and puts it to his mouth." << std::endl;
	}
};

class Violinist: public String {
public:
	Violinist(std::string m_name = "", std::string m_surmname = "", std::string m_profession = "") :
		String(m_name, m_surmname, m_profession) {
	}
	std::string getProfession() {
		return m_profession;
	}

	void rehearsal() {
		std::cout << getProfession();
		String::play();

	}
	void take_place() {
		std::cout << getProfession();
		Musicans::take_place();

	}
	void play() {
		std::cout << getProfession();
		String::play_strart();
		std::cout << "violin ";
		String::play_end();
	}
};

class Flutist :public Wind {
public:
	Flutist(std::string m_name = "", std::string m_surmname = "", std::string m_profession = "") :
		Wind(m_name, m_surmname, m_profession) {
	}
	std::string getProfession() {
		return m_profession;
	}
	void take_place() {
		std::cout << getProfession();
		Musicans::take_place();

	}
	void play() {
		std::cout << getProfession();
		Wind::play_strart();
		std::cout << "fluit ";
		Wind::play_end();
	}
};


class Orchestr {
private:
	std::vector<Musicans*>arr;
public:
	Orchestr(std::vector<Musicans*>arr_) {
		arr.resize(arr_.size());
		for (int i = 0; i < arr.size(); ++i) {
			arr[i] = arr_[i];
		}
	}
	Orchestr() {
	}
	void take_place(){
		for (auto v : arr) {
			v->print();
			v->take_place();
		}
	}
	void rehearsal() {
		for (auto v : arr) {
			v->print();
			v->rehearsal();
		}

	}
	void play(){
		for (auto v : arr) {
			v->print();
			v->play();
		}

	}
	void add_mus(Musicans& t){
		arr.push_back(&t);
	}
	void count_flutist() {
	}
};
