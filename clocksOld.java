package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: clocks
*/
import java.io.*;
import java.util.*;

//indexes always go
//[y] then [x]
//[0 1 2
//[3 4 5
//[6 7 8




public class clocksOld {
	
	static int[][] origin = new int[3][3];
	static ArrayList<Integer> path = new ArrayList<Integer>();
	static boolean solution = false;
	static ArrayList<Integer> finalpath = new ArrayList<Integer>();
	
	
	public static int[][] operate(int[][] initial, int index){
		
		
		switch(index){
		
		case 1:
		
			initial[0][0]+=3;
			initial[0][1]+=3;
			initial[1][0]+=3;
			initial[1][1]+=3;
			break;     			
		
		case 2:
			initial[0][0]+=3;
			initial[0][1]+=3;
			initial[0][2]+=3;
			
			break;
		
		case 3:
			
			initial[0][1]+=3;
			initial[0][2]+=3;
			initial[1][1]+=3;
			initial[1][2]+=3;
			break;
		
		case 4:
			initial[0][0]+=3;
			initial[1][0]+=3;
			initial[2][0]+=3;
			break;
		
		case 5:
			initial[0][1]+=3;
			initial[1][0]+=3;
			initial[1][1]+=3;
			initial[1][2]+=3;
			initial[2][1]+=3;
			break;
		case 6:
			initial[0][2]+=3;
			initial[1][2]+=3;
			initial[2][2]+=3;
			break;
		case 7:
			initial[1][0]+=3;
			initial[1][1]+=3;
			initial[2][0]+=3;
			initial[2][1]+=3;
			break;
		case 8:
			initial[2][0]+=3;
			initial[2][1]+=3;
			initial[2][2]+=3;
			break;
		case 9:
			initial[1][1]+=3;
			initial[1][2]+=3;
			initial[2][1]+=3;
			initial[2][2]+=3;
			break;
		}
		
		
		initial=mod(initial);
		
		
return initial;		
		
	}
	
	public static int[][] mod(int[][]initial){
		
		for(int y=0;y<3;y++){
			for(int x=0;x<3;x++){
				if(initial[y][x]>12){
					initial[y][x]-=12;
				}
			}
		}
		
		
		return initial;
	}
	public static boolean check(int[][]initial){
		
		for(int y=0;y<3;y++){
			for(int x=0;x<3;x++){
				if(initial[y][x]!=12) return false;
			}
		}
		return true;
	}
	
	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("clocks.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("clocks.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    String temp = f.readLine()+" "+f.readLine()+" "+f.readLine();
    
    
    StringTokenizer st = new StringTokenizer(temp);
	
    int[][] original= new int[3][3];
    //int[][] changed = new int[3][3];
    //ArrayList<Integer> order = new ArrayList<Integer>();
    //ArrayList<Integer> holder = new ArrayList<Integer>();
    for(int y=0;y<3;y++){
		for(int x=0;x<3;x++){
			original[y][x]=Integer.parseInt(st.nextToken());
		}
	}
    origin = original;
    int depth = 0;
   while(solution == false){
	   depth++;
	   find(original, depth, 0);
   }
    
    
    
    
    
        
    
    
    // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    
    out.println();
    out.close();
    System.exit(0);                               // don't omit this!
  }
  
    
  
  
  
  
  public static void find(int[][] changed, int depth, int counter){
	while(counter<=depth){
	  	for(int x = 1;x<9;x++){
	  		path.add(x);
	  		find(operate(changed, x), depth, counter+1);
	  		
	  	}
	  	//counter++;
	}
	if(counter==depth+1&&check(changed)){
		solution = true;
			for(int x = 0;x<path.size();x++){
				finalpath.add(path.get(x));
			}
	
	}
	path.clear();
	  return;
	  
	
	  
	  
  }
}
  /*
  

  while(no solution == true)
  	depth++
  	find(origin, depth, counter)
  	
  	if(counter<depth);
  	
  	find()
  	int counter = 0
  	for(1 to 9){
  	
  		
  	operate
  	find again sending counter down.
  	check
  		if true; find solution
  		quit
  	}
  	
  	counter++;
  	
  	
   */
