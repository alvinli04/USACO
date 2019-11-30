import java.util.*;
public class Test{
        public static void main(String[] args) {
                System.out.println(toBaseN(35, 2));
                int n = 10000000000;
        }
        public static int toBaseN(int num, int base){
                String out = "";
                int x = num;
                while(x > 0){
                        out = out + Integer.toString(x % base);
                        x /= base;
                }
                char[] bob = out.toCharArray();
                for(int n = 0; n < bob.length / 2; n++){
                        char temp = bob[n];
                        bob[n] = bob[bob.length - n - 1];
                        bob[bob.length - n - 1] = temp;
                }
                String joe = String.valueOf(bob);
                int res = Integer.parseInt(joe);
                return res;
        }
}
