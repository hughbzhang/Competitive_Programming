package Contest;

/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
//import java.awt.Point;
import java.io.*;
import java.util.*;

public class photo {
	static int[][] set;
	static boolean[] pos;
	static long answer;
	static double start;
  public static void main (String [] args) throws IOException {//I tell my program to quit if it goes overtime, so it will output -1 for any cases that are too large :P.
	  start = System.currentTimeMillis();
	  start+=3600;
     Scanner in = new Scanner(new FileReader("photo.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("photo.out")));
     
     int cow = in.nextInt();
     int photos = in.nextInt();
     answer = -1;
     
     set = new int[photos][2];

     for(int y = 0;y<photos;y++){
    	 set[y][0] = in.nextInt()-1;
    	 set[y][1] = in.nextInt()-1;
     }

     pos = new boolean[cow];
     
     recurse(0);
     

     out.println(answer);
     
     
    in.close();
    out.close();                             
    System.exit(0);                            
  }
  static void recurse(int index){
	  if(System.currentTimeMillis()>start) return;
	  if(index==set.length){
		  check();
		  return;
	  }
	  for(int x = set[index][0];x<=set[index][1];x++){
		  pos[x] = true;
		  recurse(index+1);
		  pos[x] = false;
	  }
	  
	  
  }
  static void check(){
	  for(int a = 0;a<set.length;a++){
		  boolean h = false;
		  for(int x = set[a][0];x<=set[a][1];x++){
			  if(pos[x]){
				  if(h) return;
				  h = true;
			  }
		  }
		  if(h==false) return;
	  }
	  int o = 0;
	  for(int x = 0;x<pos.length;x++){
		  if(pos[x]) o++;
		  if(o>answer) answer = o;
	  }
  }
	  
	  
	  
	  
  
  
  
}