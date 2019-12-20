import java.util.*;
import java.io.*;

public class whereami{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("whereami.in"));
                PrintWriter pw = new PrintWriter(new FileWriter("whereami.out"));
                int len = Integer.parseInt(br.readLine());
                String str = br.readLine();
                br.close();
                int least = 0;
                for(int i = 1; i <= len; i++){ //i is substring length
                        if(noRepeats(str, i)){
                                least = i;
                                break;
                        }
                }
                pw.println(least);
                pw.close();
        }

        public static boolean noRepeats(String str, int subLength){
                for(int i = 0; i <= str.length() - subLength; i++){
                        for(int j = i + 1; j <= str.length() - subLength; j++){
                                if(str.substring(i, i+subLength).equals(str.substring(j, j+subLength))){
                                        return false;
                                }
                        }
                }
                return true;
        }
}
