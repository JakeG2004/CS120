/* Week 3 lab
 * Jake Gendreau
 * Section 1
 * 9/5/2023
 */

#include <iostream>
#include <string>
using namespace std;

int main(){
    //String of queries
    int queries[23] = {0, -7, -1+(-2), -7+7, 7<8, 10>10, 
        (7<10)||(7>10), (7<10)&&(7>10), -5>=5, (7>10)||(-5==5), 
        !(6==7), (10!=11)&&(7>8), (7==6)||(7==7)||(7==8), (6<(8&&9)), 
        (1==(6<8)), (0==(0||1)), (6<(5+2)), (6+(5==5)), (6<7)+(7>=5),
        (0<7)-(0<7), (7/(7>3)), 4*(6==7), 6%(10>=10)};
    //Iterate through string and output bool result of each expression
    for(int i=0;i<23;i++){
        cout << (bool)queries[i] << endl;
    }
}