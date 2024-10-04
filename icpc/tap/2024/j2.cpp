#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	map<ll,ll>mp;
	fore(i,0,n)cin>>a[i],mp[a[i]]++;
	sort(ALL(a));
	if(k%2==0&&mp[k/2]>n-mp[k/2]+1){
		cout<<"*\n";
		return 0;
	}
	if(k%2==0&&mp[k/2]>=n-mp[k/2]-1){
		vector<ll>res(n);
		vector<ll>put;
		for(auto i:a)if(i!=k/2)put.pb(i);
		ll fg=SZ(put)>n/2,at=0;
		fore(i,0,n)res[i]=i%2==fg?k/2:put[at++];
		for(auto i:res)cout<<i<<" ";;cout<<"\n";
		return 0;
	}
	auto can=[&](vv a){
		fore(i,0,SZ(a)-1)if(a[i]+a[i+1]==k)return 0;
		return 1;
	};
	vv l,m,r;
	for(auto i:a){
		if(k%2==0&&i==k/2)m.pb(i);
		else if(i<=k/2)l.pb(i);
		else r.pb(i);
	}
	fore(i,0,2)fore(j,0,2){
		auto li=l,mi=m,ri=r;
		if(i)reverse(ALL(li));
		if(j)reverse(ALL(ri));
		vv res;
		ll w=0;
		auto pongo=[&](vv &v){
			res.pb(v.back());
			v.pop_back();
		};
		// imp(li)
		// imp(mi)
		// imp(ri)
		fore(i,0,n){
			// cout<<i<<": "<<w<<": "; imp(res)
			if(w==1&&(!SZ(mi)||(SZ(mi)==1&&SZ(li))))w=0;
			if(w==0&&!SZ(li))w=2;
			// cout<<w<<endl;
			if(w==0)pongo(li),w=1;
			else if(w==1)pongo(mi),w=0;
			else pongo(ri),w=1;
		}
		if(can(res)){
			for(auto i:res)cout<<i<<" ";;cout<<"\n";
			return 0;
		}
	}
	cout<<"*\n";
	return 0;
}