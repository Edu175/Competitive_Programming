#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll INF = 1e17;

vv pr[10];

string s;
ll cast(int i, int j){
	return (s[i]-'0')*10+s[j]-'0';
}

ll val[10];
ll n;


bool check(){
	string s1=s;
	fore(i,1,10) s1[val[i]]='.';
	ll vis[n+1];
	mset(vis,0);
	fore(i,1,SZ(s1)){
		if(s1[i]=='.' || s1[i-1]=='.') continue;
		vis[cast(i-1,i)]++;
		s1[i]='.';
		s1[i-1]='.';
	}
	fore(i,10,n+1){
		if(i%10==0) continue;
		if(!vis[i]) return false;
	}
	return true;
}

bool f (int x){
	fore(i,0,SZ(pr[x])){
		val[x] = pr[x][i];
		if(x<9) if(f(x+1)) return true;
		else{
			if(check()) return true;
		}
	}
	return false;
}


int main(){
	
	#ifdef ONLINE_JUDGE
	freopen("holes.in","r",stdin);     freopen("holes.out","w",stdout);
	#endif

	JET
	cin>>s;
	if(SZ(s)<=9) n=SZ(s);
	else n= (SZ(s)-9)/2+9;
	ll pos[n+1];
	fore(i,0,SZ(s)){
		if(s[i]=='0') pos[cast(i-1,i)] = i-1;
		else continue;
		s[i]='.';
		s[i-1]='.';
	}
	
	ll vis[n+1];
	mset(vis,-1);
	pr[s[0]-'0'].pb(0);
	fore(i,1,SZ(s)){
		ll x = s[i]-'0';
		if(s[i]=='.') continue;
		if(x>=5){
			if(s[i-1]=='.'){
				assert(!SZ(pr[x]));
				pr[x].pb(i);
				continue;
			}
			if(cast(i-1,i)>n){
				assert(!SZ(pr[x]));
				pr[x].pb(i);
				continue;
			}
			if(vis[cast(i-1,i)]!=-1){
				assert(!SZ(pr[x]));
				pr[x].pb(i);
				pr[x].pb(vis[cast(i-1,i)]);
			}
			else{
				vis[cast(i-1,i)]=i;
			}
		}
		else pr[x].pb(i);
	}		
	fore(i,0,10)sort(ALL(pr[i]));
	assert(f(1));
	fore(i,1,10){
		pos[i] = val[i];
		s[val[i]] = '.';
	}
	fore(i,1,SZ(s)){
		// cout<<"viendo pos "<<i<<endl;
		if(s[i]=='.' || s[i-1] == '.') continue;
		// cout<<"paso a cast es "<<cast(i-1,i)<<endl;
		pos[cast(i-1,i)] = i-1;
		s[i]='.';
		s[i-1]='.'; 
	}
	ll rta[2*n];
	mset(rta,-1);
	fore(i,1,n+1){
		// cout<<"i "<<i<<" pos "<<pos[i]<<endl;
		rta[pos[i]] = i;
	}
	for(auto x:rta){
		if(x!=-1) cout<<x<<" ";
	}
	cout<<"\n";
	return 0;
	
}