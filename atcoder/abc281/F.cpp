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
const ll MAXN=15e4;
ll n,a[MAXN],s,p;

bool can(ll l, ll r, ll j){
	if(j==-1)return 1;
	if(l>=r)return 0;
	ll res=-1;
	ll m=r;
	fore(i,l,r){
		if(a[i]&(1ll<<j)){
			m=i;
			break;
		}
	}
	if((p&(1ll<<j))&&(m==l||m==r))return 1;
	if(!(p&(1ll<<j))&&(m!=l&&m!=r))return 0;
	res=max(can(l,m,j-1),can(m,r,j-1)); 
	return res;
}

int main(){FIN;
	cin>>n;
	ll maxi=0;
	fore(i,0,n)cin>>a[i],maxi=max(maxi,a[i]);
	sort(a,a+n);
	//ll q; cin>>q; p=q; cout<<can(0,n,s)<<"\n";return 0;
	ll l=0,r=maxi;
	while(l<=r){
		ll m=(l+r)/2;
		p=m;
		if(can(0,n,31))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
