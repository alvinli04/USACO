import java.util.*;
import java.io.*;

public class word{

        public static void main(String[] args) throws Exception
        {
                BufferedReader br = new BufferedReader(new FileReader("word.in"));
                PrintWriter pw = new PrintWriter(new FileWriter("word.out"));
                String[] nums = br.readLine().split(" ");
                int k = Integer.parseInt(nums[1]);
                String[] words = br.readLine().split(" ");
                outer:
                for(int i = 0; i < words.length; i++)
                {
                        int tot = words[i].length();
                        pw.print(words[i]);
                        for(int j = i + 1; j < words.length; j++)
                        {
                                tot += words[j].length();
                                //System.out.println(tot);
                                if(tot > k)
                                {
                                        i = j - 1;
                                        System.out.println(i);
                                        pw.println();
                                        break;
                                }
                                pw.print(" " + words[j]);
                                if(j == words.length - 1)
                                {
                                        //System.out.println("k");
                                        break outer;
                                }
                                System.out.println(words[j]);
                        }
                }
                pw.close();
                br.close();
        }

}
