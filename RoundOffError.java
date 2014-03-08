package Algorithms;

public class RoundOffError {
	  int up(double a){
		  int temp = (int)Math.floor(a);
		  if(a-temp>0.000001) temp++;
		  return temp;
	  }
	  int down(double a){
		  int temp = (int)Math.ceil(a);
		  if(temp-a>0.000001) temp--;
		  return temp;
	  }
}
