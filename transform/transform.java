/*
ID: ali201
LANG: JAVA
TASK: ride
*/

import java.io.*;
import java.util.*;

public class transform{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("transform.in"));
                FileWriter fw = new FileWriter(new File("transform.out"));

                int n = Integer.parseInt(br.readLine());
                char[][] start = new char[n][n];
                char[][] end = new char[n][n];
                for(int i = 0; i < n; i++){
                        start[i] = br.readLine().toCharArray();
                }
                for(int i = 0; i < n; i++){
                        end[i] = br.readLine().toCharArray();
                }
                //make the arrays
                if(Arrays.equals(end, start)){
                        fw.write(6 + "\n");
                        fw.close();
                }
                else if(Arrays.equals(end, reflect(start))){
                        fw.write(4 + "\n");
                        fw.close();
                }
                else{
                        for(int i = 1; i < 4; i++){
                                start = rot90(start);
                                if(Arrays.equals(start, end)){
                                        fw.write(i + "\n");
                                        fw.close();
                                }
                                else if(Arrays.equals(reflect(start), end)){
                                        fw.write(5 + "\n");
                                        fw.close();
                                }
                        }
                        fw.write(7 + "\n");
                        fw.close();
                }
                br.close();


        }

        public static char[][] reflect(char[][] input){
                char[][] arr = input;
                for(char[] i: arr){
                        for(int j = 0; j < i.length / 2; j++){
                                char n = i[j];
                                i[j] = i[i.length - j - 1];
                                i[i.length - j - 1] = n;
                        }
                }
                return arr;
        }

        public static char[][] rot90(char[][] input){
                char[][] arr = new char[input.length][input[0].length];
                for(int i = 0; i < input.length; i++){
                        for(int j = 0; j < input[0].length; j++){
                                arr[j][arr[0].length - i - 1] = input[i][j];
                        }
                }
                return arr;
        }
}
