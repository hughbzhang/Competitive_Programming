package Contest;


/*
ID: bigfish2
LANG: JAVA
TASK: TEMPLATE
*/
import java.io.*;
import java.util.*;

public class tied {
	
	static int number;
	static int ropes;
	static int bx;
	static int by;
	static int loc;
	static int[] post;
	static int[] X;
	static int[] Y;
	static boolean[] use;
	static int max;
	static Integer[] subset;
	
  public static void main (String [] args) throws IOException {
	 Scanner in = new Scanner(new FileReader("tied.in"));
     PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tied.out")));
     number = in.nextInt();
     ropes = in.nextInt()+1;
     bx = in.nextInt();
     by = in.nextInt();
     loc = in.nextInt();
     post = new int[number];
     post[0] = in.nextInt();
     X = new int[ropes];
     Y = new int[ropes];
     use = new boolean[number];
     max = (int)Math.pow(2, number);
     Stack<Integer> line = new Stack<Integer>();
     
     for(int x = 1;x<number;x++){
    	 in.next();//skip x coodinate
    	 post[x] = in.nextInt();
     }
     Arrays.sort(post);
     //skip the start location
     for(int x = 0;x<ropes;x++){
    	 X[x] = in.nextInt();
    	 Y[x] = in.nextInt();
     }
     subset = new Integer[max];
     for(int a = 0;a<max;a++) subset[a] = a;
     final Comparator<Integer> mine = new Comparator<Integer>(){
			public int compare(Integer one, Integer two){
				int a = 0;
				int b = 0;
				for(int x = 0;x<max;x++){
					if((one&1<<x)!=0) a++;
					if((two&1<<x)!=0) b++;
				}
				if(b<a) return 1;
				else if(b==a) return 0;
				else return -1;
			}
		};
		Arrays.sort(subset, mine);
		//for(int x = 0;x<max;x++) System.out.println(subset[x]);
     
     for(int a = 0;a<max;a++){
    	 fill(subset[a]);
    	 line.clear();
    	 line.push(-1);
	     for(int x = 0; x<ropes-1;x++){
	    	 int next = intersect(x);
	    	 if(next==-1) continue;
	    	 if(line.peek()==next) line.pop();
	    	 else line.push(next);
	     }
	     if(line.size()==1) break;
     }
     int answer = 0;
     for(int x = 0;x<number;x++){
    	 if(use[x]) answer++;
     }
     out.println(answer);
     
    in.close();
    out.close();                             
    System.exit(0);                            
  }
  static void fill(int index){
	  for(int x = 0;x<number;x++){
		  if(((1<<x)&index)!=0) use[x] = true;
		  else use[x] = false;
	  }
	  
  }
  static int intersect(int index){//index refers to start location
	  int min, max;
	  if(X[index]<=X[index+1]){
		  min = X[index];
		  max = X[index+1];
	  }
	  else{
		  max = X[index];
		  min = X[index+1];
	  }
	  //System.out.println(min+" "+max);
	  if(max<loc) return -1;
	  if(min>=loc) return -1;
	  double slope = ((double)(Y[index]-Y[index+1]))/(X[index]-X[index+1]);
	  double sect = slope*(loc-X[index])+Y[index];
	  //System.out.println(sect);
	  for(int x = 0;x<post.length;x++){
		  if(use[x]) continue;
		  if(sect<post[x]) return x;
	  }
	  return post.length;
  }
  
  
}