package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: transform
*/
import java.io.*;


class transform {

	
	
  public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("transform.in"));
                                                  // input file name goes above
    //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("transform.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    //System.out.println(f.readLine());
   
    String size = f.readLine();
    boolean compare;
    int SIZE = Integer.parseInt(size);
    //int transform = 7;
    char[][]original = new char[SIZE][SIZE];
    char[][]storage = new char[SIZE][SIZE];
    char[][]goal = new char[SIZE][SIZE];
    for(int y = 0; y<SIZE;y++){//populate original array
    	String temp = f.readLine();
    	//System.out.println("GO");
    	for(int x = 0;x<SIZE;x++){
        original[y][x]=temp.charAt(x);
        storage[y][x]=temp.charAt(x);
        //System.out.println(original[y][x]);
    }
    }
    for(int y = 0; y<SIZE;y++){//populate goal array
    	String temp = f.readLine();
    	//System.out.println("GO");
    	for(int x = 0;x<SIZE;x++){
        goal[y][x]=temp.charAt(x);
     //   System.out.println(goal[y][x]);
    }
    }
    
    
    for(int x = 0;x<4;x++){
    storage = rotate90(storage, SIZE);
    compare = comparison(storage, goal, SIZE);
    if(compare) exit(x+1);
    //printArray(storage, SIZE);
    }
    
    //System.out.println(compare);
    
    storage = flip(original,SIZE);
    compare = comparison(storage, goal, SIZE);
    if(compare) exit(4);
    
    for(int x = 0;x<4;x++){
        storage = rotate90(storage, SIZE);
        compare = comparison(storage, goal, SIZE);
        if(compare) exit(5);
        //printArray(storage, SIZE);
        }
    
    compare = comparison(original, goal, SIZE);
    if(compare) exit(6);
    exit(7);
    //System.out.println(temp);
   // for(int x = 0;x<calender.length;x++) System.out.println(calender[x] + "" + x);
    
  }
  
 
  
 /* private static void printArray (char[][] storage, int SIZE){
	  for(int y = 0; y<SIZE;y++){//populate original array
	    //	String temp = f.readLine();
	    	//System.out.println("GO");
	    	for(int x = 0;x<SIZE;x++){
	      //  original[y][x]=temp.charAt(x);
	        System.out.println(storage[y][x]);
	    }
  }
  }*/
  
  
  
  
  
private static boolean comparison(char [][]original, char [][]goal, int SIZE){
  boolean compare = true;
	for(int y = 0; y<SIZE;y++){//populate goal array
  	//String temp = f.readLine();
  	//System.out.println("GO");
  	for(int x = 0;x<SIZE;x++){
      if (original[y][x] != goal[y][x]) compare = false;
   //   System.out.println(goal[y][x]);
  }
  }
return compare;

}
  
  
  private static char[] getList(char[][] initial, int SIZE){
	  int counter = 0;
	  char[] list = new char[SIZE*SIZE];
	  for(int y = 0; y<SIZE;y++){//populate goal array
	    	//String temp = f.readLine();
	    	//System.out.println("GO");
	    	for(int x = 0;x<SIZE;x++){
	    		list[counter] = initial[y][x];
	    		counter++;
	        
	    }
	    }
	  
	  return list;
  }
  
  
  private static char[][] rotate90(char[][] initial, int SIZE){
	  int counter = 0;
	  
	 
	  
	  char[][] rotated = new char[SIZE][SIZE];
	  char[] list = getList(initial, SIZE);
	  for(int x = SIZE-1;x>-1;x--){
		  for(int y = 0; y<SIZE; y++){
			  rotated[y][x]=list[counter];
			  counter++;
		  }
	  }
	  //printArray(rotated, SIZE);
	  //for(int a = 0; a<list.length;a++){
	  //  System.out.println(list[a]);
	  //}
	  return rotated;
  }
  
  private static char[][] flip(char[][] initial, int SIZE){
	 // int counter = 0;
	  
	 
	  char[][] flipped = new char[SIZE][SIZE];
	  //char[] list = getList(initial, SIZE);
	  for(int x = SIZE-1;x>-1;x--){
		  for(int y = 0; y<SIZE; y++){
			  flipped[y][x]=initial[y][SIZE-x-1];
			  //counter++;
		  }
	  }
	  //printArray(rotated, SIZE);
	  //for(int a = 0; a<list.length;a++){
	  //  System.out.println(list[a]);
	  //}
	  return flipped;
  }
  
  

private static void exit(int transform) throws IOException{
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("transform.out")));
	out.println(transform);
    out.close();
   
    System.exit(0);                               // don't omit this!
}

}