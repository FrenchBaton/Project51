#pragma once
#include<iostream>
#include"Impediment.h"
using namespace std;

class Participant
{
protected:
	int run;
	int jump;
	string name;
	bool inGame;
public:
	Participant() : run(0), jump(0), name("MEMBER"), inGame(true) {}
	Participant(string n) : run(0), jump(0), name(n), inGame(true) {}
	Participant(int r, int j, string n) : run(r), jump(j), name(n), inGame(true) {}

	bool GetInGame() { return inGame; }
	string GetName() { return name; }

	void Overcome(Impediment* imp){
		if (!inGame) return;

		int h = imp->GetHeight();
		int l = imp->GetLenght();
		string n = imp->GetName();

		if (h > 0)
		{
			if (jump >= h)
			{
				cout << "Participant "<< name <<" passed the impediment "<< n <<" at distance: " << h << endl;
			}
			else
			{
				cout << "Participant " << name << " didnt pass the impediment " << n << " at distance: " << h  << endl;
				inGame = false;
			}
		}
		else if (l > 0) {
			if (run >= l)
			{
				cout << "Participant " << name << " passed the impediment " << n << " at distance: " << l << endl;
			}
			else
			{
				cout << "Participant " << name << " didnt pass the impediment " << n << " at distance: " << l << ". Did " << run << endl;
				inGame = false;
			}
		}
		cout << endl;
	}
};


class Robot:public Participant
{
public:
	Robot() : Participant("ROBOT") {}
	Robot(int r, int j, string n) : Participant(r,j,n) {}
};

class Human :public Participant
{
public:
	Human() : Participant("ROBOT") {}
	Human(int r, int j, string n) : Participant(r, j, n) {}
};

class Cat :public Participant
{
public:
	Cat() : Participant("ROBOT") {}
	Cat(int r, int j, string n) : Participant(r, j, n) {}
};