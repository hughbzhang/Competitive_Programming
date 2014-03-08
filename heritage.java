package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: heritage
*/
import java.io.*;

public class heritage {
	
	static String in;
	static String pre;
	static boolean[] hash;
	static int[] hashed;
	static char[] answer;
	static int place;
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("heritage.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("heritage.out")));
     in = f.readLine();
     pre = f.readLine();
     hash = new boolean[26];
     hashed = new int[pre.length()];
     answer = new char[pre.length()];
     place = 0;
     
     for(int x = 0;x<pre.length();x++){
		  int index = (int)pre.charAt(x)-65;
		  hashed[x] = index;
	  }
      search(in);
      for(int x = 0;x<answer.length;x++){
    	  out.print(answer[x]);
      }
      out.println();
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  static void clear(){
	  for(int x = 0;x<26;x++) hash[x] = false;
  }
  
  static void search(String tree){
	  if(tree.length()==1){
		  answer[place]=tree.charAt(0);
		  place++;
		  return;
	  }
	  clear();
	  for(int x = 0;x<tree.length();x++){
		  int index = (int)tree.charAt(x)-65;
		  hash[index] = true;
	  }
	  int index = -1;
	  for(int x = 0;x<hashed.length;x++){
		  if(hash[hashed[x]]){
			  index = hashed[x];
			  break;
		  }
	  }
	  int root = -1;
	  for(int x = 0;x<tree.length();x++){
		  if(index== (int)tree.charAt(x)-65){
			root = x;  
		  }
	  }
	  if(root!=0) search(tree.substring(0,root));
	  if(root!=tree.length()-1) search(tree.substring(root+1, tree.length()));
	  answer[place] = tree.charAt(root);
	  place++;
	  return;
  }
  
}