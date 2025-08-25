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

protected:
    int health;
    string name;
    
    int choose_weapon(){
        return rand() % 3; // choose a weapon randomly
    }

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

    virtual void attack(transformer &target) = 0; // the "&" is to pass the reference and not a copy 

};

class optimus : public transformer{

weapon weapons_list[3];

public:
    optimus() 
    : transformer("Optimus Prime"), 
    weapons_list{weapon("Ion rifle", 6 , 100), weapon("Energon swords" , 12, 80), weapon("Shoulder canon" , 45, 25)} 
    {}

    void attack(transformer &target) override{
        weapons_list[choose_weapon()];
    }
};

class mega : public transformer{

weapon weapons_list[3];

public:
    mega()
    : transformer("Megatron"),
    weapons_list{weapon("Fusion canon", 9, 90), weapon("Fusion sowrd", 18, 70), weapon("Tank mode", 60 ,15)} 
    {}

    void attack(transformer &target) override{
        weapons_list[choose_weapon()];
    }
};


bool possibilty(int chance) {
    int rand_number =  rand() % 100 + 1; //Random number between 1 and 100
    return rand_number <= chance;
}

int main() {
    srand(time(0));  // Initialize random number generator
    
    optimus optimus_prime;
    mega megatron;

    // while (optimus.is_alive() && megatron.is_alive()) {

    //     optimus.attack(megatron);
    //     if (megatron.is_alive()) {
    //         megatron.attack(optimus);
    //     }
    // }

    return 0;
}