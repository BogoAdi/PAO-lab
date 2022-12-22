#include <iostream>
#include <string>
#include <memory> // for std::shared_ptr
#include <thread>
#include <mutex>

//Item 13
class Musician {
public:
// constructor that takes ownership of a string
Musician(std::shared_ptr<std::string>instrument) : instrument_(instrument) {}

// sing method that uses the string resource
void sing() const {
std::cout << "All I want for Christmas is you! ---" << *instrument_ << std::endl;
}

private:
std::shared_ptr<std::string>instrument_;
};

class Dancer {
public:
// constructor that takes ownership of a string
Dancer(std::auto_ptr<std::string>moves) : moves_(moves) {}

// dance method that uses the string resource
void dance() const {
std::cout << "Let me show my moves with " << *moves_ << std::endl;
}

private:
std::auto_ptr<std::string> moves_;
};

//Item 14
class Lock{
public:
    // Constructor: explicitly acquire the mutex resource
    explicit Lock(std::mutex *pm)
    : mutexPtr(pm) // Initialize member variable mutexPtr with the pointer to the mutex object passed as an argument
    { 
        mutexPtr->lock(); // Acquire the mutex resource
        std::cout<<"Lock mutex\n"; // Print a message indicating that the mutex has been acquired
    } 

    // Destructor: release the mutex resource
    ~Lock() { 
        mutexPtr->unlock(); // Release the mutex resource
        std::cout<<"Unlock mutex\n"; // Print a message indicating that the mutex has been released
    } 

private:
    // Disallow copy and assignment constructors
    Lock(const Lock& t); // Copy constructor
    Lock& operator=(const Lock& t); // Assignment operator

    // Pointer to the mutex object being locked/unlocked
    std::mutex *mutexPtr;
};


int main() {
// create a string resource that is shared by multiple Musician objects
std::shared_ptr<std::string>shared_instrument(new std::string("piano"));

// create two Musician objects that share the same string resource
Musician musician1(shared_instrument);
Musician musician2(shared_instrument);

// have the musicians sing
musician1.sing();
musician2.sing();

// when all the musicians go out of scope, the string is automatically freed

std::auto_ptr<std::string>dancer_moves(new std::string("tango"));

 // Create a mutex object
    std::mutex m;

// Create a Lock object, passing a pointer to the mutex object as an argument
    Lock lock(&m);

// Do some work that requires the mutex to be locked
    std::cout << "Doing some work that requires the mutex to be locked" << std::endl;

// When the Lock object goes out of scope, its destructor will be called and the mutex will be unlocked
 

return 0;
}