#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	//P[5]={1444441,1777771,1234567,1242421,1010003};
	vector<bint>pi,h;//,pt;
	ll n,t;
	Hash(string& s, ll ty){
		t=ty; n=SZ(s);
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
		if(t){
			e--;
			s=n-1-s,e=n-1-e;
			swap(s,e);
			e++;
		}
		return ((h[e]-h[s]+MOD)*pi[s])%MOD;
	}
};
int main(){FIN;
	string a,b; cin>>a>>b;
	ll n=SZ(a);
	Hash ha(a,0),hb(b,0);
	reverse(ALL(a));
	Hash ra(a,1);
	reverse(ALL(a));
	ll res=-1;
	fore(k,0,n){
		ll flag=ha.get(k,n)==hb.get(0,n-k);
		flag&=(hb.get(n-k,n)==ra.get(0,k));
		if(flag){
			res=k;
			break;
		}
	}
	if(res==-1)cout<<"No\n";
	else cout<<"Yes\n"<<res<<"\n";
	return 0;
}
