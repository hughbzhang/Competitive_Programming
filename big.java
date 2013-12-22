import java.math.*;
import java.util.*;

public class big{
    public static void main(String[] args){
        
        BigInteger mod = new BigInteger("10000000000");
        BigInteger sum = BigInteger.ZERO;
        BigInteger temp;
        for(int x = 1;x<1000;x++){
            temp = new BigInteger(Integer.toString(x));
            sum = sum.add(temp.modPow(temp,mod));
            sum = sum.mod(mod);
        }
        System.out.println(sum);
    }
}
