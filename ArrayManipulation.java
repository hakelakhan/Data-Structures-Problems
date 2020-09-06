import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class ArrayManipulation {

    public static void main(String[] args) throws IOException{
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        /*HashMap<Integer,Integer> hm = new HashMap();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String row[] = br.readLine().split("\\s");
        int n = Integer.parseInt(row[0]);
        int m = Integer.parseInt(row[1]);
        for(int i = 0; i < n; i++) {
            hm.put(i + 1, 0);
        }
        for(int i = 0; i < m; i++) {        
            String abk[] = br.readLine().split("\\s");
            int a = Integer.parseInt(abk[0]);
            int b = Integer.parseInt(abk[1]);
            int k = Integer.parseInt(abk[2]);
            for(int j = a; j <= b; j++) {
                hm.put(j, hm.get(j) + k);
            }
        }
        
        System.out.println(Collections.max(hm.values())); */
        /*
        HashMap<Integer,BigInteger> hm = new HashMap();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String row[] = br.readLine().split("\\s");
        int n = Integer.parseInt(row[0]);
        int m = Integer.parseInt(row[1]);
        for(int i = 0; i < n; i++) {
            hm.put(i + 1, new BigInteger("0"));
        }
        for(int i = 0; i < m; i++) {        
            String abk[] = br.readLine().split("\\s");
            int a = Integer.parseInt(abk[0]);
            int b = Integer.parseInt(abk[1]);
            BigInteger k = new BigInteger(abk[2]);
            for(int j = a; j <= b; j++) {
                 hm.put(j, ((BigInteger)hm.get(j)).add(k));
            }
        }
        Comparator<BigInteger> cmp = new Comparator<BigInteger>() {            
            public int compare(BigInteger a, BigInteger b) {
                return a.compareTo(b);
            }
        };        
        System.out.println(Collections.max(hm.values(), cmp));
        */

        /*
                HashMap<Integer,Integer> hm = new HashMap();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String row[] = br.readLine().split("\\s");
        int n = Integer.parseInt(row[0]);
        int m = Integer.parseInt(row[1]);
        for(int i = 0; i < n; i++) {
            hm.put(i + 1, 0);
        }
        for(int i = 0; i < m; i++) {        
            String abk[] = br.readLine().split("\\s");
            int a = Integer.parseInt(abk[0]);
            int b = Integer.parseInt(abk[1]);
            int k = Integer.parseInt(abk[2]);
            hm.put(a, hm.get(a) + k);
            if(b != n) {
                hm.put(b + 1, hm.get(b + 1) - k);
            }
            //System.out.println(hm.values()); 
        }
        int sum = 0;      
        int max = hm.get(1);
        for(int i  = 1; i <= n; i++) {
            sum = sum + hm.get(i);
            if(sum > max) {
                max = sum;
            }
        }
        //System.out.println(hm.values()); 
        System.out.println(max);

        */
        /*
        HashMap<Integer,BigInteger> hm = new HashMap();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String row[] = br.readLine().split("\\s");
        int n = Integer.parseInt(row[0]);
        int m = Integer.parseInt(row[1]);
        for(int i = 0; i < n; i++) {
            hm.put(i + 1, new BigInteger("0"));
        }
        for(int i = 0; i < m; i++) {        
            String abk[] = br.readLine().split("\\s");
            int a = Integer.parseInt(abk[0]);
            int b = Integer.parseInt(abk[1]);
            BigInteger k = new BigInteger(abk[2]);
            hm.put(a, hm.get(a).add(k));
            if(b != n) {
                hm.put(b + 1, (hm.get(b + 1)).subtract(k));
            }
            //System.out.println(hm.values()); 
        }
        BigInteger sum = new BigInteger("0");      
        BigInteger max = hm.get(1);
        for(int i  = 1; i <= n; i++) {
            sum = sum.add(hm.get(i));
            if(sum.compareTo(max) > 0 ) {
                max = sum;
            }
        }
        //System.out.println(hm.values()); 
        System.out.println(max.toString());
        */
        
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String row[] = br.readLine().split("\\s");
        int n = Integer.parseInt(row[0]);
        int m = Integer.parseInt(row[1]);
        long[] hm = new long[n];
        for(int i = 0; i < m; i++) {        
            String abk[] = br.readLine().split("\\s");
            int a = Integer.parseInt(abk[0]);
            int b = Integer.parseInt(abk[1]);            
            long k = Long.parseLong(abk[2]);
            hm[a - 1] = hm[a - 1] + k;
            if(b != n) {
                hm[b] = hm[b] - k;                
            }
            //System.out.println(hm.values()); 
        }
        long sum = 0L;      
        long max = hm[0];
        for(int i = 0; i < hm.length; i++) {
            sum = sum + hm[i];
            max = Math.max(sum, max);
        }
        //System.out.println(hm.values()); 
        System.out.println(max);

    }    
}