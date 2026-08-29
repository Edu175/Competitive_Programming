#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		sort(ALL(a));
		sort(ALL(b));
		set<ll> st; // a
		ll bad=0;
		queue<ll> q;
		ll po=0;
		fore(i,0,m){
			while(po<n&&a[po]<=b[i]){
				if(!st.count(a[po]))q.push(a[po]);
				po++;
			}
			if(!SZ(q)){bad=1;break;}
			st.insert(q.front());
			q.pop();
		}
		while(SZ(q))q.pop();
		po=n-1;
		for(ll i=m-1;i>=0;i--){
			while(po>=0&&a[po]>=b[i]){
				if(!st.count(a[po]))q.push(a[po]);
				po--;
			}
			if(!SZ(q)){bad=1;break;}
			st.insert(q.front());
			q.pop();
		}
		if(bad)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
