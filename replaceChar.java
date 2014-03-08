package Solved;

import java.io.*;
//import java.util.*;

public class replaceChar {
	
  public static void main (String [] args) throws IOException {
  String first = "happy";
  int index = 0;
  char r = 's';
	  
  String last = replace(first, r, index);
  
  System.out.println(last);
  }
  private static String replace(String first, char r, int index){
	  char[] temp = new char[first.length()];
	  String next = "";
	  for(int x = 0;x<temp.length;x++){
		  temp[x]=first.charAt(x);
	  }
	  temp[index] = r;
	  for(int x = 0;x<temp.length;x++){
		 next+=temp[x];
	  }
	  
	  
	  return next;
  }
  
  
  
}