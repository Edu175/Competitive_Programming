#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll C=6;
vector<vector<string>>dat;

vv val(26);
ll at=0,res;
void f(ll tab){
	while(at<SZ(dat)&&SZ(dat[at][0])>=tab){
		if(dat[at][1]=="lag")res++,at++;
		else {
			
		}
	}
}

int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("fygon.in","r",stdin);
	freopen("fygon.out","w",stdout);
	#endif
	cin.ignore();
	string s;
	getline(cin,s);
	// cout<<s<<"\n";
	while(1){
		string s;
		getline(cin,s);
		if(s=="")break;
		ll p=0;
		fore(i,0,SZ(s))if(s[i]!=' '){p=i;break;}
		vector<string> v;
		v.pb(string(p/4,' '));
		if(s[p]=='l')v.pb("lag");
		else {
			v.pb("for");
			v.pb(to_string(s[p+4]));
			v.pb(to_string(s[p+15]));
		}
		dat.pb(v);
	}
	return 0;
}