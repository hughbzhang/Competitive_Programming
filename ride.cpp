/*
ID: bigfish2
LANG: C++
TASK: ride
*/ 

#include <iostream>
#include <string>
#include <fstream>

#define endl "\n"

using namespace std;

int main(){
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");
    
    string one, two;
    fin >> one >> two;
    int pro = 1, pro1 = 1;
        
    for(int x = 0;x<one.length();x++){
        pro *= one.at(x)-64;
    }    
        
    for(int x = 0;x<two.length();x++){
        pro1 *= two.at(x)-64;
    }    
    if(pro1%47==pro%47) fout << "GO" << endl;
    else fout << "STAY" << endl; 

    return 0;
}

