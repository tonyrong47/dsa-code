#include <iostream>
using namespace std;
int main() {
    int vector1 , vector2 ;

    //Add 10 and 20 to Vector1 dynamically using push_back

    vector1.push_back(10);
    vector1.push_back(20);

    //Display the elements in vector1 using the at() method as well as its size using the size() method

    cout<<"\nvector1:"<<endl;
    cout<<"vector1.at(0)"<<endl;
    cout<<"vector1.at(1)"<<endl;
    cout<<"vector1 contains"<<vector1.size()<<"elements"<<endl;

    //Add 100 and 200 to vector2 dynamically using push_back

    vector2.push_back(100);
    vector2.push_back(200);

    //Display the the element in vector_2d using the at() method 
    cout<<"\nvector_2d:"<<endl;
    cout<<"vector_2d.at(0).at(0)"<<" "<< vector_2d.at(0).at(1);
    cout<<"vector_2d.at(1).at(0)"<<" "<< vector_2d.at(1).at(1);
    
    // change vector1.at(0) to 1000

    vector1.at(0) = 1000;
    }