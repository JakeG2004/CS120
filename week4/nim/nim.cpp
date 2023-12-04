/* the game of NIM
 * Jake Gendreau
 * Section 1
 * 9/8/2023
 * 
 * EXTRA CREDIT:
 * Added winning / losing messages
 * Added rules
 * Added commentary
 * Removed magic numbers
 * Added play again feature
 * Added input sanitization
 * 
 * Made it so opponent always wins
 */

#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

int main(){
    int num_objects = 25;
    int current_player = 1;
    int move;
    int min_pieces = 1;
    int max_pieces = 3;
    char answer = 'n';

    //Rules
     printf("Welcome to Nim!\n"
        "Rules:\n"
        "1) there are %i pieces\n"
        "2) You may choose to take %i to %i pieces\n"
        "3) The winner is whoever doesn't take the last piece\n", num_objects, min_pieces, max_pieces);

    //game loop

    do {
        //Commentary
        switch(num_objects){
            case 22:
                cout << "\nKind of a baby start." << endl;
                break;
            
            case 20:
                cout << "\nBig plays going on here!" << endl;
                break;

            case 12:
                cout << "\nAbout halfway there!" << endl;
                break;

            case 10:
                cout << "\nGetting down to the wire!" << endl;
                break;

            case 3:
                cout << "\nOnly 3 more remain!" << endl;
                break;

            case 2:
                cout << "\nEasy win for " << current_player << endl;
                break;

            case 1:
                cout << "\nAnd that's game!" << endl;
                break;
        }

        //Player move
        if(current_player == 1){

            while(printf("Player 1, enter your move (%i - %i): ", min_pieces, max_pieces) && !(cin >> move) || move > max_pieces || move < min_pieces || move > num_objects){
                cin.clear(); //clear bad input flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "Invalid input; please re-enter.\n";
            }

        } else {
            //Computer move
            do {

                //Only works if first player starts on lose position
                move = (max_pieces + 1) - move;
                if(num_objects == 1)
                    move = 1;

            } while (move < min_pieces || move > max_pieces || move > num_objects);
            cout << "\nComputer removed " << move << endl;
        }

        //Execute move
        num_objects = num_objects - move;
        cout << num_objects << " objects remaining." << endl;

        //Switch players
        current_player = (current_player + 1) % 2; 
    } while (num_objects > 0);

    //end loop

    // Win + loss messages
    if(current_player == 0){
        cout << "\nComputer wins! Player loses :(" << endl;
    } else {
        cout << "\nPlayer wins! Computer loses :D" << endl;
    }

    cout << "\nDo you want to play again? (y/n): ";
    cin >> answer;

    if(answer == 'y')
        main();
    else if (answer == 'n'){
        return 0;
    }
}