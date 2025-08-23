#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXS=1e6+5;
int add(int a, int b){a+=b; if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b; if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

vector<int> kmppre(string& t){
	vector<int> r(SZ(t)+1); r[0]=-1;
	int j=-1;
	fore(i,0,SZ(t)){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
int kmp(string &s, string &t){ // occ of s in t
	int r=0;
	string KK=s+"$"+t;
	vector<int> b=kmppre(KK);
	fore(i,0,SZ(b)){
		if(b[i]==SZ(s))r++;
	}
	return r;
}
const ll half=(MOD+1)/2;
int main(){
	JET
	ll n,q; cin>>n>>q;
	vector<string> s(1);
	cin>>s[0];
	string t; cin>>t;
	t.insert(t.begin(),'.');
	n++;
	fore(i,1,n){
		if(SZ(s.back())>=MAXS)break;
		s.pb(s.back()+string(1,t[i])+s.back());
	}
	
	vector<vv> sp(26,vv(n+1));
	
	fore(z,0,26){
		auto &s=sp[z];
		ll pot=1;
		fore(i,1,n){
			pot=mul(pot,half);
			ll val=t[i]-'a'==z?pot:0;
			s[i+1]=add(s[i],val);
		}
	}
	
	vv pot(n+5); pot[0]=1;
	fore(i,1,SZ(pot))pot[i]=mul(pot[i-1],2);
	
	// for(auto i:s)cout<<i<<"\n";
	
	while(q--){
		ll p; string w; cin>>p>>w; // ya esta bien indexado
		ll k=n;
		fore(i,0,n)if(SZ(s[i])>=SZ(w)){k=i;break;}
		if(k==n||p<k){
			cout<<"0\n";
			continue;
		}
		// cout<<k<<" k\n";
		ll m=SZ(s[k]),h=SZ(w);
		ll prim=kmp(w,s[k]);
		string sanguche=s[k].substr(m-h+1)+"a"+s[k].substr(0,h-1);
		
		ll res=0;
		fore(z,0,26){
			sanguche[h-1]='a'+z;
			ll oc=kmp(w,sanguche);
			// cout<<sanguche<<" "<<oc<<"\n";
			// oc-=2*prim;
			ll sum=sub(sp[z][p+1],sp[z][k+1]);
			ll cur=mul(mul(pot[p],sum),oc);
			// cout<<z<<" "<<sum<<" "<<pot[p]<<" "<<oc<<": "<<cur<<"\n";
			res=add(res,cur);
		}
		
		res=add(res,mul(prim,pot[p-k]));
		
		cout<<res<<"\n";
	}
	
	return 0;
}