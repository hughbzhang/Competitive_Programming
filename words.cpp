#include <fstream>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;


bool isTri(int cur){
    cur*=2;
    double temp = sqrt(cur);
    int one = floor(temp);
    int two = ceil(temp);
    if(one==two) return false;
    if(one*two==cur) return true;
    else return false;
}

int main(){
    
   ifstream fin ("words.txt");
   string total;
   fin >> total;
   int cur = 0;
   int ans = 0;
   for(int x = 1;x<total.length();x++){
      if(total.at(x)=='"'){
          if(isTri(cur)) ans++;
          cur = 0;
          x+=2;
      }
      else cur+=total.at(x)-64;
   }
   cout << ans << endl;
    
    return 0;

}
