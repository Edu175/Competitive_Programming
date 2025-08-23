#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll K=18;

struct STable{
	vector<vv>st;
	ll n;
	#define oper max
	void init(vv &a){
		n=SZ(a);
		st=vector<vv>(K,vv(n));
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n){
			ll mid=1ll<<(k-1);
			if(i+mid>=n)continue;
			st[k][i]=oper(st[k-1][i],st[k-1][i+mid]);
		}
	}
	ll query(ll s, ll e){
		assert(s>=0&&e<=n);
		ll k=__lg(e-s);
		return oper(st[k][s],st[k][e-(1ll<<k)]);
	}
	
};
ll n;
ll lwbR(ll p, ll v, STable &st){
	ll l=p,r=n;
	while(r-l>1){
		ll m=(l+r)/2;
		if(st.query(p+1,m+1)<v)l=m;
		else r=m;
	}
	return r;
}
ll lwbL(ll p, ll v, STable &st){
	ll l=-1,r=p;
	while(r-l>1){
		ll m=(l+r)/2;
		if(st.query(m,p)<v)r=m;
		else l=m;
	}
	return l;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll k; cin>>n>>k;
		vv a(n);
		vector<vv> pos(n+1);
		fore(i,0,n)cin>>a[i],pos[a[i]].pb(i);
		STable st,stneg;
		st.init(a);
		auto na=a;
		for(auto &i:na)i=-i;
		stneg.init(na);
		
		vector<vv> sps(n+1);
		fore(c,0,n+1){
			auto &vec=pos[c];
			auto &sp=sps[c];
			sp=vv(SZ(vec)+1);
			fore(i,0,SZ(vec)){
				sp[i+1]=sp[i]+vec[i]-lwbL(vec[i],-c,stneg);
			}
			// cout<<c<<": ";;fore(i,0,SZ(vec)+1)cout<<sp[i]<<" ";;cout<<"\n";
		}
		// cout<<"pinga\n";
		auto get=[&](ll s, ll e, ll c){ // [,)
			ll l=lower_bound(ALL(pos[c]),s)-pos[c].begin();
			ll r=lower_bound(ALL(pos[c]),e)-pos[c].begin();
			// cout<<c<<": ";
			// cout<<l<<" "<<r<<": "<<sps[c][r]-sps[c][l]<<"\n";
			return sps[c][r]-sps[c][l];
		};
		
		ll res=0;
		fore(i,0,n){
			// cout<<"\n"<<a[i]<<": "<<k-a[i]<<":\n";
			ll v=k-a[i];
			if(v<0||v>n)continue;
			ll suf=lwbR(i,a[i],st)-i;
			
			ll pm=lwbL(i,a[i]+1,st);
			ll s=lwbL(pm,-(v-1),stneg);
			
			ll pre=get(s+1,i,v);
			
			ll term=pre*suf;
			
			cout<<i<<": "<<pm<<" "<<s<<": "<<pre<<" "<<suf<<": "<<term<<"\n";
			
			res+=term;
		}
		cout<<res<<"\n";
	}
	return 0;
}