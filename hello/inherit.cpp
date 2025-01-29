#include <iostream>


using namespace std;
class engine {
public:
  int var_rpm = 1000;
  engine() {}

  void print(){
    cout<<"Engine spec : "<<var_rpm << endl;
  }
};

class body {
public:
  int var_body = 20;
  int door = 2;
  body() {}

  void print (){
    cout<<"Body spec : "<<endl;
    cout<<"   body : "<<var_body<<endl;
    cout<<"   door : "<<door<<endl;
  }

};

class car : public engine, public body {
public:
  int var_car = 0;

  car() {
    var_car = var_body + var_rpm;
    cout << "total" << var_car;

  }

  void car_spec (){

    cout<<"Total spec : "<<var_car<<endl;
  }
  
};

int main() {
  body b; 
  b.print();

  engine e;
  e.print();

  car maruthi;
  maruthi.car_spec();


}
