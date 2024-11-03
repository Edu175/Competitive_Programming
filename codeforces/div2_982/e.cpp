#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll ppc(ll n){return __builtin_popcountll(n);}
map<ii,ll>dp;
ll grundy(ll x, ll a){
	if(dp.count({x,a}))return dp[{x,a}];
	ll &res=dp[{x,a}];
	if(x==0)return 0;
	set<ll>st;
	fore(d,1,a+1)if((d&x)==d)st.insert(grundy(x-d,a));
	fore(i,0,SZ(st)+5)if(!st.count(i))return res=i;
	assert(0);
}
string bin(ll x, ll k=-1){
	string s;
	while(x)s.pb('0'+(x&1)),x/=2;
	if(k!=-1)s.resize(k,'0');
	reverse(ALL(s));
	return s;
}
ll mygrundy(ll x, ll a){
	while((a||x)&&!(x%2))x/=2,a/=2;
	ll gr=0,did=0;
	for(ll j=32;j>=0;j--){
		did|=a>>j&1;
		if(!did&&(x>>j&1))x^=1ll<<j;
	}
	ll win=0;
	if(a>=x){
		gr=ppc(x);
	}
	else {
		vv c(4);
		ll f10=-1,l1=-1;
		for(ll j=32;j>=0;j--){
			ll p=x>>j&1,q=a>>j&1;
			if(p&&!q&&f10==-1)f10=j;
			if(p)l1=j;
			c[2*p+q]++;
		}
		if(f10>l1)win=1;
		ll bad=c[2]%2&&c[3]==1&&c[1]==0;
		ll v=ppc(x)-bad*2;
		gr=win?v:0;
	}
	return gr;
}
ll cv(string s){
	ll x=0;
	fore(i,0,SZ(s))x=x*2+s[i]-'0';
	return x;
}
void stress(){
	ll N; cin>>N;
	random_device rd;
	mt19937 rng(rd());
	ll cnt=0;
	while(1){
		ll n=rng()%N;
		string sx(1,'1'),sa(1,'1');
		fore(i,0,n){
			ll mk=rng()%3;
			if(mk==2)sx.pb('0'),sa.pb('1');
			else if(mk)sx.pb('1'),sa.pb('0');
			else sx.pb('1'),sa.pb('1');
		}
		auto x=cv(sx),a=cv(sa);
		ll sol=grundy(x,a),ans=mygrundy(x,a);
		if(sol!=ans){
			cout<<"FAILED!!!\n";
			cout<<sx<<"\n";
			cout<<sa<<"\n";
			cout<<"expected "<<sol<<" found "<<ans<<"\n";
			exit(0);
		}
		cout<<"ok "<<++cnt<<endl;
	}
}
void test(){
	string sx,sa; cin>>sx>>sa;
	cout<<grundy(cv(sx),cv(sa))<<" "<<mygrundy(cv(sx),cv(sa))<<"\n";
	exit(0);
}
int main(){FIN;
	ll ty; cin>>ty;
	if(ty)test();
	stress();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),x(n);
		ll res=0;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>x[i];
		fore(i,0,n){
			ll gr=mygrundy(x[i],a[i]);
			res^=gr;
			// cout<<gr<<"\n";
		}
		if(res)cout<<"Alice\n";
		else cout<<"Bob\n";
		// cout<<"\n";
	}
	return 0;
}
