#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,renison=b;i<renison;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; 
typedef vector<ll> vv;

ll dif(string a, string b){
	ll res=0;
	fore(i,0,SZ(a))res+=a[i]!=b[i];
	return res;
}

int main(){
	FIN;
	ll A,B,C; cin>>A>>B>>C;
	vv let={A,B,C};
	vv slet=let; sort(ALL(slet));
	A=slet[0]; B=slet[1]; C=slet[2];
	if(C>A+B){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	ll n=A+B+C+5;
	string a(n,'a');
	string b=a;
	fore(i,0,A)b[i]='b';
	string c=b;
	ll d=A+B-C,s=A-d;
	fore(i,s,s+B){
		assert(i>=0&&i<n);
		c[i]='c';
	}
	vector<string> res={a,b,c}; sort(ALL(res));
	vector<string> ans;
	A=let[0]; B=let[1]; C=let[2]; // vuelvo a las originales
	do{
		ll fg=1;
		fg&=dif(res[0],res[1])==A;
		fg&=dif(res[0],res[2])==B;
		fg&=dif(res[1],res[2])==C;
		if(fg)ans=res;
	}while(next_permutation(ALL(res)));
	assert(SZ(ans));
	cout<<ans[0]<<"\n";
	cout<<ans[1]<<"\n";
	cout<<ans[2]<<"\n";
	return 0;
}