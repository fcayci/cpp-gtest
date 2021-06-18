#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

#include "duck.h"

using namespace std;

double Move::getLocation() { return pos; }

Fly::Fly()
{
    cout << "Fly constructor\n";
    if (!initialized) {
        speed = std::make_shared<Speed>(2, 3);
        initialized = true;
    }
};

Fly::~Fly() { cout << "Fly destructor\n"; };

void Fly::step() { pos = pos + sqrt(speed->x*speed->x + speed->y*speed->y); }
std::pair<int, int> Fly::getSpeed() { return std::make_pair(speed->x, speed->y); }
void Fly::setSpeed(int a, int b) {
    if (a < 0 || b < 0) return;
    speed->x = a; speed->y = b;
}
double Fly::getHeight() {return height;}
void Fly::setHeight(double x) { if (x >= 0) height = x;}


Walk::Walk() {
    cout << "Walk constructor\n";
    if (!initialized) {
        speed = std::make_shared<Speed>(1, 1);
        initialized = true;
    }
}

Walk::~Walk() { cout << "Walk destructor\n"; };

void Walk::step() { pos++; }
std::pair<int, int> Walk::getSpeed() { return std::make_pair(speed->x, speed->y); }
void Walk::setSpeed(int a, int b) {speed->x = a; speed->y = b;}
double Walk::getHeight() {return 0.f;}
void Walk::setHeight(double a) {(void)a;}


Duck::Duck() : Duck(_c) { cout << "Duck: default constructor\n";}
Duck::Duck(int i) : id(i) {_c++; m = setupMove(); cout << "Duck: second constructor\n";}
Duck::~Duck() { delete m; cout << "Duck: DESTRUCTOR\n"; }

Move* Duck::setupMove() {return new Fly();}

void Duck::setID(int a) {id = a;};
int Duck::getID() {return id;};
void Duck::quack() { cout << "Duck " << id << " says Quack!\n";};
void Duck::move() { m->step(); }
double Duck::getLocation() { return m->getLocation();}
std::pair<int, int> Duck::getSpeed() { return m->getSpeed(); }
void Duck::setSpeed(int a, int b) { m->setSpeed(a, b); }


Raft::Raft() {
    // ducks = vector<Duck>(4); cout << "Raft: default constructor\n";
    //for (auto i=0; i<4; ++i) {Duck *n = new Duck(i); ducks.emplace_back(n);}
    for (auto i=0; i<4; ++i) {ducks.emplace_back(make_unique<Duck>(i));}
    for (unsigned long i=0; i<ducks.size(); ++i) {
        cout << "i: " << i << " id: " << ducks[i]->getID() << endl;
        ducks[i]->setID(i);
    }
}

Raft::~Raft() {
    ducks.clear();
    cout << "Raft: DESTRUCTOR\n";
}

void Raft::sing() {for (auto& d: ducks) d->quack(); }

void Raft::move() {for (auto& d: ducks) d->move(); }
void Raft::move(int a) {ducks[a]->move(); }

vector<double> Raft::getLocations() {
    vector<double> locs; for (auto& d: ducks) locs.push_back(d->getLocation()); return locs;
}
vector<pair<int, int>> Raft::getSpeeds() {
    vector<pair<int, int>> spd; for (auto& d: ducks) spd.push_back(d->getSpeed()); return spd;
}

void Raft::deleteDuck(int) {ducks.erase(ducks.begin());}

int Duck::_c = 0;
int Fly::initialized = false;
shared_ptr<Speed> Fly::speed;
int Walk::initialized = false;
shared_ptr<Speed> Walk::speed;
