#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXF=4e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b); e>>=1;
	}
	return r;
}
ll fc[MAXF],fci[MAXF],med=(MOD+1)/2;
ll nCr(ll n, ll k){
	if(n<0||k<0||n-k<0)return 0;
	return mul(fc[n],mul(fci[k],fci[n-k]));
}

int main(){
	JET
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
	
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		if(m>n){cout<<"0\n";continue;}
		if(m==n){cout<<mul(fc[n-1],med);continue;}
		
		set<vector<vv>>st;
		vv per(n); iota(ALL(per),0);
		do{
			vv hay(n-1);
			fore(i,0,m)hay[i]=1;
			sort(ALL(hay));
			do{
				vector<vv>a;
				vv tmp;
				fore(i,0,n){
					tmp.pb(per[i]);
					if(i==n-1||!hay[i])a.pb(tmp),tmp.clear();
				}
				for(auto &i:a){
					vv r=i;
					reverse(ALL(r));
					if(r<i)i=r;
				}
				sort(ALL(a));
				st.insert(a);
			}while(next_permutation(ALL(hay)));
		}while(next_permutation(ALL(per)));
		cout<<SZ(st)<<"\n";
	}
	return 0;
}
