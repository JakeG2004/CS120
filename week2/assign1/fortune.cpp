/* The fortune Teller -
 * a simple program introducing some
 * fundamental programming concepts.
 * Jake Gendreau
 * Section 01
 * 8/25/23
 * Assignment 1
 * 
 * 
 * I added a new user input for the mystic number
 * Added some ASCII art to each fortune
 * Modified line 19 to use all 3 nums
 */

#include<iostream> //include a library
using namespace std;
int main() //main starts the program
{
    // Var declaration
    int favorite; //var to store favorite num
    int disliked; //var to store disliked num
    int lucky; //var to store the lucky number
    int unlucky;
    // Get user input
    cout << "Enter your favorite number (no decimals): "; //prompt user
    cin >> favorite; //get input and store
    cout << "Enter a number you don't like (no decimals): ";
    cin >> disliked;
    cout << "Enter your UNLUCKY number: ";
    cin >> unlucky;
    lucky = ((favorite + unlucky) * disliked) % 10;
    cout << endl << "Your secret, lucky number is: " << lucky << endl;
    if(lucky < 0){ // conditional, values less than 0
        cout << "Try to be less negative." << endl;
    }
    if(lucky >= 0 && lucky <= 4){//0-4 inclusive
        cout << "Think to the stars!\n˚. ✦.˳·˖✶ ⋆.✧˚." << endl;
    }
    if(lucky == 5) {//5
        cout << "Halfway there!\n";
        cout << "+---------+\n| 1 2 3 4 |\n+---------+\n";
    }
    if(lucky > 5 && lucky < 9){ //6-8 inclusive
        cout << "Today you should embrace technology.\n      _\n     |-|  __\n     |=| [Ll]\n     \"^\" ====`o" << endl;

    }
    if(lucky == 9){
        cout << "Today is your lucky day!\n  ____\n /\\'  \\    _____\n/: \\___\\  / .  /\\\n\\' / . / /____/..\\\n \\/___/  \\\'  \'\\  /\n          \\'__\'\\/" << endl;
    }
    if(favorite == disliked && disliked == unlucky){
        cout << "Favorite, disliked, and unlucky all the same? Clearly you don't care.\n(ﾉꐦ ఠ曲ఠ)ﾉ彡┻━┻" << endl;
        return 0;
    }
    else if (favorite == disliked){
        cout << "Do you really not care about your numbers? Favorite and disliked the same? For shame.\n•`_´•" << endl;
    } else {
        cout << "All your numbers are different! That's good, it shows that you care. 0 \\__/ 0" << endl;
    }
    
    // Code to help program exit gracefully
    cin.ignore();
    cout << "Press enter to quit. " << endl;
    cin.ignore();
    return 0;
}