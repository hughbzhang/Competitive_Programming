/*
ID: bigfish2
LANG: C++
TASK: gift1
*/ 

#include <iostream>
#include <string>
#include <fstream>

#define MAX 10

using namespace std;


string names[MAX];
int money[MAX];
int num = 0;

int find(string name){
    for(int x = 0;x<num;x++){
        if(name==names[x]) return (x);
    }
    return -1;
}


int main(){
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    fin >> num;
    for(int x = 0;x<num;x++){
        fin >> names[x];
    }
    

    string next;
    int a, b;
    for(int x = 0;x<num;x++){
        fin >> next;
        int index = find(next);
        fin >> a >> b;
        if(b==0) continue;
        money[index]+=a%b;
        money[index]-=a;
        int give = a/b;
       // int give = 2;
        for(int x = 0;x<b;x++){
            fin >> next;
            money[find(next)]+=give;
        }
    }
    for(int x = 0;x<num;x++){
        fout << names[x] << " " << money[x] << "\n";
    }


    return 0;
}
