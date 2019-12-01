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
                //start = reflect(start);
                //make the arrays
                char[][] ref = reflect(start);
                //checks
                if(Arrays.deepEquals(end, rot90(start))){
                        fw.write(1 + "\n");
                }
                else if(Arrays.deepEquals(end, rot180(start))){
                        fw.write(2 + "\n");
                }
                else if(Arrays.deepEquals(end, rot270(start))){
                        fw.write(3 + "\n");
                }
                else if(Arrays.deepEquals(end, reflect(start))){
                        fw.write(4 + "\n");
                }
                else if(
                (Arrays.deepEquals(end, rot90(ref)))||
                (Arrays.deepEquals(end, rot180(ref)))||
                (Arrays.deepEquals(end, rot270(ref)))
                ){
                        fw.write(5 + "\n");
                }
                else if(Arrays.deepEquals(end, start)){
                        fw.write(6 + "\n");
                }
                else{
                        fw.write(7 + "\n");
                }
                fw.close();
                br.close();

                //brint(start);
                brint(reflect(rot270(start)));
                System.out.println();
                brint(end);
                System.out.println("deepEquals: " + Arrays.deepEquals(end, reflect(rot270(start))));
        }

        public static char[][] reflect(char[][] input){
                char[][] arr = new char[input.length][input.length];
                for(int i = 0; i < input.length; i++){
                        for(int j = 0; j < input.length; j++){
                                arr[i][j] = input[i][input.length - j - 1];
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
        public static char[][] rot180(char[][] input){
                return(rot90(rot90(input)));
        }
        public static char[][] rot270(char[][] input){
                return(rot90(rot180(input)));
        }

        public static void brint(char[][] input){
                for(char[] i: input){
                        System.out.println(i);
                }
        }
}
