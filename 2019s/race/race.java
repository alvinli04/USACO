import java.util.*;
import java.io.*;

public class race{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("race.in"));
                PrintWriter pw = new PrintWriter(new FileWriter("race.out"));
                String[] numss = br.readLine().split(" ");
                int k = Integer.parseInt(numss[0]);
                int numLines = Integer.parseInt(numss[1]);
                for(int i = 0; i < numLines; i++){
                        if(k == 0){
                                pw.println(1);
                                continue;
                        }
                        pw.println(leastTime(k, Integer.parseInt(br.readLine())));
                }
                pw.close();
                br.close();
                //System.out.println(mountain(2,2));
        }

        public static int mountain(int max, int min){
                int s1 = max*(max + 1)/2;
                int s2 = max*(max-1)/2 - min*(min-1)/2;
                return s1 + s2;
                //length: 2*max - min
        }

        public static int leastTime(int k, int x){
                //find biggest possible mountain
                int iFin = 0;
                for(int i = x; mountain(i, x) < k; i++){
                        iFin = i;
                }
                if(iFin == 0){
                        for(int i = 1; ;i++){
                                if(i*(i+1)/2 >= k) return i;
                        }
                }
                int secF = 2 * iFin - x;
                //System.out.println(secF);
                int diff = k - mountain(iFin, x);
                int added = (int) Math.ceil((float) diff/iFin);
                //System.out.println(added);
                return secF + added;
        }
}
