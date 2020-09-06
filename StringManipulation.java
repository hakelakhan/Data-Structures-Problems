import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class StringManipulation {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        char ch1, ch2;
        int del = 0, n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int k = 0 ; k < n; k++) {
            String str = sc.next();
            del = 0;
            if(str.length() == 0) {
                System.out.println("0");
                return;
            }
            ch1 = str.charAt(0);
            for(int i = 1; i < str.length() ; i++) {
                ch2 = str.charAt(i);
                if(ch1 == ch2) {
                    del++;

                }
                else {
                    ch1 = str.charAt(i);
                }

            }
            System.out.println(del+"");    
            }
        
        
        
    }
}