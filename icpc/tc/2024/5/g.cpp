#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll nue (int x){
	ll rta=1;
	fore(i,0,x) rta*=9;
	return rta;
}

int main(){
	JET
	string s; cin>>s;
	ll rta=0;
	ll acc=1;
	fore(i,0,SZ(s)){
		if(s[i]=='1'){
			if(i==0){
				rta=max(rta,nue(SZ(s)-1));
				continue;
			}
			else if(i==SZ(s)-1){
				rta=max(rta,acc);
				continue;
			}
			else continue;
		}
		if(s[i]=='0') continue;
		if(i!=SZ(s)-1){
			acc*=(s[i]-'0'-1);
		}
		else acc*=(s[i]-'0');
		rta=max(rta,acc*nue(SZ(s)-i-1));
		acc/=(s[i]-'0'-1);
		acc*=(s[i]-'0');
	}
	cout<<rta<<"\n";
	
	return 0;
}