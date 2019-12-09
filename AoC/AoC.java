import java.io.*;
import java.util.*;

public class AoC{

        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("input.txt"));
                String[] in = br.readLine().split(",");
                int[] yee = new int[in.length];
                for(int i = 0; i < yee.length; i++){
                        yee[i] = Integer.parseInt(in[i]);
                }
                System.out.println(foo(yee));
        }

        public static int foo(int[] input){
                //int[] arr = {1,a,b,3,1,1,2,3,1,3,4,3,1,5,0,3,2,13,1,19,1,19,10,23,1,23,13,27,1,6,27,31,1,9,31,35,2,10,35,39,1,39,6,43,1,6,43,47,2,13,47,51,1,51,6,55,2,6,55,59,2,59,6,63,2,63,13,67,1,5,67,71,2,9,71,75,1,5,75,79,1,5,79,83,1,83,6,87,1,87,6,91,1,91,5,95,2,10,95,99,1,5,99,103,1,10,103,107,1,107,9,111,2,111,10,115,1,115,9,119,1,13,119,123,1,123,9,127,1,5,127,131,2,13,131,135,1,9,135,139,1,2,139,143,1,13,143,0,99,2,0,14,0};
                int[] arr = input;
                int i = 0;
                while(i < input.length){
                        int opcode = arr[i] % 100;
                        int p1 = arr[i] / 100 % 10;
                        int p2 = arr[i] / 1000 % 10;
                        int g1;
                        int g2;
                        if(p1 == 0){
                                g1 = arr[arr[i+1]];
                        }
                        else{
                                g1 = arr[i+1];
                        }
                        if(p2 == 0){
                                g2 = arr[arr[i+2]];
                        }
                        else{
                                g2 = arr[i+2];
                        }

                        if(opcode == 99){
                                break;
                        }
                        else if(opcode == 1){
                                arr[arr[i+3]] = g1 + g2;
                                i += 4;
                        }
                        else if(opcode == 2){
                                arr[arr[i+3]] = g1 * g2;
                                i += 4;
                        }
                        else if(opcode == 3){
                                int num = 1;
                                arr[arr[i+1]] = num;
                                i += 2;
                        }
                        else if(opcode == 4){
                                System.out.println(arr[arr[i+1]]);
                                i += 2;
                        }
                }
                return arr[0];
        }
}
