#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
random_device rd;
mt19937 rng(rd());
const ll B=140;

ll dis(string &a, string &b){
	ll res=0;
	fore(i,0,SZ(a))res+=a[i]!=b[i];
	return res;
}

int main(){
	ll n,m,k; cin>>n>>m>>k;
	vector<string>a(n);
	vector<pair<string,ll>>b;
	fore(i,0,n)cin>>a[i],b.pb({a[i],i});
	vector<pair<string,ll>>bi;
	while(SZ(b)>B){
		shuffle(ALL(b),rng);
		for(ll s=0;s<SZ(b);s+=B){
			ll e=min(SZ(b),s+B);
			fore(i,s,e){
				ll flag=1;
				fore(j,s,e)if(i!=j&&dis(b[i].fst,b[j].fst)!=k){
					flag=0;
					break;
				}
				if(flag)bi.pb(b[i]);
			}
		}
		assert(SZ(bi)<SZ(b));
		swap(b,bi),bi.clear();
	}
	ll res=-1;
	fore(i,0,SZ(b)){
		ll flag=1;
		fore(j,0,n)if(i!=j&&dis(b[i].fst,a[j])!=k){
			flag=0;
			break;
		}
		if(flag)res=b[i].snd;
	}
	cout<<res+1<<"\n";
	return 0;
}
