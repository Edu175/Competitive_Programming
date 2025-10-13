#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int maxn = 1e5+100;
vv g[maxn];
vv roots;
set<ii> a,b,nexta,nextb;
vector<ii> rta;
ll v[maxn];

ll f(ll x){
	auto &res=v[x];
	if(res!=-1)return res;
	res=1;
	for(auto y:g[x]) res += f(y);
	// cout<<"f "<<x<<": "<<res<<"\n";
	return res;
}

void quitar(ii x){
	a.erase(x);
	b.erase(x);
	nexta.erase(x);
	nextb.erase(x);
}

void put(ll x, ll y){
	rta.pb({x+1,y+1});
	// cout<<"i put "<<x+1<<" "<<y+1<<"\n";
	for(auto i:nextb) b.insert(i);
	for(auto i:nexta) a.insert(i);
	nextb.clear();
	nexta.clear();
	if(x+1) for(auto i:g[x]) nextb.insert({f(i),i}), a.insert({f(i),i});
	if(y+1) for(auto i:g[y]) nexta.insert({f(i),i}), b.insert({f(i),i});
}


int main(){
	#ifdef ONLINE_JUDGE
	freopen("dual.in","r",stdin);     freopen("dual.out","w",stdout);
	#endif
	JET
	mset(v,-1);
	ll n; cin>>n;
	fore(i,0,n){
		ll x; cin>>x;
		x--;
		if(x>=0)g[x].pb(i);
		else roots.pb(i);
	}
	for(auto x:roots){
		a.insert({f(x),x}), b.insert({f(x),x});
	}
	while(SZ(a) + SZ(b)){
		// cout<<"a: \n";
		// for(auto x:a) cout<<x.snd<<" ";
		// cout<<"\nb: \n";
		// for(auto x:b) cout<<x.snd<<" ";
		// cout<<"\n"<<endl;
		// if(SZ(rta) >7) break;
		
		if(!SZ(b)){
			auto it = *a.begin();
			quitar(it);
			put(it.snd, -1);
			continue;
		}
		if(!SZ(a)){
			auto it = *b.begin();
			quitar(it);
			put(-1, it.snd);
			continue;
		}
		if(*a.rbegin() > *b.rbegin()){
			auto m = *a.rbegin();
			quitar(m);
			if(!SZ(b)){
				put(m.snd,-1);
				continue;
			}
			auto k = *b.begin();
			quitar(k);
			put(m.snd, k.snd);
		}
		else{
			auto m = *b.rbegin();
			quitar(m);
			if(!SZ(a)){
				put(-1,m.snd);
				continue;
			}
			auto k = *a.begin();
			quitar(k);
			put(k.snd,m.snd);
		}
		
	}
	cout<<SZ(rta)<<"\n";
	for(auto [x,y] : rta) cout<<x<<" "<<y<<"\n";
	
	
	return 0;
}