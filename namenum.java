package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: namenum
*/
import java.io.*;
import java.util.*;

class namenum {

public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("namenum.in"));
    BufferedReader d = new BufferedReader(new FileReader("dict.txt"));
    
    // input file name goes above
    
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("namenum.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    //StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    //System.out.println(f.readLine());
    //System.out.println(d.readLine());
    
    String number = f.readLine();
    //String [] temp = new String[5000];
    String temp;
    boolean marker = true;
    char [][] numbered = new char [1][number.length()];
    char [][] words = new char [3][number.length()];
    //char [][] dict = new char [5000][12];
    //String [] dct = new String [5000];
    ArrayList<String> good = new ArrayList<String>();
    /*
    //int NUMBER = Integer.parseInt(number);
    for(int y = 0; y<5000;y++){
    	temp = d.readLine();
    	if(temp==null) break;
    	dct[y]=temp;
    	for(int x = 0; x<temp.length();x++){
    		dict[y][x]=temp.charAt(x);
    		//if(dict[y][x]==null) dict[y][x]='z';
    	}
    }
      */ 
    
    
    for(int x = 0; x<number.length();x++){
    	numbered[0][x] = number.charAt(x);
    }
    
    words = fillArray(numbered, number);
    
    for(int a = 0; a<5000; a++){
    
    	temp = d.readLine();
    	if(temp==null) break;
    	marker= true;
    	if(temp.length()!=number.length()) continue;
    	for(int x = 0; x<temp.length();x++){
    		
    		if(marker==false) break;
    		marker = false;
    		for(int y = 0; y<3;y++){
    			
    			if(words[y][x]==temp.charAt(x)) marker = true;
    			//System.out.println(temp);
    		}
    		
    		//temp = "";
    		//temp += words[]
    		
    		
    		
    	
    
    //if(dict[0][4] == '\u0000')
   
    	}
    	if(marker) good.add(temp);
    
    
    }
    //System.out.println(good.get(0));

    
    if(good.isEmpty()){
    
    	 out.println("NONE");
    
    out.close();
    System.exit(0);    
    }
    for(int a=0;a<good.size();a++){
    System.out.println("activate");
    	out.println(good.get(a));
    }
    out.close();
    System.exit(0);                               // don't omit this!
  
  }


private static char[][] fillArray(char [][] numbered, String number){
	char [][] words = new char [3][number.length()];
	
	//for(int y = 0; y<3;y++){
	for(int x = 0; x<number.length();x++){
		switch((int)numbered[0][x]){
			
		case 50: words[0][x] = 'A'; words[1][x] = 'B'; words[2][x] = 'C'; break;
		case 51: words[0][x] = 'D'; words[1][x] = 'E'; words[2][x] = 'F'; break;
		case 52: words[0][x] = 'G'; words[1][x] = 'H'; words[2][x] = 'I'; break;
		case 53: words[0][x] = 'J'; words[1][x] = 'K'; words[2][x] = 'L'; break;
		case 54: words[0][x] = 'M'; words[1][x] = 'N'; words[2][x] = 'O'; break;
		case 55: words[0][x] = 'P'; words[1][x] = 'R'; words[2][x] = 'S'; break;
		case 56: words[0][x] = 'T'; words[1][x] = 'U'; words[2][x] = 'V'; break;
		case 57: words[0][x] = 'W'; words[1][x] = 'X'; words[2][x] = 'Y'; break;
		default: System.out.println((int)numbered[0][x]); break;	
		
			//2: A,B,C     5: J,K,L    8: T,U,V
	          //3: D,E,F     6: M,N,O    9: W,X,Y
	          //4: G,H,I     7: P,R,S
		}
	//}
	}
	
	return words;
}




}