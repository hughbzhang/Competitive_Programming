package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: beads
*/
import java.io.*;

class beads {

public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("beads.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    //StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    
    String length = f.readLine();//length of necklace
    String beads = f.readLine();//beads
    
    char wrongColor = 'a';
    boolean activated = false;
    int counter = 0;
    int a;
    int runtime = 0;
    int record = runtime;
    int LENGTH = Integer.parseInt(length);
    int arraylength=2*LENGTH;
    char[] necklace = new char[arraylength];
    
    for(int x=0;x<LENGTH;x++){//populate the necklace array with twice length to account for circle
    	necklace[x]=beads.charAt(x);
    	necklace[x+LENGTH]=beads.charAt(x);
    }
    
    for(int x = 0; x<necklace.length;x++){
    	
    	if(necklace[x]!='w'){
    		activated = true;
	    	if(necklace[x] == 'b') wrongColor = 'r';
	    	if(necklace[x] == 'r') wrongColor = 'b';
	    	
    	
	    	for(int y = x; y<necklace.length;y++){
	    		
	    		if (necklace[y] == wrongColor) break;
	    		counter++;
	    	
	    	}
    
	    	if(x>0){
	    		for(a = x-1; a>=0;a--){
	    			if(necklace[a] != 'w') break;
	    			if(a==0) break;//QUESTION
	    			counter++;
	    		}
	    		System.out.println(a);
	    		if (a==0&&necklace[0]=='w');
	    		else{
	    		System.out.println(a);
	    		if(necklace[a] == 'b') wrongColor = 'r';
	        	if(necklace[a] == 'r') wrongColor = 'b';	
	        	if(wrongColor == 'r') System.out.println("r");
			    	for(int y = a; y>-1;y--){
			    		if (necklace[y] == wrongColor) break;
			    		counter++;
			    		}
	    		}
	    	}    
    	}
    	if(record<counter) record = counter;
    	counter = 0;
    	runtime++;
    	
    
    }
    

    System.out.println(record);
    if(record>LENGTH) record = LENGTH;
    if(activated == false) record = LENGTH;
    
    out.println(record);
    
    out.close();
    System.exit(0);                               // don't omit this!
  
  }
}