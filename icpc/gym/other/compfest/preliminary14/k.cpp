#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=4e5+5;

ll uf[3*MAXN],val[3*MAXN];

ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
void uf_join(ll x, ll y){
	x=uf_find(x); y=uf_find(y);
	assert(x!=y);
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
}
set<ii>st;

void merge(ll l, ll r, ll to){
	vv nod;
	for(auto it=st.lower_bound({l,-1});it!=st.end()&&it->fst<r;it=st.erase(it))nod.pb(it->snd);
	if(!SZ(nod))return;
	fore(i,0,SZ(nod)-1)uf_join(nod[i],nod[i+1]);
	ll p=uf_find(nod[0]);
	val[p]=to;
	st.insert({to,p});
}
ll cnt=0;
void upd(ll x, ll v){
	uf[x]=cnt;
	// uf[cnt]=-1;
	val[cnt]=v;
	st.insert({v,cnt});
	cnt++;
}
int main(){
    JET
	mset(uf,-1);
	ll n; cin>>n;
	vv a(n);
	cnt=n;
	fore(i,0,n)cin>>a[i],upd(i,a[i]);
	ll q; cin>>q;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll p,v; cin>>p>>v; p--;
			upd(p,v);
		}
		if(ty==2){
			ll p; cin>>p; p--;
			cout<<val[uf_find(p)]<<"\n";
		}
		if(ty==3){
			ll l,r; cin>>l>>r;
			ll m=(l+r)/2+1;
			r++;
			merge(l,m,l-1);
			merge(m,r,r);
		}
	}
    return 0;
}