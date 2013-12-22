import java.math.BigInteger;
import java.util.*;

public class fib{
    public static void main(String[] args){
        
        BigInteger a = new BigInteger("1");
        BigInteger b = new BigInteger("2");
        String max = "";
        for(int x = 0;x<999;x++){
            max+="9";
        }
        BigInteger MAX = new BigInteger(max);
        int x = 3;
        BigInteger temp;
        while(MAX.max(b).equals(MAX)){
            temp = a.add(b);
            a = b;
            b = temp;
            x++;
        }
        System.out.println(x);
    }

}
