package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: runround
*/
import java.io.*;

public class runround {

	
	
  public static void main (String [] args) throws IOException {
    BufferedReader f = new BufferedReader(new FileReader("runround.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("runround.out")));
    
    int start = Integer.parseInt(f.readLine());
    String change;
    boolean[] digits;
    int index = 0;
    int length = 0;
    
    top: while(true){
    	start++;
    	change = Integer.toString(start);
    	if(check(change)==false) continue;
    	length = change.length();
    	digits = new boolean[length];
    	index = 0;
    	for(int x = 0; x<length;x++){
    		index = (index+(change.charAt(index)-48))%length;
    		if(digits[index]==false) digits[index]=true;
    		else continue top;
    	}
    	break;
    }
    out.println(change);
    
    
    
    out.close();
    System.exit(0);
  }
  static boolean check(String checker){
	  
	  boolean one = false;
	  boolean two = false;
	  boolean three = false;
	  boolean four = false;
	  boolean five = false;
	  boolean six = false;
	  boolean seven = false;
	  boolean eight = false;
	  boolean nine = false;
	  
	  for(int x = 0; x<checker.length();x++){
		  char key = checker.charAt(x);
		  if(key=='0') return false;
		  switch(key){
		  case '1': if(one==false) one = true; else return false; break;
		  case '2': if(two==false) two = true; else return false; break;
		  case '3': if(three==false) three = true; else return false; break;
		  case '4': if(four==false) four = true; else return false; break;
		  case '5': if(five==false) five = true; else return false; break;
		  case '6': if(six==false) six = true; else return false; break;
		  case '7': if(seven==false) seven = true; else return false; break;
		  case '8': if(eight==false) eight = true; else return false; break;
		  case '9': if(nine==false) nine = true; else return false; break;
		  default: System.out.println("error"); break;
		  }
	  }
	  return true;
  }
  
  
 }
