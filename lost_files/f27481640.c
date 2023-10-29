#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		string s; cin>>s;
		vector<ll>a(n);
		fore(i,0,n)a[i]=s[i]-'0';
		vector<ll>z(n,n),u(n,-1);
		fore(i,0,n){
			if(i)z[i]=z[i-1];
			else z[i]=-1;
			if(!a[i])z[i]=i;
		}
		for(ll i=n-1;i>=0;i--){
			if(i<n-1)u[i]=u[i+1];
			else u[i]=n;
			if(a[i])u[i]=i;
		}
		set<ii>st; //{-1,-1} vacio
		fore(i,0,m){
			ll l,r; cin>>l>>r; l--,r--;
			ll li=u[l],ri=z[r];
			if(ri<li)st.insert({-1,-1});
			else st.insert({li,ri});
		}
		cout<<SZ(st)<<"\n";
	}
	return 0;
}
