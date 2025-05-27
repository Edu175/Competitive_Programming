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
const ll INF=1e6+5,MAXN=1e5+5;
// const ll INF=10,MAXN=1e5+5;
struct UF{
	int uf[MAXN];
	void init(ll n){fore(i,0,n)uf[i]=-1;}
	int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	bool join(int x, int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		if(uf[x]>uf[y])swap(x,y); // y -> x
		uf[x]+=uf[y];uf[y]=x;
		return true;
	}
};
typedef vector<array<ll,4>> ved;
ll ans[MAXN],lam[MAXN]; // smallest lambda for each k
UF uf,Luf,Ruf;

void actu(ll k, ll res, ll lm){
	// cerr<<"actu "<<k<<": "<<res<<" "<<lm<<"\n";
	if(ans[k]==-1)ans[k]=res,lam[k]=lm;
	else assert(ans[k]==res),lam[k]=min(lam[k],lm);
}

void rec(ll s, ll e, ved ed, ll k, ll sum){
	ll m=(s+e)/2;
	for(auto& [w,c,x,y]:ed)w+=c*m;
	sort(ALL(ed));
	vv used,nod;
	ll cant=0,tot=0;
	for(auto& [w,c,x,y]:ed){
		w-=c*m;
		used.pb(uf.join(x,y));
		if(used.back())cant+=c,tot+=w;
		nod.pb(x),nod.pb(y);
	}
	for(auto i:nod)uf.uf[i]=-1;
	// cerr<<"rec "<<s<<","<<e<<": "<<k<<" "<<sum<<": { ";
	// for(auto [w,c,x,y]:ed)cerr<<"("<<x<<","<<y<<" "<<w<<","<<(c?'R':'B')<<") ";;cerr<<"}"<<endl;
	if(e-s==1||!SZ(ed)){
		k+=cant; sum+=tot;
		actu(k,sum,s);
		return;
	}
	ved L,R;
	ll Lk=0,Lsum=0;
	ll Rk=0,Rsum=0; // useless, always 0
	fore(i,0,SZ(ed)){
		auto& [w,c,x,y]=ed[i];
		ll side=c^used[i]^1;
		if(used[i]){
			(side?Luf:Ruf).join(x,y);
			(side?Lk:Rk)+=c;
			(side?Lsum:Rsum)+=w;
		}
		(side?R:L).pb(ed[i]);
	}
	auto doit=[&](ved &ed, UF &uf){
		for(auto& [w,c,x,y]:ed)x=uf.find(x),y=uf.find(y);
		for(auto i:nod)uf.uf[i]=-1;
	};
	doit(L,Luf); doit(R,Ruf);
	rec(s,m,L,k+Lk,sum+Lsum);
	rec(m,e,R,k+Rk,sum+Rsum);
}



int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ved ed;
		uf.init(n); Luf.init(n); Ruf.init(n);
		fore(i,0,m){
			ll x,y,w; char c; cin>>x>>y>>w>>c; x--,y--;
			// uf.join(x,y);
			ed.pb({w,c=='R',x,y});
		}
		/*graph is connected, but its useful for debugging*/
		// if(-uf.uf[uf.find(0)]!=n){
		// 	fore(i,0,n)cout<<"-1 ";
		// 	cout<<"\n";
		// 	continue;
		// }
		// uf.init(n);
		/**/
		fore(i,0,n)ans[i]=-1;
		rec(-INF,INF,ed,0,0);
		ll prev=-1,lm=-1;
		ll typ=0;
		fore(k,0,n){
			if(ans[k]==-1){
				if(prev!=-1)ans[k]=(prev-k)*lm+ans[prev];
			}
			else prev=k,lm=lam[k];
			ll bo=ans[k]!=-1;
			if(!typ&&bo)typ++;
			if(typ==1&&!bo)typ++;
			if(typ==2)assert(!bo);
			cout<<ans[k]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
