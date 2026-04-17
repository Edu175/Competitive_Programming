#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define RB(x) (x<n?r[x]:0)
void csort(vv &sa, vv& r, int k){
	int n=SZ(sa);
	vv f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}
vv constructSA(string &s){
	int n=SZ(s),rank;
	vv sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k+=k){
		csort(sa,r,k);
		csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}
int main(){
	#ifdef ONLINE_JUDGE
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	#endif
	JET
	ll n; cin>>n;
	vv a(n);
	vv p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	string ans(n,'.');
	ll u=n-1,s=0;
	while(u>=0&&p[u]==s)ans[u--]='0',s++;
	if(u<0){
		cout<<ans<<"\n";
		return 0;
	}
	ans[u]='1';
	for(ll i=u-1;i>=0;i--){
		ans[i]='0'+(p[i]>p[i+1]);
	}
	ans.pb('.');
	auto sa=constructSA(ans);
	assert(sa[0]==n); sa.erase(sa.begin());
	ans.pop_back();
	if(sa==a){
		cout<<ans<<"\n";
	}
	else cout<<"Error\n";
	return 0;
}