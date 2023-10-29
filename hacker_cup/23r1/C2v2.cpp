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
const ll MAXN=4e1+5;

vector<ll>divs[MAXN];
void divisores(){
	fore(i,1,MAXN){
		//cout<<i<<endl;
		for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
	}
}

int main(){FIN;
	divisores();
	ll _t; cin>>_t;
	fore(_,1,_t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		string s; cin>>s;
		vector<ll>a(n),b(n);
		fore(i,0,n){
			a[i]=s[i]-'0';
		}
		fore(i,1,n+1){
			for(ll j=i-1;j<n;j+=i)b[j]^=a[i-1];
		}
		vector<ll>c(n);
		fore(i,1,n+1){
			for(ll j=i-1;j<n;j+=i){
				if(b[j])c[i-1]++;
			}
		}
		ll res=0;
		fore(i,0,n)res+=b[i];
		ll ans=0;
		cout<<"\n";
		imp(b);
		ll q; cin>>q;
		while(q--){
			ll k; cin>>k;
			res-=c[k-1];
			c[k-1]=n/k-c[k-1];
			res+=c[k-1];
			ll bi=0;
			a[k-1]^=1;
			for(auto d:divs[k])bi^=a[d-1];
			ll ch=(bi?1:-1);
			for(auto d:divs[k]){
				if(d!=k){
					c[d-1]+=ch;
				}
			}
			ans+=res;
			imp(c);
			cout<<res<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
