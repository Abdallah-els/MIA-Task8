#include <iostream>
using namespace std;

class transformer {\
private:
    int weapon_level;

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
        while (weapon_level > 3){ // choose a weapon randomly
            int weapon_level = rand() % 10 + 1; 
        }
        if (weapon_level == 1){
            
        }
        target.take_damage(10);
        display();
    }

};

int possibilty(int chance) {
    int rand_number =  rand() % 100 + 1; //Random number between 1 and 100
    return rand_number <= chance;
}

int main() {
    srand(time(0));  // Initialize random number generator
    
    transformer optimus("Optimus Prime");
    transformer megatron("Megatron");

    return 0;
}