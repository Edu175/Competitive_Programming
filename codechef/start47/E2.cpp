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
const ll MAXN=1000005;
ll n;
string a;

bool f(ll pos,ll op1,string s){
	bool flag=1;
	if(n<SZ(s)*2)return 0;
	ll j=0;
	if(op1==0)j=1;
	fore(i,pos,n){
		//cout<<i<<" "<<s<<" "<<op1<<" "<<j<<"\n";
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
					//cout<<"2sz";
					break;
				}
			}
			else return flag=max(f(i+1,0,s),f(i+1,1,s+=a[i]));
		}
	}
	//cout<<s<<" "<<op1<<" "<<j<<"\n";
	return flag;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		//eeeeeef
		//eeeef
		cin>>n;
		cin>>a;
		string s;
		s.pb(a[0]);
		if(f(1,1,s)&&n>1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
