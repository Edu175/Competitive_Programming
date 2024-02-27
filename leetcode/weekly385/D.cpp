#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	//P[5]={1444441,1777771,1234567,1242421,1010003};
	vector<bint>pi,h;//,pt;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1);//,pt.resize(SZ(s)+1);
		pi[0]=1,h[0]=0;//,pt[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+s[i-1]*p)%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
			//pt[i]=p;
		}
	}
	ll get(ll s, ll e){
		return ((h[e]-h[s]+MOD)*pi[s])%MOD;
	}
};

const ll MAXN=5e5+5;
int tr[MAXN][26];
ll c[MAXN];
ll cnt=1;
int add(ll x, char c){
	int &res=tr[x][c-'a'];
	if(res!=-1)return res;
	return res=cnt++;
}
ll solve(vector<string>a){
	mset(tr,-1);
	cnt=1;
	mset(c,0);
	ll n=SZ(a);
	ll res=0;
	fore(i,0,n){
		Hash h(a[i]);
		ll x=0;
		fore(j,0,SZ(a[i])){
			x=add(x,a[i][j]);
			if(c[x]&&h.get(0,j+1)==h.get(SZ(a[i])-j-1,SZ(a[i])))res+=c[x];
			//,cout<<i<<","<<j<<": "<<c[x]<<"\n";
		}
		c[x]++;
	}
	return res;
}
/*int main(){FIN;
	ll n; cin>>n;
	vector<string>a(n);
	fore(i,0,n)cin>>a[i];
	cout<<solve(a)<<"\n";
	return 0;
}*/
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        return solve(words);
    }
};
