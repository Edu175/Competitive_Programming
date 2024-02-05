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
		ll n; cin>>n;
		string s; cin>>s;
		vector<ll> mx(n);
		mx[n-1]=n-1;
		for(ll i=n-2;i>=0;i--){
			mx[i]=mx[i+1];
			if(s[i]>=s[mx[i]])mx[i]=i;
		}
		vector<ll>p;
		ll x=mx[0];
		while(x<n-1){
			p.pb(x);
			x=mx[x+1];
		}
		p.pb(x);
		ll sz=1;
		fore(i,1,SZ(p)){
			if(s[p[i]]==s[p[i-1]])sz++;
			else break;
		}
		vector<ll>b=p;
		reverse(ALL(b));
		string a=s;
		fore(i,0,SZ(p))a[p[i]]=s[b[i]];
		//imp(p); cout<<a<<"\n";
		string as=a;
		sort(ALL(as));
		ll res=SZ(p)-sz;
		if(a==as)cout<<res<<"\n";
		else cout<<"-1\n";
		//cout<<"\n";
	}
	return 0;
}
