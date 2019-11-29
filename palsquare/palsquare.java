/*
ID: ali201
LANG: JAVA
TASK: palsquare
*/

import java.io.*;
import java.util.*;

public class palsquare{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("palsquare.in"));
                FileWriter fw = new FileWriter(new File("palsquare.out"));
                //1 <= N <= 300 b10
                int base = Integer.parseInt(br.readLine());
                for(int i = 1; i < 301; i++){
                        if(palindrome(toBaseN(i * i, base))){
                                fw.write(toBaseN(i, base) + " " + toBaseN(i*i, base) + "\n");
                        }
                }
                fw.close();
                br.close();
        }

        public static int toBaseN(int num, int base){
                String out = "";
                int x = num;
                while(x > 0){
                        out += x % base;
                        x /= base;
                }
                
                return Integer.parseInt(out);
        }

        public static boolean palindrome(int n){
                String num = Integer.toString(n);
                for(int i = 0; i < num.length() / 2; i++){
                        if(num.charAt(i) != num.charAt(num.length() - 1 - i)){
                                return false;
                        }
                }
                return true;
        }
}
