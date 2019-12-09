/*
ID: ali201
TASK: milk
LANG: JAVA
*/

import java.util.*;
import java.io.*;

public class milk{
        public static void main(String[] args) throws IOException{
                BufferedReader br = new BufferedReader(new FileReader("milk.in"));
                FileWriter fw = new FileWriter("milk.out");
                String[] foo = br.readLine().split(" ");
                int milkNeeded = Integer.parseInt(foo[0]);
                int numFarmers = Integer.parseInt(foo[1]);

                HashMap<Integer, Integer> prices = new HashMap<>(numFarmers); //price to amt limit.
                int[] sortedPrices = new int[numFarmers];

                for(int i = 0; i < numFarmers; i++){
                        foo = br.readLine().split(" ");
                        prices.put(Integer.parseInt(foo[0]), Integer.parseInt(foo[1]));
                        sortedPrices[i] = Integer.parseInt(foo[0]);
                }
                Arrays.sort(sortedPrices);
                /*
                for(int i: sortedPrices){
                        System.out.print(i + " ");
                }
                */
                int amtBought = 0;
                int moneySpent = 0;
                for(int i = 0; i < sortedPrices.length; i++){
                        if(amtBought + prices.get(sortedPrices[i]) <= milkNeeded){
                                amtBought += prices.get(sortedPrices[i]);
                                moneySpent += sortedPrices[i] * prices.get(sortedPrices[i]);
                                System.out.print(amtBought + " " + moneySpent + " ");
                        }
                        else{
                                moneySpent += sortedPrices[i] * (milkNeeded - amtBought);
                                amtBought = milkNeeded;
                                System.out.print(amtBought + " " + moneySpent + " ");
                                break;
                        }
                }

                fw.write(moneySpent + "\n");
                fw.close();
                br.close();
                //badcase answer: 993159
                //myanswer: 1026829
        }
}
