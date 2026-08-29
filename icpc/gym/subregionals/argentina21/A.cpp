#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(int i=(b)-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int MOD=1e9+7;

constexpr int CUTOFF = 14; // The O(N^2) base-case threshold

void karatsuba_core(const int* a, const int* b, int* res, int n, int* scratch) {
    if (n <= CUTOFF) {
        for (int i = 0; i < 2 * n; ++i) res[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (!a[i]) continue;
            for (int j = 0; j < n; ++j) {
                res[i + j] = (res[i + j] + 1LL * a[i] * b[j]) % MOD;
            }
        }
        return;
    }

    int half = n >> 1;
    
    int* a_sum = scratch;
    int* b_sum = scratch + half;
    int* p3 = scratch + n;
    int* next_scratch = scratch + 2 * n;

    for (int i = 0; i < half; ++i) {
        a_sum[i] = a[i] + a[i + half];
        if (a_sum[i] >= MOD) a_sum[i] -= MOD; 
        
        b_sum[i] = b[i] + b[i + half];
        if (b_sum[i] >= MOD) b_sum[i] -= MOD;
    }

    karatsuba_core(a, b, res, half, next_scratch);
    karatsuba_core(a + half, b + half, res + n, half, next_scratch);
    karatsuba_core(a_sum, b_sum, p3, half, next_scratch);

    // FIX: Calculate the middle term entirely before modifying 'res'
    for (int i = 0; i < n; ++i) {
        int sub_val = res[i] + res[i + n];
        if (sub_val >= MOD) sub_val -= MOD;
        
        p3[i] -= sub_val;
        if (p3[i] < 0) p3[i] += MOD; 
    }

    // Now safely add the middle term in place
    for (int i = 0; i < n; ++i) {
        res[i + half] += p3[i];
        if (res[i + half] >= MOD) res[i + half] -= MOD;
    }
}

vector<int> multiply_karatsuba(const vector<int>& A, const vector<int>& B) {
    if (A.empty() || B.empty()) return {};
    
    int req_len = SZ(A) + SZ(B) - 1;
    
    int n = 1;
    while (n < max(SZ(A), SZ(B))) n <<= 1;
    
    vector<int> a(n, 0), b(n, 0);
    copy(A.begin(), A.end(), a.begin());
    copy(B.begin(), B.end(), b.begin());
    
    vector<int> res(2 * n, 0);
    vector<int> scratch(4 * n, 0);
    
    karatsuba_core(a.data(), b.data(), res.data(), n, scratch.data());
    
    res.resize(req_len);
    return res;
}

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=5005;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}

int main(){FIN;
	factos();
	int n,R; cin>>n>>R;
	vector<int> a(n);
	fore(i,0,n)cin>>a[i],a[i]=R-a[i]+1; // r[i] = [0,a[i])
	for(ll i=n-2;i>=0;i--)a[i]=min(a[i],a[i+1]);
	if(a[0]<0){
		cout<<"0\n";
		return 0;
	}
	auto vals=a; vals.resize(unique(ALL(vals))-vals.begin());
	ll m=SZ(vals);
	vector<int> d(m); fore(i,0,SZ(d))d[i]=vals[i]-(!i?0:vals[i-1]);
	// show(a);
	// show(d);
	vector<vector<int>> dp(2,vector<int>(n+1));
	dp[m&1][n]=1;
	forr(v,0,m){
		auto &ac=dp[v&1];
		auto &otr=dp[(v+1)&1];
		ll l=n;
		fore(i,0,n)if(a[i]>=vals[v]){l=i;break;}
		vector<int> c(n-l+1);
		c[0]=1;
		fore(i,1,SZ(c))c[i]=mul(d[v]+i-1,c[i-1]);
		fore(i,0,SZ(c))c[i]=mul(c[i],fci[i]);
		// show(c)
		reverse(ALL(c));
		
		ll s=n;
		fore(i,0,n+1)if(otr[i]){s=i;break;}
		vector<int> pol(otr.begin()+s,otr.end());
		
		// cerr<<"l "<<l<<"\n";
		auto got=multiply_karatsuba(c,pol);
		// show(got)
		ac=vector<int>(n+1);
		fore(i,l,n+1)ac[i]=got[SZ(c)-1-s+i];
		// cout<<v<<": ";
		// show(ac)
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}
