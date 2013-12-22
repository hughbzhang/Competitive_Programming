/*
ID: bigfish2
LANG: C++
TASK: sec
*/ 

#include <iostream>
#include <string>
#include <fstream>

#define endl "\n"
#define MAXN 500100
#define p(x) fout << x << " "

using namespace std;



ifstream fin ("sec.in");
ofstream fout ("sec.out");

int children[MAXN][2];
int down[MAXN];//number of decendants that are ancestors excluding self
int end[MAXN];//true if this node is the end of a code. false otherwise
int cnt = 0;

int getchild(int cur, int next){//get the child of the current node
//with next string
    int &point = children[cur][next];//&sign is essentially making the int tied together with the array. So when point changes so does children
    if(point==0){//if point doesnt exist
        point = ++cnt;//make it
    }
    return point;


}

int find(){
    int length;
    fin >> length;
    int cur = 0;
    int next = 0;
    int count = 0;
    for(int x = 0;x<length;x++){
        fin >> next;
        cur = getchild(cur, next);
        if(end[cur]) count+=end[cur];
    }
    //at this point cur is at the end and we can just print the ancestor+dec
    fout << down[cur]+count << endl;
}

int main(){
    
    int messages, codes, length, in;
    fin >> messages >> codes;
    int cur = 0;
    for(int x = 0;x<messages;x++){
        fin >> length;
        cur = 0;
        for(int a = 0;a<length;a++){
            down[cur]++;//every node you visit must have you as a decendant
            //note that yourself does not get a decendant bonus
            fin >> in;
            cur = getchild(cur, in);
        }
        end[cur]++;
    }
    for(int x = 0;x<codes;x++){
        find();
    }
    

    return 0;
}

