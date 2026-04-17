#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct event{
	ll t,ty,d; // ty 1 = query
	bool operator<(event e)const{
		return ii({t,ty})<ii({e.t,e.ty});
	}
};

int main(){
    JET
    #ifdef ONLINE_JUDGE
    freopen("expect.in","r",stdin);     freopen("expect.out","w",stdout);
    #endif
    ll n,q;
    cin>>n>>q;
	ll in=0,out=0;
    vector<ii> ins,outs;
    fore(i,0,n){
        char c; cin>>c;
        ll t,k; cin>>t>>k;
        if(c=='+'){
            in+=k; 
            ins.pb({t,k});
        }
        else{
            out+=k;
            outs.pb({t,k});
        }
    }
    ll mini = max(0ll,out-in);
    // cout<<"mini "<<mini<<"\n";
	ins.pb({0,mini});
    // ins.pb({1000000,1000000});
    sort(ALL(ins));
    vector<ii> usar = ins, poner = outs;
    vector<pair<ii,ll>> flechas;
    int j = 0;
    for(auto [y,x] : poner){
        while(x>0){
            while(usar[j].snd==0) j++;
            // if(j>=SZ(usar))break;
			ll k = min(usar[j].snd,x);
            usar[j].snd -= k;
            x-=k;
            if(usar[j].fst>y) flechas.pb({{y,usar[j].fst},k});
        }
    }
	
	ll res=0;
	for(auto [par,w]:flechas){
		auto [l,r]=par;
		res+=w*(r-l);
	}
	sort(ALL(flechas));
	vector<event>ev;
	ll po=0,suma=0,pob=0,sumb=0;
	fore(i,0,SZ(flechas)){
		auto [par,w]=flechas[i];
		auto [l,r]=par;
		while(po<i&&flechas[po].fst.snd<l)suma-=flechas[po++].snd;
		while(pob<SZ(flechas)&&flechas[pob].fst.fst<=r)sumb+=flechas[pob++].snd;
		ll sum=suma+1;
		ev.pb({mini+sum,0,+l});
		ev.pb({mini+sum+w,0,-l});
		// cout<<"sums: "<<sum<<" ";
		sum=sumb-w+1;
		// sum=spl[e]-spl[s]+1;
		// cout<<sum<<"\n\n";
		ev.pb({mini+sum,0,-r});
		ev.pb({mini+sum+w,0,+r});
		suma+=w;
		sumb-=w;
	}
	vector<ii>qs(q);
	fore(i,0,q){
		ll t; cin>>t; qs[i]={t,i};
	}
	sort(ALL(qs));
	vv ans(q);
	for(auto [t,idx]:qs){
		if(t<mini)ans[idx]=-1;
		else {
			ev.pb({t,1,idx});
		}
	}
	sort(ALL(ev));
	// cout<<"events:\n";
	// for(auto e:ev){
	// 	cout<<e.t<<","<<e.ty<<" "<<e.d<<"\n";
	// }
	ll T=mini;
	ll z=0;
	// cout<<"inicial "<<res<<"\n";
	for(auto e:ev){
		// cout<<"paso de "<<T<<" a "<<e.t<<" con z "<<z<<"\n";
		res+=z*(e.t-T);
		T=e.t;
		if(e.ty==0)z+=e.d;//,cout<<"upd "<<e.d<<"\n";
		else{
			ans[e.d]=res+z;
			// cout<<"query "<<res<<"\n";
		}
	}
	for(auto i:ans){
		if(i==-1)cout<<"INFINITY\n";
		else cout<<i<<"\n";
	}
	return 0;

}