#include <cstdio>
#include <cmath>
#include <iostream>
#include <utility>

#define A first
#define B second

using namespace std;
typedef int num;
typedef long double ld;
typedef pair<num,num> pii;

const ld sigma = 1e-10;

bool equal(ld one, ld two){ if(abs(one-two)<sigma) return true; else return false;}

class vec{
    public:
    num x;
    num y; 
    num z;
    vec(num a,num b, num c){ x = a; y = b; z = c;}
    ld length(){ return sqrt(this->x*this->x+this->y*this->y+this->z*this->z);}
    vec add(vec two){ return vec(this->x+two.x,this->y+two.y,this->z+two.z);}
    num dot(vec two){ return this->x*two.x+this->y*two.y+this->z*two.z;}
    vec cross(vec two){ return vec(this->y*two.z-this->z*two.y,this->z*two.x-this->x*two.z,this->x*two.y-this->y*two.x);}
    bool parallel(vec two){ if(equal(cross(two).length(),0)) return true; else return false;}
    
};


void print(vec in){ cout << in.x << " " << in.y << " " << in.z << "\n";}
ld area(num X1, num Y1, num X2, num Y2, num X3, num Y3){//area of triangle with these three points
    vec one = vec(X2-X1,Y2-Y1,0);
    vec two = vec(X3-X1,Y3-Y1,0);
    return 0.5*one.cross(two).length();
}
ld dist(num X1, num Y1, num X2, num Y2, num PX, num PY){//dist from Point(X,Y) to line
    vec one = vec(PX-X1,PY-Y1,0);
    vec two = vec(X2-X1,Y2-Y1,0);
    return one.cross(two).length()/two.length();
}
ld angle(pii top, pii mid, pii bot){//mid is the vertex ALL THREE POINTS MUST BE UNIQUE
    vec one = vec(top.A-mid.A,top.B-mid.B,0);
    vec two = vec(bot.A-mid.A,bot.B-mid.B,0);
    return acos(one.dot(two)/(one.length()*two.length()));
}


int main(){
    //vec one = vec(2,0,0);
    //vec two = vec(1,0,0);
    pii one = pii(0,0);
    pii two = pii(0,0);
    pii thr = pii(0,1);
    cout << angle(two,one,thr) << endl;
    return 0;
}

