package Solved;
/*
ID: bigfish2
LANG: JAVA
TASK: gifts
*/
import java.io.*;
import java.util.*;

public class gifts {
  public static void main (String [] args) throws IOException {
    BufferedReader f = new BufferedReader(new FileReader("gifts.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gifts.out")));
    
    StringTokenizer st = new StringTokenizer(f.readLine());
    
    
  
    int number = Integer.parseInt(st.nextToken());    
    int temp = -1;
    int money = Integer.parseInt(st.nextToken()); 
    int index = -1;
    int storage;
    boolean go = true;
    boolean coupon = true;
    int nextcheapest = 0; 
    int couponindex = -1;
    int fmoney = -1;
    
    System.out.println(fmoney+couponindex+nextcheapest+index);
    System.out.println(coupon);
    
 ArrayList<Integer> buying = new ArrayList<Integer>();
 ArrayList<Integer> pot = new ArrayList<Integer>();

    
    
    int[][] prices =new int[number][4];//y then x
    
    for(int x=0;x<number;x++){
    	StringTokenizer holder = new StringTokenizer(f.readLine());
    	
    	
    	prices[x][0] = Integer.parseInt(holder.nextToken());    //price of gift
    	prices[x][1] = Integer.parseInt(holder.nextToken());    //shipping
    	prices[x][2] = prices[x][0]+prices[x][1]; //total cost without coupon
    	prices[x][3] = (prices[x][0]/2)+prices[x][1]; //total cost with coupon
      if(temp<prices[x][0]){
    	  temp = prices[x][0];
    	  couponindex = x;
      }
    
    }
  
   
    
   while(go){
	   go = false;
	   for(int x = 1;x<number;x++){
		   if(prices[x][2]<prices[x-1][2]){
			   storage = prices[x][2];
			   prices[x][2] = prices[x-1][2];
			   prices[x-1][2]=storage;
			   storage = prices[x][0];
			   prices[x][0] = prices[x-1][0];
			   prices[x-1][0]=storage;
			   
			   go = true;
		   }
	   }
   }
   int tmoney = money;

   for(int y = 0;y<number;y++){
    	tmoney=money;
    	
    	tmoney-=prices[y][3];
    	if(tmoney<0) continue;
    	pot.add(y);
    	
    	
    for(int x = 0;x<number;x++){
    	if(pot.contains(x)) continue;
    	if(tmoney>=prices[x][2]){
    		tmoney-=prices[x][2];
    		// System.out.println(money);
    		pot.add(x);
    		continue;
    	}    		
    	else{
    		index = x;
    		
    		break;	
    	}
    }
    if(pot.size()>buying.size()){
    	buying.clear();

        for(int a = 0;a<pot.size();a++){
        	buying.add(pot.get(a));
        }
        fmoney=tmoney;
    	
       
    	
    }
    pot.clear();
    
    
    }

   
    
   //System.out.println(fmoney);
    /*
    if(buying.contains(couponindex)){
    	money-=prices[couponindex][3];
    	money+=prices[couponindex][2];
    	 for(int x = 0;x<number;x++){
    	    	if(buying.contains(x)) continue;
    	    	if(money>=prices[x][2]){
    	    		money-=prices[x][2];
    	    		buying.add(x);
    	    		continue;
    	    	}    		
    	    	else break;
    	    	
    	    }
    }
    
    
    
    
    
    else{
    	if(money>=prices[couponindex][3]){
    		buying.add(couponindex);
    		money-=temp;
    		
    	}
    }*/
    
    
  //System.out.println(money);
    
    
    
    
    
   // System.out.println(money);
    
    
    
    out.println(buying.size());          
    out.close();                                 
    System.exit(0);                       
  }
}