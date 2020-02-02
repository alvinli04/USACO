import java.util.*;
import java.io.*;

public class Test{
        public static char[] nPermute(String bob, int n) {
                char[] str = bob.toCharArray();
                Arrays.sort(str);
                int i = 1;
                do {
                        if (i == n)
                            break;
                        i++;
                }
                while (next_permutation(str));
                return str;
        }

        public static boolean next_permutation(char[] p){
            for (int a = p.length - 2; a >= 0; --a)
                if (p[a] < p[a + 1])
                for (int b = p.length - 1;; --b)
                    if (p[b] > p[a]){
                        char t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b){
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
            return false;
        }
        
        public static void main(String[] args){
            System.out.println(nPermute("01234567", 2));
        }
}
