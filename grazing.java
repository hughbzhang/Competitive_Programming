package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: grazing
*/
import java.io.*;
import java.util.*;

public class grazing {
	//static ArrayList<int[][]> paths = new ArrayList<int[][]>();
	static boolean [][] field = new boolean[5][5];//y then x
	//static boolean [][] pseudo = new boolean[5][5];//y then x
    static int counter = 0;
	
  public static void main (String [] args) throws IOException {
    BufferedReader f = new BufferedReader(new FileReader("grazing.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("grazing.out")));
    
    
    for(int y = 0;y<5;y++){
    	for(int x = 0;x<5;x++){
    		field[y][x]=true;
   // 		pseudo[y][x]=true;
    	}
    }
    int number = Integer.parseInt(f.readLine()); 
   
    for(int x = 0;x<number;x++){
        StringTokenizer st = new StringTokenizer(f.readLine());
        int i1 = Integer.parseInt(st.nextToken())-1;    
        int i2 = Integer.parseInt(st.nextToken())-1; 
        field[i1][i2]=false;  
    //    pseudo[i1][i2]=false;
    }

    //ArrayList<int[][]> pos = new ArrayList<int[][]>();
    
   
    findPaths(0, 0, 4, 4);

   
    
    
    
    out.println(counter);          
    out.close();                                 
    System.exit(0);                       
  }
  
  
  public static void findPaths(int y, int x, int b, int a){//giving a lot of credit to pseudo code for maze running i found online. It was pseudo code NOT CODE. http://www.cs.bu.edu/teaching/alg/maze/
	  
	  if(x<0||x>4||y<0||y>4) return;
	  if(a<0||a>4||b<0||b>4) return;
	  if(b==y&&a==x){
		  if(onepatches(b, a)){
			  counter++;
		  }
		  return;
	  }
	  if(field[y][x]==false||field[b][a]==false) return;
	  
	  field[y][x]=false;
	  field[b][a]=false;
	  
	  findPaths(y-1, x, b-1, a);
	  findPaths(y-1, x, b+1, a);
	  findPaths(y-1, x, b, a-1);
	  findPaths(y-1, x, b, a+1);
	  findPaths(y+1, x, b-1, a);
	  findPaths(y+1, x, b+1, a);
	  findPaths(y+1, x, b, a-1);
	  findPaths(y+1, x, b, a+1);
	  findPaths(y, x+1, b-1, a);
	  findPaths(y, x+1, b+1, a);
	  findPaths(y, x+1, b, a-1);
	  findPaths(y, x+1, b, a+1);
	  findPaths(y, x-1, b-1, a);
	  findPaths(y, x-1, b+1, a);
	  findPaths(y, x-1, b, a-1);
	  findPaths(y, x-1, b, a+1);
	  field[y][x]=true;
	  field[b][a]=true;
	  return;
  }

  public static boolean onepatches(int b, int a){
	  int holder=0;
	  for(int y = 0;y<5;y++){
	    	for(int x = 0;x<5;x++){
	    		if(field[y][x]==true) holder++;
	  
	    	}
	  }
	  if(holder==1&&field[b][a]==true) return true;
	  else return false;
  }
  
  
  
  /*
  
  
	  public static void reset(){
	    for(int y = 0;y<5;y++){
	    	for(int x = 0;x<5;x++){
	    		pseudo[y][x]=field[y][x];
	    	}
	    }
  }
	  */
	  
	  
	  
  
  /*    
    for(int y = 0;y<5;y++){
    	for(int x = 0;x<5;x++){

System.out.println(field[y][x]);
    	}
    	
    		
    }*/
  
  
  
  
  
  
}