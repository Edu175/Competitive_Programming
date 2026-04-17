#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
void pinchilon(){
	#ifdef ONLINE_JUDGE
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	#endif
}

void format(string &s){
	reverse(ALL(s));
	while(SZ(s)<19)s.pb('0');
}

int main(){pinchilon();
	JET
	ll op[10][10];
	fore(i,0,10)fore(j,0,10)cin>>op[i][j];
	ll l,r; cin>>l>>r;
	string s=to_string(l); l++;
	format(s);
	fore(i,l,r+1){
		auto t=to_string(i);
		format(t);
		fore(i,0,SZ(s))s[i]='0'+op[s[i]-'0'][t[i]-'0'];
	}
	while(SZ(s)>1&&s.back()=='0')s.pop_back();
	reverse(ALL(s));
	cout<<s<<"\n";
	return 0;
}