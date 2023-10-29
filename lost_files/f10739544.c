#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		//eeeeeef
		//eeeef
		ll n; cin>>n;
		string a; cin>>a;
		string s;
		s.pb(a[0]);
		ll flag=1;
		if(n==1)flag=0;
		ll j=0;
		ll op1=1;
		fore(i,1,n){
			if(j==SZ(s))j=0,op1=0,s+=s;
			if(op1==1){
				if(a[i]==s[j])j++;
				else {
					flag=0;
					break;
				}
			}
			else{
				if(a[i]!=s[0]){
					s+=a[i];
					op1=1;
					if(n>SZ(s)&&n<SZ(s)*2){
						flag=0;
						break;
					}
				}
				else j++,op1=1;
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
