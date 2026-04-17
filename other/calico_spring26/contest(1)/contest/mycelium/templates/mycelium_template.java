import java.io.*;

class Solution {
    /**
     * Return the total number of tiles mycelium will ever occupy.
     *
     * X_G: x-coordinate of grass starting position
     * Y_G: y-coordinate of grass starting position
     * X_M: x-coordinate of mycelium starting position
     * Y_M: y-coordinate of mycelium starting position
     */
    static int solve(int X_G, int Y_G, int X_M, int Y_M) {
        // YOUR CODE HERE
        return -1;
    }

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String[] temp = in.readLine().split(" ");
            int X_G = Integer.parseInt(temp[0]), Y_G = Integer.parseInt(temp[1]);
            int X_M = Integer.parseInt(temp[2]), Y_M = Integer.parseInt(temp[3]);
            out.println(solve(X_G, Y_G, X_M, Y_M));
        }
        out.flush();
    }
}
