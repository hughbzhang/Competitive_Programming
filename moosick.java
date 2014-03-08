package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: moosick
*/
import java.io.*;
import java.util.*;

public class moosick {
	

	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("moosick.in"));
                                            // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("moosick.out")));                               // close the output file
    //ArrayList<String> file = new ArrayList<String>();
    //f.readLine();
    //StringTokenizer st = new StringTokenizer(f.readLine()); 
    int length = Integer.parseInt(f.readLine());
    int[] music = new int [length];
   int record= 0;
   ArrayList<Integer> printable = new ArrayList<Integer>();
    for(int x = 0 ; x<length;x++){
    	music[x]=Integer.parseInt(f.readLine());
    	//System.out.println(music[x]);
    }
    int c = Integer.parseInt(f.readLine());
    ArrayList<Integer> chord = new ArrayList<Integer>();
    for(int x = 0 ; x<c;x++){
    	chord.add(Integer.parseInt(f.readLine()));
    	//System.out.println(chord[x]);
    }
    int temp = 0;
    int temp1= 0;
    int temp2=0;
  //  boolean go = true;
    ArrayList<Integer> checked = new ArrayList<Integer>();
    for(int x = 0; x<music.length;x++){
    //int a = 4;	
    int est = 0;
    for(int y = 0; y<chord.size();y++){
    	checked.clear();
    	temp = x;
    	temp2=y;
    	est = 0;
    	//temp3=chord.get(temp2)+temp1;
    	checked.add(temp2);
    		while(true){
		    	//temp = music[x]-chord.get(y);
    			//est += temp1;
		    	if(temp+1>=music.length){
		    		//System.out.println("break");
		    		break;
		    	}
    			temp1=music[temp+1]-music[temp];
		    	if(chord.contains(chord.get(temp2)+temp1+est)&&checked.contains(chord.get(temp2)+temp1+est)==false){
		    		temp++;
		    		checked.add(chord.indexOf(chord.get(temp2)+temp1+est));
		    		//System.out.println("go");
		    	}
		    	else{
		    		//System.out.println(chord.contains(chord.get(temp2)+temp1+est));
		    		//System.out.println(chord.get(temp2)+temp1+est);
		    		break;
		    	}
		    	if(checked.size()==chord.size()){
		    		record++;
		    		printable.add(x);
		    		break;
		    		
		    	}
    		}
    		
    		
    		
    		
    	}
    }
    
    //ArrayList<Integer> possible = new ArrayList<Integer>();
    
    //possible = recurse(chord,possible);
    
    
    out.println(record);
    for(int x = 0;x<printable.size();x++){
    	
    
    out.println(printable.get(x));
    }
    out.close();
    System.exit(0);                               // don't omit this!
  }
  /*private static ArrayList<Integer> recurse(int[] chord, ArrayList<Integer>possible){
	  recurse(chord,possible);
	  return possible;
  }*/

  
}
    