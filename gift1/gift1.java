/*
ID: ali201
LANG: JAVA
TASK: gift1
*/

import java.util.*;
import java.io.*;
class gift1{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("gift1.in"));
                FileWriter fw = new FileWriter(new File("gift1.out"));

                int numberOfPeople = Integer.parseInt(br.readLine());
                HashMap<String, Integer> money = new HashMap<>();
                String[] names = new String[numberOfPeople];
                for(int i = 0; i < numberOfPeople; i++){
                        String name = br.readLine();
                        money.put(name, 0);
                        //System.out.println(name);
                        names[i] = name;
                }
                for(;;){
                        try{
                                String name = br.readLine();
                                String[] moneyInput = br.readLine().split(" ");
                                int given = Integer.parseInt(moneyInput[0]);
                                int people = Integer.parseInt(moneyInput[1]);
                                if(people == 0){
                                        money.replace(name, money.get(name) + given);
                                }
                                else{
                                        money.replace(name, money.get(name) - people * (given / people));
                                }
                                for(int i = 0; i < people; i++){
                                        String bob = br.readLine();
                                        money.replace(bob, money.get(bob) + given / people);
                                }
                        }
                        catch(NullPointerException e){
                                break;
                        }
                }
                for(int i = 0; i < names.length; i++){
                        fw.write(names[i] + " " + money.get(names[i]) + "\n");
                }
                br.close();
                fw.close();
        }
}
