package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: haybales
*/
import java.io.*;
import java.util.*;

public class haybales {
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("haybales.in"));
                                            // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("haybales.out")));                               // close the output file
    //ArrayList<String> file = new ArrayList<String>();
    //f.readLine();
    //StringTokenizer st = new StringTokenizer(f.readLine()); 
    int number = Integer.parseInt(f.readLine());
    int sum = 0;
    int average = 0;
    int moved = 0;
    ArrayList<Integer> hay = new ArrayList<Integer>();
    for(int x = 0;x<number;x++){
    	hay.add(Integer.parseInt(f.readLine()));
    	sum+=hay.get(x);
    	//System.out.println(hay.get(x));
    }
    average = sum/number;
    //System.out.println(average);
    
    for(int a = 0; a<number;a++){
    	if(hay.get(a)<average){
    		moved+=(average-hay.get(a));
    		//System.out.println(moved);
    	}
    }
    
    
    out.println(moved);
    //out.println();
    out.close();
    System.exit(0);                               // don't omit this!
  }
}
    