/*
ID: ali20
LANG: JAVA
TASK: dualpal
*/

import java.util.*;
import java.io.*;

public class dualpal{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("dualpal.in"));
                FileWriter fw = new FileWriter(new File("dualpal.out"));
                String[] input = br.readLine().split(" ");
                int n = Integer.parseInt(input[0]);
                int s = Integer.parseInt(input[1]);
                br.close();
                //first n numbers greater than s palindromic in 2 or more bases
                //2<=base<=10
                int[] nums = new int[n];
                int index = 0;
                int toFill = 0;

                for(int i = s + 1; toFill < n; i++){
                        int palBases = 0;
                        for(int b = 2; b < 11 && palBases < 2; b++){
                                if(palindrome(toBaseN(i, b))){
                                        palBases++;
                                }
                        }
                        if(palBases == 2){
                                //System.out.println(index + " " + i);
                                toFill++;
                                nums[index] = i;
                                index++;
                        }
                }
                for(int i = 0; i < nums.length; i ++){
                        fw.write(nums[i] + "\n");
                }
                fw.close();
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
