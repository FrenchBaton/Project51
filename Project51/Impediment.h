#pragma once
#include<iostream>
using namespace std;

class Impediment
{
protected:
	int height;
	int lenght;
	string name;
public:
	Impediment() : height(0), lenght(0), name("IMPEDIMENT"){}
	Impediment(int h, int l, string n) : height(h), lenght(l), name(n){}
	int GetHeight() const { return height; }
	int GetLenght() const { return lenght; }
	string GetName() const { return name; }
};

class Wall:public Impediment
{
public:
	Wall() :Impediment(0,1,"WALL") {}
	Wall(int l, string n) :Impediment(0, l, n) {}
};

class Racetrack :public Impediment
{
public:
	Racetrack() :Impediment(0, 1, "WALL") {}
	Racetrack(int h, string n) :Impediment(h, 0, n) {}
};
