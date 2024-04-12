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
const ll MAXN=105;
ii a[MAXN];
ll sq(ll x){return x*x;}
ll dis(ll i, ll j){
	return sq(a[i].fst-a[j].fst)+sq(a[i].snd-a[j].snd);
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	vector<ll>res(n);
	fore(i,0,n){
		ii mx={-1,0};
		fore(j,0,n)mx=max(mx,{dis(i,j),-j});
		cout<<-mx.snd+1<<"\n";
	}
	return 0;
}
