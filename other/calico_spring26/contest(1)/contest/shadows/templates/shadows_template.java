import java.io.*;

class Solution {
    /**
     * Return the maximal and minimal volume of the shape (in that order)
     *
     * N: max dimensions of shape
     * S1: projection (shadow) in X-Z plane
     * S2: projection (shadow) in Y-Z plane
     */
    static String solve(int N, String[] S1, String[] S2) {
        // YOUR CODE HERE
        return "-1 -1";
    }

	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(in.readLine());
            String[] S1 = new String[N];
            for (int i = 0; i < N; i++) {
                S1[i] = in.readLine();
            }
            String[] S2 = new String[N];
            for (int i = 0; i < N; i++) {
                S2[i] = in.readLine();
            }
            out.println(solve(N, S1, S2));
        }
        
        out.flush();
        out.close();
        in.close();
    }
}
