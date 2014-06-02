#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <utility>
#define A first
#define B second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,bool> pii;
typedef struct {
  int img[120][250];
} Image;

char scratch[1000];
Image cur;
int numgood = 190;
int numbad = 210;
Image GOOD[400];
Image BAD[400];
pii arr[500];

bool diff(Image& I){
    int in = 0;
    for(int a = 0;a<numgood;a++){
        ll ans = 0;
        for(int x = 0;x<250;x++){
            for(int y = 0;y<120;y++){
                ans+=abs(I.img[y][x]-GOOD[a].img[y][x]);
            }
        }
        arr[in++] = pii(ans,1);
    }
    for(int a = 0;a<numbad;a++){

        ll ans = 0;
        for(int x = 0;x<250;x++){
            for(int y = 0;y<120;y++){
                ans+=abs(I.img[y][x]-GOOD[a].img[y][x]);
            }
        }
        arr[in++] = pii(ans,0);
    }
    sort(arr,arr+400);
    int vict = 0;
    for(int x = 0;x<9;x++){
         if(arr[x].B==0) vict++;
        else vict--;
    }
    if(vict>0) return true;
    else return false;
}

ll dark(Image& I){
    ll ans = 0;
    for(int x = 1;x<249;x++){
        for(int y = 1;y<59;y++){
            ans+=I.img[y][x];
        }
    }

    for(int x = 1;x<249;x++){
        for(int y = 61;y<119;y++){
            ans-=I.img[y][x];
        }
    }
    return ans;
}

ll reflect(Image& I){
    ll ans = 0;
    for(int x = 0;x<250;x++){
        for(int y = 0;y<60;y++){
            ans+=((I.img[y][x]-I.img[119-y][x])*(I.img[y][x]-I.img[119-y][x]));
        }
    }
    return ans;
}
ll contrast(Image& I){
    ll ans = 0;
    for(int x = 1;x<249;x++){
        for(int y = 1;y<59;y++){
            ans+=(I.img[y+1][x]+I.img[y-1][x]+I.img[y][x+1]+I.img[y][x-1]);
            ans-=(4*I.img[y][x]);
        }
    }

    for(int x = 1;x<249;x++){
        for(int y = 61;y<119;y++){
            ans-=(I.img[y+1][x]+I.img[y-1][x]+I.img[y][x+1]+I.img[y][x-1]);
            ans+=(4*I.img[y][x]);
        }
    }
    return ans;
}
ll third(Image& I){
    ll ans = 0;
    for(int x = 1;x<100;x++){
        for(int y = 1;y<59;y++){
            ans+=(I.img[y+1][x]+I.img[y-1][x]+I.img[y][x+1]+I.img[y][x-1]);
            ans-=(4*I.img[y][x]);
        }
    }

    for(int x = 1;x<100;x++){
        for(int y = 61;y<119;y++){
            ans-=(I.img[y+1][x]+I.img[y-1][x]+I.img[y][x+1]+I.img[y][x-1]);
            ans+=(4*I.img[y][x]);
        }
    }
    return ans;
}

void flip(Image& x){
  for(int i = 0; i < 60; i++){
    for(int j = 0; j < 250; j++){
      x.img[i][j] ^= x.img[119-i][j];
      x.img[119-i][j] ^= x.img[i][j];
      x.img[i][j] ^= x.img[119-i][j];
    }
  }
}

int main(){
  FILE *fout = fopen("out.txt", "w");
  int correct = 0;
  ll bad = 0;
  ll good = 0;
  int numg = 0;
  int numb = 0;
  int FP = 0;
  int FN = 0;
  ll mid = 1000000000;
  for(int t = 1; t <= 800; t++){
    //printf("t: %d\n", t);
    sprintf(scratch, "airplanes-txt/image_%04d.txt", t);
    //printf("%s\n", scratch);
    FILE *fin = fopen(scratch, "r");
    fscanf(fin, "%s", scratch);
    bool up = scratch[0] == 'U';
    for(int i = 0; i < 120; i++){
      for(int j = 0; j < 250; j++){
        fscanf(fin, "%d", &cur.img[i][j]);
      }
    }
    /*if(t <= 400){
      if(!up) flip(cur);
      // image has been flipped to be rightside-up; do something here to train
    } else {
      bool guess = false;
      correct += (up == guess);
      printf("%d / %d\n", correct, t-400);
    }*/
    if(t<=400){
        if(up){
            GOOD[numg++] = cur;
        }
        else{
            BAD[numb++] = cur;
        }
    }
    if(t>400){
        bool guess = diff(cur);
        if(guess==up) correct++;
        if(guess&&!up) FP++;
        if(!guess&&up) FN++;
    }
    fprintf(fout,"%d %d\n",up,third(cur));

    fclose(fin);
  }
  //cout << good/(ld)numgood << endl;
  //cout << bad/(ld)numbad << endl;
  printf("Correct: %d / 400\n", correct);
  printf("FP: %d / 400\n", FP);
  printf("FN: %d / 400\n", FN);
  
  
  printf("Score: %.1f/10.0\n", 10*max(correct - 200.0, 0.0)/200.0);
  return 0;
}
