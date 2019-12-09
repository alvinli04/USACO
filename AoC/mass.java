import java.util.*;
import java.io.*;
public class mass{
        public static void main(String[] args) throws Exception{
                BufferedReader br = new BufferedReader(new FileReader("input.txt"));
                int sum = 0;
                for(int i = 1; i <= 100; i++){
                        int initfuel = Integer.parseInt(br.readLine());
                        //int mod;
                        while(initfuel > 0){
                                int mod = initfuel / 3 - 2;
                                if(mod > 0){
                                        sum += mod;
                                }
                                initfuel = mod;
                        }
                }
                System.out.println(sum);
        }
}
