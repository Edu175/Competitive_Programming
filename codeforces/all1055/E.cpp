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

vv ask(vv a){
	cout<<"? "<<SZ(a)<<" ";
	for(auto i:a)cout<<i+1<<" ";
	cout<<endl;
	ll c; cin>>c;
	if(c==-1)exit(0);
	vv ret(c);
	fore(i,0,c)cin>>ret[i],ret[i]--;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll N=n*n+1;
		vv vis(N);
		vector<vv> a;
		fore(_,0,n){
			vv s;
			fore(i,0,N)if(!vis[i])s.pb(i);
			if(!SZ(s))break;
			auto r=ask(s);
			for(auto i:r)vis[i]=1;
			a.pb(r);
		}
		if(count(ALL(vis),0)){
			ll p=-1;
			fore(i,0,N)if(!vis[i]){p=i;break;}
			assert(p!=-1);
			a.pb({p});
		}
		vv res;
		if(SZ(a)>n){
			ll p=a.back()[0];
			res={p};
			for(ll i=SZ(a)-2;i>=0;i--){
				p=*prev(lower_bound(ALL(a[i]),p));
				res.pb(p);
			}
			reverse(ALL(res));
		}
		else {
			for(auto v:a)if(SZ(v)>n)res=v;
		}
		assert(SZ(res)>n);
		while(SZ(res)>n+1)res.pop_back();
		assert(SZ(res)==n+1);
		cout<<"! ";
		for(auto i:res)cout<<i+1<<" ";;cout<<endl;
	}
	return 0;
}
