#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){
  FILE *fkey = fopen("findroad.key", "r");
  FILE *fout = fopen("findroad.out", "r");
  FILE *fnew = fopen("newkey", "w");
  int R,C;
  fscanf(fkey, "%d%d", &R, &C);
  fprintf(fnew, "%d %d\n", R, C);
  int both = 0, either = 0;
  for(int i=0;i<R;i++){for(int j=0;j<C;j++){
    char d=' ',c=' ';
    do fscanf(fkey,"%c",&d); while(!feof(fkey) && d != 'y' && d != 'n');
    if(d != 'y' && d != 'n') { printf("BAD KEY\n"); return 0; }
    //printf("i j d: %d %d %c\n", i, j, d);
    do fscanf(fout,"%c",&c); while(!feof(fout) && c != 'y' && c != 'n');
    if(c != 'y' && c != 'n') { printf("ERROR \n"); return 0; }
    both += c == 'y' && d == 'y';
    either += c == 'y' || d == 'y';
    fprintf(fnew, "%c", d);
  } fprintf(fnew, "\n"); }
  double score = max(0.0, min(5.0, 10.0 * (both * 1.0 / either - 0.2)));
  printf("score: %d/%d = %.2f (out of 5.00)\n", both, either, score);
  return 0;
}
