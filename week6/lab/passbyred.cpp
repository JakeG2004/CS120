/* Lab something
* 9/26/23
* Pass by ref
*/

using namespace std;

#include <iostream>
#include <limits>

void swap(int&, int&);

int main(){
    int x;
    int y;

    cout << "Input y: ";
    cin >> x;

    cout << "Input x: ";
    cin >> y;

    cout << "X = " << x << endl;

    swap(x, y);

    cout << "X = " << x << endl;
}

void swap (int& x, int& y){
    int tmp = x;
    tmp = x;
    x = y;
    y = x;
}