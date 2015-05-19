#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

const char * ACTIONS_FILE = "actions.txt";
const char * RESULTS_FILE = "results.txt";

const char * SIMULATION_EXECUTABLE = "java -jar pendulum.jar";

const int MIN_ANGLE = 0;
const int CORRECT_ANGLE = 90;
const int MAX_ANGLE = 180;

const int MAX_ANGULAR_SPEED = 30;
const int CORRECT_ANGULAR_SPEED = 0;
const int MIN_ANGULAR_SPEED = -30;

const int NUM_SIMULATIONS = 10;

/* Do NOT edit the above constants. Otherwise, the program will likely not work. */

/**
 * Runs the provided simulation, and returns the statistics.
 * You should not need to modify this function.
 */
void runSimulation(vector<string>& results, bool visualization) {
    /* Run the simulation. */
    string simulation = SIMULATION_EXECUTABLE;
    if(!visualization) {
        char numstr[21];
        sprintf(numstr, "%d", NUM_SIMULATIONS);
        simulation += " " + string(numstr);
    }
    int exitCode = system(simulation.c_str());
    cout << "Exit code: " << exitCode << endl;
    if(exitCode != 0) {
        cout << "There is an error in the starter code. Please alert a ProCo staff member.\n";
        return;
    }

    /* Parse the results from the output file. */
    ifstream fin(RESULTS_FILE);
    string str;
    while (getline(fin, str)) {
        results.push_back(str);
    }
}

/**
 * Produces an actions file.
 */
void generateActions(double mul,int L, int R) {
    ofstream fout (ACTIONS_FILE);
    /***********************************************************************
     * You will need to modify the logic here to make the behavior smarter.
     **********************************************************************/


    srand(7);
    int cnt = 0;
    for(int angle = MIN_ANGLE; angle <= MAX_ANGLE; angle++) {
        for(int angularSpeed = MIN_ANGULAR_SPEED; angularSpeed <= MAX_ANGULAR_SPEED; angularSpeed++) {
            fout << angle << " " << angularSpeed << " ";
            
            double key = angle+mul*angularSpeed;
            int right = R;
            int left = L;

            if(key>right){
                fout << "R";
                //if(cnt%10==0) fout << "L";
                //else fout << "R";
            }
            else if(key<left){
                fout << "L";
                //if(cnt%10==0) fout << "R";
                //else fout << "L";
            }
            else if(key<=right&&key>90){
                fout << "L";
            }
            else{
                fout << "R";
            }
            fout << "\n";
        }
    }
}

/* Add whatever you want here. */

int main() {

    /* Generate your actions file.
     * This is a file containing a map from state -> action.
     * Each line contains three space-separated values:
     *   ANGLE, SPEED, and ACTION.
     * This means that if the pendulum has angle ANGLE and speed SPEED,
     *   then the pendulum should move in direction ACTION (R (right) or L (left)). */
    double mul;
    int L,R;
    cin >> mul >> L >> R ;
    generateActions(mul,L,R);

    /* Run the simulation to get back the results in the file RESULTS_FILE.
     * To turn visualization off, pass in FALSE. */
    vector<string> results;
    //runSimulation(results, true);
    for(int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}
