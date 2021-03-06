#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

namespace Criminal{
  class Record{
  private:
    string name;
    string sex;
    string father_name;
    string address;
    string offense;
    string blood_type;
    string date_of_birth;
    long crim_code;
    int reward;
    void display();

  public:
    Record();
    void get_data();
    void write_data();
    void read_data();
    void search();
    void delete_record();
    void modify();
  };
}
