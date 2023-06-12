#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,k;cin>>k>>n;
	ll a[n]; fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(m,1,1<<n){
		__int128 c=1;
		fore(i,0,n){
			if(m&(1<<i))c*=a[i];
			if(c>k)break;
		}
		//cout<<m<<" "<<c<<"\n";
		if(__builtin_popcountll(m)&1)res+=k/c;//,cout<<m<<" +"<<k/c<<" = ";
		else res-=k/c;//, cout<<m<<" -"<<k/c<<" = ";
		//cout<<res<<"\n";
	}
	pres;
	return 0;
}
