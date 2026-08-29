#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) for(auto y:x){cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<LL,LL> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

const ll MAXS=805*805/2;

vv z_function(string s){
	ll l=0,r=0,n=SZ(s);
	vv z(SZ(s),0);
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}

ll qidx=0,tr[MAXS][26];

ll add(ll x, char c){
	auto &res=tr[x][c-'a'];
	if(res!=-1)return res;
	return res=++qidx;
}

ii doit(string t){ // res,dob
	LL ans=0;
	ll dob=0;
	mset(tr,-1);
	qidx=0;
	ll n=SZ(t);
	vector<vv> wh(n);
	vv cant(MAXS);
	fore(l,0,n){
		ll x=0;
		fore(r,l,n){
			x=add(x,t[r]); // add real
			cant[x]++;
			wh[r].pb(x);
		}
	}
	// for(auto x:wh[n-1])cant[x]--;
	for(ll s=n-1;s>0;s--){
		for(auto x:wh[s])cant[x]--;
		vv z=z_function(t.substr(s));
		ll xd=0; // el b, solo para dob
		ll res=0;
		fore(r,s+1,n+1){ // r)
			xd=tr[xd][t[r-1]-'a'];
			dob+=cant[xd];
			ll x=0; // el a
			fore(j,r+1,n){ // j)
				x=tr[x][t[j-1]-'a'];
				res+=cant[x]*(z[j-s]>=r-s);
				// if(z[j-s]>=r-s){
				// 	// cerr<<s<<" "<<r<<" "<<j<<": ";
				// 	// cerr<<"b="<<t.substr(s,r-s)<<" a="<<t.substr(r,j-r)<<": "<<cant[x]<<"\n";
				// 	res+=cant[x];
				// }
			}
		}
		ans+=res;
	}
	// cerr<<"solve "<<t<<": "<<res<<" "<<dob<<"\n\n";
	return {ans,dob};
}

int main(){
	JET
	string s; cin>>s;
	auto got1=doit(s);
	reverse(ALL(s));
	auto got2=doit(s);
	assert(got1.snd==got2.snd);
	LL res=got1.fst+got1.snd+got2.fst;
	cout<<res<<"\n";
	return 0;
}