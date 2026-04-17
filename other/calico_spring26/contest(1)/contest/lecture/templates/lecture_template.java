import java.io.*;
import java.util.*;

class Solution {
    /**
     * M: number of rows in the lecture hall
     * N: number of columns in the lecture hall
     * K: number of friends who need seats
     * GRID: array of M strings of length N; '#' is a blocked seat, '-' is an empty seat
     *
     * Return a list of K int[2] {row, col} for the chosen seats.
     */
    static List<int[]> solve(int M, int N, int K, String[] GRID) {
        // YOUR CODE HERE
        List<int[]> result = new ArrayList<>();
        for (int i = 0; i < K; i++) {
            result.add(new int[]{0, 0});
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);
        in.resetSyntax();
        in.wordChars('!', '~');
        in.whitespaceChars(0, ' ');

        in.nextToken(); int T = Integer.parseInt(in.sval);
        for (int t = 0; t < T; t++) {
            in.nextToken(); int M = Integer.parseInt(in.sval);
            in.nextToken(); int N = Integer.parseInt(in.sval);
            in.nextToken(); int K = Integer.parseInt(in.sval);
            String[] GRID = new String[M];
            for (int i = 0; i < M; i++) {
                in.nextToken();
                GRID[i] = in.sval;
            }
            List<int[]> result = solve(M, N, K, GRID);
            for (int[] p : result) {
                pw.println(p[0] + " " + p[1]);
            }
        }
        pw.flush();
    }
}
