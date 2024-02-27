
// C++ program for Count the number of strings of
// length N  which have string S as subsequence
#include <iostream>
using namespace std;
 
// Initialise mod value.
const int mod = 10007;
 
// Binary exponentiation
long long int power(long long int x, long long int y,
                    long long int p)
{
    long long int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
// Calculate nCr for given n and r
long long int nCr(int n, int r, long long int factorials[])
{
	n%=mod;
    if (r > n)
        return 0;
 	
    long long int answer = factorials[n];
 
    // Divide factorials[r]
    answer *= power(factorials[r], mod - 2, mod);
    answer %= mod;
    // Divide factorials[n-r]
    answer *= power(factorials[n - r], mod - 2, mod);
    answer %= mod;
 
    return answer;
}
 
// Function to count number of possible strings
int numberOfStrings(int N, int X)
{
 
    // if N is less than X, then just print 0.
    if (X > N) {
        return 0;
    }
 	if(X==0)return power(26,N,mod);
    // Precalculate factorials
    long long int factorials[N + 1];
 
    factorials[0] = 1;
    for (int i = 1; i <= N; i++) {
        factorials[i] = factorials[i - 1] * i;
        factorials[i] %= mod;
    }
 
    // Store answer
    long long int answer = 0;
 
    // Iterate over possible ending
    // indices for first subsequence of S
    // in the string
    for (int i = X; i <= N; i++) {
        long long int add
            = nCr(i - 1, X - 1, factorials);
 
        add *= power(26, N - i, mod);
        add %= mod;
 
        add *= power(25, i - X, mod);
        add %= mod;
 
        answer += add;
        if (answer >= mod)
            answer -= mod;
    }
    return (int)answer;
}
 
// Driver Code
int main()
{
    int N,X; cin>>N>>X;
    cout << numberOfStrings(N, X)<<"\n";
    return 0;
}

