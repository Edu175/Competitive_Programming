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

ll won(vector<string> a){
 	ll res=0;
 	fore(i,0,3){
		char c=a[i][0];
		if(a[i][0]=='.')continue;
		ll flag=1;
		fore(j,1,3)if(a[i][j]!=c)flag=0;
		res|=flag;
	}
	fore(j,0,3){
		char c=a[0][j];
		if(c=='.')continue;
		ll flag=1;
		fore(i,1,3)if(a[i][j]!=c)flag=0;
		res|=flag;
	}
	res|=(a[1][1]!='.'&&a[0][0]==a[1][1]&&a[1][1]==a[2][2]);
	res|=(a[1][1]!='.'&&a[0][2]==a[1][1]&&a[1][1]==a[2][0]);
	/*if(res){cout<<"won\n"; 
		fore(i,0,3){
			cout<<a[i]<<"\n";
		}
		cout<<"\n";
	}*/
	return res;
}
map<vector<string>,ll>dp;
ll val[3][3];
ll f(vector<string>a, ll p){
	if(dp.count(a))return dp[a];
	ll &res=dp[a];
	if(won(a))return res=0;
	res=2;
	fore(i,0,3)fore(j,0,3)if(a[i][j]=='.'){
		auto as=a;
		as[i][j]='a'+p;
		res=min(res,f(as,p^1));
	}
	if(res==2){
		ll sum=0;
		fore(i,0,3)fore(j,0,3){
			if(a[i][j]=='a')sum+=val[i][j];
			else sum-=val[i][j];
		}
		res=(p!=(sum>0));
	}
	else res^=1;
	return res;
}
int main(){FIN;
	fore(i,0,3)fore(j,0,3)cin>>val[i][j];
	vector<string> a(3,string(3,'.'));
	if(f(a,0))cout<<"Takahashi\n";
	else cout<<"Aoki\n";
	return 0;
}
