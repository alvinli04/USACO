/*
ID: ali201
LANG: JAVA
TASK: transform
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

                //tset print
                //System.out.println();

                //checks
                if(equals(end, rot(start))){
                        fw.write(1 + "\n");
                }
                else if(equals(end, rot(rot(start)))){
                        fw.write(2 + "\n");
                }
                else if(equals(end, rot(rot(start)))){
                        fw.write(3 + "\n");
                }
                else if(equals(end, reflect(start))){
                        fw.write(4 + "\n");
                }
                else if(
                (equals(end, reflect(rot(start))))||
                (equals(end, reflect(rot(rot(start)))))||
                (equals(end, reflect(rot(rot(rot(start))))))
                ){
                        fw.write(5 + "\n");
                }
                else if(equals(end, start)){
                        fw.write(6 + "\n");
                }
                else{
                        fw.write(7 + "\n");
                }
                fw.close();
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

        public static char[][] rot(char[][] input){
                char[][] arr = new char[input.length][input[0].length];
                for(int i = 0; i < input.length; i++){
                        for(int j = 0; j < input[0].length; j++){
                                arr[j][arr[0].length - i - 1] = input[i][j];
                        }
                }
                return arr;
        }
        public static boolean equals(char[][] a, char[][] b){
                int len = a.length;
                for(int i = 0; i < len; i++){
                        for(int j = 0; j < len; j++){
                                if(a[i][j] != b[i][j]){
                                        return false;
                                }
                        }
                }
                return true;
        }
}
