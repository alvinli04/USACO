/*
ID: ali20
LANG: JAVA
TASK: milk2
*/
 import java.util.*;
 import java.io.*;

 public class milk2{
         public static void main(String[] args) throws IOException{
                 BufferedReader br = new BufferedReader(new FileReader("milk2.in"));
                 FileWriter fw = new FileWriter(new File("milk2.out"));
                 int num = Integer.parseInt(br.readLine());
                 int[][] periods = new int[num][2];
                 for(int i = 0; i < num; i++){
                         String[] temp = br.readLine().split(" ");
                         periods[i][0] = Integer.parseInt(temp[0]);
                         periods[i][1] = Integer.parseInt(temp[1]);
                 }

                 int[] sorted = new int[2*num];
                 int tempCount = 0;
                 for(int[] i: periods){
                         for(int j: i){
                                 sorted[tempCount] = j;
                                 tempCount++;
                         }
                 }
                 Arrays.sort(sorted);
                 boolean[] working = new boolean[sorted[sorted.length - 1] - sorted[0] + 1];
                 Arrays.fill(working, false);

                 for(int[] i: periods){
                         for(int j = 0; j < 2; j++){
                                 i[j] -= sorted[0];
                         }
                 }
                 //test print
                 /*
                 for(int[] i: periods){
                         for(int j: i){
                                 System.out.print(j + " ");
                         }
                         System.out.println();
                 }
                 */

                 for(int[] i: periods){
                         for(int j = i[0]; j < i[1]; j++){
                                 working[j] = true;
                         }
                 }
                 /*
                 for(boolean i: working){
                         System.out.println(i + " ");
                 }
                 */
                 //find plateaus
                 int maxWork = 0;
                 int maxIdle = 0;
                 int pt = 0;
                 int pf = 0;
                 for(int i = 0; i < working.length; i++){
                         if(working[i]){
                                 pt++;
                                 maxIdle = Math.max(maxIdle, pf);
                                 pf = 0;
                         }
                         else{
                                 pf++;
                                 maxWork = Math.max(maxWork, pt);
                                 pt = 0;
                         }
                 }

                 fw.write(maxWork + " " + maxIdle + "\n");

                 fw.close();
                 br.close();
         }

 }
