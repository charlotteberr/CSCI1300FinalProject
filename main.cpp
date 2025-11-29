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
    int index=0;
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

            characterInfo[index]=Player(n, exp, acc, eff, ins, dp);
            index++;
        }
    }
    inFile.close();

    cout<<"Welcome to the Journey Through the Genome!"<<endl;
    cout<<"Here we have the 5 characters to choose from..."<<endl;
    cout<<endl;
    for(int i=0;i<5;i++){  //display all 5 characters info
        cout<<i+1<<". ";
        cout<<characterInfo[i].getName()<<" | Experience: "<<characterInfo[i].getExperience();
        cout<<" | Accuracy: "<<characterInfo[i].getAccuracy()<<" | Efficiency: "<<characterInfo[i].getEfficiency();
        cout<<" | Insight: "<<characterInfo[i].getInsight()<<" | DP: "<<characterInfo[i].getDiscoveryPts()<<endl;
    }

    cout<<"PLAYER 1, choose your character (Type a number 1-5): ";
    int choice1;
    cin>>choice1;
    players[0]=characterInfo[choice1-1];
    cout<<"PLAYER 2, choose your character (Type a number 1-5, not including "<<choice1<<"): ";
    int choice2;
    cin>>choice2;
    while(choice1==choice2){
        cout<<"Choose a different character that is not being used byt PLAYER 1: ";
        cin>>choice2;
    }
    players[1]=characterInfo[choice2-1];
}