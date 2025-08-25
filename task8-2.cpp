#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class weapon{
    private:
    string name;
    int damage;
    int accuracy;
    
    public:
    
    weapon(){}
    weapon(string name, int damage , int accuracy) : name(name), damage(damage), accuracy(accuracy) {}
    
    //getters
    string get_name() {return name;}
    int get_damage() {return damage;}
    int get_accuracy() {return accuracy;}
    
    
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
        if (health < 0) health = 0; 
    }
    // virtual void display(transformer &target) = 0;

    // virtual void attack(transformer &target) = 0; // the "&" is to pass the reference and not a copy 

    bool possibilty(int chance) {
        int rand_number =  rand() % 100 + 1; //Random number between 1 and 100
        return rand_number <= chance;
    }
    
    // getters
    string get_name() {return name;}
    int get_health() {return health;}
    
};

class optimus : public transformer{

weapon weapons_list[3];
weapon power;

public:
    optimus() 
    : transformer("Optimus Prime"), 
    weapons_list{weapon("Ion rifle", 6 , 100), weapon("Energon swords" , 12, 80), weapon("Shoulder canon" , 45, 25)} 
    {}

    void display(transformer &target){
        cout << name << " hit " << target.get_name() << " with " << power.get_name() << "!!" << endl;
        cout << target.get_name() << " health is " << target.get_health() << endl;
        cout << "______________________________________________________" << endl;
    }
    
    void attack(transformer &target) {
        power = weapons_list[choose_weapon()];
        if (possibilty(power.get_accuracy()) == true){
            target.take_damage(power.get_damage());
            display(target);
        }
        else{
            cout << name << " missed!" << endl;
        }
    }
};

class mega : public transformer{

weapon weapons_list[3];
weapon power;

public:
    mega()
    : transformer("Megatron"),
    weapons_list{weapon("Fusion canon", 9, 90), weapon("Fusion sword", 18, 70), weapon("Tank mode", 60 ,15)} 
    {}

    void display(transformer &target){
        cout << name << " hit " << target.get_name() << " with " << power.get_name() << "!!" << endl;
        cout << target.get_name() << " health is " << target.get_health() << endl;
        cout << "______________________________________________________" << endl;
    }
    
    void attack(transformer &target) {
        power = weapons_list[choose_weapon()];
        if (possibilty(power.get_accuracy()) == true){
            target.take_damage(power.get_damage());
            display(target);
        }
        else{
            cout << name << " missed!" << endl;
        }
    }

};




int main() {
    srand(time(0));  // Initialize random number generator
    
    optimus optimus_prime;
    mega megatron;

    while (optimus_prime.is_alive() && megatron.is_alive()) {

        optimus_prime.attack(megatron);
        if (megatron.is_alive()) {
            megatron.attack(optimus_prime);
        }
    }

    return 0;
}
