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
const ll MAXN=2e5+5;
ll n;
ll a[MAXN],sp[MAXN];
ll cnt(ll l, ll r){
	if(l>r)swap(l,r);
	ll res=(r-l+1)*(a[l]-a[r]);
	res+=sp[l];
	res+=sp[n]-sp[r+1];
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		sp[0]=0;
		fore(i,0,n)cin>>a[i],sp[i+1]=0;
		fore(i,1,n+1)sp[i]=a[i-1]+sp[i-1];
		ll res=sp[n];
		ll l1=0,r1=n-1;
		fore(i,0,n){
			if(cnt(i,r1)>=res)l1=i,res=cnt(i,r1);
		}
		for(int i=n-1;i>=0;i--){
			if(cnt(l1,i)>=res)r1=i,res=cnt(l1,i);
		}
		cout<<res<<"\n";
		cout<<l1<<" "<<r1<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
