#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class A{
    public:
    A(){
        callA = 0;
    }
    private:
    int callA;
    void inc(){
        callA++;
    }
    protected:
    void func(int &a){
        a = a*2;
        inc();
    }
    public:
    int getA(){
        return callA;
    }
};
class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};
class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};
class D : public C, public B, public A{
    int val;
    public:
    D(){
        val = 1;
    }
    void update_val(int new_val){
         while(new_val%2==0){
            A::func(val);
            new_val/=2;
         }
         while(new_val%3==0){
            B::func(val);
            new_val/=3;
         }
         while(new_val%5==0){
            C::func(val);
            new_val/=5;
         }
    }
    void check(int new_val){
        update_val(new_val);
        cout << "Value = " << val << endl;
        cout << "A's func called " << getA() << " times\n";
        cout << "B's func called " << getB() << " times\n";
        cout << "C's func called " << getC() << " times\n";
    }
};


int main() {
    int n;
    D d;
    cin >> n;
    d.check(n);
    return 0;
};