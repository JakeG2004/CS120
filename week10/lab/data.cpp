#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class day{
    public:
        int day;
        double high;
        double low;
        double precipitation;
        double snow;
        double snowDepth;

};

double lowTemp(day[], int);
double avgLow(day[], int);
double highTemp(day[], int);
double avgHigh(day[], int);
void snowChange(day[], int);

int main(int argc, char* argv[]){

    int rows = 0;

    if(argc != 2){
        cout << "Improper usage! Usage: ./data.out <infile.txt>" << endl;
        exit(1);
    }
    //Open file
    ifstream infile;
    infile.open(argv[1]);

    //Report error if file can't open
    if(!(infile)){
        cout << "Error opening file" << argv[1] << endl;
        exit(2);
    }

    //Get rows
    string line;
    while(getline(infile, line)){
        rows++;
    }

    day data[rows];

    //Reset getline position
    infile.clear();
    infile.seekg(0, ios_base::beg);

    getline(infile, line);

    int i=0;
    //Load everything into an aray of objects
    while (getline(infile, line, '\t')) {
        //Make the date usable as an int
        int pos = line.find(' ');
        line = (line.substr(0, pos));
        line.erase(remove(line.begin(), line.end(), '\n'), line.cend());

        data[i].day = stoi(line);

        infile >> data[i].high;
        infile >> data[i].low;
        infile >> data[i].precipitation;
        infile >> data[i].snow;
        infile >> data[i].snowDepth;
        if(i < rows)
            i++;
    }

    cout << "The lowest recorded temperature in the data set is " << lowTemp(data, rows) << endl;
    cout << "The average low temperature in the data set is " << avgLow(data, rows) << endl << endl;
    cout << "The highest recorded temperature in the data set is " << highTemp(data, rows) << endl;
    cout << "The average high temperature in the data set is " << avgHigh(data, rows) << endl << endl;
    snowChange(data, rows);
}

double lowTemp(day data[], int rows){
    double lowest = 100;

    //Linear search
    for(int i=0; i<rows - 1; i++){
        if(data[i].low < lowest){
            lowest = data[i].low;
        }
    }
    return lowest;
}

double highTemp(day data[], int rows){
    double highest = -100;

    //Linear search
    for(int i=0; i<rows - 1; i++){
        if(data[i].high > highest){
            highest = data[i].high;
        }
    }
    return highest;
}

double avgLow(day data[], int rows){
    double avg;
    for(int i=0; i<rows - 1; i++){
        avg += data[i].low;
    }
    return avg / rows;
}

double avgHigh(day data[], int rows){
    double avg;
    for(int i=0; i<rows - 1; i++){
        avg += data[i].high;
    }
    return avg / rows;
}

void snowChange(day data[], int rows){
    cout << "DAY\tSNOW CHANGE" << endl;
    cout << data[0].day << "\t" << data[0].snowDepth << endl;
    for(int i=1; i<rows - 1; i++){
        cout << data[i].day << "\t" << data[i].snowDepth - data[i-1].snowDepth << endl;
    }
    cout << endl;
}