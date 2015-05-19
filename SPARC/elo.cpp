#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <utility>

#define A first
#define B second

using namespace std;
typedef pair<int,int> pii;

const double startElo = 4.0;//chess starting elo is ~1500 but it has a /400 factor
const double K = 0.3;


//CHANGE THIS BETWEEN SETS
const string filename = "resultsC.txt";
const int players = 16;

//20 for A
//17 for B
//16 for C


class team{
    public:
        int ID;
        double rating;
        double win; //# of games won, draw is 0.5
        int game; // # of games played
        double SOS; // average ELO of opponent
        vector<pii> opp;
        int h2h[30];
        team(){
            rating = startElo;
            win = 0;
            game = 0;
            SOS = 0;
        }
        bool operator<(team other) const{  // reverse sorting
            return rating > other.rating;
        }
       
} all[30];




//function that updates the ratings as games are played

void updateRatings(int team1, int team2, int score1, int score2){
    double Q1 = pow(10,all[team1].rating);
    double Q2 = pow(10,all[team2].rating);
    double E1 = Q1/(Q1+Q2);//E1 is player 1's chances of winning
    double E2 = Q2/(Q1+Q2);
    double actual = 0.5; //in case of draw
    //cout << E1 << " " << E2 << endl;
    if(score1>score2) actual = 1;
    else if(score1<score2) actual = 0;
    all[team1].rating += K*(actual-E1);
    all[team2].rating += K*((1-actual)-E2);
}





 //borrowing from a similar term used in Go tournaments
 //we essentially calculate the average strength of each person's opponents

void calcSOS(){
    for(int x = 0;x<30;x++){
        for(int a = 0;a<all[x].opp.size();x++){
            all[x].SOS+=all[(all[x].opp)[a].B].rating;
        }
        if(all[x].game!=0) all[x].SOS/=all[x].game;
    }
}
    




int main(){
    freopen(filename.c_str(),"r",stdin);
    for(int x = 0;x<30;x++) all[x].ID = x;

    int a,b,c,d;
    while(cin>>a){
        cin >> b >> c >> d;
        updateRatings(a,b,c,d);

        double actual = 0.5;
        if(c>d) actual = 1;
        else actual = 0;
        all[a].win+=actual;
        all[b].win+=(1-actual);
        if(actual!=0.5){
            all[a].h2h[b]+=(2*actual-1);
            all[b].h2h[a]+=(1-2*actual);
        }

        all[a].opp.push_back(pii(actual,b));
        all[b].opp.push_back(pii(1-actual,a));
        all[a].game++;
        all[b].game++;
          
        
    }
    calcSOS();
    sort(all,all+players); // sort by rating
    cout << "Rating Wins Games Win% SOS\n";
    
    for(int x = 0;x<players;x++){
        if(all[x].game==0) cout << "NO GAMES\n";
        else cout << all[x].ID << " " << all[x].rating << " " << all[x].win << " " << all[x].game << " " << all[x].win/all[x].game << " " << all[x].SOS << "\n";
        
        /*sort(all[x].opp.begin(),all[x].opp.end());
        for(int a = 0;a<all[x].game;a++){
            cout << all[x].opp[a].B << " ";
            if(a<all[x].game-1&&all[x].opp[a].A==0&&all[x].opp[a+1].A==1) cout << "\n";  
        }*/
        for(int a = 0;a<players;a++) cout << a << " ";
        cout << endl;
        for(int a = 0;a<players;a++) cout << all[x].h2h[a] << " ";
        cout << "\n\n";
    }
    
}

        
