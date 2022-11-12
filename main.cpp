#include <iostream>

using namespace std;
class Weel{
    public:
        string brand;

        Weel (string brand, string id):
        brand(brand),
        id(id) {}
    void toString(){
        cout<<"brand weel: "<<this->brand<<endl;
        cout<<"id: "<<this->id<<endl;
    }
     Weel(const Weel& rhs) {
        this -> brand = rhs.brand;
        this -> id = id;
    }
    Weel& operator=(const Weel& rhs) {
        if (this != &rhs){
            this -> brand = rhs.brand;
            this ->id = rhs.id;
            }
        return *this;
    }
    string getId(){
        return this->id;
    }
    private :
    string id;

};
class Bike{
private:
    string producer;
    string id;
    Weel* weels;
public:
    string brand;
    string colour;
    int numberOfBrakes;
//    Bike(){
//    this->brand = "Hervis";
//    this->colour= "red";
//    this->numberOfBrakes = 1;
//    this->producer = "China";
//    }
    Bike(string producer, string id, string brand, string colour, int numberOfBrakes, Weel *weels)
    :
        producer(producer),
        id(id),
        brand(brand),
        colour(colour),
        numberOfBrakes(numberOfBrakes),
        weels(weels)
        {}
     Bike(const Bike& rhs) {
        this->colour = rhs.colour;
        this->brand = rhs.brand;
        this->producer = rhs.producer;
        this->numberOfBrakes = rhs.numberOfBrakes;
        this->weels = rhs.weels;
    }

    Bike& operator=(const Bike& rhs) {
        if (this != &rhs){
            this->colour = rhs.colour;
            this->brand = rhs.brand;
            this->producer = rhs.producer;
            this->numberOfBrakes = rhs.numberOfBrakes;
            this->weels = rhs.weels;
        }
        return *this;
    }
    void showAttributes(){
        cout<<brand<<" number of brakes "<<numberOfBrakes<<" colour "<<colour<<" ";
        this->weels->toString();
    }
    void toString(){
        cout<<brand<<" " << numberOfBrakes<<" "<<colour<<endl;
    }

};

class DollarBill{
    public:
        string id;
        int  value;
        DollarBill(string id, int value):
            id(id),
            value(value)
        {}

    DollarBill(const DollarBill&);
    DollarBill operator=(const DollarBill&);
    void toString(){
        cout<<id<<" "<<value<<endl;
    }
};

int main()
{
    Weel w1("Continental","IDSF1234312");
//    Bike b23;
//    b23.toString();
    Bike b1("Nea Nicu","1234s","Nike","blue",1,&w1);
    b1.showAttributes();
    Bike b2 = b1;
    Bike b5(b1);
    b5.showAttributes();
    b2.showAttributes();
    DollarBill d1("123412",20);
    d1.toString();
    //DollarBill d2 = d1;
    return 0;
}
