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
const ll MAXN=1e6+5;

ll uso[MAXN],c[MAXN];
vector<ll> divs[MAXN];
void divisores(){
	fore(i,2,MAXN)for(ll j=i;j<MAXN;j+=i){
		if(uso[j])divs[j].pb(i);
	}
}
//ll tle=0;
int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i],uso[a[i]]=1;
	divisores();
	fore(i,0,n)for(auto j:divs[a[i]])c[j]++;//,tle++;
	ll res=1;
	for(int i=MAXN-3;i>=1;i--){
		if(c[i]>=2){
			res=i;
			break;
		}
	}
	//cout<<tle<<"\n";
	cout<<res<<"\n";
	return 0;
}
