#include <iostream>
#include "crime.hpp"
#include <string>
#include <cmath>

using namespace std;
using namespace Criminal;

int main(){
  Record c;
  int choice;
  do{
    cin>>choice;
    cout<<"*******************************************************"<<endl;
    cout<<"        Press 1 to Enter Criminal Information"<<endl;
    cout<<"        Press 2 to Delete Criminal Information"<<endl;
    cout<<"        Press 3 to Modify Criminal Information"<<endl;
    cout<<"        Press 4 to Search for Criminal Information"<<endl;
    cout<<"        Press 5 to Display Criminal Information"<<endl;
    cout<<"*******************************************************"<<endl;
    switch(choice){
      case 1: c.write_data();
              break;
      case 2: c.delete_record();
              break;
      case 3: c.modify();
              break;
      case 4: c.search();
              break;
      case 5: c.get_data();
              break;
      case 6: break;
      default: cout<<"Choose the correct option !!"<<endl;
    }
  } while(choice != 6);
  cout<<"Good Bye!!"<<endl;
}
