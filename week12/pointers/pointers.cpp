/*
Jake Gendreau
Nov 3
Pointer Program
Played with void* a bit and used malloc and free
added menu system along with appropriate function calls
functionalized software so it's not just a wall of text
*/

#include <iostream>
#include <limits>

using namespace std;

void incrementX(int*);
void badInput();

void createDescribe(int*);
int* changePtr(int*, int*);
void changeVar(int*, int*);
void changeFunc(int*, int*);
void voidStar();
void arrays();

int main(){

    //Establish vars
    int choice = 0;
    int* ptr;
    int x = 65;

    //Menu
    do{
        cout << "Welcome to the Powerful Pointer Program. What would you like to learn about?\n"
            << "1) Creation / description of pointers\n"
            << "2) Changing pointer values\n"
            << "3) Changing variable value using pointers\n"
            << "4) Changing variable value using a function\n"
            << "5) Void pointers\n"
            << "6) The relationship between pointers and arrays\n"
            << "7) Exit program\n";

        //Validate input
        while(cout << "> " && !(cin >> choice)){
            badInput();
        }

        switch(choice){
            case 1:
                //How to create a pointer and what they
                createDescribe(ptr);
                break;

            case 2:
                //Demonstrate pointer changing its value
                ptr = changePtr(ptr, &x);
                break;

            case 3:
                //Demonstrate changing value of x with ptr
                changeVar(ptr, &x);
                break;

            case 4:
                //Change value of x with a function
                changeFunc(ptr, &x);
                break;

            case 5:
                //Void*
                voidStar();
                break;

            case 6:
                //arrays and pointers
                arrays();
                break;
        }

        cout << endl;

    }while(choice != 7);

}

void createDescribe(int* ptr){
    //How to create a pointer and what they do
    cout << "A pointer is a special type of variable that stores the address of a chunk of memory associated with a variable.\n"
        << "They are created using the \"*\" character. For example:\n"
        << "int* ptr;\n"
        << "Creates a variable called \"ptr\" that stores the address of an int.\n"
        << "The current value of ptr is " << ptr << endl;

}

int* changePtr(int* ptr, int* x){
    //Demonstrate pointer changing its value
    cout << "The pointer \"ptr\" stores a random address at the moment\n"
        << "Now, I will change it to point at the int x using the following command:\n"
        << "ptr = &x;\n"
        << "It is important to remember that a pointer stores an address, so to get an address of a variable, the character \"&\" should be used\n"
        << "A good way to remember this is that \"&\" means \"andress\"\n";
    ptr = x;
    cout << "The new value of ptr is " << ptr << endl;
    return ptr;
}

void changeVar(int* ptr, int* x){
    //Demonstrate changing value of x with ptr
    cout << "The value of other variables can also be changed by use of a pointer.\n"
        << "Using the \"*\" character again, we can do something called a \"dereference\"\n"
        << "A dereference allows us to change the value of the integer at the address in the pointer\n"
        << "At the moment, x = " << *x << "\n"
        << "We can make ptr point to x by using\n"
        << "ptr = &x\n"
        << "Since ptr is pointing to x, we can use\n"
        << "*ptr = x+1;\n"
        << "to increment x by 1\n";
    ptr = x;
    *ptr = (*x)+1;
    cout << "The new value of x is " << *x << endl;
}

void changeFunc(int* ptr, int* x){
    //Change value of x with a function
    cout << "A function can be used to change the value of x without ever passing in x. We can make ptr store the address of x using\n"
        << "ptr = &x;\n"
        << "Then we can create a function.\n\n"
        << "void incrementX(int* ptr){\n"
        << "\t *ptr += 1;\n"
        << "}\n\n"
        << "Before calling the function, the value of x is " << *x << endl;
    ptr = x;
    incrementX(ptr);
    cout << "After, the value of x is " << *x << endl;
}

void voidStar(){
    //Void pointers
    void* ptr2 = malloc(1);
    cout << "A void pointer acts very similarly to any other type of pointer, but it can point to anything, functions or variables, or just memory.\n"
        << "I will use malloc() to call a chunk of memory and use the void* to point to it by using\n"
        << "ptr2 = malloc(1);\n"
        << "malloc calls 1 byte of memory and returns a void pointer to that memory\n"
        << "The current address of ptr2 is " << ptr2 << endl
        << "The current value of ptr2 is " << *(bool*)ptr2 << endl
        << "Remember to always use free() when using malloc!\n";
    free(ptr2);
}

void arrays(){
    //How pointers and arrays are related
    int myArr[4];
    for(int i=0; i<4; i++){
        myArr[i] = i;
    }
    cout << "When an array is defined, such as using\n"
        << "int myArr[4];\n"
        << "A pointer to a chunk of memory with 4*sizeof(int) is created. So, we can print the address of the array using\n"
        << "cout << &myArr << endl;\n"
        << "This value is " << myArr << endl
        << "This memory points to the rest of the array.\n"
        << "The [i] notation for arrays is a simplification of pointer arithmetic. By multiplying i by the size of the datatype, one can find the address of each piece of data in the array.\n"
        << "Visualization (Each set of square brackets represents a new piece of memory): [myArr][myArr + 1][myArr + 2][...][myArr + n]";

    cout << "For example, the value of the array at i = 0 can be obtained using myArr[0], and that value is " << myArr[0] << endl
        << "Now, the same value can be found by using *myArr. This value is " << *myArr << endl
        << "Now, finding the value at i = 1 using traditional means gives " << myArr[1] << endl
        << "Finding any value using pointer arithmetic means using *(myArr + i). For i = 1, this value is " << *(myArr + 1) << endl;
}

void incrementX(int* ptr){
    *ptr += 1;
}

void badInput(){
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}
