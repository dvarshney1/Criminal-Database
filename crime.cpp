#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
#include "crime.h"
using namespace std;

namespace Criminal{
    Record::Record(){
      long crim_code = 0;
      string name = "Unknown";
      string sex = "N/A";
      string father_name = "Unknown";
      string address = "N/A";
      string offense = "N/A";
      string blood_type = "N/A";
      string date_of_birth = "N/A";
      int reward = 0;
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
      get_data();
      fout.write((char*)&c, sizeof(c));
      fout.close();
    }
    void Record::read_data(){
      ifstream fin;
      fin.open("Record", ios::in):
      fin.seekg(0, ios::beg);
      fin.read((char*)&c, sizeof(c));
      while(fin){
        display();
        fin.read((char*)&c, sizeof(c));
      }
      fin.close();
    }
    void Record::search(){
      string name;
      cout<<endl<<"Enter Criminal Name to be searched: ";
      gets(name);
      ifstream fin;
      fin.open("Record");
      fin.seekg(0, ios::beg);
      fin.read((char*)&c, sizeof(c));
      while(fin){
        if(strcmp(name, this->name) == 0)
          display();
        fin.read((char*)&c, sizeof(c));
      }
      fin.close();
    }
    void Record::delete_record(){
      ifstream fin("Record", ios::app);
      ofstream fout("new", ios::app);
      fin.seekg(0, ios::beg);
      string name;
      cout<<endl<<"Enter Criminal's Name whose record needs to be deleted: ";
      gets(name);
      fin.read((char*)&c, sizeof(c));
      while(fin){
        if(strcmp(name, this->name)==0)
          fout.write((char*)&c, sizeof(c));
        fin.read((char*)&c, sizeof(c));
      }
      fin.close();
      fout.close();
      remove("Record");
      rename("new", "Record");
    }
    void Record::modify(){
      string name;
      cout<<endl<<"Enter Name of Criminal whose details are to be modified: ";
      gets(name);
      int p;
      fstream f;
      f.open("Record", ios::in|ios::out);
      f.seekg(0, ios::beg);
      f.read((char*)&c, sizeof(c));
      int size = f.tellg();
      while(!f.eof(){
        if(!strcmp(name, this->name)){
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
            case 1: gets(name);
                    break;
            case 2: gets(sex);
                    break;
            case 3: gets(date_of_birth);
                    break;
            case 4: gets(blood);
                    break;
            case 5: gets(father_name);
                    break;
            case 6: gets(address);
                    break;
            case 7: gets(offense);
                    break;
            case 8: cin>>reward;
                    break;
            default: cout<<"Wrong choice, please enter again"<<endl;
          }
          f.seekg(size-sizeof(c), ios::beg);
          f.write((char*)&c, sizeof(c));
        }
        f.read((char*)&c, sizeof(c));
        size = f.tellg();
      }
      f.close();
    }
}
