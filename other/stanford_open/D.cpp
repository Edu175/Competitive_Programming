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
	ll n; cin>>n;
	vv a(n),b(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n)cin>>b[i],b[i]--;
	vector<vv> res;
	auto mop=[&](vv ids){
		// cout<<"mop "; imp(ids)
		assert(SZ(ids)==n/2);
		res.pb(ids);
		vv valsA,valsB;
		for(auto i:ids)valsA.pb(a[i]),valsB.pb(b[i]);
		sort(ALL(valsA));
		sort(ALL(valsB));
		fore(i,0,SZ(ids)){
			a[ids[i]]=valsA[i];
			b[ids[i]]=valsB[i];
		}
		// imp(a)
		// imp(b)
		// cout<<endl;
	};
	fore(_,0,5){
		vv good(n);
		fore(i,0,n)good[i]=(a[i]==i&&b[i]==i);
		if(count(ALL(good),1)==n)break;
		vv p(n),q(n);
		fore(i,0,n)p[a[i]]=i,q[b[i]]=i;
		set<ll> st;
		ll po=0;
		vv otr;
		while(po<n&&SZ(st)<n/2){
			if(good[po]){
				otr.pb(po);
				po++;
				continue;
			}
			if(SZ(st)<n/2)st.insert(po);
			if(SZ(st)<n/2)st.insert(p[po]);
			if(SZ(st)<n/2)st.insert(q[po]);
			po++;
		}
		reverse(ALL(otr));
		while(SZ(st)<n/2){
			assert(!st.count(otr.back()));
			st.insert(otr.back());
			otr.pop_back();
		}
		vv ids;
		for(auto i:st)ids.pb(i);
		mop(ids);
	}
	vv per(n);
	iota(ALL(per),0);
	assert(a==per&&b==per);
	cout<<SZ(res)<<"\n";
	for(auto v:res){
		for(auto i:v)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
