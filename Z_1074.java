import java.util.*;
import java.io.*;

public class Z_1074{
    static int stoi(String s) { return Integer.parseInt(s);}
 
    static int N;
    static int r;
    static int c;
    static int count = 0;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        N = stoi(st.nextToken());
        r = stoi(st.nextToken());
        c = stoi(st.nextToken());
 
        search(0, 0, getSize(N));
    }

    static void search(int x, int y, int size) {
        if(size == 1) {
            if(x == r && y == c)
                System.out.println(count);
            count++;
            return;
        }
 
        int s = size/2;
 
        search(x, y, s);
        search(x, y+s, s);
        search(x+s, y, s);
        search(x+s, y+s, s);
    }
 
    static int getSize(int n) {
        int result = 1;
        for(int i=0; i<n; i++)
            result *= 2;
        return result;
    }
}