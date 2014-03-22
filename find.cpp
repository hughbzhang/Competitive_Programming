#include <iostream>
#include <cmath>

using namespace std;

int num,top;
int total = 0;

int main(){
    cin >> num >> top;
    for(int x = 0;x<num;x++){
        int temp;
        cin >> temp;
        total+=temp;
    }
    cout << ceil(abs(total)/(double)top) << endl;
}
