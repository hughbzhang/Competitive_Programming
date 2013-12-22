import java.math.BigInteger;

public class e{
    public static void main(String[] args){
        BigInteger top = BigInteger.ONE;
        BigInteger bot = BigInteger.ONE;
        BigInteger temp = BigInteger.ONE;
        BigInteger temp2 = BigInteger.ONE;
        BigInteger two = new BigInteger("2");
        BigInteger thr = new BigInteger("3");
        BigInteger eig = new BigInteger("8");
        for(int x = 66;x>2;x-=2){
            temp = bot.multiply(new BigInteger(Integer.toString(x+1))).add(top);
            temp2 = top.multiply(two).add(bot.multiply(new BigInteger(Integer.toString(2*x+1))));
            top = temp;
            bot = temp2;
        }
        top = top.multiply(thr).add(bot.multiply(eig));


        System.out.println(top+"/"+bot);
        String done = top.toString();
        int sum = 0;
        for(int x = 0;x<done.length();x++){
            sum+=done.charAt(x)-'0';
        }
        System.out.println("SUM = "+sum);

    }
}
