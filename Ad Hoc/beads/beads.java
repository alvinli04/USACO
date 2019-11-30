/*
ID: ali201
LANG: JAVA
TASK: beads
*/
import java.util.*;
import java.io.*;

public class beads{
        public static void main(String[] args) throws Exception{
                //IO
                BufferedReader br = new BufferedReader(new FileReader("beads.in"));
                FileWriter fw = new FileWriter(new File("beads.out"));
                int beadNum = Integer.parseInt(br.readLine());
                String input = br.readLine();

                input = input + input; //doubles string so it loops like a circle
                //System.out.println(input);
                int plateau1 = 0; // stores p2
                int plateau2 = 0; //updates continuously
                int max = 0; //stores max 2 plateau val
                int initPos = 0; //initial pos block thing
                int lastnum = 0;
                for(int i = 1; i < input.length(); i++){
                        //forms plateaus after a string of whites and other color
                        if(input.charAt(initPos) == input.charAt(i) || input.charAt(i) == 'w'){
                                continue;
                        }
                        else{
                                //go back for whites by looping back a little
                                int numW = 0;
                                for(int j = initPos - 1; j >= 0 && input.charAt(j) == 'w'; j--){
                                        numW++;
                                }
                                //System.out.println(numW);

                                //stores last plateau and starts making a new one
                                plateau1 = plateau2;
                                plateau2 = i - initPos;
                                initPos = i;

                                //update max
                                max = Math.max(max, plateau1 + plateau2 + lastnum);
                                System.out.println(max);
                                lastnum = numW;
                        }
                }

                if(plateau1 == 0 || max > input.length() / 2){
                        fw.write(input.length() / 2 + "\n");
                        //if homogeneous it's the whole thing
                }
                else{
                        fw.write(max + "\n");
                }
                br.close();
                fw.close();
                //wwwbbrwrbrbrrbrbrwrwwrbwrwrrbwwwbbrwrbrbrrbrbrwrwwrbwrwrrb
        }
}
