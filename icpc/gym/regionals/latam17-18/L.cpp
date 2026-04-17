#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXQ=1e5+5;

ll ans[MAXQ];

void cand(ll idx, ll cur){
	if(ans[idx]==-1||cur<ans[idx])ans[idx]=cur;
}

void answer(vv a, vv b, vector<array<ll,5>> qs){
	vv pos,spA(SZ(a)+1),spB(SZ(b)+1);
	fore(i,1,SZ(spA))spA[i]=spA[i-1]+a[i-1];
	fore(i,1,SZ(spB))spB[i]=spB[i-1]+b[i-1];
	fore(i,0,SZ(b))if(b[i]==1)pos.pb(i);
	
	for(auto& [i0,j0,i1,j1,idx]:qs)if(i0<=i1&&j0<=j1&&i1-i0>=j1-j0){
		auto ptr=lower_bound(ALL(pos),j0);
		ll good=ptr!=pos.end()&&*ptr<j1;
		ll fij=spA[i1]-spA[i0]+spB[j1]-spB[j0],d=i1-i0-(j1-j0);
		ll res=fij+(d/2*2)*5;
		// cout<<fij<<" fij\n";
		// cout<<i0<<","<<j0<<" "<<i1<<","<<j1<<"\n";
		if(good){
			cand(idx,fij+d/2*2);
			continue;
		}
		if(ptr!=pos.begin()){ // izq
			ll cur=fij;
			ll to=*prev(ptr),am=j0-to-1;
			cur+=5*am*2;
			ll d2=max(0ll,d-2*am);
			cur+=d2/2*2;
			// cerr<<"izq: "<<am<<" "<<d<<": "<<d2<<" "<<cur<<"\n";
			res=min(res,cur);
		}
		cand(idx,res);
	}
}

void answ(vv a, vv b, vector<array<ll,5>> qs, ll tra, ll rev){
	// cerr<<revA<<" "<<revB<<" "<<sw<<"\n";
	if(rev){
		reverse(ALL(a));
		reverse(ALL(b));
	}
	for(auto& [i0,j0,i1,j1,idx]:qs){
		if(rev){
			i0=SZ(a)-i0,i1=SZ(a)-i1;
			j0=SZ(b)-j0,j1=SZ(b)-j1;
			swap(i0,i1),swap(j0,j1);
		}
		if(tra)swap(i0,j0),swap(i1,j1);
	}
	if(tra)swap(a,b);
	answer(a,b,qs);
}

int main(){ET;
	ll n; cin>>n;
	vv a(n-1),b(n-1);
	fore(i,0,n-1)cin>>a[i];
	fore(i,0,n-1)cin>>b[i];
	ll q; cin>>q;
	vector<array<ll,5>> qs(q);
	fore(idx,0,q){
		ll i0,j0,i1,j1; cin>>i0>>j0>>i1>>j1; i0--,i1--,j0--,j1--;
		if(i0>i1)swap(i0,i1);
		if(j0>j1)swap(j0,j1);
		qs[idx]={i0,j0,i1,j1,idx};
	}
	mset(ans,-1);
	fore(i,0,2)fore(j,0,2)answ(a,b,qs,i,j);
	fore(i,0,q)cout<<ans[i]<<"\n";
}