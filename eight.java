package Contest;

import java.awt.Point;
/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;

public class eight {
	static class sorter{
		int start;
		int end;
		int value;
		int length;
		int min;
		
		public sorter(int a, int b, int c, int d){
			start = a;
			end = b;
			value = c;
			length = end-start;
			min = d;
		}
		public String toString(){
			return start+" "+end+" "+value;
		}
		
	}
	
  public static void main (String [] args) throws IOException {
     BufferedReader f = new BufferedReader(new FileReader("eight.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("eight.out")));
     int size = Integer.parseInt(f.readLine());
     int pos = size*(size-1)/2;
     Point[] interval = new Point[pos];
     int[] topmax = new int[pos];
     int[] topmin = new int[pos];
     int[] botmax = new int[pos];
     int[] botmin = new int[pos];
     for(int x = 0;x<pos;x++){
    	 topmax[x] = -1;
    	 topmin[x] = -1;
    	 botmax[x] = -1;
    	 botmin[x] = -1;
    	 
     }
     int index = 0;
     boolean[][] field = new boolean[size][size];
     for(int y = 0;y<size;y++){
    	 String temp = f.readLine();
    	 for(int x = 0;x<size;x++){
    		 if(temp.charAt(x)=='.') field[y][x] = true;
    	 }
     }
     for(int x = 0;x<size-1;x++){
    	 int cur = size-x-1;
    	 int a = 0;
    	 while((a+cur)<size){
    		 interval[index] = new Point(a, a+cur);
    		 index++;
    		 a++;
    	 }
     }
     int[][] bad = new int[size][size+1];//first one is marker
     int[][] vert = new int[size][2];//0 is top 1 is bottom
     for(int x = 0;x<size;x++){
    	 int last = -1;
    	 boolean first = true;
    	 for(int y = 0;y<size;y++){
    		 if(field[y][x]==false){
    			 if(first){
    				 vert[x][0] = y;
    				 first = false;
    			 }
    			 last = y;
    		 }
    	 }
    	 if(first) vert[x][0] = size+1;
    	 vert[x][1] = last;
     }
     
     for(int y = 0;y<size;y++) for(int x = 1;x<=size;x++) bad[y][x] = -1;
     for(int y = 0;y<size;y++) bad[y][0] = 1;
     
     for(int y = 0;y<field.length;y++){
		  for(int x = 0;x<field[0].length;x++){
			  if(field[y][x]==false){
				  bad[y][bad[y][0]] = x;
				  bad[y][0]++;
			  }
		  }
	 }
     for(int a = 0;a<pos;a++){//loop through each interval
    	 int start = interval[a].x;
    	 int end = interval[a].y;
    	 mid: for(int x = 0;x<size;x++){//loops through the grid
    		 //if any bad[x][a] is within range continue loop
    		 //otherwise break and mark it
    		 int first = 1;
    		 int last = bad[x][0]-1;
    		 index = (first+last)/2;
    		 while(first<=last){//BINARY SEARCH
				if(bad[x][index]>=start&&bad[x][index]<=end) continue mid;
				if(bad[x][index]<start) first = index+1;
				else last = index-1;
				index = (first+last)/2;
    		 }
    		 topmax[a] = x;
    		 break;
    	 } 
     }
     
     for(int a = 0;a<pos;a++){//loop through each interval
    	 
    	 int start = interval[a].x;
    	 int end = interval[a].y;
    	 int here = Math.max(vert[start][1], vert[end][1]);
    	 if(here==-1) here = 0;
    	 if(here>=size) here = size-1;
    	 mid: for(int x = here;x<size;x++){//loops through the grid
    		 //if any bad[x][a] is within range continue loop
    		 //otherwise break and mark it
    		 int first = 1;
    		 int last = bad[x][0]-1;
    		 index = (first+last)/2;
    		 while(first<=last){//BINARY SEARCH
				if(bad[x][index]>=start&&bad[x][index]<=end) continue mid;
				if(bad[x][index]<start) first = index+1;
				else last = index-1;
				index = (first+last)/2;
    		 }
    		 botmax[a] = x;
    		 break;
    	 } 
     }
     for(int a = 0;a<pos;a++){//loop through each interval
    	 int start = interval[a].x;
    	 int end = interval[a].y;
    	 mid: for(int x = size-1;x>=0;x--){//loops through the grid
    		 //if any bad[x][a] is within range continue loop
    		 //otherwise break and mark it
    		 int first = 1;
    		 int last = bad[x][0]-1;
    		 index = (first+last)/2;
    		 while(first<=last){//BINARY SEARCH
				if(bad[x][index]>=start&&bad[x][index]<=end) continue mid;
				if(bad[x][index]<start) first = index+1;
				else last = index-1;
				index = (first+last)/2;
    		 }
    		 botmin[a] = x;
    		 break;
    	 } 
     }
     int holder = 0;
     for(int a = 0;a<pos;a++){//loop through each interval
    	 int start = interval[a].x;
    	 int end = interval[a].y;
    	 int here = Math.min(vert[start][0], vert[end][0]);
    	 if(here==-1) here = size-1;
    	 if(here>=size) here = size-1;
    	 mid: for(int x = here;x>=0;x--){//loops through the grid
    		 //if any bad[x][a] is within range continue loop
    		 //otherwise break and mark it
    		 int first = 1;
    		 int last = bad[x][0]-1;
    		 index = (first+last)/2;
    		 while(first<=last){//BINARY SEARCH
				if(bad[x][index]>=start&&bad[x][index]<=end) continue mid;
				if(bad[x][index]<start) first = index+1;
				else last = index-1;
				index = (first+last)/2;
    		 }
    		 topmin[a] = x;
    		 if(topmin[a]>holder) holder = topmin[a];
    		 break;
    	 } 
     }
    /* sorter[] sorted = new sorter[pos];
     for(int x = 0;x<pos;x++){
    	 sorted[x] = new sorter(interval[x].x, interval[x].y, topmin[x], topmax[x]);
     }
     
     final Comparator<sorter> mine = new Comparator<sorter>(){
			public int compare(sorter one, sorter two){
				if(one.value<two.value) return 1;
				if(one.value>two.value) return -1;
				//same value
				if((one.length)<(two.length)) return 1;
				if((one.length)>(two.length)) return -1;
				return 0;
			}
		};
     Arrays.sort(sorted, mine);*/
     /*int[] hash = new int[size];
     for(int x = 0;x<size;x++) hash[x] = -1;
     for(int x = 0;x<pos;x++){
    	 if(sorted[x].value==-1) continue;
    	 if(hash[sorted[x].value]==-1) hash[sorted[x].value] = x;
     }
     int start = holder-1;
     holder = hash[holder];
     int length = sorted[holder].length;
     for(int x = start;x>=0;x--){
    	 if(hash[x]==-1){
    		 hash[x] = holder;
    		 continue;
    	 }
    	 int cur = sorted[hash[x]].length;
    	 if(length>cur) hash[x] = holder;
    	 else if(length<cur){
    		 length = cur;
    		 holder = hash[x];
    	 }
     }*/
     
     long answer = -1;
   //  Point bot = new Point(0,0);
     for(int x = 0;x<pos;x++){
    	 int width = interval[x].y-interval[x].x;
    	 int height = size-botmax[x]-1;
    	 long area = (width-1)*(height-1);
    	 if(area*(size-2-botmax[x])*(width)<answer) break;
    	 long curarea = 0;
    	 for(int a = 0;a<pos;a++){

    		 if((interval[a].y-interval[a].x-1)*(botmax[x]-1)<curarea) break;
    		 if(interval[a].x<interval[x].x) continue;
    		 if(interval[a].y>interval[x].y) continue;
    		 if(topmin[a]<botmax[x]) continue;
    		 long temp = (interval[a].y-interval[a].x-1)*(botmax[x]-topmax[a]-1);
    		 if(temp>curarea){
    			 curarea = temp;
    		 }
    	 }
    	 area*=curarea;
    	 if(area>answer){
    		 answer = area;
//    		 bot = interval[x];
    	 }
     }
     out.println(answer);
     
     
     
     
     
     
     
     
    f.close();
    out.close();                             
    System.exit(0);                            
  }
  static void print(boolean[][]field){
	  for(int y = 0;y<field.length;y++){
		  for(int x = 0;x<field[0].length;x++){
			  if(field[y][x]) System.out.print(".");
			  else System.out.print("*");
		  }
		  System.out.println();
	     }
	  
	  
  }
  static void print(int[][]field){
	  for(int y = 0;y<field.length;y++){
		  for(int x = 0;x<field[0].length;x++){
			  System.out.print(field[y][x]+" ");
		  }
		  System.out.println();
	     }
	  
	  
  }
}