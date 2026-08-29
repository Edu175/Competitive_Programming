#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
const ll MAXV=1e4+5;
vector<ii> rans;
vector<ld> tot;
ll n;
bool in(ll t, ll l, ll r){return l<=t&&t<r;}
ld calcp(ll k){
	assert(k>=2&&k<=n);
	ld res=0;
	vv per(n); fore(i,n-k,n)per[i]=1;
	do{
		fore(t,1,MAXV){
			ld prob=1;
			fore(i,0,n){
				auto [l,r]=rans[i];
				if(!per[i]){
					ll len=min(t+1,r)-l;
					len=max(len,0ll);
					prob*=len/tot[i];
				}
				else prob*=in(t,l,r);
			}
			res+=t*prob;
		}
	}while(next_permutation(ALL(per)));
	return res;
}

int main(){
	JET
	cin>>n;
	rans.resize(n); tot.resize(n);
	fore(i,0,n)cin>>rans[i].fst>>rans[i].snd,rans[i].snd++;
	fore(i,0,n)tot[i]=rans[i].snd-rans[i].fst;
	ld cuenta1=0;
	vector<ld> leq(MAXV);
	fore(wh,0,n){
		auto [l,r]=rans[wh];
		fore(t,1,MAXV){
			ld prob=max(r-max(t,l),0ll)/tot[wh];
			fore(i,0,n)if(i!=wh){
				ll len=min(t+1,r)-l;
				len=max(len,0ll);
				prob*=len/tot[i];
			}
			leq[t]+=prob;
		}
	}
	fore(t,1,13)cerr<<leq[t]<<" ";;cerr<<"\n";
	fore(t,1,MAXV){
		ld prob=leq[t]-leq[t-1];
		cuenta1+=t*prob;
	}
	ld res=cuenta1;
	cerr<<"cuenta1 "<<cuenta1<<"\n";
	fore(k,2,n+1){
		ld cur=calcp(k);
		res+=cur*(k%2?1:-1);
		cerr<<"k "<<k<<": "<<cur<<"\n";
	}
	cout<<fixed<<setprecision(15);
	cout<<res<<"\n";
	return 0;
}