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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,kmax; cin>>n>>kmax;
		string s,t; cin>>s>>t;
		vv to(n+1,n-1);
		ll mx=0,fg=1;
		for(ll i=n-1;i>=0;i--){
			to[i]=to[i+1];
			to[i]=min(to[i],i);
			while(to[i]>=0&&s[to[i]]!=t[i])to[i]--;
			if(to[i]==-1)fg=0;
			mx=max(mx,i-to[i]);
		}
		if(!fg||mx>kmax){
			cout<<"-1\n";
			continue;
		}
		vector<string> mat(mx+1,string(n,'.'));
		fore(p,0,n){
			ll j=to[p];
			fore(i,0,mx+1){
				mat[i][j]=t[p];
				if(j<p)j++;
			}
		}
		mat[0]=s;
		fore(i,1,mx+1)fore(j,0,n){
			if(mat[i][j]=='.')mat[i][j]=mat[i-1][j];
		}
		cout<<mx<<"\n";
		fore(i,1,mx+1)cout<<mat[i]<<"\n";
	}
	return 0;
}
