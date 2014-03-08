package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: lamps
*/
import java.io.*;
import java.util.*;

public class lamps {
	
	static int length;
	static int counter;
	static int[] end;
	static ArrayList<String> solutions = new ArrayList<String>();
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader f = new BufferedReader(new FileReader("lamps.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lamps.out")));
		length = Integer.parseInt(f.readLine());
		counter = Integer.parseInt(f.readLine());
		end = new int[length];
		
		
		
		
		StringTokenizer st = new StringTokenizer(f.readLine());
		String temp = st.nextToken();
		int holder = 0;
		
		
		for(;;){
			holder = Integer.parseInt(temp)-1;
			if(holder==-2) break;
			end[holder] = 2;
			temp = st.nextToken();
		}
		st = new StringTokenizer(f.readLine());
		temp = st.nextToken();
		for(;;){
			
			holder = Integer.parseInt(temp)-1;
			if(holder==-2) break;
			end[holder] = 1;
			temp = st.nextToken();
		}
		
		
		
		if(counter>2){
			int parity = counter%2;
			
			if(parity==0){
				flip("0");
				flip("12");
				flip("13");
				flip("14");
				flip("23");
				flip("24");
				flip("34");
				flip("1234");
			}
			else{
				flip("1");
				flip("2");
				flip("3");
				flip("4");
				flip("123");
				flip("234");
				flip("134");
				flip("124");
			}
			
		}
		else if(counter==1){
			flip("1");
			flip("2");
			flip("3");
			flip("4");
		}
		else if(counter==2){
			flip("0");
			flip("12");
			flip("13");
			flip("14");
			flip("23");
			flip("24");
			flip("34");
		}
		
		else if(counter==0){
			flip("0");
		}
		
		
		
		
		
		
		
		
		
		
		
		if(solutions.size()==0){
			out.println("IMPOSSIBLE");
			out.close();
			System.exit(0);
		}
		String[] almost = new String[solutions.size()];
		
		for(int x = 0;x<almost.length;x++){
			almost[x]=solutions.get(x);
		}
		
		boolean go = true;
		String storage;
		
		while(go){
			go = false;
			for(int x = 1;x<almost.length;x++){
				if(almost[x].compareTo(almost[x-1])==0){
					almost[x]+="0";
					go = true;
				}
				else if(almost[x].compareTo(almost[x-1])<0){
					storage = almost[x];
					almost[x] = almost[x-1];
					almost[x-1]  = storage;
					go = true;
				}
			}
		}
		
		for(int x = 0;x<almost.length;x++){
			if(almost[x].length()>length) break;
			out.println(almost[x]);
		}
		
		out.close();
		System.exit(0);
		
	}
	static void flip(String rubric){
		
		char key;
		boolean[] pot = new boolean[length];
		
		for(int x = 0;x<length;x++){
			pot[x]=true;
		}
		
		
		for(int x = 0;x<rubric.length();x++){
			key = rubric.charAt(x);
			
			switch(key){
			
			case '1':
				for(int a = 0;a<pot.length;a++) pot[a] = !pot[a];
				break;
			case '2':
				for(int a = 0;a<pot.length;a=a+2) pot[a] = !pot[a];
				break;
			case '3':
				for(int a = 1;a<pot.length;a=a+2) pot[a] = !pot[a];
				break;
			case '4':
				for(int a = 0; a<pot.length;a=a+3) pot[a] = !pot[a];
				break;
			default:
				break;
			}
		}
		
		
		check(pot);
		return;

		
	}
	static void print(boolean[] printer){
		for(int x = 0;x<printer.length;x++){
			System.out.print(printer[x]+" ");
			
		}
		System.out.println();
		System.out.println();
	}
	
	
	static boolean check(boolean[] pot){
		
		if(pot.length!=length) return false;
		for(int x = 0;x<length;x++){
			if(end[x]==1&&pot[x]==true) return false;
			else if(end[x]==2&&pot[x]==false) return false;
		}
		StringBuffer sol = new StringBuffer("");
		for(int x = 0;x<pot.length;x++){
			if(pot[x]) sol.append(1);
			else sol.append(0);
		}
		solutions.add(sol.toString());
		
		return true;
	}	
}