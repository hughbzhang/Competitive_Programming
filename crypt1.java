package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: crypt1
*/
import java.io.*;
import java.util.*;

class crypt1 {
		
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
   
	  
	  
	  
	 BufferedReader f = new BufferedReader(new FileReader("crypt1.in"));                                              // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("crypt1.out")));                               // close the output file
    

	int number = Integer.parseInt(f.readLine());//store number of possible digits
	StringTokenizer st = new StringTokenizer(f.readLine());
	
	int Ntwo = number*number;//number of possible two digit numbers
	int Nthree = number*Ntwo;//number of possible three digit numbers
	int Nfour = number*Nthree;//number of possible four digit numbers
	String[] digits = new String[number];
	String[] twos = new String[Ntwo];//holds two digit numbers
	String[] threes = new String[Nthree];//holds two digit numbers
	String[] fours = new String[Nfour];//holds two digit numbers
	int[] Idigits = new int[number];
	int[] Itwos = new int[Ntwo];//holds two digit numbers
	int[] Ithrees = new int[Nthree];//holds two digit numbers
	int[] Ifours = new int[Nfour];//holds two digit numbers
	for(int x = 0;x<number;x++){
		digits[x]=st.nextToken();//populate digits with possible numbers
		Idigits[x]=Integer.parseInt(digits[x]);
	}
	int counter = 0;
	
	for(int x = 0;x<number;x++){
		for(int y = 0;y<number;y++){
			twos[counter]=digits[x]+digits[y];
			Itwos[counter]=Integer.parseInt(twos[counter]);
			counter++;
		}
	}
	counter = 0;
	for(int x = 0;x<number;x++){
		for(int y = 0;y<Ntwo;y++){
		
			threes[counter]=digits[x]+twos[y];
			Ithrees[counter]=Integer.parseInt(threes[counter]);
			counter++;
		}
	}
	counter = 0;
	for(int x = 0;x<number;x++){
		for(int y = 0;y<Nthree;y++){
		
			fours[counter]=digits[x]+threes[y];
			Ifours[counter]=Integer.parseInt(fours[counter]);
			counter++;
		}
	}
	counter = 0;
	
	
	int holder1,holder2;
	for(int x = 0;x<Nthree;x++){
		for(int y = 0;y<Ntwo;y++){
	
			
			if(search(Ifours,Ithrees[x]*Itwos[y])){
				
				holder1=(int)twos[y].charAt(0)-48;
				holder2=(int)twos[y].charAt(1)-48;
				if(search(Ithrees,Ithrees[x]*holder1)&&search(Ithrees,Ithrees[x]*holder2)) counter++;
				
			}
		}
	}
	
	
	

	
	
	
	
	
	//System.out.println(digits[x]);
	out.println(counter);
    out.close();
    System.exit(0);                               // don't omit this!
  }

	private static boolean search(int[] origin, int item){
		
		
		
		for(int x = 0;x<origin.length;x++){
			if(origin[x]==item) return true;
		}
		
		return false;
	
	}






}
    