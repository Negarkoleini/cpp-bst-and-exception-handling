#include<iostream>
#include<execution>
#include"pieapple.h"
#include<string>

Date::Date(int y, int m, int d): year(y) , month(m) , day(d){}

bool Date:: isValid() const {
	if (0 < day <= 30 && 0 < month < 13 && 0 < year < 2026)
		return true;

	else
		throw invalid_argument("date is not true");

}

int Date::get_day() {
	return day;
}
int Date::get_mounth() {
	return month;
}
int Date::get_year() {
	return year;
}


Creation::Creation(Date date): creationDate(date) {
	++numberOfCreations;
}

Date Creation::getCreationDate() const {
	return creationDate;
}

int Creation::getNumberOfCreations() {
	return numberOfCreations;

}

int Creation::getId() const {
	return id;
}

Human::Human(string n, Date date) : isAlive(true), Creation(date)  {
	if (n == "")
		throw invalid_argument("there is no name");
    else if (n.length() > 15)
		throw length_error("name is too long");
	else
		name = n;
	if (0 > date.get_day() > 30 || 0 > date.get_mounth() > 13 || 0 > date.get_year() > 2026)
		throw logic_error("date is not true");

}

Human:: ~Human(){}

string Human::getName() const {
	return name;
}

void Human::setName(string newName) {
	if (newName == "")
		throw invalid_argument("thereis no name");
	else if (newName.length() > 15)
		throw length_error("name is too long");
	else
	name = newName;
}

void Human::markAsDeceased() {
	if (isAlive == true)
		isAlive = false;
	else
		throw logic_error("this person has already dead");
}

bool Human::getIsAlive() const {
	return isAlive;
}


Apple::Apple(string c, bool rotten, Date date): isRotten(rotten), Creation(date)  {
	if (c == "")
		throw invalid_argument("there is no color");
	else
		color = c;
}

Apple::~Apple(){}

bool Apple::getIsRotten() const {
	return isRotten;
}

void Apple::setRotten(bool rotten) {
	isRotten = rotten;
}

string Apple::getColor() const {
	return color;
}

ApplePie::ApplePie(): isDelicious(true){}

Universe* Universe::getInstance() {
	if (instance == nullptr)
		instance = new Universe();

	return instance;
}

void Universe::addCreation(Creation* creation) {

	if (creation == nullptr)
		throw invalid_argument("creation doesn't exist");

	if (capacity == count) {
		throw bad_alloc();
	}

	if(creations == nullptr)
		creations = new Creation*[capacity] ();

		creations[count] = creation;
		++count;
		
}

bool Universe::deleteCreation(int id) {
	for (int i = 0; i < count ; ++i) {
		if (creations[i]->getId() == id) {
			delete creations[i];
			creations[i] = nullptr;
			return true;
		}

	}
	throw logic_error("this Id doesn't exist");
}

ApplePie* Universe::bakeApplePie() {
	int humancount =0;
	int applecount =0;

	for (int i = 0; i < count; ++i) {
		Human* temp = static_cast<Human*>(creations[i]);

		if (temp != nullptr) {
			if (temp->getIsAlive() == true)
				++humancount;
		}
	
		else {
			++applecount;
		}
	}

	if (humancount >= 1 && applecount >= 1) {
		ApplePie* pie = new ApplePie();
		return pie;
	}
	else
		throw runtime_error("there is no person or apple");

}
Creation** Universe::getCreations() const {
	return creations;
}

void Universe::delete_instance(){
	delete instance;

}

Universe :: ~Universe() {
	
	for (int i = 0; i < count; ++i) {
		delete creations[i];
	}

	delete[] creations;
}
