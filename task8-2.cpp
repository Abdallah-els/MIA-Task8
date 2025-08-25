#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class weapon{
public:
    string name;
    int damage;
    int accuracy;

    weapon(string name, int damage , int accuracy) : name(name), damage(damage), accuracy(accuracy) {}


};

class transformer { //abstract class
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

    virtual void attack(transformer &target) {}

    void choose_weapon(){
        while (weapon_level > 3){ // choose a weapon randomly
            int weapon_level = rand() % 10 + 1; 
        }

    }
};

class optimus : public transformer{

weapon weapons[3];

public:
    optimus() 
    : transformer("Optimus Prime"), 
    weapons{weapon("Ion rifle", 6 , 100), weapon("Energon swords" , 12, 80), weapon("Shoulder canon" , 45, 25)} 
    {}


};

class mega : public transformer{

weapon weapons[3];

public:
    mega()
     : transformer("Megatron"),
    weapons{weapon("Fusion canon", 9, 90), weapon("Fusion sowrd", 18, 70), weapon("Tank mode", 60 ,15)} 
    {}

};


bool possibilty(int chance) {
    int rand_number =  rand() % 100 + 1; //Random number between 1 and 100
    return rand_number <= chance;
}

int main() {
    srand(time(0));  // Initialize random number generator
    
    optimus optimus_prime;
    mega megatron;

    
    weapon fusion_canon("Fusion canon", 9, 90);
    weapon fusion_sowrd("Fusion sowrd", 18, 70);
    weapon tank_mode("Tank mode", 60 ,15);

    // while (optimus.is_alive() && megatron.is_alive()) {

    //     optimus.attack(megatron);
    //     if (megatron.is_alive()) {
    //         megatron.attack(optimus);
    //     }
    // }

    return 0;
}