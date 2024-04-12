#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ceoi=b;i<ceoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto kdjfhg:v)cout<<kdjfhg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e6+5;
ll L[MAXN],R[MAXN];
ll t[MAXN];
ll cnt=0, pos=0,q=0;
string s;
ll parse(){
	//cout<<"parse "<<pos<<endl;
	ll x=cnt++;
	if(s[pos]=='?'){
		q++;
		pos++;
		return x;
	}
	t[x]=(s[pos+2]=='x');
	pos+=4;
	L[x]=parse();
	//comma
	pos++;
	R[x]=parse();
	//)
	pos++;
	return x;
}
ii dp[MAXN];
ll sum[MAXN];
int main(){
	cin>>s;
	parse();
	ll n=cnt;
	/*fore(i,0,n){
		cout<<i<<" ("<<t[i]<<"): "<<g[i].fst<<","<<g[i].snd<<"\n";
	}*/
	for(ll x=n-1;x>=0;x--){
		ii &res=dp[x];
		if(!L[x]){
			res={0,0};
			sum[x]=1;
			continue;
		}
		auto [l1,r1]=dp[L[x]];
		auto [l2,r2]=dp[R[x]];
		ll n1=sum[L[x]],n2=sum[R[x]];
		if(t[x]){
			l1=n1-1-l1,r1=n1-1-r1;
			swap(l1,r1);
			l2=n2-1-l2,r2=n2-1-r2;
			swap(l2,r2);
		}
		auto &[l,r]=dp[x];
		l=min(l1,l2);
		r=r1+r2;
		sum[x]=n1+n2;
		if(t[x]){
			l=sum[x]-1-l,r=sum[x]-1-r;
			swap(l,r);
		}
		//cout<<x<<": "<<l<<","<<r<<"\n";
	}
	cout<<dp[0].snd-dp[0].fst+1<<"\n";
	return 0;
}
