#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll operator*(ii a, ii b){
	return a.fst*b.fst+a.snd*b.snd;
}

bool check(vector<ii>a, ll n, ll m){
	vector<ii>b;
	auto sa=a; sort(ALL(a));
	fore(i,0,n)fore(j,0,m)b.pb({i,j});
	
	if(SZ(a)!=n*m)return 0;
	for(auto [i,j]:a)if(!st.count({i,j}))return 0;
	vector<ii>d;
	fore(i,0,SZ(a)-1){
		d.pb({a[i+1].fst-a[i].fst,a[i+1].snd-a[i].snd});
	}
	for(auto [x,y]:d)if(abs(gcd(x,y))!=1)return 0;
	fore(i,0,SZ(d)-1)if(d[i]*d[i+1]<0)return 0;
	return 1;
}

int main(){JET;
	
	return 0;
}