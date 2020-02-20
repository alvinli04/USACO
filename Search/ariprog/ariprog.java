/*
ID: ali201
TASK: ariprog
LANG: JAVA
*/

import java.util.*;
import java.io.*;
public class ariprog{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("ariprog.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("ariprog.out"));

		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		br.close();

		TreeSet<Integer> bisquares = new TreeSet<Integer>();
		for(int i = 0; i <= M; i++){
			for(int j = 0; j <= M; j++){
				bisquares.add(i*i + j*j);
			}
		}
		
		HashMap<Integer, ArrayList<Integer>> toVal = new HashMap<Integer, ArrayList<Integer>>();
		boolean exists = false;

		for(Integer i : bisquares){
			Set<Integer> ss = bisquares.subSet(i, false, bisquares.last(), true);
			outer: for(Integer j : ss){
				int diff = j - i;
				for(int k = 0; k < N; k++){
					if(!bisquares.contains(i + k*diff)){
						continue outer;
					}
				}
				exists = true;
				if(!toVal.keySet().contains(diff)){
					toVal.put(diff, new ArrayList<Integer>());
				}
				toVal.get(diff).add(i);
			}
		}
		
		Integer[] keys = new Integer[toVal.keySet().size()];
		toVal.keySet().toArray(keys);
		Arrays.sort(keys);
		for(Integer i : keys){
			Collections.sort(toVal.get(i));
		}
		for(Integer i : keys){
			for(Integer j : toVal.get(i)){
				pw.println(j + " " + i);
			}
		}
		if(!exists){
			pw.println("NONE");
		}
		pw.close();
	}

}
