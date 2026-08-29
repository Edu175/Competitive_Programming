#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v){for(auto x:v)cout<<x<<" "; cout<<"\n";}
#define showm(v){for(auto x:v)show(x);}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

// 20:42

ll A,B;
ll n;

ll can(vector<array<ll,3>> &h, ll a, ll b, ll t, ll fg){ // fg is return min value
	vector<vector<ii>> vs(3);
	ll za=0,zb=0,zc=0;
	for(auto [i,v,c]:h){
		ll da=A-i; if(da<0)da+=n;
		ll db=B-i; if(db<0)db+=n;
		ll mk=(da<=t)+2*(db<=t);
		if(mk){
			mk--;
			vs[mk].pb({v,c});
			(!mk?za:(mk==1?zb:zc))+=c;
		}
	}
	if(!fg){
		// cerr<<"can "<<t<<": "<<za<<" "<<zb<<" "<<zc<<"\n";
		ll q=min(a,za);
		a-=q; za-=q;
		q=min(b,zb);
		b-=q; zb-=q;
		return a+b<=zc;
	}
	ll c=0;
	fore(i,0,3)sort(ALL(vs[i]));
	vv po(3);
	ll res=0;
	while(c<a+b){
		ll w=-1;
		fore(i,0,3){
			auto &p=po[i];
			auto &v=vs[i];
			if(p==SZ(v))continue;
			if(w==-1||v[p]<vs[w][po[w]])w=i;
		}
		assert(w!=-1); // se deberia poder
		auto &p=po[w];
		auto &v=vs[w];
		auto &d=(!w?a:(w==1?b:c));
		ll fal=a+b-c;
		ll q=min((w<2?min(d,fal):fal),v[p].snd);
		ll pr=v[p].fst;
		res+=q*pr; p++;
		if(w<2)d-=q;
		else d+=q;
	}
	return res;
}

ll get(vector<array<ll,3>> &h, ll a, ll b){ // h[i]={pos,price,cant}
	// cerr<<"get "<<a<<" "<<b<<":\n"; showm(h)
	
	ll l=-1,r=n;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(h,a,b,m,0))r=m;
		else l=m;
	}
	ll t=r;
	// cerr<<"= "<<t<<"\n\n";
	return t;
}

int main(){
    JET
    ll m,k; cin>>n>>m>>k>>A>>B;
	vector< vector<array<ll,3>> > hs(m);
	vv as(m),bs(m);
	fore(i,0,m)cin>>as[i];
	fore(i,0,m)cin>>bs[i];
	fore(i,0,k){
		ll s,t,x,c; cin>>s>>t>>x>>c; t--;
		hs[t].pb({s,c,x});
	}
	vv ts(m);
	fore(i,0,m)ts[i]=get(hs[i],as[i],bs[i]);
	ll t=*max_element(ALL(ts));
	
	if(t>=n){
		cout<<"impossible\n";
		return 0;
	}
	ll res=0;
	fore(i,0,m){
		res+=can(hs[i],as[i],bs[i],t,1);
	}
	cout<<t<<" "<<res<<"\n";
	return 0;
}
