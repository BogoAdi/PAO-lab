#include <iostream>

using namespace std;
class Bike{
    private:
        string brand;
        string id;
        int numberOfBrakes;
        string colour;
    public:
      int price;

    Bike (string brand, string id, int numberOfBrakes, string colour, int price):
        brand(brand),
        id(id),
        price(price),
        numberOfBrakes(numberOfBrakes),
        colour(colour)
        {}
    // Bike() {
    //     this->brand= "China";
    //     this->id="112";
    //     this->price=10;
    //     this->numberOfBrakes=1;
    //     this->colour="yellow";
    // }
    
    Bike(const Bike& rhs)  {
        this -> brand = rhs.brand;
        this -> id = rhs.id;
        this -> numberOfBrakes = rhs.numberOfBrakes;
        this->  colour = rhs.colour;
        this-> price =rhs.price;
    }
    Bike& operator=(const Bike& rhs) {
        if (this != &rhs){
            this -> brand = rhs.brand;
            this ->id = rhs.id;
            this ->numberOfBrakes = rhs.numberOfBrakes;
            this-> colour = rhs.colour;
            this-> price =rhs.price;
            }

        return *this;
    }
      Bike& operator*=(const Bike& rhs) {
        if (this != &rhs){
            this-> price =rhs.price*100; // custom price for *=
            this -> brand = rhs.brand;
            this ->id = rhs.id;
            this ->numberOfBrakes = rhs.numberOfBrakes;
            this-> colour = rhs.colour;
            }

        return *this;
    }
     void showBase(){
        cout<<" Bike: "<<this->brand<<" "<< this->id <<" "<<this->price<<endl;
    }
    

};

class ElectricBike : public Bike{
    private: 
    string typeEnginee;
    int power;
    int maxSpeed;

    public:

ElectricBike(string typeEnginee, int power,int maxSpeed,string brand, string id, int numberOfBrakes, string colour, int price)
    : Bike(brand, id, numberOfBrakes, colour, price)
    ,
        typeEnginee(typeEnginee),
        power(power),
        maxSpeed(maxSpeed)
        {}

    public:
     ElectricBike(const ElectricBike& rhs): Bike(rhs) {
      this->maxSpeed = rhs.maxSpeed;
      this->power = rhs.power;
      this->typeEnginee = rhs.typeEnginee;
    }

    ElectricBike& operator=(const ElectricBike& rhs) {
        if (this != &rhs){
            Bike::operator=(rhs);
            this->typeEnginee = rhs.typeEnginee;
            this->maxSpeed = rhs.maxSpeed;
            this->power = rhs.power;
            
        }
        else 
        cout<<"Same object assignments"<<endl;
        return *this;
    }
    void showIt(){
        cout<<"Electric Bike: "<<this->typeEnginee<<" "<< this->power <<" CP "<<this->maxSpeed<<" Km/h and price "<<this->price<<endl;
    }
    //   static void doSomethingSpecial( Bike& rb, ElectricBike* pd){
    //      if(rb.price > pd->price) cout<< rb.price<<endl;
    //      else if(rb.price < pd->price)
    //             cout<<"Musk wins"<<endl;
    //      else   {
    //             cout<<"Draw"<<endl;
    //             cout<<&rb<<endl;
    //             delete &rb;
    //             rb.showBase();
    //             Bike rd(pd->brand, pd->id, pd->numberOfBrakes, pd->colour,pd->price);
    //             cout<<&rb<<endl;
    //             rb.showBase();
    //     }   
    //  }

};

int main(){
    Bike b1("Nike","12fds213adsfA1",2,"black0",150);
    Bike b55( "Adidas","IE23adsf",2,"red",3500);
    b1.showBase();
    Bike b2= b1;
    b2.showBase();
    Bike b3 = b1;
    b3.showBase();
    b3*=b1;
    ElectricBike eb1("RTX23",500, 40, "Adidas","IE23adsf",2,"red",3500);
    eb1.showIt();
    eb1.Bike::showBase();
    b3.showBase();
    b1 = b1;
    b1.showBase();
    eb1= eb1;
    eb1.showIt();
    // ElectricBike::doSomethingSpecial(b1,&eb1);
    // ElectricBike::doSomethingSpecial(b55,&eb1);

}