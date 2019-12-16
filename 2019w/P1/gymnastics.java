import java.util.*;
import java.io.*;

public class gymnastics{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("gymnastics.in"));
                PrintWriter pw = new PrintWriter(new FileWriter("gymnastics.out"));
                String[] L = br.readLine().split(" ");
                int numLines = Integer.parseInt(L[0]);
                int numCows = Integer.parseInt(L[1]); //cow ids are from 1 -> n
                HashMap<Integer, ArrayList> betterThan = new HashMap<>();

                String[] foo = br.readLine().split(" ");
                int[] cows = new int[numCows];
                for(int i = 1; i <= numCows; i++){
                        cows[i - 1] = i;
                }

                for(int i = 0; i < foo.length; i++){
                        betterThan.put(Integer.parseInt(foo[i]), new ArrayList<Integer>());

                        for(int j = i + 1; j < foo.length; j++){
                                betterThan.get(Integer.parseInt(foo[i])).add(Integer.parseInt(foo[j]));
                        }
                        //System.out.println(betterThan.get(Integer.parseInt(foo[i])).toString());
                }

                for(int i = 0; i < numLines - 1; i++){
                        foo = br.readLine().split(" ");
                        for(int j = 0; j < foo.length; j++){
                                for(int k = j + 1; k < foo.length; k++){
                                        int key = Integer.parseInt(foo[j]);
                                        Integer removed = new Integer(Integer.parseInt(foo[k]));
                                        //System.out.println(key + " " + removed);
                                        if(betterThan.get(removed).contains(key)){
                                                betterThan.get(removed).remove(new Integer(key));
                                                //System.out.println(betterThan.get(key).toString());
                                        }
                                }
                        }
                }
                int sum = 0;
                for(int i : cows){
                        sum += betterThan.get(i).size();
                        System.out.println(betterThan.get(i).toString());
                }
                pw.println(sum);
                pw.close();
                br.close();
        }

}
