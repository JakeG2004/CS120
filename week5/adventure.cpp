/* Adenture game
 * Jake Gendreau
  * Section 1
  * CS120
  * Took me many hours :<
  */

//Libraries
#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

//Prototypes
void describeRoom(int room);
void badInput();
void showMap(int room);
void printPainting(bool backwards);
void printImage(string image);
void combat(string enemy, int enemyHealth, int enemyDamage);
void playAgain();
void showRoom(int room);

int room0();
int room1();
int room2();
int room3();
int room4();
int room5();
int room6();
int room7();
int room8();
int room9();

//Globals
int gold = 0;
int health = 100;
bool zoom = false;
bool exploredPots = false;
bool talkedToSkelly = false;
bool talkedToOcky = false;
bool lookedInMirror = false;
bool hasKey = false;
bool hasPotion = false;
bool foughtMimic = false;

int main(){
  srand(time(0));
  int room = 1;

  //Print title image
  printImage("title");

  cout << "Welcome to Dunk's Quest! In this text-based adventure, you (Dunk) will be exploring a dungeon long lost to man. Be sure to play it multiple times to see all of the dialogue options!\n" << endl;
  
  while(health > 0){
    switch(room){
      case 0:
        room = room0();
        break;

      case 1:
        room = room1();
        break;

      case 2:
        room = room2();
        break;

      case 3:
        room = room3();
        break;

      case 4:
        room = room4();
        break;

      case 5:
        room = room5();
        break;

      case 6:
        room = room6();
        break;

      case 7:
        room = room7();
        break;

      case 8:
        room = room8();
        break;

      case 9:
        room = room9();
        break;

      case 10:
        playAgain();
    }
  }
}

void badInput(){
  cin.clear(); //clear bad input flag
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
  cout << "Invalid input; please re-enter.\n";
}

void showMap(int room){

  string character = "▣";
  //Stats
  printf("Health: %i \tGold: %i \tKey: %s\n", health, gold, hasKey ? "True" : "False");

  if(zoom == false){
      //Map
    string rooms[4][4] = {
      {" ", " ", "□", " "},
      {"□", " ", "□", "□"},
      {"□", "□", "□", " "},
      {" ", "□", "□", "□"}};

    //Select room
    switch (room) {
      case 0:
          rooms[3][1] = character;
          break;

      case 1:
          rooms[3][2] = character;
          break;

      case 2:
          rooms[3][3] = character;
          break;

      case 3:
          rooms[2][0] = character;
          break;

      case 4:
          rooms[2][1] = character;
          break;

      case 5:
          rooms[2][2] = character;
          break;

      case 6:
          rooms[1][0] = character;
          break;

      case 7:
          rooms[1][2] = character;
          break;

      case 8:
          rooms[1][3] = character;
          break;

      case 9:
          rooms[0][2] = character;
          break;
    }

    //Print map
    cout << endl;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        cout << "\t" << rooms[i][j];
      }
      cout << endl << endl;
    }
  } else {
    showRoom(room);
  }
}

void showRoom(int room){
  //All rooms drawn by yours truly
  if(room == 0){
    cout << "#============]                  [============#\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[ |                                          ]\n"
    << "[ |                                           \n"
    << "[ |                                           \n"
    << "[ |                   (\")/                   \n"
    << "[ |                                           \n"
    << "[ |                                           \n"
    << "[ |                                          ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "#============================================#\n";
  }
  if(room == 1){
    cout << "#============]                  [============#\n"
    << "[   _                                        ]\n"
    << "[  / \\                 ,                     ]\n"
    << "[  \\_/               __I__                   ]\n"
    << "                      | |                      \n"
    << "                                              \n"
    << "                      (\")/                   \n"
    << "                                              \n"
    << "                                              \n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "#============================================#\n";
  }
  if(room == 2){
    cout << "#============================================#\n"
    << "[  (0.0)                                     ]\n"
    << "[   =|=                                      ]\n"
    << "[                                            ]\n"
    << "                                             ]\n"
    << "                                           | ]\n"
    << "                      (\")/                 | ]\n"
    << "                                           | ]\n"
    << "                                             ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "#============================================#\n";
  }
  if(room == 3){
    cout << "#============]                  [============#\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[     ___                                     \n"
    << "[    /| |\\                                    \n"
    << "[    |_8_|            (\")/                   \n"
    << "[                                             \n"
    << "[                                             \n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "#============================================#\n";
  }
  if(room == 4){
    cout << "#============================================#\n"
    << "[                   -------                  ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "                                              \n"
    << "                                              \n"
    << "                      (\")/                   \n"
    << "                                              \n"
    << "                                              \n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "#============]                  [============#\n";
  }
  if(room == 5){
    cout << "#============]                  [============#\n"
    << "[ @=@                                    @=@ ]\n"
    << "[  I                                      I  ]\n"
    << "[ @=@                                    @=@ ]\n"
    << "                                             ]\n"
    << "                                             ]\n"
    << "                      (\")/                   ]\n"
    << "                                             ]\n"
    << "                                             ]\n"
    << "[ @=@                                    @=@ ]\n"
    << "[  I                                      I  ]\n"
    << "[ @=@                                    @=@ ]\n"
    << "#============]                  [============#\n";
  }
  if(room == 6){
    cout << "#============================================#\n"
    << "[                                            ]\n"
    << "[         (                                  ]\n"
    << "[         )                                  ]\n"
    << "[         (            oo        (           ]\n"
    << "[         )           oo         )           ]\n"
    << "[                  o             (           ]\n"
    << "[                                )           ]\n"
    << "[____________________________________________]\n"
    << "[                                            ]\n"
    << "[                     (\")/                   ]\n"
    << "[                                            ]\n"
    << "#============]                  [============#\n";
  }
  if(room == 7){
    cout << "#============||||||||||8|||||||||============#\n"
    << "[                                            ]\n"
    << "[ ___                                        ]\n"
    << "[ | |                                        ]\n"
    << "[ | |                                         \n"
    << "[ / \\                                         \n"
    << "[                     (\")/                    \n"
    << "[                                             \n"
    << "[ |                                           \n"
    << "[ |                                          ]\n"
    << "[ |                                          ]\n"
    << "[                                            ]\n"
    << "#============]                  [============#\n";
  }
  if(room == 8){
    cout << "#============================================#\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "                                             ]\n"
    << "                    (^-^)                    ]\n"
    << "                 ____|_|______               ]\n"
    << "                   |       |                 ]\n"
    << "                                             ]\n"
    << "[                                            ]\n"
    << "[                     (\")/                   ]\n"
    << "[                                            ]\n"
    << "#============================================#\n";
  }
  if(room == 9){
    cout << "#============================================#\n"
    << "[                                            ]\n"
    << "[                      |_|                   ]\n"
    << "[                      (\")                   ]\n"
    << "[                      / \\                   ]\n"
    << "[                      | |                   ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "[                     (\")/                   ]\n"
    << "[                                            ]\n"
    << "[                                            ]\n"
    << "#============||||||||||8|||||||||============#\n";
  }
}

void printPainting(bool backwards){
  //Art by yours truly
  string painting = "+---------+\n| (0-0)   |\n|   |_/   |\n|   /\\    |\n+---------+";
  string tmp;
  if(backwards == true){
    for(int i = painting.length() - 1; i >= 0; i--){
      cout << painting[i];
    }
    cout << endl;
  } else {
    cout << painting << endl;
  }
}

void printImage(string image){
  if(image == "pot"){
  //Credit to hrr https://asciiart.website/index.php?art=objects/vases
  cout << "          ________\n"
        << "        .:________:.\n"
        << "          )      (\n"
        << "         /        \\\n"
        << "       ,'          `.\n"
        << "      /              \\\n"
        << "     /                \\\n"
        << "    (                  )\n"
        << "     \\                /\n"
        << "      `.            ,'\n"
        << "        `.________,'\n";
  }
  if(image == "candle"){
  //Art by Joan Stark
  //https://www.asciiart.eu/miscellaneous/candles
  cout << "       (\n"
  << "       )\\\n"
  << "       {_}\n"
  << "      .-;-.\n"
  << "     |'-=-'|\n"
  << "     |     |\n"
  << "     |     |\n"
  << "     |     |\n"
  << "     |     |\n"
  << "     '.___.'\n";
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
  if(image == "pillar"){
    //Art by Evan M Corcoran https://ascii.co.uk/art/column
    cout << " ___ \n"
         << "@   @\n"
         << " ||| \n"
         << " ||| \n"
         << " ||| \n"
         << " ||| \n"
         << "(___)\n";
  }
  if(image == "title"){
    //Thanks to https://patorjk.com/software/taag/#p=display&f=Big&t=DUNK'S%20QUEST for this art
    cout << " _____  _    _ _   _ _  ___  _____    ____  _    _ ______  _____ _______ \n"
    << " |  __ \\| |  | | \\ | | |/ ( )/ ____|  / __ \\| |  | |  ____|/ ____|__   __|\n"
    << " | |  | | |  | |  \\| | ' /|/| (___   | |  | | |  | | |__  | (___    | |\n"
    << " | |  | | |  | | . ` |  <    \\___ \\  | |  | | |  | |  __|  \\___ \\   | |\n"
    << " | |__| | |__| | |\\  | . \\   ____) | | |__| | |__| | |____ ____) |  | |\n"
    << " |_____/ \\____/|_| \\_|_|\\_\\ |_____/   \\___\\_\\____/|______|_____/   |_|\n";
  }
  if(image == "dunk"){
    //Uncredited on https://www.asciiart.eu/people/occupations/knights
    cout << "      __      _\n"
    << "     /__\\__  //\n"
    << "    //_____\\///\n"
    << "   _| /-_-\\)|/_\n"
    << "  (___\\ _ //___\\\n"
    << "  (  |\\\\_/// * \\\n"
    << "   \\_| \\_((*   *))\n"
    << "   ( |__|_\\\\  *//\n"
    << "   (o/  _  \\_*_/\n"
    << "   //\\__|__/\\\n"
    << "  // |  | |  |\n"
    << " //  _\\ | |___)\n"
    << "//  (___|\n";
  }
  if(image == "sign"){
    cout << "+--------------+\n"
    << "|    Earl's    |\n"
    << "|     Shop     |\n"
    << "|    ---->     |\n"
    << "+--------------+\n";
  }
  if(image == "door"){
    //Credit to MT-2 on https://ascii.co.uk/art/doors
    cout << "      ______\n"
    << "   ,-' ;  ! `-.\n"
    << "  / :  !  :  . \\\n"
    << " |_ ;   __:  ;  |\n"
    << " )| .  :)(.  !  |\n"
    << " |     (##)  _  |\n"
    << " |  :  ;`'  (_) (\n"
    << " |  :  :  .     |\n"
    << " )_ !  ,  ;  ;  |\n"
    << " || .  .  :  :  |\n"
    << " |  .  |  :  .  |\n"
    << " |    _;----.___|\n";
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
  if(image == "grave"){
    //credit to jgs https://ascii.co.uk/art/rip
    cout << "       .\n"
    << "     -|-\n"
    << "      |\n"
    << "  .-'~~~`-.\n"
    << ".'         `.\n"
    << "|  R  I  P  |\n"
    << "|   DUNK    |\n"
    << "|           |\n"
    << "|           |\n"
    << "^^^^^^^^^^^^^\n";
  }
  if(image == "firework"){
    //Credit to Joan Stark https://www.asciiart.eu/holiday-and-events/fireworks
    cout << "                                   .''.       \n"
    << "       .''.      .        *''*    :_\\/_:     . \n"
    << "      :_\\/_:   _\\(/_  .:.*_\\/_*   : /\\ :  .'.:.'.\n"
    << "  .''.: /\\ :   ./)\\   ':'* /\\ * :  '..'.  -=:o:=-\n"
    << " :_\\/_:'.:::.    ' *''*    * '.\'/.' _\\(/_'.':'.'\n"
    << " : /\\ : :::::     *_\\/_*     -= o =-  /)\\    '  *\n"
    << "  '..'  ':::'     * /\\ *     .'/.\'.   '\n"
    << "      *            *..*         :\n";
  }
  if(image == "ocky"){
    //credit to unkown https://ascii.co.uk/art/octopus
    cout << "                    .---.         ,,\n"
    << "         ,,        /     \\       ;,,'\n"
    << "        ;, ;      (  o  o )      ; ;\n"
    << "          ;,';,,,  \\  \\/ /      ,; ;\n"
    << "        ,,,  ;,,,,;;,`   '-,;'''',,,'\n"
    << "       ;,, ;,, ,,,,   ,;  ,,,'';;,,;''';\n"
    << "         ;,,,;    ~~'  '';,,''',,;'''' \n"
    << "                            '''\n";
  }
  if(image == "chest"){
    //credit to ejm97 http://www.ascii-art.de/ascii/c/chest.txt
    cout << "         __________\n"
    << "        /\\____;;___\\\n"
    << "       | /         /\n"
    << "       `. ())oo() .\n"
    << "        |\\(%()*^^()^\\\n"
    << "       %| |-%-------|\n"
    << "      % \\ | %  ))   |\n"
    << "      %  \\|%________|\n";
  }
  if(image == "demon"){
    //Credit to Joan Stark https://www.asciiart.eu/mythology/devils
    cout << "   ,    ,    /\\   /\\\n"
    << "  /( /\\ )\\  _\\ \\_/ /_\n"
    << "  |\\_||_/| < \\_   _/ >\n"
    << "  \\______/  \\|0   0|/\n"
    << "    _\\/_   _(_  ^  _)_\n"
    << "   ( () ) /`\\|V\"\"\"V|/`\\\n"
    << "     {}   \\  \\_____/  /\n"
    << "     ()   /\\   )=(   /\\\n"
    << "     {}  /  \\_/\\=/\\_/  \\\n";
  }
}

void combat(string enemy, int enemyHealth, int enemyDamage){
  int turn = 1;
  int choice = 0;
  bool dodge = false;
  while(health > 0 && enemyHealth > 0){
    if(turn == 1){
      cout << "1) Attack\n"
      << "2) Dodge\n";

      while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 2){
        badInput();
      }

      switch(choice){
        //Attack
        case 1:
          if((rand()%9) != 0){
            //Normal
            cout << "You attack with your sword\n"
             << "10 damage!\n";
             enemyHealth -= 10;
          } else {
            //Crit
            cout << "Critical hit!\n"
            << "20 damage!\n";
            enemyHealth -= 20;
          }
          break;

        //Dodge
        case 2:
          if(rand()%4 == 0){
            //Fail
            dodge = false;
            cout << "Dodge failed!\n";
          } else {
            //Succeed
            dodge = true;
            cout << "Successfully dodged!\n";
          }
          break;
      }

    //Enemy move
    } else {
      if(rand()%9 != 0 && dodge == false){
        //regular
        cout << enemy << " attacks!\n";
        health -= enemyDamage;
      } else if(dodge == false){
        //Crit
        cout << enemy << " got a critical hit!\n";
        health -= enemyDamage * 2;
      } else {
        cout << enemy << " missed its attack because you dodged!" << endl;
        cout << "In the enemy's struggle to hit you, it hit itself!" << endl;
        enemyHealth -= 5;
      }
      dodge = false;
    }

    cout << enemy << " health: " << enemyHealth << endl;
    cout << "Dunk health: " << health << endl << endl;
    //Switch player
    turn = (turn + 1) % 2;
  }

  if(enemyHealth <= 0){
    cout << "You vanquished the " << enemy << endl;
  } else {
    cout << "You were vanquished by the " << enemy << endl;
    playAgain();
  }
}

void playAgain(){

  if(health <= 0){
    cout << "You have failed to save this world." << endl;
    printImage("grave");
  } else {
    cout << "You have succeeded in freeing the world!" << endl;
    printImage("firework");
    cout << "The town thanks you for your effort!" << endl;

    printImage("ocky");
    cout << "Thank you so much! I can swim without ever having to worry about that wretched demon again!" << endl;

    printImage("skelly");
    cout << "Kid, I always saw that you had courage in your bones. It takes real guts (which I don't have) to do something like that. Thanks." << endl;

    printImage("shop");
    cout << "Can't say I didn't expect it. Thanks for your business kid." << endl;
  }

  char choice;
  gold = 0;
  health = 100;
  zoom = false;
  exploredPots = false;
  talkedToSkelly = false;
  lookedInMirror = false;
  hasKey = false;
  hasPotion = false;
  foughtMimic = false;

  while(cout << "Play again? (y/n)" && !(cin >> choice) && choice != 'y' && choice !='n'){
    badInput();
  }

  if(choice == 'n'){
    exit(3);
  } else {
    main();
  }
  
}

int room0(){ //Left painting
  showMap(0);
  int choice = 0;
  cout << "This room has a large painting on the wall. What would you like to do?\n"
     << "1) Investigate the painting\n"
     << "2) Go right\n"
     << "3) Go up\n";
 
  //While no movement action is chosen
  while(choice < 2){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 3){
      badInput();
    }
    switch(choice){
      case 1:
        //Explore painting
        printPainting(true);
        cout << "The painting looks very realistic. You reach out to touch it, and fall into it. You look around and see that you are now in an identical, but mirrored room.\nYou feel as if your world is now somehow bigger\n" << endl;
        zoom = true;
        return 2;
        break;

      case 2:
        return 1;
        break;

      case 3:
        return 4;
        break;
    }
  }
  return 0;
}

int room1(){ //Start
  showMap(1);
  int choice = 0;
  cout << "You enter a grand room with marble floors, a table with a candle, and a large golden pot in the corner. What would you like to do?\n"
     << "1) Investigate the pot\n"
     << "2) Investigate the candle\n"
     << "3) Go left\n"
     << "4) Go right\n"
     << "5) Go up\n";

  //While no movement action is chosen
  while(choice < 3){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 5){
      badInput();
  }
    switch(choice){
      case 1:
        //Explore pot
        printImage("pot");
        if(exploredPots == false){
          cout << "You found 10 gold!" << endl;
          gold += 10;
          exploredPots = true;
        } else {
          cout << "It's empty." << endl;
        }
        break;

      case 2:
        cout << "Yup. That's a candle" << endl;
        printImage("candle");
        break;

      //Left
      case 3:
        return 0;
      
      //Right
      case 4:
        return 2;

      //Up
      case 5:
        return 5;
    }
  }
  return 0;
}

int room2(){ //Skeleton

  showMap(2);
  int choice = 0;
  char talk = ' ';

  cout << "You see a skeleton sitting in the corner and a small painting on the wall.\nWould you like to do?\n"
     << "1) Investigate the skeleton\n"
     << "2) Investigate the painting\n"
     << "3) Go left\n";

  //While no movement choice is made  
  while(choice < 2){
    //Validate input
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 3){
      badInput();
    }
    switch(choice){
      case 1:
        //Explore skeleton
        if(talkedToSkelly == false){
          printImage("skelly");
          cout << "As you approach the skelton, he wakes up.\n"
            << "Skeleton: My name is Dr. Bones! You're the first person I've talked to in decades! I'll offer you some help, if you answer my riddle NYEHEHEHE\n";
          
          //Get input
          while(cout << "Answer the riddle? (y/n): " && !(cin >> talk)){
            badInput();
          }

          //If player talks to skelton
          if(talk == 'y'){

            //Skelly's riddle
            cout << "Dr. Bones: What is a skeleton's favorite snack?\n"
              << "1) Nothing. Skeletons can't eat!\n"
              << "2) Milk to make the bones strong!\n"
              << "3) Spare ribs!\n";

            //Handle bad input
            while(cout << "> " && !(cin >> talk)){
              badInput();
            }

            //Logic
            if(talk == '3' && talkedToSkelly == false){
              cout << "Dr. Bones: Congrats! You've answered correctly! 10 gold for you!" << endl;
              gold += 10;
            } else {
              cout << "Dr. Bones: WHY MUST YOU ALWAYS FAIL ME! You've hit my funny bone. Im not talking to you anymore >:(" << endl;
            }
            talkedToSkelly = true;
          }
        //If user has talked to skeleton
        } else {
          cout << "Mr. Bones seems disinterested..." << endl;
        }
        return 2;

      case 2:
        printPainting(false);
        cout << "The painting looks very realistic. You reach out to touch it, and fall into it. You look around and see that you are now in an identical, but mirrored room.\nYou feel as if your world is somehow smaller.\n" << endl;  
        zoom = false;
        return 0;

      case 3:
        return 1;
    }
  }
  return 0;
}

int room3(){ //Mimic
  showMap(3);
  int choice = 0;
  cout << "A single chest lies in the room. What would you like to do?\n"
     << "1) Investigate the chest\n"
     << "2) Go up\n"
     << "3) Go right\n";

  //While no movement action is chosen
  while(choice < 3){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 5){
      badInput();
  }
    switch(choice){
      case 1:
        //Explore chest
        if(foughtMimic == false){
          printImage("chest");
          cout << "As you reach to open the chest, it lunges at you! You've been attacked by a mimic!" << endl;
          //Go to combat, mimic has 50 health and does 5 damage
          combat("Mimic", 50, 5);
          foughtMimic = true;
          //Compensate player
          cout << "The mimic dropped 5 gold!" << endl;
          gold += 5;
          return 3;
        } else {
          cout << "It's a dead mimic." << endl;
        }
        break;

      //Up
      case 2:
        return 6;
        break;

      //Right
      case 3:
        return 4;
        break;
    }
  }
  return 0;
}

int room4(){ //Empty
  showMap(4);
  int choice = 0;
  cout << "The room is completely empty, save for the painting on the wall. What would you like to do?\n"
     << "1) Investigate the painting\n"
     << "2) Go right\n"
     << "3) Go left\n"
     << "4) Go down\n";

  //While no movement action is chosen
  while(choice < 2){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 4){
      badInput();
  }
    switch(choice){
      case 1:
        //Explore painting
        printPainting(false);
        cout << "It's quite a nice painting. It makes your world feel different." << endl;
        zoom = !zoom;
        return 4;
        break;

      //right
      case 2:
        return 5;
        break;

      //Left
      case 3:
        return 3;
        break;
      
      //down
      case 4:
        return 0;
        break;
    }
  }
  return 0;
}

int room5(){ //Pillar
  showMap(5);
  int choice = 0;
  cout << "The room is quite empty. Large quartz pillars line the walls, but nothing stands out. What would you like to do?\n"
     << "1) Investigate the pillars\n"
     << "2) Go up\n"
     << "3) Go left\n"
     << "4) Go down\n";

  //While no movement action is chosen
  while(choice < 2){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 4){
      badInput();
  }
    switch(choice){
      case 1:
        //Explore pillars
        printImage("pillar");
        cout << "The pillars are Ionic. Nice" << endl;
        break;

      //up
      case 2:
        return 7;
        break;

      //Left
      case 3:
        return 4;
        break;
      
      //Down
      case 4:
        return 1;
        break;
    }
  }
  return 0;
}

int room6(){ //Octopus
  showMap(6);
  int choice = 0;
  char talk;
  cout << "You enter a small room that has a small ledge to walk on. Beyond this ledge is a decently sized pool. You can't see the bottom. What would you like to do?\n"
     << "1) Investigate the pool\n"
     << "2) Go down\n";

  //While no movement action is chosen
  while(choice < 2){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 2){
      badInput();
  }
    switch(choice){
      case 1:
        //Explore skeleton
        if(talkedToOcky == false){
          printImage("ocky");
          cout << "As you peer over the edge of the pool, the water becomes uneven. A massive octopus reveals itself!.\n"
            << "Octopus: What is it that you seek, my dear? My name is Octavia and if you solve my puzzle, I can help you however you please.\n";
          
          //Get input
          while(cout << "Answer the riddle? (y/n): " && !(cin >> talk)){
            badInput();
          }

          //If player talks to skelton
          if(talk == 'y'){

            //Skelly's riddle
            cout << "Octavia: How many tickles does it take to make an octopus laugh?\n"
              << "1) 8, since octopuses have 8 tentacles!\n"
              << "2) None. Octopuses can't laugh.\n"
              << "3) Actually only 1. It's surprisingly easy to get an octopus to laugh.\n"
              << "4) 10 Tickles!\n";

            //Handle bad input
            while(cout << "> " && !(cin >> talk)){
              badInput();
            }

            //Logic
            if(talk == '4' && talkedToOcky == false){
              cout << "Octavia: Fantastic job my dear! Oh how I've missed being tickled. Could you indulge me for just a moment?" << endl;
              while(cout << "Tickle Octavia? (y/n): " && !(cin >> talk))
              {
                badInput();
              }
              if(talk == 'y'){
                cout << "Octavia: HAHAHAHAHHAHA THANK YOU MY DEAR! I forgot what it felt like to laugh. Here, take this as my gratitude.\n"
                << "+10 gold!\n";
                gold += 10;
              } else {
                cout << "Octavia: Oh, I suppose that's alright. Thank you for answering my riddle. Take this for your troubles.\n"
                << "+5 gold!\n";
                gold += 5;
              }
              talk = 4;
            } else {
              cout << "Octavia: WRONG. YOU STUPID HUMANS ARE ALWAYS WRONG. ITS TEN LIKE TENTACLE.\n"
              << "Octavia sinks into the depths.\n";
            }
            talkedToOcky = true;
          }
        //If user has talked to octavia
        } else {
          cout << "The waters seem infinitely deep. Nothing is coming up." << endl;
        }
        return 6;
        break;

      case 2:
        return 3;
        break;
    }
  }
  return 0;
}

int room7(){ //Mirror
  showMap(7);
  int choice = 0;
  cout << "The room is mostly empty, however you see a sign on the wall and a mirror on another wall. There is also a locked door in front of you. What would you like to do?\n"
     << "1) Investigate the mirror\n"
     << "2) Investigate the sign\n"
     << "3) Investigate the door\n"
     << "4) Go down\n"
     << "5) Go right\n";

  //While no movement action is chosen
  while(choice < 4){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 5){
      badInput();
  }
    switch(choice){
      //Explore mirror
      case 1:
        cout << "You look in the mirror. It's you!\n";
        printImage("dunk");
        if(lookedInMirror == false){
          cout << "Seeing yourself fills you with courage. +10 health\n";
          health += 10;
          lookedInMirror = true;
        } else {
          cout << "You're filled with courage, but not as much as before\n";
        }
        
        break;

      //Check sign
      case 2:
        printImage("sign");
        break;

      //Check door
      case 3:
        printImage("door");
        if(hasKey == true){
          cout << "You use the key to unlock the door.\n";
          return 9;
        } else {
          cout << "The door seems locked\n";
        }
        break;
      
      //Down
      case 4:
        return 5;
        break;

      //Right
      case 5:
        return 8;
        break;
    }
  }
  return 0;
}

int room8(){ //Shop
  showMap(8);
  int choice = 0;
  char talk = ' ';
  bool discount = false;

  cout << "You enter a room. The only thing in it is a creature working it's shop. What would you like to do?\n"
     << "1) Investigate the shop\n"
     << "2) Go left\n";

  //While no movement action is chosen
  while(choice < 2){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 2){
      badInput();
  }
    switch(choice){
      case 1:
        //Investigate shop
        printImage("shop");
        cout << "As you approach the shopkeeper, it perks up to talk to you.\n"
          << "Shopkeeper: My name is Earl. I have wares, if you have coin!\n";

          //Get input
          while(cout << "Go shopping? (y/n): " && !(cin >> talk)){
            badInput();
          }

          //If player talks to shopkeep
          if(talk == 'y'){

            //Shopkeep dialogue
            if(talkedToOcky && talkedToSkelly && foughtMimic && exploredPots && gold < 25){
                cout << "Earl: You know what, you seem like a good fellow. You've helped us out with that mimic and you've talked to Octavia and Dr. Bones"
                << ", and they both needed a friend. Just this once, you can have the key for " << gold << " gold. How's that?\n";
                discount = true;
            } else {
                cout << "Earl: What would you like to purchase? I have a health potion (10 gold), and a key (25 gold).\n";
            }
              cout << "1) Health potion\n"
              << "2) Key\n"
              << "3) Leave shop\n"
              << "Gold: " << gold << endl;

            //Handle bad input
            while(cout << "> " && !(cin >> talk)){
              badInput();
            }

            //Leave
            if(talk == '3'){
              cout << "Earl: See you again soon\n" << endl;
            //Key
            } else if (talk == '2' && hasKey == false){
              if(gold >= 25){
                cout << "Earl: Here's your key kind sir." << endl;
                gold -= 25;
                hasKey = true;
              } else if(discount == true){
                cout << "Earl: Here's your key. Pay it back by freeing us." << endl;
                gold -= gold;
                hasKey = true;
              } else {
                cout << "Earl: You can't buy that. Get out of my shop\n";
              }
          
            //Potion
            } else if(talk == '1' && gold >= 10 && hasPotion == false){
              cout << "Shopkeep: It's too strong for a dragon, let alone a man, but I'll let you have it\n"
               << "*You drink the health potion. +25 health!\n";
              hasPotion = true;
              gold -= 10;
              health += 25;
            } else {
              cout << "Earl: You can't buy that. Get out of my shop\n";
            }
          }
          return 8;
          break;

      case 2:
        return 7;
        break;

    }
  }
  return 0;
}

int room9(){ //Boss
  showMap(9);
  int choice = 0;
  cout << "You enter a grand room with marble floors, a golden chandelier, and a large throne in the center. Sitting on the throne is a large, misshapen purple demon. \nWhat would you like to do?\n"
     << "1) Investigate the demon\n"
     << "2) Go down\n";

  //While no movement action is chosen
  while(choice < 2){
    while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 2){
      badInput();
  }
    switch(choice){
      case 1:
        //Explore boss
        
        printImage("demon");
        cout << "Demon: Ha! I knew you'd come one day. I've heard about you my whole life. You, the tiny little dunk would topple me?\n"
        << " I don't think so! You've heard of my brother, the one-eyed one-horned flying purple people eater. Now, get ready for\n"
        <<" THE TWO-EYED TWO-HORNED GROUNDED PURPLE PEOPLE EATER!!! Dunk, prepare to get eaten.\n";
        //Go to combat, mimic has 50 health and does 5 damage
        combat("Demon", 100, 10);
        return 10;
        break;

      //Up
      case 2:
        return 6;
        break;
    }
  }
  return 0;
}