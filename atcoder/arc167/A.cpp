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
	ll n,m; cin>>n>>m;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	vector<ll>p(m);
	ll j=0,pos=-1;
	for(ll i=n-1;i>=0;i--){
		if(j==m){
			pos=i;
			break;
		}
		p[j]+=a[i];
		j++;
	}
	
	for(ll i=pos,j=m-1;i>=0;i--,j--){
		p[j]+=a[i];
	}
	ll res=0;
	fore(i,0,m)res+=p[i]*p[i];
	//imp(p);
	cout<<res<<"\n";
	return 0;
}
