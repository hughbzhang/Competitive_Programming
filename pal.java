public class pal{
    private static boolean drome(String in){
        for(int x = 0;x<in.length();x++){
            if(in.charAt(x)!=in.charAt(in.length()-x-1)) return false;
        }
        return true;
    }
    
    public static void main(String[] args){
        int sum = 0;
        for(int x = 1;x<1000000;x++){
            String one = Integer.toString(x);
            String two = Integer.toBinaryString(x);
            if(drome(one)&&drome(two)) sum+=x;
        }
        System.out.println(sum);
    }
}
