#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,isudgh=b;i<isudgh;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jhglkdfjg:v)cout<<jhglkdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
vector<vector<ll>> g={
	{},
	{0},
	{0},
	{0},
	{1,2},
	{1,3},
	{2,3},
	{4,5,6}
};

int main(){FIN;
	ll A=32;
	ll n=8;
	ll best=0,val=20;
	fore(mk,1,(1ll<<n)-1){
		ll flag=1;
		fore(i,0,n)for(auto j:g[i])flag&=((mk>>i&1)!=(mk>>j&1));
		ll vali=__builtin_popcountll(mk);
		if(flag&&vali<val)best=mk,val=vali;
	}
	cout<<val<<"\n";
	cout<<best<<"\n";
	/*vector<ll>pot(9); pot[0]=1;
	fore(i,1,9)pot[i]=pot[i-1]*A;
	vector<ll>a(n),iden(n);
	iota(ALL(a),0);
	iota(ALL(iden),0);
	auto best=a; ll val=pot.back();
	// imp(a);
	do{
		ll vali=0;
		vector<ll>p(n);
		fore(i,0,n)p[a[i]]=i;
		
		fore(e,0,n){
			set<ll>l,r;
			fore(i,0,n)for(auto j:g[i]){
				if((i<e)!=(j<e)){
					if(i<e)l.insert(i),r.insert(j);
					else l.insert(j),r.insert(i);
				}
			}
			if(a==iden){cout<<e<<": ";imp(l);}
			// mx=max(mx,(ll)min(SZ(l),SZ(r)));
			vali+=pot[SZ(l)];
		}
		if(a==iden)cout<<"\n";
		
		if(vali<val)best=a,val=vali;
		
	}while(next_permutation(ALL(a)));
	
	cout<<val<<"\n";
	imp(best);*/
	return 0;
}