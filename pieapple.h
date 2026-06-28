#pragma once

#include <iostream>
#include<execution>
#include<string>

using namespace std;

class Date {

private:
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d);
	bool isValid() const;
	int get_day();
	int get_mounth();
	int get_year();

};

class Creation {

private:
	static int numberOfCreations;
	int id;
	Date creationDate;



public:
	Creation(Date date);
	virtual ~Creation() = default;
	Date getCreationDate() const;
	static int getNumberOfCreations();
	int getId() const;


};


class Human : public Creation {

private:
	string name;
	bool isAlive;


public:
	Human(string n , Date date );
	~Human();
	string getName() const;
	void setName(std::string newName);
	void markAsDeceased();
	bool getIsAlive() const;
};


class Apple : public Creation {

private:
	string color;
	bool isRotten;

public:
	Apple(string c, bool rotten, Date date);
	~Apple();
	bool getIsRotten() const;
	void setRotten(bool rotten);
	std::string getColor() const;

};

class ApplePie  {

private:
	bool isDelicious;

public:

	ApplePie();

};

class Universe {

private:
	static Universe* instance;
	Creation** creations;
	int count = 0;
	int capacity = 100;


public:
	static Universe* getInstance();
	void addCreation(Creation* creation);
	bool deleteCreation(int id);
	ApplePie* bakeApplePie();
	Creation** getCreations() const;
	void delete_instance();
	~Universe();

};