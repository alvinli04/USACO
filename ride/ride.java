/*
ID: ali201
LANG: JAVA
TASK: ride
*/

import java.util.*;
import java.io.*;
class ride{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("ride.in"));
                FileWriter fw = new FileWriter(new File("ride.out"));
                String a = br.readLine();
                String b = br.readLine();
                String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                char[] alph = alphabet.toCharArray();
                int prod1 = 1;
                int prod2 = 1;
                for(char i: a.toCharArray()){
                        for(int j = 0; j < alph.length; j++){
                                if(i == alph[j]){
                                        prod1 *= j+1;
                                        continue;
                                }
                        }
                }
                for(char i: b.toCharArray()){
                        for(int j = 0; j < alph.length; j++){
                                if(i == alph[j]){
                                        prod2 *= j+1;
                                        continue;
                                }
                        }
                }
                if(prod1 % 47 == prod2 % 47){
                        fw.write("GO\n");
                }
                else{
                        fw.write("STAY\n");
                }
                br.close();
                fw.close();
        }
}
