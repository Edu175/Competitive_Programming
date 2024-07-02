#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		// cout<<s<<": ";
		if(SZ(s)==2){
			cout<<stoll(s)<<"\n";
			continue;
		}
		if(SZ(s)==3){
			ll mn=stoll(s);
			fore(m,1,3)fore(d,0,2){
				ll a=stoll(s.substr(0,m)),b=stoll(s.substr(m,3-m));
				if(d)mn=min(mn,a*b);
				else mn=min(mn,a+b);
			}
			cout<<mn<<"\n";
			continue;
		}
		if(count(ALL(s),'0')){
			cout<<"0\n";
			continue;
		}
		ll mn=10;
		fore(i,0,n-1)mn=min(mn,(ll)s[i]-'0');
		ll flag=0;
		fore(i,0,n-1)flag|=s[i]-'0'==mn&&s[i+1]!='1';
		ll sum=0;
		fore(i,0,n)if(s[i]>'1')sum+=s[i]-'0';
		if(mn!=1)sum-=mn;
		ll res=10*mn+sum;
		if(!flag)res++;
		// cout<<mn<<" "<<sum<<" "<<flag<<" = ";
		cout<<res<<"\n";
	}
	return 0;
}
