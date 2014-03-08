package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.*;

public class collab1 {
  public static void main (String [] args) throws IOException {
  
	  int number;
	  
	  
	 for(int x = 100;x<1000000;x++){
		 number = swap(x);
		 
		 if(number == 4*x){
			 System.out.println(x + " " + number);
			 
		 }
	 }
	 
	  
	  
	  
	  
    System.exit(0);  
  }
  
  private static int swap(int start){
	  String number = Integer.toString(start);
	  char[] temp  = new char[number.length()];
	  String next = "";
	  for(int x = 0; x<number.length();x++){
		  temp[x]=number.charAt(x);
	  }
	  next+=temp[number.length()-2];
	  next+=temp[number.length()-1];
	
	  for(int x = 0; x<number.length()-2;x++){
		  next+=temp[x];
	  }
	  
	  
	  return Integer.parseInt(next);
  }
}