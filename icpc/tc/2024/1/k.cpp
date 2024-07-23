#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll busco=1,debug=0;
const ll INF=100;
ll res=INF;
bool digit(char c){return (c>='0'&&c<='9')||c==':';}
ll flag=1;
string to_str(ll n){
	if(n<0)return ":"+to_string(abs(n));
	return to_string(abs(n));
}
ll sto(string s){
	if(s[0]==':')s[0]='-';
	return stoll(s);
}
map<string,ll>dp;
ll parse(string s){
	// if(dp.count(s))return dp[s];
	auto res=0;//=dp[s];
	// cout<<s<<endl;
	// return;
	// search ()
	ll p=-1;
	fore(i,0,SZ(s)){
		if(s[i]=='(')p=i;
		if(p!=-1&&s[i]==')'){
			return res=parse(s.substr(0,p)+
			to_str(parse(s.substr(p+1,i-p-1)))+
			s.substr(i+1,SZ(s)-i-1));
		}
	}
	ll c=0;
	for(auto i:s)c+=!digit(i);
	// cout<<s<<" "<<flag<<"\n";
	// cout<<c<<" signos\n";
	if(c==0)return res=sto(s);
	if(c==1){
		// cout<<"1 termino\n";
		ll p=-1;
		fore(i,0,SZ(s))if(!digit(s[i]))p=i;
		ll l=parse(s.substr(0,p)),
		r=parse(s.substr(p+1,SZ(s)-p-1));
		char c=s[p];
		if(c=='+')return res=l+r;
		if(c=='-')return res=l-r;
		if(c=='*')return res=l*r;
		if(c=='/'){
			// cout<<l<<" "<<r<<" l r\n";
			if(r!=0&&l%r==0)return res=l/r;
			// cout<<"invalidado\n";
			flag=0;
			return res=1;
		}
	}
	
	// search * o /
	auto pordiv=[&](char c){
		return c=='*'||c=='/';
	};
	auto yes=[&](char c){
		return 1;
	};
	ll ans=0,did=0;
	auto search=[&](auto cond){
		char ty='.'; ll l=-1,m=-1;
		fore(i,0,SZ(s)+1){
			if(i==SZ(s)||!digit(s[i])){
				if(cond(ty)&&m>0){
					string t;
					// cout<<l<<","<<m<<","<<i<<" "<<ty<<"\n";
					if(l+1>0)t+=s.substr(0,l+1);
					t+=to_str(parse(s.substr(l+1,i-l-1)));
					t+=s.substr(i,SZ(s)-i);
					ans=parse(t); did=1;
					return;
				}
				l=m,m=i;
				if(i<SZ(s))ty=s[i];
			}
		}
	};
	
	// cout<<"search pordiv\n";
	search(pordiv);
	if(did)return res=ans;
	// cout<<"search yes\n";
	search(yes);
	return res=ans;
	
}
void process(string s, ll val){
	flag=1;
	ll ans=parse(s);
	if(flag&&ans==24)res=min(res,val);//,cout<<s<<" se pudo "<<flag<<"\n";
	// if(busco&&flag&&ans==24&&val==2)cout<<s<<"\n";
}
vector<string> ops={"+","-","*","/"};
void solve(vector<ll>a){
	vector<ll> p(4);
	iota(ALL(p),0);
	do{
		ll sw=0;
		fore(i,0,4)fore(j,i+1,4)sw+=(p[i]>p[j]);
		// 0 parentesis
		fore(mk,0,64){
			string s;
			fore(i,0,4){
				s+=to_string(a[p[i]]);
				if(i<3)s+=ops[(mk>>(2*i))&3];
			}
			process(s,2*sw);
		}
		// 1 parentesis
		fore(mk,0,64)fore(l,0,3)fore(r,l+1,4){
			string s;
			fore(i,0,4){
				if(l==i)s+="(";
				s+=to_string(a[p[i]]);
				if(r==i)s+=")";
				if(i<3)s+=ops[(mk>>(2*i))&3];
			}
			process(s,2*sw+1);
		}
		// 2 parentesis
		fore(mk,0,64)fore(l,0,3)fore(r,l+1,4)
		fore(l2,0,3)fore(r2,l2+1,4){
			string s;
			fore(i,0,4){
				if(l==i)s+="(";
				if(l2==i)s+="(";
				s+=to_string(a[p[i]]);
				if(r==i)s+=")";
				if(r2==i)s+=")";
				if(i<3)s+=ops[(mk>>(2*i))&3];
			}
			process(s,2*sw+2);
		}
	}
	while(next_permutation(ALL(p)));
}
int main(){JET
	if(debug){
		string s; cin>>s;
		process(s,0);
		return 0;
	}
	vector<ll>a(4);
	fore(i,0,4)cin>>a[i];
	solve(a);
	if(res>=INF)cout<<"impossible\n";
	else cout<<res<<"\n";
}