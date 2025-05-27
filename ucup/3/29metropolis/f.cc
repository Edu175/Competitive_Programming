#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MOD=998244353, MAXN=1e5+10;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int f[MAXN],inv[MAXN],invf[MAXN];
int cmb(int n, int k){return n<k?0:mul(f[n],mul(invf[k],invf[n-k]));}
void init_facs(){	//call before using cmb!!
	inv[1]=1; fore(i,2,MAXN) inv[i]=mul(sub(0,MOD/i),inv[MOD%i]);
	f[0]=invf[0]=1;
	fore(i,1,MAXN) f[i]=mul(f[i-1],i), invf[i]=mul(invf[i-1],inv[i]);
}

int get(int n){
    
    vector<int> b(n+1);
    b[1]=1;
    fore(i,2,n+1){
        int asd=f[i];
        fore(x,1,i) asd=sub(asd, mul(b[x], f[i-x]));
        b[i]=asd;
    }
    cout<<"b: ";;fore(i,0,n+1)cout<<b[i]<<" ";;cout<<"\n";
    vector<int> dp(n+1);
    dp[1]=0;
    fore(i,2,n+1){
        int sum=b[i];
        fore(k,2,i){
            sum=add(sum, mul(mul(b[k], f[i-k]), add(add(1, dp[k]), dp[i-k])));
			sum+=b[k]*f[i-k]*(1+dp[k]+dp[i-k])
        }

        int den=sub(f[i], b[i]);
        den=fpow(den, MOD-2);

        int one=mul(dp[i-1], f[i-1]);

        dp[i]=mul(add(one, sum), den);
        cout<<i<<": "<<dp[i]<<"\n";
    }
    
    return dp.back();
}


int main(){FIN;
    init_facs();

    int n; cin>>n;
    vector<int> a(n);
    fore(i,0,n) cin>>a[i],a[i]--;

    int pos=0;
    int ans=0;

    while(pos<n){
        int id=pos;
        set<int> s={a[pos]};
        while(*s.begin()!=pos || *s.rbegin()!=id){
            id++;
            s.insert(a[id]);
        }

        int can=1;
        fore(i,pos,id+1){
            can&=a[i]==i;
        }

        if(can)continue;

        ans=add(ans, add(1, get(id-pos+1)));

        pos=id+1;
    }
	get(10);
    cout<<ans<<"\n";
}
