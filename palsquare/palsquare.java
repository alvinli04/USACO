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
                //System.out.println(toBaseN(10, 10));
                fw.close();
                br.close();
        }

        public static String toBaseN(int num, int base){
                String out = "";
                int x = num;
                while(x > 0){
                        if(x % base > 9){
                                String add = "ABCDEFGHIJKLMN";
                                out = out + add.substring(x % base - 10, x % base - 9);
                        }
                        else{
                                out = out + Integer.toString(x % base);
                        }
                        x /= base;
                }
                char[] bob = out.toCharArray();
                for(int n = 0; n < bob.length / 2; n++){
                        char temp = bob[n];
                        bob[n] = bob[bob.length - n - 1];
                        bob[bob.length - n - 1] = temp;
                }
                String joe = String.valueOf(bob);
                return(joe);
        }

        public static boolean palindrome(String n){
                String num = n;
                for(int i = 0; i < num.length() / 2; i++){
                        if(num.charAt(i) != num.charAt(num.length() - 1 - i)){
                                return false;
                        }
                }
                return true;
        }
}
