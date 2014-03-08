package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: barn1
*/
import java.io.*;

public class sequence {
	
	private static double recurse(double start, double counter, double total){
		
		if(counter>5000){
			return total;
		}
		
		start = start/(counter+2);
		
		double nextT;
		
		nextT = recurse(start, counter+1, total+start);
		return nextT;
	}

	
  public static void main (String [] args) throws IOException {
	  
	  double total = recurse(720, 1, 0);
	  System.out.println(((total+720)/1440+2)/Math.E);
	  
	  
  }
}
    