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
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		vv sp(n+1);
		vector<vector<ll>> pos(n);
		fore(i,0,n){
			if(i&1)swap(a[i],b[i]);
			pos[a[i]].pb(i);
			pos[b[i]].pb(i);
			sp[i+1]=sp[i]+(a[i]==b[i]);
		}
		// imp(a)
		// imp(b)
		// imp(sp)
		auto get=[&](ll p, ll q, ll dif)->ll{
			ll fg=0;
			fore(h,0,2){
				ll u=(h?a:b)[p];
				ll v=(h^dif?a:b)[q];
				fg|=u==v;
			}
			if(!fg)return 0;
			if(p==q&&dif)return 0;
			ll ret=0;
			if(abs(p-q)==1&&!dif)ret=0;
			else ret=p+1+sp[n]-sp[q+1];
			// cout<<p<<","<<q<<" "<<same<<": "<<ret<<"\n";;
			return ret;
		};
		ll res=0;
		fore(c,0,n){
			auto &v=pos[c];
			// cout<<"color "<<c<<"\n";
			// for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
			fore(i,0,SZ(v)-1)fore(j,0,2){
				res=max(res,get(v[i],v[i+1],j));
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
