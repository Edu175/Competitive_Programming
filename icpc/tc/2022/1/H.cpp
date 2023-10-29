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
	string s;
	cin>>s;
	vector<string>p;
	string pi;
	ll pt=SZ(s);
	ll j=0;
	for(auto i:s){
		if((i>='0'&&i<='9')||i=='.'){
			if(i!='.')pi.pb(i);
			else pt=j;
		}
		else if(SZ(pi)){
			if(pt!=j-3)pi+="00";
			p.pb(pi);
			pi.clear();
		}
		j++;
	}
	if(SZ(pi)){
		if(pt!=j-3)pi+="00";
		p.pb(pi);
	}
	ll res=0;
	ll resi=0;
	for(auto i:p){
		for(auto j:i)resi+=j-'0',resi*=10;
		resi/=10;
		res+=resi;
		//cout<<resi<<" ";
		resi=0;
	}
	string ans=to_string(res);
	ll mod;
	//cout<<SZ(ans)<<" "<<mod<<" ";
	//cout<<ans<<" ";
	if(SZ(ans)==1)ans="00"+ans;
	else if(SZ(ans)==2)ans="0"+ans;
	if(ans[SZ(ans)-1]=='0'&&ans[SZ(ans)-2]=='0'){
		ans.pop_back();
		ans.pop_back();
		mod=(SZ(ans))%3;
	}
	else mod=(SZ(ans)-2)%3;
	//cout<<SZ(ans)<<" "<<mod<<" ";
	fore(i,0,SZ(ans)){
		if(i%3==mod&&i)cout<<'.';
		cout<<ans[i];
	}
	cout<<"\n";
	return 0;
}
