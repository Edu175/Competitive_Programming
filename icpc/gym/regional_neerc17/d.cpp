#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
	ll A,B,C; cin>>A>>B>>C;
	vector<ii> v={{A,0},{B,1},{C,2}};
	sort(ALL(v));
	ll a=v[0].fst,b=v[1].fst,c=v[2].fst;
	vv cv(3);
	vv tr={1,0,2};
	fore(i,0,3){
		ll ax=v[i].snd;
		cv[ax]=tr[i];
	}
	// for(auto i:cv)cout<<i<<" ";;cout<<" cv\n";
	if(a*b<c){
		cout<<"-1\n";
		return 0;
	}
	vv w(b);
	ll c_=c-b;
	fore(i,0,b){
		ll p=min(c_,a-1);
		// cout<<c_<<": "<<p<<"\n";
		w[i]=p+1;
		c_-=p;
	}
	// cout<<a<<" "<<b<<" "<<c<<"\n";
	// for(auto i:w)cout<<i<<" ";;cout<<endl;
	// assert(w[0]==a);
	vector<array<ll,3>>h;
	fore(i,0,b){
		vv per(a); iota(ALL(per),0);
		rotate(per.begin(),per.begin()+(i%a),per.end());
		fore(j,0,w[i])h.pb({per[j],i,0});
	}
	auto check=[&](vector<array<ll,3>> &outs){
		set<ii>xs,ys,zs;
		for(auto [x,y,z]:outs){
			xs.insert({y,z});
			ys.insert({x,z});
			zs.insert({x,y});
		}
		return (SZ(zs)==A&&SZ(ys)==B&&SZ(xs)==C);
	};
	cout<<SZ(h)<<"\n";
	vv per(3); iota(ALL(per),0);
	vector<array<ll,3>>ans;
	do{
		vector<array<ll,3>>outs;
		for(auto arr:h){
			array<ll,3> out;
			fore(i,0,3)out[i]=arr[per[i]];
			outs.pb(out);
		}
		if(check(outs)){ans=outs;break;}
	}while(next_permutation(ALL(per)));
	assert(SZ(ans));
	for(auto out:ans){
		fore(i,0,3)cout<<out[i]<<" ";
		cout<<"\n";
	}
	
    return 0;
}