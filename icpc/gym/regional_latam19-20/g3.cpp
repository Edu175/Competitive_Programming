#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
#define bint __int128
const bint MOD=212345678987654321LL,P=1777771;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(bint a, bint b){return a*b%MOD;}
vector<int> z_function(string& s){
	int l=0,r=0,n=SZ(s);
	vector<int>z(SZ(s),0);
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-1]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}
const ll C=200;

int main(){ET
	string s; cin>>s;
	ll m; cin>>m;
	vector<string> a(m);
	fore(i,0,m)cin>>a[i];
	fore(i,0,m){
		ll res=0;
		auto t=a[i];
		if(SZ(t)>=C){
			string b=t+"$"+s;
			auto z=z_function(b);
			ll p=0;
			while(p<SZ(t)){
				res++;
				ll k=
			}
		}
	}
}