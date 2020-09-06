import java.io.*;
import java.util.*;

public class HourGlassSum {
    public static int getHourGlassSum(int a[][], int rownum, int colnum) {
        int m = a.length;
        int n = a[0].length;
        //System.out.println("m = "+m+" n = "+ n);
        int sum = 0;
        for(int i = rownum; i < rownum + 3; i++) {
            for(int j = colnum; j < colnum + 3; j++) {
                sum = sum + a[i][j];
            }
        }
        
        return sum - a[rownum + 1][colnum] - a[rownum + 1][colnum + 2];
    }
    public static void main(String[] args) throws IOException {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int m = 6;
        int n = 6;
        TreeSet<Integer> ts = new TreeSet();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] a = new int[m][n];
        for(int i = 0; i < m; i++) {
            String[] row = br.readLine().split("\\s");
            for (int j = 0; j < n; j++) {
                a[i][j] = Integer.parseInt(row[j]);
            }
        }
        for(int i = 0; i < m; i++) {        
            for (int j = 0; j < n; j++) {
                if(i + 3 <= m && j + 3 <= n) {
                    ts.add(getHourGlassSum(a, i,j) );    
                }
                
            }
        }        
        System.out.println(Collections.max(ts));
        /*
        for(int i = 0; i < m; i++) {
            
            for (int j = 0; j < n; j++) {
                System.out.print (a[i][j] + " ");
            }
            System.out.println();
        }*/
    }
}