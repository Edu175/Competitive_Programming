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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
bool cmp(vector<ll>&a,vector<ll>&b){return SZ(a)>SZ(b);}
vector<ll> join(vector<ll>&a,vector<ll>&b){
	vector<ll> ret;
	fore(i,0,SZ(a)){
		ret.pb(a[i]);
		if(i<SZ(b))ret.pb(b[i]);
	}
	return ret;
}
vector<ll> rcy(vector<ll>a, ll d){
	//cout<<SZ(a)<<" "<<d<<"\n";
	assert(gcd(SZ(a),d)==1);
	vector<ll>ret(SZ(a),-1);
	fore(i,0,SZ(a))ret[(d*i)%SZ(a)]=a[i];
	return ret;
}
ll MOD;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<ll> vis(n,0);
		vector<vector<ll>>p;
		fore(i,0,n){
			if(vis[i])continue;
			vector<ll>add={i}; vis[i]=1;
			for(ll j=a[i];j!=i;j=a[j])add.pb(j),vis[j]=1;
			p.pb(add);
		}
		ll flag=1;
		ll ki=k;
		while(ki&&flag){
			ki--;
			ll bet=0;
			sort(ALL(p),cmp);
			//cout<<ki<<": "<<p<<"\n";
			vector<vector<ll>>q;
			fore(i,0,SZ(p)){
				if(i<SZ(p)-1&&SZ(p[i])==SZ(p[i+1])){
					q.pb(join(p[i],p[i+1]));
					bet=1;
					i++;
				}
				else {
					ll m=SZ(p[i]);
					if(m%2==0){
						if(ki==k-1)flag=0;
						q.pb(p[i]);
					}
					else{
						q.pb(rcy(p[i],2));
					}
				}
			}
			p=q;
			if(!bet)break;
		}
		//cout<<ki<<": "<<p<<"\n";
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		fore(i,0,SZ(p)){
			MOD=SZ(p[i]);
			if(SZ(p[i])&1)p[i]=rcy(p[i],fpow(2,ki));
		}
		vector<ll>res(n,-1);
		for(auto q:p){
			fore(i,0,SZ(q))res[q[i]]=q[(i+1)%SZ(q)];
		}
		cout<<"YES\n";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
