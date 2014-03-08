package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: ride
*/
import java.io.*;

class ride {
	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("ride.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
    
    String comet = f.readLine();
    String group = f.readLine();
    int number = 0;
    int total = 1;
    int modulus;
    
	for(int a = 0; a<comet.length(); a++){
		char holder = comet.charAt(a);
		number = (int) holder;
		number = number - 64;
		total = total * number;
	}
    modulus = total%47;
    
    number = 0;
    total = 1;
    int modulus2;
    
	for(int a = 0; a<group.length(); a++){
		char holder = group.charAt(a);
		number = (int) holder;
		number = number - 64;
		total = total * number;
	}
    modulus2 = total%47;
    
    if (modulus2 == modulus) out.println("GO");
    if (modulus2 != modulus) out.println("STAY");
    
    out.close();
    System.exit(0);                               // don't omit this!
  }
}