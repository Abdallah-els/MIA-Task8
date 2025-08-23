#include <iostream>
using namespace std;

class transformer {
protected:
    int health;
    string name;

public:
    // Constructor to initialize 
    transformer(string n, int h =100 ) : health(h) , name(n) {}  

    bool is_alive() {
        return health > 0;
    }

    void take_damage(int damage) {
        health -= damage;
    }
    void display(){
        cout << name << "attacked!" << endl;
    }

    void attack(transformer &target) {
        target.take_damage(10);
        display();
    }

};

int main() {
    
    transformer optimus("Optimus Prime");
    transformer megatron("Megatron");

    return 0;
}