#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,isudgh=b;i<isudgh;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jhglkdfjg:v)cout<<jhglkdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MOD=998244353;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

const ll A=64; //alphabet
ll q[64][64];
string cv(ll mk, ll sz){
	string r="(";
	fore(i,0,sz){
		if(i)r.pb(',');
		r+=to_string(mk%A),mk/=A;
	}
	r.pb(')');
	return r;
}

ll solve(vector<string>&a){
	if(!SZ(a))return 0;
	// cout<<"solve "; imp(a);
	ll n=SZ(a);
	vector<char>c;
	fore(i,0,n)c.pb(a[i][0]),c.pb(a[i].back());
	sort(ALL(c));
	vector<char> ci;
	fore(i,0,SZ(c))if(!i||c[i]!=c[i-1])ci.pb(c[i]);
	c=ci;
	for(auto &s:a){
		auto change=[&](char &j){
			ll p=lower_bound(ALL(c),j)-c.begin();
			j=p;
		};
		change(s[0]); change(s.back());
	}
	ll Z=SZ(c);
	// imp(a);
	set<string> st[A][A];
	for(auto s:a){
		st[int(s[0])][int(s.back())].insert(s);
		reverse(ALL(s));
		st[int(s[0])][int(s.back())].insert(s);
	}
	fore(i,0,A)fore(j,0,A)q[i][j]=SZ(st[i][j]);
	/*fore(i,0,A){
		imp(q[i]);
	}*/
	// vector<ll>pot(5); pot[0]=1;
	// fore(i,1,5)pot[i]=pot[i-1]*A;
	ll cnt=0;
	vector<ll>num(1<<18);
	fore(mk,0,1<<18){
		vector<ll>a(3);
		ll mki=mk,flag=1;
		fore(i,0,3)a[i]=mki&63,mki>>=6,flag&=a[i]<Z;
		if(!flag)continue;
		cnt++;
		fore(c,0,A){
			ll val=1;
			fore(j,0,3)val=mul(val,q[a[j]][c]);
			num[mk]=add(num[mk],val);
		}
		// cout<<mk<<" "<<cv(mk,3)<<": "<<num[mk]<<"\n";
	}
	ll ans=0;
	fore(mk,0,1<<24){	
		vector<ll>a(4);
		ll mki=mk,flag=1;
		fore(i,0,4)a[i]=mki&63,mki>>=6,flag&=a[i]<Z;
		if(!flag)continue;
		cnt++;
		ll res=1,m=mk>>6;
		fore(i,0,4){
			res=mul(res,num[m]);
			//m=(m+a[i]*pot[3])>>6;
			m=(m|(a[i]<<18))>>6;
			// if(num[m])cout<<m<<": "<<num[m]<<"\n";
		}
		ans=add(ans,res);
		/*if(res){
			imp(a);
			// imp(num);
			cout<<": "<<res<<"\n\n";
		}*/
	}
	// cout<<ans<<"\n";
	cout<<cnt<<" pasos "<<endl;
	return ans;
	
}
const ll MAXV=11;
int main(){FIN;
	ll n; cin>>n;
	vector<string> b[MAXV];
	fore(i,0,n){
		string s;cin>>s;
		b[SZ(s)].pb(s);
	}
	ll res=0;
	fore(i,0,MAXV){
		res=add(res,solve(b[i]));
	}
	// res=solve(b[5]);
	cout<<res<<"\n";
	return 0;
}