import java.io.*;
import java.util.*;

class Solution {
    /**
     * Simulate the factory and return the final output as the fraction P / Q,
     * stored as a two-element array {P, Q}.
     *
     * N: number of rows in the factory grid
     * M: number of columns in the factory grid
     * factory: array of N strings of length M, each character one of '^<>vSX.'
     */
    static long[] solve(int N, int M, String[] factory) {
        // YOUR CODE HERE
        return new long[]{-1, -1};
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int T = Integer.parseInt(br.readLine().trim());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            String[] factory = new String[N];
            for (int i = 0; i < N; i++) factory[i] = br.readLine();
            long[] ans = solve(N, M, factory);
            pw.println(ans[0] + " " + ans[1]);
            pw.flush();
        }
    }
}
