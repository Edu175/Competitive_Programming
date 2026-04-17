import java.io.*;
import java.util.*;

class Solution {
    /**
     * Return a two-element Object array { int[] A, int[] discards } where
     * A has length N (values in [1, 10^9]) and discards contains at most D
     * distinct 1-indexed cell indices.
     *
     * The discards output line will begin with t, the number of discarded
     * cells, followed by those t indices; t is computed and written for
     * you in main().
     *
     * N: length of the array A
     * M: number of cells
     * D: maximum number of cells you may discard
     * cells: M-by-4 array; cells[k] = {R, C, V, W}. For cell k (0-indexed
     *        here, 1-indexed in the output), the product A[R] * A[C] should
     *        be close to the target V, with weight W
     */
    static Object[] solve(int N, int M, int D, int[][] cells) {
        // YOUR CODE HERE
        int[] A = new int[N];
        Arrays.fill(A, 1);
        int[] discards = new int[0];
        return new Object[]{A, discards};
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StreamTokenizer in = new StreamTokenizer(br);

        in.nextToken(); int N = (int) in.nval;
        in.nextToken(); int M = (int) in.nval;
        in.nextToken(); int D = (int) in.nval;
        int[][] cells = new int[M][4];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 4; j++) {
                in.nextToken();
                cells[i][j] = (int) in.nval;
            }
        }

        Object[] result = solve(N, M, D, cells);
        int[] A = (int[]) result[0];
        int[] discards = (int[]) result[1];

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if (i > 0) sb.append(' ');
            sb.append(A[i]);
        }
        pw.println(sb);
        sb.setLength(0);
        sb.append(discards.length);
        for (int idx : discards) sb.append(' ').append(idx);
        pw.println(sb);
        pw.flush();
    }
}
