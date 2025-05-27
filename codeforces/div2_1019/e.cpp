#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		vector<ii> sa;
		fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
		sort(ALL(sa));
		ll fg=1;
		fore(i,0,n)fg&=sa[i].fst==a[i];
		if(fg){cout<<"0\n";continue;}
		map<ll,ll>mp;
		fore(i,0,n)mp[a[i]]=i;
		vv pos(n);
		fore(i,0,n)pos[sa[i].snd]=i;
		ll x=-1,y=-1;
		fore(i,0,n){
			if(mp.count(k-a[i])&&mp[k-a[i]]!=i)x=i,y=mp[k-a[i]];
		}
		if(x==-1){
			cout<<"-1\n";
			continue;
		}
		
		// x e y ahora van a ser los elementos
		
		vv p(n);
		iota(ALL(p),0);
		vector<array<ll,3>>res;
		auto dbg=[&](){
			fore(i,0,n){
				if(i==p[x])cout<<'x';
				else if(i==p[y])cout<<'y';
				else cout<<a[i];
				cout<<" ";
			}
			cout<<endl;
			imp(a)
		};
		// for(auto i:sa)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
		auto manda=[&](ll z){ // a la pos de x
			// dbg();
			// cout<<"manda "<<z<<": "<<x<<" "<<y<<"\n";
			ll px=p[x],py=p[y],pz=p[z];
			ll v=a[px]-a[pz];
			assert(a[px]+a[py]==k);
			res.pb({px,py,v});
			a[px]-=v,a[py]+=v;
			swap(p[x],p[z]);
		};
		vv good(n);
		auto ciclo=[&](){
			while(1){
				ll ind=sa[p[x]].snd;
				// cout<<"paso ciclo "<<ind<<" "<<z<<"\n";
				good[ind]=1;
				if(ind==x)break;
				// if(z==x||z==y)break;
				manda(ind);
			}
		};
		ciclo();
		fore(i,0,n)if(i!=x&&!good[i]){
			good[i]=1;
			manda(i);
			ciclo();
		}
		if(sa[p[x]].fst!=a[p[x]]){
			ll v=-(sa[p[x]].fst-a[p[x]]);
			res.pb({p[x],p[y],v});
			a[p[x]]-=v,a[p[y]]+=v;
		}
		cout<<SZ(res)<<"\n";
		for(auto [i,j,v]:res){
			cout<<i+1<<" "<<j+1<<" "<<v<<"\n";
		}
		// dbg();
	}
	return 0;
}
