/*
ID: ali201
LANG: JAVA
TASK: namenum
*/

import java.util.*;
import java.io.*;

public class namenum{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("namenum.in"));
                BufferedReader dict = new BufferedReader(new FileReader("dict.txt"));
                FileWriter fw = new FileWriter("namenum.out");
                HashMap<String, ArrayList<String>> map = new HashMap<>();

                String line;
                while((line = dict.readLine()) != null) {
                        String num = "";
                        for(int i = 0; i < line.length(); i++){
                                if(line.charAt(i) == 'A' || line.charAt(i) == 'B' || line.charAt(i) == 'C'){
                                        num = num + "2";
                                }
                                else if(line.charAt(i) == 'D' || line.charAt(i) == 'E' || line.charAt(i) == 'F'){
                                        num = num + "3";
                                }
                                else if(line.charAt(i) == 'G' || line.charAt(i) == 'H' || line.charAt(i) == 'I'){
                                        num = num + "4";
                                }
                                else if(line.charAt(i) == 'J' || line.charAt(i) == 'K' || line.charAt(i) == 'L'){
                                        num = num + "5";
                                }
                                else if(line.charAt(i) == 'M' || line.charAt(i) == 'N' || line.charAt(i) == 'O'){
                                        num = num + "6";
                                }
                                else if(line.charAt(i) == 'P' || line.charAt(i) == 'R' || line.charAt(i) == 'S'){
                                        num = num + "7";
                                }
                                else if(line.charAt(i) == 'T' || line.charAt(i) == 'U' || line.charAt(i) == 'V'){
                                        num = num + "8";
                                }
                                else if(line.charAt(i) == 'W' || line.charAt(i) == 'X' || line.charAt(i) == 'Y'){
                                        num = num + "9";
                                }
                        }
                        //convert all the names to number strings
                        if(map.containsKey(num)){
                                map.get(num).add(line);
                        }
                        else{
                                map.put(num, new ArrayList<String>());
                                map.get(num).add(line);
                        }
                        //put every number to a name in dict
                }
                String numName = br.readLine();
                if(!map.containsKey(numName)){
                        fw.write("NONE\n");
                        fw.close();
                        System.exit(0);
                }
                ArrayList<String> answer = map.get(numName);
                String[] bob = new String[answer.size()];
                for(int i = 0; i < answer.size(); i++){
                        bob[i] = answer.get(i);
                }
                Arrays.sort(bob);
                for(String i: bob){
                        fw.write(i + "\n");
                }

                fw.close();
                dict.close();
                br.close();
        }
}
