#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n;
ll QUERIES,MAXQUERIES;
ll ask(vv a){
	assert(++QUERIES<=MAXQUERIES);
	assert(SZ(a)==n);
	cout<<"? ";
	for(auto i:a)cout<<i+1<<" ";
	cout<<endl;
	ll ret; cin>>ret; ret--;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		QUERIES=0; MAXQUERIES=2*n*n-2*n+1;
		vector<vv> a(n);
		ll cnt=0;
		fore(i,0,n)fore(j,0,n)a[i].pb(cnt++);
		auto saca=[&](ll i, ll x){
			auto ptr=find(ALL(a[i]),x); assert(ptr!=a[i].end());
			a[i].erase(ptr);
		};
		auto front=[&](ll i, ll x){
			saca(i,x);
			a[i].insert(a[i].begin(),x);
		};
		auto where=[&](ll x){
			fore(i,0,n)if(a[i][0]==x)return i;
			assert(0);
		};
		auto askfront=[&](){
			vv b; fore(i,0,n)b.pb(a[i][0]);
			return ask(b);
		};
		
		fore(i,0,n)front(i,ask(a[i]));
		vv ans;
		while(SZ(a[0])>2){
			fore(i,0,n)assert(SZ(a[i])==SZ(a[0]));
			fore(s,0,n){
				ll p=askfront();
				ans.pb(p);
				ll w=where(p);
				saca(w,p);
				if(s!=w){
					a[w].pb(a[s].back());
					a[s].pop_back();
				}
				// cantidades estan bien, tengo que acomodar w
				vv b=a[w];
				fore(i,0,n)if(i!=w){
					ll po=1;
					while(SZ(b)<n&&po<SZ(a[i]))b.pb(a[i][po++]);
				}
				assert(SZ(b)==n);
				ll x=ask(b);
				ll d=count(ALL(a[w]),x)?w:-1;
				fore(i,0,n)if(d==-1&&count(ALL(a[i]),x))d=i;
				ll pos=find(ALL(a[d]),x)-a[d].begin();
				swap(a[d][pos],a[w][0]);
			}
		}
		fore(i,0,n)assert(SZ(a[i])==2);
		// 1 query por cada una de las siguientes n+1 bolas
		fore(_,0,n+1){
			ll p=askfront();
			ans.pb(p);
			ll w=where(p);
			saca(w,p);
			if(!SZ(a[w])){
				ll pos=-1;
				fore(i,0,n)if(SZ(a[i])==2)pos=i;
				if(pos!=-1)a[w].pb(a[pos].back()),a[pos].pop_back();
				else assert(_==n);
			}
		}
		assert(QUERIES==MAXQUERIES);
		assert(SZ(ans)==n*n-(n-1));
		cout<<"! "; for(auto i:ans)cout<<i+1<<" ";; cout<<endl;
	}
	return 0;
}
