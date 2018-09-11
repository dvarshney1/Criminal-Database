#include <iostream>
#include "crime.h"
#include <string>
#include <cmath>

using namespace std;
using namespace Criminal;

int main(){
  Record c;
  // TODO: Get all the parameters and switch case statement of a criminal's
  //       record and push it onto github
  do{
    int choice;
    cin>>choice
    cout<<"*******************************************************"<<endl;
    cout<<"        Press 1 to Enter Criminal Information"<<endl;
    cout<<"        Press 2 to Delete Criminal Information"<<endl;
    cout<<"        Press 3 to Modify Criminal Information"<<endl;
    cout<<"        Press 4 to Search for Criminal Information"<<endl;
    cout<<"        Press 5 to Display Criminal Information"<<endl;
    cout<<"*******************************************************"<<endl;
    switch(choice){
      case 1: write_data();
              break;
      case 2: delete();
              break;
      case 3: modify();
              break;
      case 4: search();
              break;
      case 5: get_data();
              break;
      case 6: break;

      default: cout<<"Choose the correct option !!"<<endl;
    }
  } while(choice != 6);
  cout<<"Good Bye!!"<<endl;
}
