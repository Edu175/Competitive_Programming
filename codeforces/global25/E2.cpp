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
	Hash(){}
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
Hash h,rh;
ll n;
bool isPal(ll l, ll r){
	//cout<<"isPal "<<l<<" "<<r<<" | ";
	ll x=h.get(l,r);
	r--;
	l=n-1-l,r=n-1-r;
	swap(l,r);
	r++;
	ll y=rh.get(l,r);
	//cout<<l<<" "<<r<<"\n";
	return x==y;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		n=SZ(s);
		string rs=s; reverse(ALL(rs));
		//cout<<s<<" "<<rs<<"\n";
		if(s!=rs){
			cout<<"YES\n1\n"<<s<<"\n";
			continue;
		}
		h=Hash(s),rh=Hash(rs);
		ll p=-1;
		fore(e,1,n){
			if(!isPal(0,e)&&!isPal(e,n)){
				p=e;
				break;
			}
		}
		if(p==-1)cout<<"NO\n";
		else {
			cout<<"YES\n2\n";
			fore(i,0,p)cout<<s[i];
			cout<<" ";
			fore(i,p,n)cout<<s[i];
			cout<<"\n";
		}
		
	}
	return 0;
}
