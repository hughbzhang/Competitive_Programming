import java.math.BigInteger;
import java.util.*;

public class powers{
    static int NUM = 4;

    static BigInteger[] arr = new BigInteger[NUM*NUM];

    public static void main(String[] args){
        int cnt = 0;
        int ans = 1;
        for(int x = 2;x<NUM+2;x++){
            BigInteger cur = new BigInteger(Integer.toString(x));
            for(int y = 2;y<NUM+2;y++){
                arr[cnt] = cur.pow(y);
                cnt++;
            }
        }
        Arrays.sort(arr);
        System.out.println(arr[0]);
        for(int x = 1;x<cnt;x++){
            System.out.println(arr[x]);
            if(!arr[x].equals(arr[x-1])) ans++;
        }

    System.out.println(ans);
    }
} 
