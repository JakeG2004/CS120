#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int screen[20][40];

    //Fill array
    for(int r=0; r<20; r++){
        for(int c=0; c<40; c++){
            screen[r][c] = int(5 + 3*sin(r/2.0) + 2 * cos(c/2.0));
        }
    }

    //Print array
    for(int r=0; r<20; r++){
        for(int c=0; c<40; c++){
            switch(screen[r][c]){
                case 0:
                    cout << " ";
                    break;
                case 1:
                    cout << ".";
                    break;
                case 2:
                    cout << ",";
                    break;
                case 3:
                    cout << ";";
                    break;
                case 4:
                    cout << "*";
                    break;
                case 5:
                    cout << "|";
                    break;
                case 6:
                    cout << "p";
                    break;
                case 7:
                    cout << "P";
                    break;
                case 8:
                    cout << "A";
                    break;
                case 9:
                    cout << "H";
                    break;
                default:
                    cout << "x";
                    break;
            }
        }
        cout << endl;
    }
}