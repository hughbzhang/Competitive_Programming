/*
ID:bigfish2
LANG: JAVA
TASK: buylow
*/

import java.math.*;
import java.io.*;
import java.util.*;



public class buylow{
    public static void main(String[] args) throws IOException{
        BufferedReader f = new BufferedReader(new FileReader("buylow.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("buylow.out")));
        int num = Integer.parseInt(f.readLine());
        int day[] = new int[num];
        int pre[] = new int[num];
        BigInteger cnt[] = new BigInteger[num];
        TreeSet<Integer> vis = new TreeSet<Integer>();
        String temp, good = "";
        temp = f.readLine();
        for(int x = 0;x<num;x++){
            cnt[x] = BigInteger.ZERO;
        }
        while(temp!=null){
            good+=(temp);
            good+=" ";
            temp = f.readLine();
        }
        StringTokenizer st = new StringTokenizer(good);
        for(int x = 0;x<num;x++){
            day[x] = Integer.parseInt(st.nextToken());
        }
        int best = 0;
         for(int y = num-1;y>=0;y--){
            pre[y] = 1;
            cnt[y] = BigInteger.ONE;
            vis.clear();
            for(int x = y+1;x<num;x++){
                if(day[y]>day[x]){//if this is lower
                    if(pre[x]>=pre[y]){//reset our best
                        pre[y] = pre[x]+1;
                        vis.clear();
                        cnt[y] = BigInteger.ZERO;
                    }
                    if(pre[x] == pre[y]-1&&!vis.contains(day[x])){//we'll take it
                        vis.add(day[x]);
                        cnt[y]=cnt[y].add(cnt[x]);
                    }
                }
            }
            if(pre[y]>best) best = pre[y];
         }
         vis.clear();
        BigInteger ans = BigInteger.ZERO;
        for(int x = 0;x<num;x++){
            if(best==pre[x]&&!vis.contains(day[x])){
                ans = ans.add(cnt[x]);
                vis.add(day[x]);
            }
        }
        out.println(best + " " + ans);
        out.close(); 
    }
}
