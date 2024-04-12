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

ld out(ld x){
	cout<<fixed<<setprecision(17)<<x<<"\n";
	string s=to_string(x*1e7);
	fore(i,0,SZ(s))if(s[i]=='.'){
		s.resize(i);
		break;
	}
	//cout<<s<<"\n";
	ll d=s.back()-'0',k=0;
	if(d>5)k=1;
	if(d==5&&(s[SZ(s)-2]-'0')%2)k=1;
	return (stoll(s)/10+k)*1e-6;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ld>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ld>p(105);
	ld res=0;
	for(ll i=n-1;i>=0;i--){
		fore(j,0,a[i]){
			fore(k,0,j)res+=p[k]/a[i];
		}
		fore(j,0,a[i])p[j]+=1./a[i];
	}
	cout<<fixed<<setprecision(6)<<out(res)<<"\n";
	//cout<<to_string(res)<<"\n";
	return 0;
}
