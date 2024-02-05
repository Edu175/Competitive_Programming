#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;

ld dp[5][7][7][7];
vector<ll>cho[5][7][7][7];

ld val(vector<ll>a){
	ld res=0;
	fore(i,0,3)if(a[i]>=3)res+=i+1+a[i]-3;
	return res;
}
ld f(ll k, vector<ll>a){
	ld &res=dp[k][a[0]][a[1]][a[2]];
	if(res!=-1)return res;
	cho[k][a[0]][a[1]][a[2]].resize(4);
	if(k==0)return res=val(a);
	for(vector<ll>ai=a;ai[0]>=0;ai[0]--)
	for(ai[1]=a[1];ai[1]>=0;ai[1]--)
	for(ai[2]=a[2];ai[2]>=0;ai[2]--){
		ai[3]=0;
		ll c=6-ai[0]-ai[1]-ai[2]-ai[3];
		ld p=1;
		fore(i,0,c)p/=6.0;
		ld resi=0;
		fore(mk,0,1ll<<(2*c)){
			vector<ll>b=ai;
			ld pi=p;
			fore(i,0,c){
				ll t=(mk&(3ll<<(2*i)))>>(2*i);
				b[t]++;
				if(t==3)pi*=3.0;
			}
			resi+=pi*f(k-1,b);
		}
		if(resi>res)res=resi,cho[k][a[0]][a[1]][a[2]]=ai;
	}
	return res;
}

int main(){FIN;
	fore(i,0,5)fore(j,0,7)fore(k,0,7)fore(l,0,7)dp[i][j][k][l]=-1;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>k;
		string s; cin>>s;
		vector<ll>a(4);
		fore(i,0,SZ(s)){
			if(s[i]>='0'&&s[i]<='9')a[s[i]-'1']++;
			else a[3]++;
		}
		cout<<fixed<<setprecision(15);
		cout<<f(k,a)<<"\n";
		
		vector<ll>ai=cho[k][a[0]][a[1]][a[2]];
		string re,typ="123";
		if(k){
			fore(i,0,3)fore(j,0,a[i]-ai[i])re.pb(typ[i]);
			fore(i,0,SZ(s))if(!(s[i]>='0'&&s[i]<='9'))re.pb(s[i]);
		}
		if(SZ(re))cout<<re<<"\n";
		else cout<<"-\n";
	}
	return 0;
}
