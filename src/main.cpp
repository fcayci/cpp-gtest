#include "duck.h"

using namespace std;

int main() {

    Raft b;
    cout << "===========\n";
    b.sing(); b.sing(); b.sing();
    b.move(); b.move(); b.move();
    b.move(2);
}
