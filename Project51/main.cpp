#include<iostream>
#include<vector>
#include"Impediment.h"
#include"Participant.h"
using namespace std;



void NextStage(vector<Participant*> par, vector<Impediment*> imp, int& stage) {
	if (imp.size() <= stage) {
		cout << "Winners: \n";
		for (auto ptr = par.begin(); ptr != par.end(); ptr++) {
			if ((*ptr)->GetInGame()) {
				cout << (*ptr)->GetName() << endl;
			}
		}
		return;
	}
	Impediment* curImp = imp[stage];
	for (auto ptr = par.begin(); ptr != par.end(); ptr++) {
		(*ptr)->Overcome(curImp);
	}
	stage++;
	cout << endl;
}

void InitVect(vector<Participant*>& par, vector<Impediment*>& imp, int& stages) {
	par.push_back(new Cat(10, 10, "CAT"));
	par.push_back(new Human(5, 2, "HUM"));
	par.push_back(new Robot(100, 100, "ROB"));

	imp.push_back(new Wall(4, "W1"));
	imp.push_back(new Wall(7, "W2"));
	imp.push_back(new Racetrack(4, "RUN"));
	imp.push_back(new Racetrack(100, "RUN2.0"));
	stages = imp.size();
}

int main() {
	vector<Participant*> par;
	vector<Impediment*> imp;
	int stages;
	int curStage = 0;

	InitVect(par, imp, stages);

	for (int i = 0; i <= stages; i++) {
		NextStage(par, imp, curStage);
	}


	for (auto ptr = imp.begin(); ptr != imp.end(); ptr++)
	{
		delete *ptr;
	}
	for (auto ptr = par.begin(); ptr != par.end(); ptr++)
	{
		delete* ptr;
	}
	return 0;
}