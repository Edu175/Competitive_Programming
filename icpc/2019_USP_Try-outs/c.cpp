#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto dsfkjhg:v)cout<<dsfkjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	JET
	ll n,q; cin>>n>>q;
	map<ll,ll>mp;
	multiset<ll>st;
	fore(i,1,n+1){
		ll x; cin>>x;
		mp[i]=x;
		st.insert(x);
	}
	while(q--){
		char ty; cin>>ty;
		if(ty=='+'){
			ll w,id; cin>>w>>id;
			mp[id]=w;
			st.insert(w);
		}
		if(ty=='-'){
			ll id; cin>>id;
			st.erase(st.find(mp[id]));
		}
		if(ty=='?'){
			ll id; cin>>id;
			ll x=mp[id],flag=0,s=0,res=0;
			// cout<<"? "<<x<<": "; imp(st);
			vector<ll>pop;
			while(1){
				auto lwb=st.lower_bound(s);
				if(lwb==st.end())break;
				ll v=*lwb;
				if(!flag&&s+v>x)v=x;
				flag|=v==x;
				// cout<<s<<": "<<v<<" "<<flag<<"\n";
				res++;
				s+=v;
				pop.pb(v);
				st.erase(st.find(v));
			}
			for(auto i:pop)st.insert(i);
			cout<<res<<"\n";
		}
	}
	return 0;
}