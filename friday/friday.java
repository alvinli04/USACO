/*
ID: ali201
LANG: JAVA
TASK: friday
*/
import java.util.*;
import java.io.*;

class friday{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("friday.in"));
                FileWriter fw = new FileWriter(new File("friday.out"));
                int years = Integer.parseInt(br.readLine());
                int currentyear = 1900;
                int[] freq = new int[7]; //starts saturday, for monday start counter at 2
                int counter = 2;
                int[] months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                int[] monthsLeap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                for( ; currentyear < 1900 + years; currentyear++){
                        if(currentyear % 400 == 0 || (currentyear % 4 == 0 && currentyear % 100 != 0)){
                                for(int month = 0; month < 12; month++){ //month is index of month array
                                        for(int day = 1; day <= monthsLeap[month]; day++){
                                                if(day == 13){
                                                        freq[counter]++;
                                                }
                                                counter++;
                                                counter = counter % 7;
                                        }
                                }
                        }
                        else{
                                for(int month = 0; month < 12; month++){ //month is index of month array
                                        for(int day = 1; day <= months[month]; day++){
                                                if(day == 13){
                                                        freq[counter]++;
                                                }
                                                counter++;
                                                counter = counter % 7;
                                        }
                                }
                        }
                }
                for(int i = 0; i < 7; i++){
                        if(i < 6){
                                fw.write(freq[i] + " ");
                        }
                        else{
                                fw.write(freq[i] + "\n");
                        }
                }
                br.close();
                fw.close();
        }
}
