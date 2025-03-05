#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2*4e5+10,MAXV=MAXN;

vector<ll> divs[MAXV];
void divisores(){
	fore(i,1,MAXV)for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
}

int main(){FIN;
	divisores();
	ll t; cin>>t;
	while(t--){
		map<ll,ll>mp;
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n){
			cin>>a[i];
			mp[a[i]]++;
		}
		ll B=2*n+5;
		ll res=0;
		for(auto i:mp)res=max(res,i.fst+i.snd);
		vv hist(B);
		// vv all;
		for(auto v:a)if(v<B){
			for(auto d:divs[v]){
				res=max(res,d+(++hist[d]));
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
