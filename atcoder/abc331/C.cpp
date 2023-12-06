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
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
	sort(ALL(a)); reverse(ALL(a));
	vector<ll>res(n);
	ll sum=0;
	ll s=0;
	fore(i,0,n){
		if(i==n-1||a[i].fst!=a[i+1].fst){
			ll add=0;
			fore(j,s,i+1)res[a[j].snd]=sum,add+=a[j].fst;
			s=i+1;
			sum+=add;
		}
	}
	fore(i,0,n)cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}
