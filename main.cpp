#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Board.h"
#include "Player.h"

using namespace std;

vector<string> split(string line, char delimiter){
    vector<string> parts;
    string temp="";
    for(int i=0;i<line.length();i++){
        if(line[i]==delimiter){
            parts.push_back(temp);
            temp="";
        }
        else{
            temp+=line[i];

        }
    }
    parts.push_back(temp);
    return parts;
}

int main(){
    srand(time(0));
    Board board;
    Player characterInfo[5]; //for reading in characters.txt
    Player players[2];

    ifstream inFile;
    inFile.open("characters.txt");
    string line;
    int i=0;
    if(inFile.fail()){
        cout<<"Error opening characters.txt"<<endl;
        return 1;
    }
    else{
        while(getline(inFile, line)){    // loads the 5 characters and their stats in characters.txt into an index of characterInfo
            vector<string> parts=split(line,'|');
            string n=parts[0];
            int exp=stoi(parts[1]);
            int acc=stoi(parts[2]);
            int eff=stoi(parts[3]);
            int ins=stoi(parts[4]);
            int dp=stoi(parts[5]);

            characterInfo[i]=Player(n, exp, acc, eff, ins, dp);
            i++;
        }
    }

}