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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

vector<pair<ll,ll>>res;
void mov(ll n, ll s, ll e){
	if(n==0)return;
	ll p=6-s-e;
	mov(n-1,s,p);
	res.pb({s,e});
	mov(n-1,p,e);
}

int main(){FIN;
	ll n; cin>>n;
	mov(n,1,3);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
	return 0;
}
