#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((int)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// typedef long long ll;
// typedef pair<ll,ll> ii;
// typedef vector<ll> vv;
typedef unsigned long long ull;

struct ran{
	typedef unsigned long long uint64;
	vector<uint64> state;
	ran(uint64 seed){state = { seed, seed ^ 0x7263d9bd8409f526 };}
	uint64 next() {
	  uint64 s0 = state[0];
	  uint64 s1 = state[1];
	  uint64 result = s0 + s1;
	  s1 ^= s0;
	  state[0] = ((s0 << 55) | (s0 >> 9)) ^ s1 ^ (s1 << 14);
	  state[1] = (s1 << 36) | (s1 >> 28);
	  return result&((1ull<<50)-1); // last 50 only
	}
};

const int B=20;
typedef bitset<50> mask;
// assuming 50-lengthed integers
ull top(ull mk, int k){
	k=50-k;
	return (mk>>k)<<k;
}

int main(){
    JE
	
	int basura; cin>>basura;
	vector<ran> rng;
	
	fore(i,0,4){
		ull s; cin>>s;
		rng.pb(ran(s));
	}
	
	vector<vector<ull>> as(4);
	vector<vector<pair<ull,int>>> sd(4);
	fore(i,0,4){
		fore(j,0,1<<B){
			ull val=rng[i].next();
			as[i].push_back(val);
			sd[i].push_back({val,j});
		}
		sort(ALL(sd[i]));
	}
	
	vector<vector<pair<ull,pair<int,int>>>> cmb(2);
	fore(it,0,2){
		int s=it*2;
		auto &cur=cmb[it];
		auto &a=sd[s];
		auto &b=sd[s+1];
		for(auto [v,i]:a){
			ull nv=top(v,B);
			int po=lower_bound(ALL(b),pair<ull,int>{nv,-1})-b.begin();
			while(po<SZ(b)&&top(b[po].fst,B)==nv){
				cur.pb({v^b[po].fst,{i,b[po].snd}});
				po++;
			}
		}
		sort(ALL(cur));
	}
	
	auto &a=cmb[0];
	auto &b=cmb[1];
	int po=0;
	for(auto [v,snd]:a){
		while(po<SZ(b)&&b[po].fst<v)po++;
		if(po<SZ(b) && b[po].fst==v){
			auto [i,j]=snd;
			auto [k,l]=b[po].snd;
			cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<"\n";
			
			ull w=as[0][i];
			ull x=as[1][j];
			ull y=as[2][k];
			ull z=as[3][l];
			// cerr<<mask(w)<<" "<<mask(x)<<" "<<mask(y)<<" "<<mask(z)<<"\n";
			// cerr<<mask(w^x)<<" "<<mask(y^z)<<"\n";
			// cerr<<mask(v)<<" "<<mask(b[po].fst)<<"\n";
			// cerr<<mask(w^x^y^z)<<"\n";
			assert((w^x^y^z)==0);
			exit(0);
		}
	}
	assert(0);
	
    return 0;
}