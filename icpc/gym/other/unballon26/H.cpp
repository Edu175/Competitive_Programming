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
const ll MAXV=1e5+5;
int cr[MAXV];
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
map<int,int> fact(int n){
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}
const ll MX=18;

int main(){FIN;
	init_sieve();
	ll q; cin>>q;
	vv es(MAXV);
	set<ll> st;
	vv ta(MAXV);
	while(q--){
		ll ty,x; cin>>ty>>x;
		if(ty==1){
			auto fa=fact(x);
			for(auto [p,e]:fa)if(ta[p]<2){
				es[p]=min(MX,es[p]+e);
				if(es[p]==MX)ta[p]=2,st.erase(p);
				else if(!ta[p])st.insert(p),ta[p]=1;
			}
		}
		else if(ty==2){
			vv out;
			for(auto p:st){
				es[p]=min(MX,es[p]*x);
				if(es[p]==MX)ta[p]=2,out.pb(p);
			}
			for(auto p:out)st.erase(p);
		}
		else {
			auto fa=fact(x);
			ll res=1;
			for(auto [p,e]:fa)res&=e<=es[p];
			if(res)cout<<"Yes\n";
			else cout<<"No\n";
		}
		
	}
	return 0;
}
