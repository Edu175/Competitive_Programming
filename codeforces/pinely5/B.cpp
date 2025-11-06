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
		ll n; cin>>n;
		vector<string> a(n);
		fore(i,0,n)cin>>a[i];
		set<ll> st1,st2;
		ll cant=0,pi=-1,pj=-1;
		fore(i,0,n){
			fore(j,0,n)if(a[i][j]=='#'){
				if(pi==-1)pi=i,pj=j;
				cant++;
				st1.insert(i+j);
				st2.insert(i-j);
			}
		}
		ll fg=0;
		auto doit=[&](set<ll> &st){
			if(SZ(st)>2)return;
			vv a;
			for(auto i:st)a.pb(i);
			if(SZ(a)<=1||abs(a[0]-a[1])==1)fg=1;
		};
		doit(st1);
		doit(st2);
		if(pi!=-1&&cant==4&&pi<n-1&&pj<n-1){
			ll good=1;
			fore(i,0,2)fore(j,0,2)good&=a[pi+i][pj+j]=='#';
			fg|=good;
		}
		if(fg)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
