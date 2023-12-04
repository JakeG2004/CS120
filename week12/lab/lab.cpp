#include<iostream>
using namespace std;

int func(int, int &);
void func2(int, int []);

int main(){
    //Establish values
    int x = 99, y = 55;
    int a[5] = {1,2,3,4,5};
    int *p;

    //Set p -> a[0]
    p = a;

    //P -> a[1]
    p++;

    //increment X
    x++;

    //a[1] = 8
    * p = 8;

    //p -> a[3]
    p = &a[3];

    // a[3] = 12
    * p = 12;

    //p -> a[2]
    p--;
    
    //a[2] = 11
    * p = 11;

    //y = 101
    //a[0] = 102
    a[0] = func(x,y);

    //a[4] = 456
    func2(x,a);

    //Print x and y
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    //Print out array values
    for(int i = 0; i < 5; i++){
        cout << "a[" << i << "] = " << a[i] << endl;
    }
}

int func(int a, int &b){
    a = 100;
    b = 101;
    return 102;
}

void func2(int a, int b[]){
    a = 123;
    b[4] = 456;
}
