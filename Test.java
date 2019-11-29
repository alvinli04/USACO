import java.util.*;
public class Test{
        public static void main(String[] args) {
                char[][] bob = {
                        {'-', '@', '@', '@', '-'},
                        {'-', '@', '@', '-', '-'},
                        {'-', '@', '-', '-', '-'},
                        {'-', '-', '-', '-', '-'},
                        {'-', '-', '-', '-', '-'},
                };

                char[][] joe = {
                        {'-', '@', '@', '@', '-'},
                        {'-', '@', '@', '-', '-'},
                        {'-', '@', '-', '-', '-'},
                        {'-', '-', '-', '-', '-'},
                        {'-', '-', '-', '-', '-'},
                };
                int[] sam = {1,2,3};
                int[] sal = {1,2,3};
                System.out.println(foo(bob, joe));
                //false
        }

        public static boolean foo(char[][] a, char[][] b){
                int len = a.length;
                for(int i = 0; i < len; i++){
                        if(!(Arrays.equals(a[i], b[i]))){
                                return false;
                        }
                }
                return true;
        }
}
