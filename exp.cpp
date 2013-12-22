#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    ifstream fin ("exp.txt");
    int one, two;
    char buf;
    double max = 0;
    double temp = 0;
    int best = -1;
    for(int x = 1;x<=1000;x++){
        fin >> one >> buf >> two;
        temp = two*log10(one);
        if(temp>max){
            max = temp;
            best = x;
        }
    }

    cout << best << endl;

    return 0;
}
