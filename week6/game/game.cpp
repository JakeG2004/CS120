/* The game
* Week 6
* Jake Gendreau
* Section 1
* 9/29/23
*/

using namespace std;

//Libraries
#include <limits>
#include <iostream>
#include <string>
#include <cmath>

//Prototypes
void printImage(string);
int rollDie();
void badInput();
void showMap();
void gameLoop();
void makeRoom();
void restartGame();
int findPos(string[6][7], int, int, int);

//rooms
void endGame();

void findGunk(int);
void gunkBandit(int);
void gunkShop(int, int);
void drBones(int);
void snail(int, int);

//Vars
int position = 0;
int gunk = 15;
int bonus = 0;
bool hasSprayBottle = false;
int turns = 0;
int skeletons = 0;
int bandits = 0;
int shops = 0;
int gunks = 0;
int snails = 0;

int maxRoll = 4;

int main(){
    srand(time(0));
    
    //Name and instructions etc...
    printImage("title");
    cout << "Welcome to slime time! In this game, you play as a ball of sludge and your goal is to make it to the sludgy swamp at the end of the map. You'll encounter many challenges along the way. Have fun!" << endl;
    
    while(position < 27){
        turns++;
        gameLoop();
    }

    endGame();
}

void gameLoop(){

    int roll = 0;
    char answer;

    while(cout << "Roll the die? (y/n): " && !(cin >> answer)){
        badInput();
    }

    if(answer == 'y'){
        roll = rollDie() + bonus;
        if(bonus > 0){
            cout << "Bonus! +" << bonus << endl;
        }
        cout << "You rolled " << roll << endl;
        position += roll;
        bonus = 0;
        showMap();
        if(position < 27){
            makeRoom();
        }       
    }
}

int rollDie(){
    return ((rand()%maxRoll) + 1);
}

void showMap(){

  string character = "▣";
  int pos = 0;
  //Stats
  printf("Gunk: %i\tHas Spray Bottle: %s", gunk, hasSprayBottle ? "true" : "false");

    string board[6][7] = {
        {"□", "□", "□", " ", "□", "□", "□"},
        {"□", " ", "□", "□", "□", " ", "□"},
        {"□", " ", " ", " ", " ", "□", "□"},
        {"□", "□", "□", "□", " ", "□", " "},
        {" ", " ", " ", "□", " ", "□", "□"},
        {"□", "□", "□", "□", " ", " ", "□"}
    };

    findPos(board, 5, 0, 0);

    //Print map
    cout << endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
        cout << "\t" << board[i][j];
        }
        cout << endl << endl;
    }
}

void makeRoom(){
    int room = (rand()%5);

    switch(room){
        
        //Find gunk in room
        case 0:
            findGunk((rand()%10) + 1);
            break;
        
        //Gunk bandit
        case 1:
            gunkBandit((rand()%10) + 1);
            break;

        //Shop
        case 2:
            gunkShop((rand()%20 + 1), (rand()%maxRoll + 1));
            break;

        case 3:
            drBones((rand()%5 + 1));
            break;
        case 4:
            snail((rand()%maxRoll + 1), rand()%10 + 1);
            break;            
    }
}

void endGame(){

    if(gunk <= 0){
        cout << "You have failed to make it to the swamp with some gunk." << endl;
        printImage("grave");
    } else {
        cout << "You made it to the swamp!" << endl;
        cout << "You used " << turns << " turns!" << endl;
        printf("Gunks: %i\nSkeletons: %i\nBandits: %i\nShops: %i\nSlugs: %i\n", gunks, skeletons, bandits, shops, snails);
    }

    char choice;
    position = 0;
    gunk = 15;
    bonus = 0;
    hasSprayBottle = false;
    turns = 0;
    skeletons = 0;
    bandits = 0;
    shops = 0;
    gunks = 0;
    snails = 0;

    while(cout << "Play again? (y/n): " && !(cin >> choice) && choice != 'y' && choice !='n'){
        badInput();
    }

    if(choice == 'n'){
        exit(3);
    } else {
        main();
    }
  
}

int findPos(string board[6][7], int posy, int posx, int count){

    //Recursively move through the map to find the player's progress

    count++;
    while (count <= position){

        //yay for arrays being pointers because returning a 2D array would be a pain

        //Set pos
        board[posy][posx] = "▣";

        //Check verticals
        if(posy + 1 <= 5 && board[posy+1][posx] == "□"){
            return findPos(board, posy+1, posx, count);
        } else if (posy - 1 >= 0 && board[posy-1][posx] == "□"){
            return findPos(board, posy-1, posx, count);
        }

        //Check horizontals
        if(posx + 1 <= 6 && board[posy][posx+1] == "□"){
            return findPos(board, posy, posx+1, count);
        } else if (posx - 1 >= 0 && board[posy][posx-1] == "□"){
            return findPos(board, posy, posx-1, count);
        }
        return 0;
    }
    return 0;
}

void printImage(string image){
    if(image == "title"){
        //Credit to https://patorjk.com/software/taag/#p=display&f=Wet%20Letter&t=SLIME%20TIME
        cout << "   .---. ,-.    ,-.         ,---.    _______ ,-.         ,---.\n"
        << "  ( .-._)| |    |(||\\    /| | .-'   |__   __||(||\\    /| | .-'   \n"
        << " (_) \\   | |    (_)|(\\  / | | `-.     )| |   (_)|(\\  / | | `-.   \n"
        << " _  \\ \\  | |    | |(_)\\/  | | .-'    (_) |   | |(_)\\/  | | .-'   \n"
        << "( `-'  ) | `--. | || \\  / | |  `--.    | |   | || \\  / | |  `--. \n"
        << " `----'  |( __.'`-'| |\\/| | /( __.'    `-'   `-'| |\\/| | /( __.' \n"
        << "         (_)       '-'  '-'(__)                 '-'  '-'(__)     \n";
    }
    if(image == "slimeball"){
        //credit to https://patorjk.com/software/taag/#p=display&f=Wet%20Letter&t=O (With a little tweaking)
        cout << " .---.   \n"
        << "/     )  \n"
        << "|    (_) \n"
        << "|     |\n"
        << "\\     /  \n"
        << " )---'  \n"
        << "(_)\n";

    }
    if(image == "bandit"){
        //yours truly
        cout << "    _____\n"
        << "   /     \\\n"
        << "  |       |\n"
        << "  (=======)\n"
        << "-------------\n"
        << "  | \"   \" |\n"
        << "  |_______|\n"
        << "  |\\#####/|\n"
        << "  | \\###/ |\n";
    }
    if(image == "grave"){
        //credit to jgs https://ascii.co.uk/art/rip
        cout << "       .\n"
        << "     -|-\n"
        << "      |\n"
        << "  .-'~~~`-.\n"
        << ".'         `.\n"
        << "|  R  I  P  |\n"
        << "|   GOO     |\n"
        << "|    BALL   |\n"
        << "|           |\n"
        << "^^^^^^^^^^^^^\n";
    }
    if(image == "shop"){
    //Made by yours truly
    cout << "      /^\\/^\\       ((\n"
    << "     [ \"  \"]      //\n"
    << "     [_____]     ||\n"
    << "     /     \\    (__) ()==;;\n"
    << "  []#=====================#[]\n"
    << " _[]_______________________[]_\n"
    << "[_____________________________]\n"
    << " ||                         ||\n";
  }
    if(image == "skelly"){
    //Credit to 142 https://www.asciiart.eu/mythology/skeletons
    cout << "      .-.\n"
           << "     (o.o)\n"
           << "      |=|\n"
           << "     __|__\n"
           << "   //.=|=.\\\\\n"
           << "  // .=|=. \\\\\n"
           << "  \\\\ .=|=. //\n"
           << "   \\\\(_=_)//\n"
           << "    (:| |:)\n"
           << "     || ||\n"
           << "     () ()\n"
           << "     || ||\n"
           << "     || ||\n"
           << "    ==' '==\n";
  }
    if(image == "snail"){
        //credit to Dirk-Lueder Kreie https://www.asciiart.eu/animals/insects/snails
        cout << "         __,._\n"
        << "        /  _  \\\n"
        << "       |  6 \\  \\  oo \n"
        << "        \\___/ .|__|| \n"
        << " __,..=\"^  . , \"  , \\ \n"
        << "<.__________________/\n";
    }
}

void badInput(){
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}

void findGunk(int found){
    gunks++;

    cout << "Nice! You found " << found << " gunk on the floor! + " << found << " gunk!" << endl;
    gunk += found;
    printImage("slimeball");
}

void gunkBandit(int steal){
    char choice;
    bandits++;
    printImage("bandit");

    cout << "You're sliming your way to the swamp when a bandit jumps you!" << endl;
    cout << "Bandit: Why, lookie what we got here! We got a real gunker on our hands here! HAHA\nTell me, goo, do you want to live to see tomorrow? (y/n)" << endl;

    while(cout << "> " && !(cin >> choice)){
        badInput();
    }

    if(choice == 'y'){
        cout << "Bandit: You made the right choice. Hand over some gunk or I'll dry you out!\n*He holds a paper towel over you*" << endl;

        while(cout << "Hand over gunk? (y/n): " && !(cin >> choice)){
            badInput();
        }

        if(choice == 'y'){
            cout << "Bandit: You're smarter than you look. Thanks for the " << steal << " gunk.\n The bandit walks away, laughing. -" << steal << " gunk." << endl;
            gunk -= steal;
            if(gunk < 0){
                gunk = 0;
            }
        }
        else {
            cout << "Bandit: I would have thought you were smarter than that.\n*He drops the paper towel and walks away*" << endl;    
            if(hasSprayBottle == false){
                cout << "You feel yourself drying out. This is where your journey ends." << endl;
                gunk -= gunk;
                endGame();
            } else {
                cout << "As he drops the towel on you, you use the spray bottle to rejuvinate yourself" << endl;
                hasSprayBottle = false;
            }
            
        }
        choice = 'y';
    } else {
        if(rand() % 2 == 0){
            cout << "Bandit: You stupid slimeballs don't know anything.\n*He scoops some gunk out from you*" << endl;
            steal = steal + (floor(gunk / 2));
            gunk -= steal;
            cout << "The bandit walks away, leaving you degunked. He took " << steal << " gunk" << endl;
            if(gunk <= 0){
                endGame();
            }
        } else {
            cout << "Bandit: Wow, I wasn't expecting you to say no. I feel bad for you. Here, take this" << endl;
            cout << "+" << floor(steal * 1.5) << " gunk" << endl;
            gunk += floor(steal * 1.5);
            cout << "The bandit walks away, looking back occasionally." << endl;
        }
    }
}

void gunkShop(int price, int move){
    char choice;
    shops++;
    printImage("shop");

    cout << "Travelling merchant: Welcome to my shop! I've got goods, I've got goo. Whaddya want? I can only sell ya one item right now. Come back later for more." << endl;
    printf("1) +%i to roll (%i gunk)\n2) Spray Bottle (%g gunk)\n3) +%i gunk (-%i on next roll)\n4) Leave the shop\n", move, price, ceil(price / 2), price, move);

    while(cout << "> " && !(cin >> choice)){
        badInput();
    }

    if(choice == '1' && gunk >= price){
        gunk -= price;
        cout << "You've gained +" << move << " on your next roll!" << endl;
        bonus = move;
    } else if(choice == '2' && gunk > ceil(price / 2)){
        gunk -= ceil(price / 2);
        cout << "You now have a spray bottle" << endl;
        hasSprayBottle = true;
    } else if(choice == '3'){
        gunk += price;
        bonus -= move;
        cout << "You gained " << price << " gunk at the price of -" << move << " on your next move" << endl;
    } else {
        cout << "Travelling merchant: Get outta my shop! I gotta go! Smell ya later slimeball!" << endl;
    }
}

void drBones(int bones){
    char choice;
    skeletons++;
    printImage("skelly");

    cout << "Skeleton: Hello! My name is Dr. Bones and it seems that I've stumbled into another goo pit, and it would mean a great deal to me if you could help me out of it." << endl;

    while(cout << "Help Dr. Bones? (y/n): " && !(cin >> choice)){
        badInput();
    }

    if(choice == 'y'){
        cout << "*You lift the skeleton out of the goo*" << endl;
        cout << "Dr. Bones: Thank you! Now it would mean a lot to me if you could answer my riddle! Will you?" << endl;

        while(cout << "Answer the riddle? (y/n): " && !(cin >> choice)){
            badInput();
        }

        if(choice == 'y'){
            cout << "Dr. Bones: Perfect. The question is what is a skeleton's favorite instrument?\n"
            << "1) The bass\n"
            << "2) The Trumpet\n"
            << "3) The trombone!\n"
            << "4) The xylophone\n";

            while(cout << "> " && !(cin >> choice)){
                badInput();
            }

            if(choice == '3'){
                cout << "Dr. Bones: YES!!! ITS THE TROM-BONE HAHAHAHAHAHA! You really tickle my funny bone! Here, take this!" << endl;
                cout << "+ " << bones << " gunk" << endl;
                gunk += bones;
            } else {
                cout << "Dr. Bones: WHY MUST YOU FAIL ME!!! JUST FOR THAT IM TAKING SOME GUNK" << endl;
                cout << "-" << bones << " gunk" << endl;
                gunk -= bones;
            }

            choice == 'y';
        } else {
            cout << "Dr. Bones: Oh, well that's disappointing. Well, guess I better get going. See ya around" << endl;
            cout << "*Mr bones walks away*" << endl;
        }
        choice == 'y';
    } else {
        cout << "Dr. Bones: CURSE YOUUUUUUU!!!" << endl;
    }
}

void snail(int move, int slime){
    printImage("snail");
    char choice;
    snails++;

    while(cout << "Snail: You going to the swamp too? (y/n): " && !(cin >> choice)){
        badInput();
    }

    if(choice == 'y'){
        cout << "Snail: Me too. I'll give you a ride kid, " << move << " spaces too, as long as you give me " << slime << " sludge and a spray with a spray bottle" << endl;

        while(cout << "Get a ride? (y/n): " && !(cin >> choice)){
            badInput();
        }

        if(choice == 'y' && hasSprayBottle == true && gunk >= slime){
            position += move;
            gunk -= slime;
            cout << "Snail: Thanks kid. Enjoy your walk!" << endl;
            hasSprayBottle = false;
            showMap();
        } else {
            cout << "Snail: Sorry kid, no can do. Enjoy your walk" << endl;
        }

        choice == 'y';
    } else {
        cout << "Snail: Well, that's the only place with where you're going. Hope you get to wherever you're going." << endl;
    }

}
