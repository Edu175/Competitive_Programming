#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n; cin>>n;
	vector<vv> Fa(n,vv(2));
	vector<char> col(n);
	fore(i,0,n){
		cin>>Fa[i][0]>>Fa[i][1]>>col[i];
		fore(j,0,2)Fa[i][j]--;
	}
	auto can=[&](ll mk)->string { // empty if impossible
		auto fa=Fa;
		fore(i,0,n)if(mk>>i&1)swap(fa[i][0],fa[i][1]);
		vector<set<char>> sts(n);
		vector<char> mxs(n);
		for(ll i=n-1;i>=0;i--){
			auto &me=sts[i];
			me.insert(col[i]);
			if(SZ(me)>2||*me.begin()!=col[i])return "";
			auto &mxi=mxs[i];
			mxi=max(mxi,col[i]);
			if(SZ(me)==2&&*next(me.begin())<mxi)return "";
			ll p=fa[i][1];
			if(p!=-1)mxs[p]=max(mxs[p],mxi);
			ll idx=0;
			for(auto c:me){
				ll p=fa[i][idx];
				if(p==-1)continue;
				auto &he=sts[p];
				he.insert(c);
				if(SZ(he)>2)return "";
				idx++;
			}
		}
		// cerr<<mk<<":\n";
		// fore(i,0,n){
		// 	for(auto j:sts[i])cout<<j;
		// 	cout<<" "<<mxs[i]<<"\n";
		// }
		string ret;
		fore(i,0,n){
			auto &me=sts[i];
			string cur=string(ALL(me));
			if(SZ(me)<2){
				ll p=fa[i][1];
				char c=mxs[i];
				if(p!=-1){
					for(auto j:sts[p])if(j>=mxs[i]){
						c=j;
						break;
					}
				}
				me.insert(c);
				cur.pb(c);
			}
			ret+=cur;
			// assert that conditions hold
			assert(cur[0]==col[i]);
			assert(cur[0]<=cur[1]);
			assert(SZ(cur)==2);
			fore(j,0,2)if(fa[i][j]!=-1)assert(sts[fa[i][j]].count(cur[j]));
		}
		assert(SZ(ret)==2*n);
		return ret;
	};
	string ans;
	fore(mk,0,1ll<<n){
		auto got=can(mk);
		if(!SZ(got))continue;
		if(!SZ(ans)||got<ans)ans=got;
	}
	if(!SZ(ans)){
		cout<<"-1\n";
		return 0;
	}
	fore(i,0,n)cout<<ans[2*i]<<ans[2*i+1]<<"\n";
	return 0;
}
