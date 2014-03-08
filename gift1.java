package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: gift1
*/

/*
import java.io.*;
import java.util.*;
//ArrayList Way
class gift1 {

	
	public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("gift1.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    //StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    Integer storage;//storage value
    int GIFT;//GIFT value
    String temp;//temporary string
    String giver;
    Hashtable group = new Hashtable();//people ArrayList
    temp = f.readLine();//read first line
    
    int PEOPLE = Integer.parseInt(temp);//add people and money to their arraylists
    for(int x = 0; x < PEOPLE; x++){
    	group.put(f.readLine(), 0);
    }
    
	
		
	

    
    giver = f.readLine();
    
    while(temp != null){
    		
    		//int index = group.indexOf(temp);
    		temp = f.readLine();
    		StringTokenizer st = new StringTokenizer(temp);  // Get line, break into tokens
    		int MONEY = Integer.parseInt(st.nextToken());    // first integer
    		int RECEIVERS = Integer.parseInt(st.nextToken());    // second integer
    		if(RECEIVERS != 0){
    		GIFT = (int) Math.floor(MONEY/RECEIVERS); // floor creates a double
    		storage = (Integer) group.get(giver);
    		group.remove(giver);
    		group.put(giver, storage-(RECEIVERS*GIFT));
    		for(int x=0;x<RECEIVERS;x++){
    			temp = f.readLine();
    			//index = group.indexOf(temp);
    			storage = (Integer) group.get(temp);
    			group.remove(temp);
    			group.put(temp, storage+GIFT);
    		}
    		}
    		temp = f.readLine();
    	}		
    	System.out.println(group.values());
    	for(int a = 0; a<PEOPLE; a++){
    		//temp = group.get(a);
    		//storage = money.get(a);
    		//out.println(temp + " " + storage);
    	}
    		
    		out.close();
    		System.exit(0);                               // don't omit this!
    	}
	}


*/
import java.io.*;
import java.util.*;
//ArrayList Way
class gift1 {

	
	public static void main (String [] args) throws IOException {
    // Use BufferedReader rather than RandomAccessFile; it's much faster
    BufferedReader f = new BufferedReader(new FileReader("gift1.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    //StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    //int i1 = Integer.parseInt(st.nextToken());    // first integer
    //int i2 = Integer.parseInt(st.nextToken());    // second integer
    //out.println(i1+i2);                           // output result
    //out.close();                                  // close the output file
    int storage;//storage value
    int GIFT;//GIFT value
    String temp;//temporary string
    ArrayList<String> group = new ArrayList<String>();//people ArrayList
    ArrayList<Integer> money = new ArrayList<Integer>();//money ArrayList
    temp = f.readLine();//read first line
    
    int PEOPLE = Integer.parseInt(temp);//add people and money to their arraylists
    for(int x = 0; x < PEOPLE; x++){
    	group.add(f.readLine());
    	money.add(0);
    }
    
	
		
	

    
    temp = f.readLine();
    
    while(temp != null){
    		
    		int index = group.indexOf(temp);
    		temp = f.readLine();
    		StringTokenizer st = new StringTokenizer(temp);  // Get line, break into tokens
    		int MONEY = Integer.parseInt(st.nextToken());    // first integer
    		int RECEIVERS = Integer.parseInt(st.nextToken());    // second integer
    		if(RECEIVERS != 0){
    		GIFT = (int) Math.floor(MONEY/RECEIVERS); // floor creates a double
    		storage = money.get(index);
    		money.set(index, storage-(RECEIVERS*GIFT));
    		for(int x=0;x<RECEIVERS;x++){
    			temp = f.readLine();
    			index = group.indexOf(temp);
    			storage = money.get(index);
    			money.set(index, storage+GIFT);
    		}
    		}
    		temp = f.readLine();
    		System.out.println(group);
    		System.out.println(money);
    	}		
    	
    	for(int a = 0; a<PEOPLE; a++){
    		temp = group.get(a);
    		storage = money.get(a);
    		out.println(temp + " " + storage);
    	}
    		
    		out.close();
    		System.exit(0);                               // don't omit this!
    	}
	}

