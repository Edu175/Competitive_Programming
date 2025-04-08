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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll num(string a){
	ll n=SZ(a);
	ll q=0;
	fore(i,0,n){
		if(i==n-1||a[i]!=a[i+1])q++;
	}
	return q-1;
}
ll bfs(string a){
	if(!SZ(a))return {};
	// reverse(ALL(a));
	unordered_set<string>st;
	queue<pair<ll,string>>q;
	st.insert(a);
	q.push({0,a});
	ll n=SZ(a);
	ll res=n+5;
	while(SZ(q)){
		auto [d,x]=q.front(); q.pop();
		if(d>=res)break;
		// cout<<d<<": "; imp(x)
		res=min(res,d+num(x));
		fore(i,1,n-2){
			auto y=x;
			swap(y[i],y[i+1]);
			if(!st.count(y)){st.insert(y);q.push({d+1,y});}
		}
	}
	// cout<<"bfs ";;for(auto i:a)cout<<i<<" ";;cout<<"= "<<res<<"\n";
	return res;
}
ll get(vv a){
	ll n=SZ(a);
	vector<ii>sa;
	fore(i,0,n)sa.pb({a[i],i});
	sort(ALL(a));
	string s(n,'.');
	char k='a';
	fore(i,0,n){
		s[sa[i].snd]=k;
		if(i<n-1&&sa[i].fst!=sa[i+1].fst)k++;
	}
	return bfs(s);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv dp(n); dp[n-1]=0;
		for(ll i=n-2;i>=0;i--){
			auto &res=dp[i];
			res=n+5;
			vv b={a[i]};
			fore(j,i+1,min(n,i+8)){
				b.pb(a[j]);
				res=min(res,get(b)+dp[j]);
			}
			// cerr<<i<<"\n";
		}
		cout<<dp[0]+1<<"\n";
	}
	return 0;
}
