import java.io.*;
import java.util.*;

class Solution {
    /**
     * Build a factory with N rows and M columns that produces the target rate.
     *
     * P: the target numerator of the fraction P / (2^A * 3^B)
     * A: the exponent of 2 in the denominator
     * B: the exponent of 3 in the denominator
     */
    static String[] solve(int P, int A, int B) {
        // YOUR CODE HERE
        return new String[]{"."};
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);

        in.nextToken(); int T = (int) in.nval;
        for (int t = 0; t < T; t++) {
            in.nextToken(); int P = (int) in.nval;
            in.nextToken(); int A = (int) in.nval;
            in.nextToken(); int B = (int) in.nval;
            String[] factory = solve(P, A, B);
            int N = factory.length;
            int M = factory[0].length();
            pw.println(N + " " + M);
            for (String row : factory) {
                pw.println(row);
            }
        }
        pw.flush();
    }
}
