import java.util.*;
import java.io.*;

public class photo{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("photo.in"));
                PrintWriter pw = new PrintWriter(new FileWriter("photo.out"));
                int n = Integer.parseInt(br.readLine());
                String[] numss = br.readLine().split(" ");
                int[] nums = new int[n-1];
                for(int i = 0; i < n-1; i++){
                        nums[i] = Integer.parseInt(numss[i]);
                }

                int[] reordered = new int[n];
                for(int j = 1; j < nums[0]; j++){
                        boolean repeat = false;
                        reordered = new int[n];
                        reordered[0] = j;
                        reordered[1] = nums[0] - j;
                        for(int i = 2; i < reordered.length; i++){
                                reordered[i] = reordered[i - 2] + (nums[i-1] - nums[i-2]);
                        }
                        int lowest = Integer.MAX_VALUE;
                        for(int i : reordered){
                                if(i < lowest) lowest = i;
                        }
                        if(lowest < 0){
                                for(int i = 0; i < n; i++){
                                        reordered[i] += lowest + 1;
                                }
                        }
                        Set<Integer> set = new HashSet<>();
                        for(int i : reordered){
                                if(set.add(i) == false){
                                        repeat = true;
                                        break;
                                }
                        }
                        int highest = -1;
                        for(int i : reordered){
                                if(i > highest) highest = i;
                        }
                        if(highest > n) repeat = true;
                        if(!repeat) break;
                }
                pw.print(reordered[0]);
                for(int i = 1; i < n; i++){
                        pw.print(" " + reordered[i]);
                }
                pw.close();
                br.close();
        }
}
