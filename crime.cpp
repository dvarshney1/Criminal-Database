#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
#include "crime.hpp"
using namespace std;

namespace Criminal{
    Record::Record(){
      crim_code = 0;
      name = "Unknown";
      sex = "N/A";
      father_name = "Unknown";
      address = "N/A";
      offense = "N/A";
      blood_type = "N/A";
      date_of_birth = "N/A";
      reward = 0;
    }
    void Record::get_data(){
      cout<<endl<<"Enter Criminal's Unique Code: ";
      cin>>crim_code;
      cout<<endl<<"Enter Criminal's Name: ";
      getline(cin, name);
      cout<<endl<<"Enter Criminal's Sex: ";
      getline(cin, sex);
      cout<<endl<<"Enter Criminal's Father Name: ";
      getline(cin, father_name);
      cout<<endl<<"Enter Criminal's Address: ";
      getline(cin, address);
      cout<<endl<<"Enter Criminal's Offense: ";
      getline(cin, offense);
      cout<<endl<<"Enter Criminal's Blood Tyoe: ";
      getline(cin, blood_type);
      cout<<endl<<"Enter Criminal's Date of Birth: ";
      getline(cin, date_of_birth);
      cout<<endl<<"Enter Reward on Criminal: ";
      cin>>reward;
      cout<<endl;
    }
    void Record::display(){
      cout<<endl<<"Name: "<<name;
      cout<<endl<<"Sex: "<<sex;
      cout<<endl<<"Father's name: "<<father_name;
      cout<<endl<<"Address: "<<address;
      cout<<endl<<"Offense: "<<offense;
      cout<<endl<<"Blood Type: "<<blood_type;
      cout<<endl<<"Date of Birth: "<<date_of_birth;
    }
    void Record::write_data(){
      ofstream fout;
      fout.open("Record", ios::app);
      this->get_data();
      fout.write((char*)this, sizeof(*this));
      fout.close();
    }
    void Record::read_data(){
      ifstream fin;
      fin.open("Record", ios::in);
      fin.seekg(0, ios::beg);
      fin.read((char*)this, sizeof(*this));
      while(fin){
        this->display();
        fin.read((char*)this, sizeof(*this));
      }
      fin.close();
    }
    void Record::search(){
      string name;
      cout<<endl<<"Enter Criminal Name to be searched: ";
      getline(cin, name);
      ifstream fin;
      fin.open("Record");
      fin.seekg(0, ios::beg);
      fin.read((char*)this, sizeof(*this));
      while(fin){
        if(name == this->name)
          this->display();
        fin.read((char*)this, sizeof(*this));
      }
      fin.close();
    }
    void Record::delete_record(){
      ifstream fin("Record", ios::app);
      ofstream fout("new", ios::app);
      fin.seekg(0, ios::beg);
      string name;
      cout<<endl<<"Enter Criminal's Name whose record needs to be deleted: ";
      getline(cin, name);
      fin.read((char*)this, sizeof(*this));
      while(fin){
        if(name == this->name)
          fout.write((char*)this, sizeof(*this));
        fin.read((char*)this, sizeof(*this));
      }
      fin.close();
      fout.close();
      remove("Record");
      rename("new", "Record");
    }
    void Record::modify(){
      string name;
      cout<<endl<<"Enter Name of Criminal whose details are to be modified: ";
      getline(cin, name);
      int p;
      fstream f;
      f.open("Record", ios::in|ios::out);
      f.seekg(0, ios::beg);
      f.read((char*)this, sizeof(*this));
      int size = f.tellg();
      while(!f.eof()){
        if(name != this->name){
          cout<<endl<<"Press 1 to change name";
          cout<<endl<<"Press 2 to change sex";
          cout<<endl<<"Press 3 to change DOB";
          cout<<endl<<"Press 4 to change blood group";
          cout<<endl<<"Press 5 to change Father's name";
          cout<<endl<<"Press 6 to change Address";
          cout<<endl<<"Press 7 to change Crime Committed";
          cout<<endl<<"Press 8 to change reward on criminal"<<endl;
          cin>>p;
          switch(p){
            case 1: getline(cin, name);
                    break;
            case 2: getline(cin, sex);
                    break;
            case 3: getline(cin, date_of_birth);
                    break;
            case 4: getline(cin, blood_type);
                    break;
            case 5: getline(cin, father_name);
                    break;
            case 6: getline(cin, address);
                    break;
            case 7: getline(cin, offense);
                    break;
            case 8: cin>>reward;
                    break;
            default: cout<<"Wrong choice, please enter again"<<endl;
          }
          f.seekg(size-sizeof(*this), ios::beg);
          f.write((char*)this, sizeof(*this));
        }
        f.read((char*)this, sizeof(*this));
        size = f.tellg();
      }
      f.close();
    }
}
