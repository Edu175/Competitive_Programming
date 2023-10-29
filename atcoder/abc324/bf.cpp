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
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	ll q; cin>>q;
	vector<vector<ll>>p(q+1);
	p[0]=a;
	fore(i,1,q+1){
		ll t,s,x; cin>>t>>s>>x;
		p[i]=p[s];
		vector<ll>l,r;
		if(t==1){
			fore(j,0,SZ(p[i])){
				if(j>=x)r.pb(p[i][j]);
				else l.pb(p[i][j]);
			}
		}
		else {
			fore(j,0,SZ(p[i])){
				if(p[i][j]>=x)r.pb(p[i][j]);
				else l.pb(p[i][j]);
			}
		}
		p[s]=l,p[i]=r;
		//cout<<i<<": ";imp(p[i]);
		cout<<SZ(p[i])<<"\n";
	}
	return 0;
}
