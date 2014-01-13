#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    double a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    int answer = ceil(a/c)*ceil(b/c);
    printf("%d", answer);

    return 0;
}
