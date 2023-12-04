/* Ascii art program -
 * a simple program introducing some
 * fundamental programming concepts.
 * Jake Gendreau
 * Section 01
 * 8/29/23
 * Lab 1
 * 
 * 
 * I will attempt to make an ASCII art cat.
 * We will see how it goes.
 */

#include<iostream> //include a library
#include<string>
#include<cstring>
using namespace std;
int main() //main starts the program
{
    string cat = "   /\\                    /\\   \n"
        "  /  \\__________________/  \\  \n"
        " /    \\                /    \\ \n"
        "|                            |\n"
        "|                            |\n"
        "|    ( 0 )          ( 0 )    |\n"
        "|                            |\n"
        "|         ====XX====         |\n"
        "\\             ||             /\n"
        " \\      \\_____/\\____/       /\n"
        "  \\________________________/  \n"
        "    |                    |    \n"
        "    /                     \\   \n"
        "   |                       |  \n"
        "   |   |      |   |         \\ \n"
        "   |   |      |   |          \\\n"
        "   /  /       |   |          |\n"
        "  |   |       |   |          |\n"
        "  |   |       |   | _______/ |\n"
        "  (|||)_______(|||)(_________/\n";
    //ASCII art must be 30 wide by 20 tall
    //Determine horizontal and vertical dimensions of string
    int catlen = strlen(cat.c_str());
    int width = 0;
    int height = 0;

    //count rows
    for(int i = 0; i < catlen; i++){
        if(cat[i] == '\n'){
            height += 1;
        }
    }

    //determine columns, assuming uniform row length
    width = catlen / height;
    printf("Dimensions of image (determined mathematically):\n"
        "Width: %i\n"
        "Height: %i\n", catlen / height, catlen / width);
    printf("\n");
    printf("%s", cat.c_str());
}