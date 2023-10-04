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
/*const ll MAXV=1e6+5;
int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before		O(log(n))
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}*/

map<int,int> fact(ll x){
	map<int,int>v;
	//if(x==1)v.pb({1,0}); 
	for(ll i=2; i*i<=x; i++){
		ll count=0;
		while(x%i==0){
			count++;
			x/=i;
		}
		if(count)v[i]=count;
	}
	if(x>1)v[x]++;
	return v;
}
int main(){FIN;
	//init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		map<int,int>f=fact(n);
		ll cd=1;
		for(auto i:f)cd*=i.snd+1;
		map<int,int>_f=f;
		ll _cd=cd;
		while(q--){
			ll ty; cin>>ty;
			if(ty==2)f=_f,cd=_cd;
			else {
				ll x; cin>>x;
				map<int,int>fi=fact(x);
				for(auto i:fi){
					cd/=f[i.fst]+1;
					f[i.fst]+=i.snd;
					cd*=f[i.fst]+1;
				}
				//cout<<n<<" "<<cd<<"\n";
				ll flag=1;
				for(auto i:fact(cd)){
					if(f[i.fst]<i.snd)flag=0;
				}
				if(flag)cout<<"YES\n";
				else cout<<"NO\n";
			}
		}
		cout<<"\n";
	}
	return 0;
}
