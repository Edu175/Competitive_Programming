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
// typedef long double ld;
// const ld EPS=1e-12;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
void tle(bool b){
	if(!b){
		auto start=clock();
		while(clock()-start<33*CLOCKS_PER_SEC);
		cout<<"pinga\n";
	}
}
const ll INF=1e18;

ll ceil(ll a, ll b){
	ll sgn=(a*b<0);
	a=abs(a),b=abs(b);
	if(sgn)return -a/b;
	return (a+b-1)/b;
}
ll floor(ll a, ll b){
	ll sgn=(a*b<0);
	a=abs(a),b=abs(b);
	if(sgn)return -(a+b-1)/b;
	return a/b;
}
const ll MAXN=1005;
ii a[MAXN];
ll n,C,L;
map<ll,ll> rans;
ll po=0;
ll cant=0;

ll inter(ll i, ll j){ // rounded up
	auto num=a[j].fst-a[i].fst;
	auto den=a[i].snd-a[j].snd;
	if(!den)return INF;
	return ceil(num,den);
}
ii get_ran(ll i, ll j){ // j is on top of i
	ll c=a[j].fst-a[i].fst-C;
	ll m=a[j].snd-a[i].snd;
	ll l=0,r=INF;
	if(!m){
		if(c<0)return {0,0};
		return {l,r};
	}
	if(m>0)l=ceil(-c,m);
	else r=floor(c,-m)+1;
	l=max(l,0ll);
	r=max(r,0ll);
	return {l,r};
}
ll eval(ll i, ll t){
	return a[i].fst+a[i].snd*t;
}

vv per,pos;
ll t;
bool cmp(ll i, ll j){
	return ii{eval(i,t),a[i].snd}<ii{eval(j,t),a[j].snd};
}
void sortit(ll l, ll r){
	// cerr<<"sortit "<<l<<","<<r<<"\n";
	sort(per.begin()+l,per.begin()+r,cmp);
	fore(i,l,r)pos[per[i]]=i;
}
enum{SWAP,CH,QUERY};
typedef array<ll,3> typ;
set<ii> did;
priority_queue<typ,vector<typ>,greater<typ>> all;
void add_ev(ii e){
	if(!did.count(e)){
		did.insert(e);
		all.push({e.snd,e.fst,-1});
	}
}
void agr(ll i, ll j){ // j on top
	// cerr<<"agr "<<i<<" "<<j<<"\n";
	if(pos[i]>=pos[n-1]||pos[j]<=pos[0])return;
	auto [l,r]=get_ran(i,j);
	// l=max(l,t); r=max(r,t);
	l=min(l,r);
	// cerr<<"added range "<<l<<","<<r<<"\n";
	rans[l]++,rans[r]--;
	if(l<t&&t<=r)cant++;
	if(l>=t)add_ev({CH,l});
	if(r>=t)add_ev({CH,r});
}

void sac(ll i, ll j){
	// cerr<<"sac "<<i<<" "<<j<<"\n";
	if(pos[i]>=pos[n-1]||pos[j]<=pos[0])return;
	auto [l,r]=get_ran(i,j);
	l=min(l,r);
	// l=max(l,t); r=max(r,t);
	// cerr<<"removed range "<<l<<","<<r<<"\n";
	rans[l]--,rans[r]++;
	if(l<t&&t<=r)cant--;
}

void agr_range(ll l, ll r){
	l=max(l,0ll); r=min(r,n);
	fore(i,l,r-1)agr(per[i],per[i+1]);
}
void sac_range(ll l, ll r){
	l=max(l,0ll); r=min(r,n);
	fore(i,l,r-1)sac(per[i],per[i+1]);
}

int main(){FIN;
	cin>>n>>C>>L;
	fore(i,1,n+1)cin>>a[i].fst>>a[i].snd;
	a[0]={0,0};
	a[n+1]={L,0};
	n+=2;
	per=pos=vv(n); iota(ALL(per),0);
	t=0;
	sortit(0,n);
	map<ll,set<ll>> bad;
	fore(i,0,n)fore(j,i+1,n){
		ll p=inter(i,j);
		if(p<0)continue;
		bad[p].insert(i);
		bad[p].insert(j);
		add_ev({SWAP,p});
	}
	agr_range(0,n);
	ll q; cin>>q;
	vv qs(q);
	fore(i,0,q){
		ll t; cin>>t;
		qs[i]=t;
		all.push({t,QUERY,i});
	}
	vv ans(q);
	ll oldt=0;
	for(ll done=0;done<q;){
		auto [_t,ty,i]=all.top(); all.pop();
		t=_t;
		assert(t>=oldt); oldt=t;
		assert(t<INF);
		// cerr<<"\n";
		// cerr<<"time "<<t<<" "<<(ty==QUERY?"QUERY":(ty==CH?"CH":"SWAP"))<<" "<<cant<<"\n";
		// imp(per)
		if(ty==QUERY){
			// cerr<<"query "<<i<<" "<<cant<<"\n";
			ans[i]=cant>0;
			done++;
		}
		else if(ty==CH)cant+=rans[t];
		else {
			vv ind;
			for(auto i:bad[t])ind.pb(pos[i]);
			if(!SZ(ind))continue;
			sort(ALL(ind));
			ll l=ind[0];
			fore(i,0,SZ(ind)){
				if(i==SZ(ind)-1||ind[i]+1<ind[i+1]){
					ll r=ind[i]+1;
					sac_range(l-1,r+1);
					sortit(l,r);
					agr_range(l-1,r+1);
					if(i+1<SZ(ind))l=ind[i+1];
				}
			}
		}
	}
	fore(i,0,q){
		cout<<"NY"[ans[i]]<<"\n";
	}
	return 0;
}