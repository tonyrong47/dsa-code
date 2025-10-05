#include <iostream>
using namespace std;

int main(){
    double code;
    cout << "Enter the private code:";
    cin >> code;
    try{
        if(code!=9762){
            throw code;
        }
        else{
            cout << "Access Granted" << endl;
        }
    }
    catch(double wrongCode){
        cout << "\nERROR: Entered wrong code"<<endl;
    }
    return 0;
}
