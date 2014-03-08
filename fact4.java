package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: fact4
*/
import java.io.*;
import java.util.*;

public class fact4 {
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("fact4.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fact4.out")));
     int fact = Integer.parseInt(f.readLine());
     //int[] numbers = new int[fact+1];
     int five = 0;
     int two = 0;
     int temp = 0;
     long total = 1;
     //numbers[0] = 1;
     for(int x = 1;x<=fact;x++){
    	 
    	 temp = x;
    	 while(temp%5==0){
    		 temp/=5;
    		 five++;
    	 }
    	 while(temp%2==0){
    		 temp/=2;
    		 two++;
    	 }
    	 total*=temp;
    	 while(total>9) total%=10;
     }
     
    
     
     if(two>five){
    	 for(int x = 0;x<two-five;x++){
    		 total*=2;
    		 while(total>9) total%=10;
    	 }
     }
     
     out.println(total);
     
    out.close();                             
    System.exit(0);                            
  }
}