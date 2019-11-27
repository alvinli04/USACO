/*
ID: ali201
LANG: JAVA
TASK: beads
*/
import java.util.*;
import java.io.*;

public class beads{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("beads.in"));
                FileWriter fw = new FileWriter(new File("beads.out"));
                int beadNum = Integer.parseInt(br.readLine());
                String input = br.readLine();
                input.concat(input);
                char[] necklace = input.toCharArray();
                int highestSum = 0;
                for(int i = 0; i < necklace.length - 1; i++){
                        int backsum = 0;
                        int fdsum = 0;
                        // Iterate backwards
                        if(necklace[i] == 'b' && necklace[i+1] == 'r' || necklace[i] == 'r' && necklace[i+1] == 'b'){
                                for(int j = i; (necklace[j] == necklace[i] || necklace[j] == 'w') && j > 0; j--){
                                        backsum++;
                                }
                                for(int j = i + 1; (necklace[j] == necklace[i+1] || necklace[j] == 'w') && j < necklace.length - 1; j++){
                                        fdsum++;
                                }
                                highestSum = Math.max(highestSum, fdsum + backsum);
                        }
                }
                fw.write(highestSum + 1 + "\n");
                br.close();
                fw.close();
                }

        //rrrbr
}
