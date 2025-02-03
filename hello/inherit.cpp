#include <iostream>

using namespace std;

enum class gear_type {
  manual,
  amt,
  cvt,
  dct,
  tc,
  ecvt

};

class engine {
public:
  int var_rpm = 0;
  engine() {}
  engine(int rpm) : var_rpm(rpm) {

    try {
      if (this->var_rpm < 1500) {
        throw(1);
      }
    }

    catch (int e) {
      cout << "RPM is below 1500..." << e << endl;
    }
  }

  void engine_print() {
    cout << " Engine specification" << endl;
    cout << "     RPM : " << var_rpm << endl;
  }

  virtual void ignintion() {
    cout << "Default Engine ignintion sequence" << endl;
  };
};

class body {
public:
  int var_door = 0;
  int var_valve = 0;
  body() {}
  body(int door, int valve) : var_door(door), var_valve(valve) {}

  void body_print() {
    cout << " Body specification" << endl;
    cout << "     Door : " << var_door << endl;
    cout << "     Valve : " << var_valve << endl;
  }
};

class gearbox {
public:
  int num_count = 0;
  gear_type g_type;

  gearbox(int count, gear_type gearbox_type)
      : num_count(count), g_type(gearbox_type) {

    try {
      if (this->g_type == gear_type::manual) {
        throw(string{"Manual"});
      }
    } catch (const string &e) {
      cout << "Invalid Gearbox type : " << e << endl;
      this->g_type = gear_type::ecvt;
      cout << "Gearbox changes to ecvt" << int(this->g_type) << endl;
    }
  }

  void gearbox_print() {
    cout << " Gearbox specification" << endl;
    cout << "     Count : " << num_count << endl;
    cout << "     Gearbox Type : " << int(g_type) << endl;
  }

  virtual void changeGear() = 0;
};

class car : public engine, public body, public gearbox {
public:
  car(int rpm, int door, int valve, int g_count, gear_type g_type)
      : engine(rpm), body(door, valve), gearbox(g_count, g_type) {}

  void car_spec() {
    cout << "Full specification of the car" << endl;
    // this->var_door = 6;
    // this->var_rpm = 1500;
    this->engine_print();
    this->body_print();
    this->gearbox_print();
    this->changeGear();
    // e1.print();
    // b1.print();
  }

  /*void ignintion() { cout << "Custom Engine ignintion sequence"; }*/

  void changeGear() { cout << "Gear changed" << endl; }
};

int main() {
  /*body b(4, 5);*/
  /*b.print();*/

  engine e(1000);
  e.ignintion();

  /*gearbox m_gear;*/
  /*m_gear.changeGear();*/

  car maruthi(1600, 6, 7, 5, gear_type::manual);
  maruthi.car_spec();
}
