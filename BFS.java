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




public class BFS {
	
	static Queue<int[]> list = new LinkedList<int[]>();
	static int [] temp;
	//static boolean solution = false;
	//static int counter = 0;
	
	public static int[] operate(int[] initial, int index){
		
		
		switch(index){
		
		case 1:
		
			initial[0]+=3;
			initial[1]+=3;
			initial[3]+=3;
			initial[4]+=3;
			break;     			
		
		case 2:
			initial[0]+=3;
			initial[1]+=3;
			initial[2]+=3;
			
			break;
		
		case 3:
			
			initial[1]+=3;
			initial[2]+=3;
			initial[4]+=3;
			initial[5]+=3;
			break;
		
		case 4:
			initial[0]+=3;
			initial[3]+=3;
			initial[6]+=3;
			break;
		
		case 5:
			initial[1]+=3;
			initial[3]+=3;
			initial[4]+=3;
			initial[5]+=3;
			initial[7]+=3;
			break;
		case 6:
			initial[2]+=3;
			initial[5]+=3;
			initial[8]+=3;
			break;
		case 7:
			initial[3]+=3;
			initial[4]+=3;
			initial[6]+=3;
			initial[7]+=3;
			break;
		case 8:
			initial[6]+=3;
			initial[7]+=3;
			initial[8]+=3;
			break;
		case 9:
			initial[4]+=3;
			initial[5]+=3;
			initial[7]+=3;
			initial[8]+=3;
			break;
		default:
			break;
		}
		
		
		
		
return mod(initial);		
		
	}
	
	public static int[] mod(int[]initial){
		
		for(int y=0;y<9;y++){
			if(initial[y]>12) initial[y]-=12;	
		}
		
		return initial;
	}
	
	
	
	
	public static void print(int[] printer){
		for(int y=0;y<9;y++){			
			System.out.print(printer[y]+" ");
		}
		System.out.println();
		System.out.println();
	}
	

	public static boolean check(int[]initial){
		
		for(int y=0;y<9;y++){
			if(initial[y]%12!=0) return false;
		}
		return true;
	}
	
	
  public static void main (String [] args) throws IOException {
    BufferedReader f = new BufferedReader(new FileReader("clocks.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("clocks.out")));
    String temp = f.readLine()+" "+f.readLine()+" "+f.readLine();
    
    
    StringTokenizer st = new StringTokenizer(temp);
    
    
    Queue<int[]> list = new LinkedList<int[]>();
    ArrayList<ArrayList<Integer>> path = new ArrayList<ArrayList<Integer>>();
    ArrayList<Integer> start = new ArrayList<Integer>();
    
    
	
    int[] original= new int[9];
    
	for(int x=0;x<9;x++){
		original[x]=Integer.parseInt(st.nextToken());
	}

    //print(original);
    list.add(original);
    start.add(0);
    path.add(start);
    int counter = search(list, 0);
   
    
    
	int count = 0;
	int number = 0;
	
	while(count<counter){
		number++;
		if(Integer.toString(number).indexOf('0')==-1) count++;
	}
	//System.out.println(number);
    //System.out.println(counter);
    
    //System.out.println(Integer.toString(counter, 9));
    
        
    
    
    // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    
	String almost = Integer.toString(number);
	StringBuffer done = new StringBuffer("");
	
	done.append(almost.charAt(0));
	
	for(int x = 1; x<almost.length();x++){
		done.append(" ");
		done.append(almost.charAt(x));
	}
	
	
	
    out.println(done);
    out.close();
    System.exit(0);                               // don't omit this!
  }
  

  
  
  
  public static int search(Queue<int[]> list, int counter){
	
	
	if(check(list.peek()))	return counter;
	
	//temp = list.peek().clone();
	
	for(int x = 1; x<10;x++){
		
		temp = list.peek().clone();
		list.add(operate(temp,x).clone());
		//print(list.get(x));
		
		//print(temp);
	}
	
	
	/*for(int x = 0; x<10;x++){
		print(list.get(x));
	}*/
	
	list.poll();
	
	return search(list, counter+1);
	  
  }
}
