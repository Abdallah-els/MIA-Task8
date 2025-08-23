#include <iostream>
using namespace std;

class transformer {
protected:
    int health;
    string name;

public:
    // Constructor to initialize 
    transformer(string n, int h =100 ) : health(h) , name(n) {}  

    
};

int main() {
    
    transformer optimus("Optimus Prime");
    transformer megatron("Megatron");

    return 0;
}