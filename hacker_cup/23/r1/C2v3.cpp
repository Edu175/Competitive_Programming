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

void press(ll k, vector<ll>&a){
	ll n=SZ(a);
	for(ll i=k;i<n;i+=k+1)a[i]^=1;
}

int main(){FIN;
	ll _t; cin>>_t;
	fore(_,1,_t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		string s; cin>>s;
		vector<ll>a(n);
		fore(i,0,n){
			a[i]=s[i]-'0';
		}
		vector<ll>p(n);
		ll res=0;
		fore(i,0,n){
			if(a[i])press(i,a),p[i]=1,res++;
		}
		ll ans=0;
		ll q; cin>>q;
		while(q--){
			ll k; cin>>k; k--;
			res-=p[k];
			p[k]^=1;
			res+=p[k];
			ans+=res;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
