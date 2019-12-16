import java.util.*;
import java.io.*;

public class lineup{
        static HashMap<Integer, ArrayList<Integer>> with = new HashMap<>();

        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("lineup.in"));
                PrintWriter pw = new PrintWriter(new FileWriter("lineup.out"));
                int numRes = Integer.parseInt(br.readLine());
                String[] names = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"}; //id: names[id] (id -> name)
                HashMap<String, Integer> map = new HashMap<>(); // name -> id 01234567
                for(int i = 0; i < 8; i++){
                        map.put(names[i], i);
                }


                for(int i = 0; i < 8; i++){
                        with.put(i, new ArrayList<Integer>());
                }

                for(int i = 0; i < numRes; i++){
                        String[] foo = br.readLine().split(" ");
                        int id1 = map.get(foo[0]);
                        int id2 = map.get(foo[foo.length - 1]);
                        with.get(id1).add(id2);
                        with.get(id2).add(id1);
                }
                int[] bob = find();
                for(int i = 0; i < bob.length; i++){
                        pw.println(names[bob[i]]);
                }
                pw.close();
                br.close();
        }

        public static int[] find(){
                for(int i = 1; i < 40321; i++){
                        char[] foo = nPermute("01234567", i);
                        //System.out.println(foo.length);
                        int[] test = new int[8];
                        for(int j = 0; j < 8; j++){
                                test[j] = Integer.parseInt(String.valueOf(foo[j]));
                                //System.out.print(j);
                        }
                        if(viable(test)){
                                return test;
                        }
                }
                return null;
        }
        public static boolean viable(int[] test){
                for(int k = 1; k < 7; k++){
                        for(int l = 0; l < with.get(test[k]).size(); l++){
                                if(!(with.get(test[k]).get(l) == test[k + 1] || with.get(test[k]).get(l) == test[k - 1])){
                                        return false;
                                }
                        }
                }
                if(with.get(test[0]).get(0) != test[1] || with.get(test[7]).get(0) != test[6]){
                        return false;
                }
                return true;
        }


        public static char[] nPermute(String bob, int n) {
                char[] str = bob.toCharArray();
            Arrays.sort(str);
            int i = 1;
            do {
                if (i == n)
                    break;
                i++;
            }
            while (next_permutation(str));
            return str;
        }

        public static boolean next_permutation(char[] p){
            for (int a = p.length - 2; a >= 0; --a)
                if (p[a] < p[a + 1])
                for (int b = p.length - 1;; --b)
                    if (p[b] > p[a]){
                        char t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b){
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
            return false;
        }

}
