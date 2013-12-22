import java.io.*;
import java.util.*;

public class MST{
    
    static class edge{
        int length;
        int start;
        int end;    

        public edge(int a,int b,int c){
            length = a;
            start = b;
            end = c;
        }
    }

    final static Comparator<edge> mine = new Comparator<edge>(){
        public int compare(edge one, edge two){
            if(one.length < two.length) return -1;
            if(one.length > two.length) return 1;
            else return 0;
        }
    };

    static PriorityQueue<edge> heap = new PriorityQueue<edge>(1000, mine);

    static int dis[];
    static long sum = 0, total = 0;

    static int head(int cur){
        if(dis[cur] == cur) return cur;
        dis[cur] = head(dis[cur]);
        return dis[cur];
    }
    static void merge(int one, int two){
        int first = head(one);
        int sec = head(two);
        dis[first] = sec;
    }
     
    
    public static void main(String[] args) throws IOException{
        int matrix[][] = new int[40][40]; 
        dis = new int[40];
        for(int x = 0;x<40;x++){
            dis[x] = x;
        }
        BufferedReader f = new BufferedReader(new FileReader("network.txt"));
        String temp;
        int prior = 0, cnt = 0;
        for(int x = 0; x<40;x++){
            temp = f.readLine();
            temp+=',';
            prior = 0;
            cnt = 0;
            for(int a = 0;a<temp.length();a++){
                if(temp.charAt(a)==','){
                    if(temp.charAt(a-1)=='-'){
                        prior = a+1;
                        cnt++;
                    }
                    else{
                        if(prior>a) break;
                        
                        int num = Integer.parseInt(temp.substring(prior,a));
                        
                        prior = a+1;
                        matrix[x][cnt] = num;
                        total+=num;
                        heap.add(new edge(num,x,cnt));
                        cnt++;
                    }
                }
            }
        }
        while(!heap.isEmpty()){
            edge next = heap.poll();
            if(head(next.start)==head(next.end)) continue;
            sum += next.length;
            merge(next.start,next.end);
        }
        if(total%2==1) System.out.println("bad");
        System.out.println(total/2-sum);
        for(int x = 0;x<40;x++){
            System.out.print(matrix[0][x]+" ");
        }
    }
}
