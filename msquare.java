package Solved;

/*
ID: bigfish2
LANG: JAVA
TASK: msquare
*/
import java.io.*;
import java.util.*;

public class msquare {
	static int[] list = new int[8];
	static boolean[] past = new boolean[50000];
	static int[] pow = new int[]{5040,720, 120, 24, 6, 2, 1, 1};
	public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("msquare.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("msquare.out")));
     StringTokenizer st = new StringTokenizer(f.readLine());
     int[] line = new int[]{1, 2, 3, 4, 8, 7, 6, 5};
 	 //Queue<int[]> queue = new LinkedList<int[]>();
 	 Queue<String> order = new LinkedList<String>();
 	 int[] target = new int[8];
     for(int x = 0;x<4;x++) target[x] = Integer.parseInt(st.nextToken());
     for(int x = 0;x<4;x++) target[7-x] = Integer.parseInt(st.nextToken());
     if(compare(target, line)){
    	 out.println(0);
    	 out.println();
    	 out.close();
    	 f.close();
    	 System.exit(0);
     }
     
     //queue.offer(shift(line,0));
     //queue.offer(shift(line,1));
     //queue.offer(shift(line,2));
     order.offer("0");
     order.offer("1");
     order.offer("2");

     StringBuffer answer;
     while(true){
    	 String old = order.poll();
    	 if(check(old)) continue;
    	 
    	 int[] now = go(old, line);
    	 int a = fact(now);
    	 if(past[a]) continue;
    	 past[a] = true;
    	 //print(now);
    	 if(compare(now, target)){
    		 answer = new StringBuffer(old);
    		 break;
    	 }
         
         //System.out.println(old);
         order.offer(old+"0");
         order.offer(old+"1");
         order.offer(old+"2");
      }
     
     
     
     
     
     out.println(answer.length());
     answer = convert(answer);
     int count = 0;
     for(int x = 0;x<answer.length();x++){
    	 out.print(answer.charAt(x));
    	 count++;
    	 if(count == 60){
    		 out.println();
    		 count = 0;
    	 }
     }
     out.println();
     
     
     f.close();
     out.close();                             
     System.exit(0);                            
  }
	static int fact(int[]num){
		for(int x = 0;x<8;x++) list[x] = x;
		int sum = 0;
		for(int x = 0;x<7;x++){
			sum+=pow[x]*list[num[x]-1];
			for(int a = num[x];a<8;a++) list[a]--;
			
		}
		return sum;
	}
	
	static int[] go(String s, int [] old){
		int[] start = new int[8];
		for(int x = 0;x<8;x++) start[x] = old[x];
		for(int x = 0;x<s.length();x++){
			start = shift(start, s.charAt(x)-48);
		}
		return start;
	}
	
	
	static boolean check(String in){
		if(in.length()<4) return false;
		
		if(in.charAt(in.length()-1)=='0'){
			if(in.charAt(in.length()-2)=='0') return true;
			return false;
			
		}
		else{
			for(int x = in.length()-1;x>in.length()-4;x--){
				if(in.charAt(x)!=in.charAt(x-1)) return false;
			}
		}
		return true;
		
	}
	
	static boolean compare(int[] one, int [] two){
		for(int x = 0;x<8;x++){
			if(one[x]!=two[x]) return false;
		}
		return true;
	}
	static StringBuffer convert(StringBuffer in){
		StringBuffer done = new StringBuffer("");
		for(int x = 0;x<in.length();x++){
			if(in.charAt(x)=='0') done.append("A");
			else if(in.charAt(x)=='1') done.append("B");
			else if(in.charAt(x)=='2') done.append("C");
		}
		return done;
	}
	
	static void print(int[] printer){
		for(int x = 0;x<4;x++) System.out.print(printer[x]+" ");
		System.out.println();
		for(int x = 4;x<8;x++) System.out.print(printer[x]+" ");
		System.out.println();
	}
	
	static int[] shift(int[] old, int index){
		int[] start = new int[8];
		for(int x = 0;x<8;x++) start[x] = old[x];
		
		switch(index){
		case 0: 
			int[] temp = new int[4];
			for(int x = 0;x<4;x++) temp[x] = start[x];
			for(int x = 0;x<4;x++) start[x] = start[x+4];
			for(int x = 0;x<4;x++) start[x+4] = temp[x]; 
			break;
		case 1:
			int end = start[3];
			start[3]=start[2];
			start[2]=start[1];
			start[1]=start[0];
			start[0]=end;

			end = start[7];
			start[7]=start[6];
			start[6]=start[5];
			start[5]=start[4];
			start[4]=end;
			
			break;
		case 2:
			int rot = start[1];
			start[1] = start[5];
			start[5] = start[6];
			start[6] = start[2];
			start[2] = rot;
			break;
		default: break;
		
		}
		
		return start;
	}
	
	
}