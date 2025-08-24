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

    void choose_weapon(){
        while (weapon_level > 3){ // choose a weapon randomly
            int weapon_level = rand() % 10 + 1; 
        }

    }
};

class weapons{
public:
    string name;
    string transformer;
    int damage;
    int accuracy;

    weapons(string name, string t, int damage , int accuracy) : name(name), transformer(t), damage(damage), accuracy(accuracy) {}


};

bool possibilty(int chance) {
    int rand_number =  rand() % 100 + 1; //Random number between 1 and 100
    return rand_number <= chance;
}

int main() {
    srand(time(0));  // Initialize random number generator
    
    transformer optimus("Optimus Prime");
    transformer megatron("Megatron");

    weapons ion_rifle("Ion rifle", "Optimus Prime", 6 , 100);
    weapons energon_swords("Energon swords" , "Optimus Prime", 12, 80);
    weapons shoulder_canon("Shoulder canon" , "Optimus Prime", 45, 25);

    weapons fusion_canon("Fusion canon", "Megatron", 9, 90);
    weapons fusion_sowrd("Fusion sowrd", "Megatron", 18, 70);
    weapons tank_mode("Tank mode", "Megatron" , 60 ,15);

    while (optimus.is_alive() && megatron.is_alive()) {

        optimus.attack(megatron);
        if (megatron.is_alive()) {
            megatron.attack(optimus);
        }
    }

    return 0;
}