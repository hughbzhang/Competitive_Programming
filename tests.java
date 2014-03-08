package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: escape
*/
import java.io.*;

public class tests {
	
  public static void main (String [] args) throws IOException {
  
	// System.out.println("s");
//	 String temp = LCM("petersg", "gpeters");

	  int end = 5/2;
	  System.out.println(end);
	  
	 //System.out.println(temp);
  }

  public static String LCM(String s1, String s2){
   
          int i = 0;
          int j = 0;
          String myStr = "";
          while(i < s1.length() && j < s2.length()){
              if(s1.charAt(i) == s2.charAt(j)){              
                 myStr+=(s1.charAt(i));
                 j++;
              }
              else{
                  //if ( s1.charAt(i) != s2.charAt(j)){
                      i++;
                 // }
              }
          }
        //String opt = new String(getMyStr());
         return  myStr;
      }
}