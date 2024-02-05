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

#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<ll>pi,h,pt;
	ll pos=0,dif=0,rev=0;
	string S;
	Hash(){}
	Hash(string& s, ll is){
		assert((P*PI)%MOD==1);
		S=s; rev=is;
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1),pt.resize(SZ(s)+1);
		pi[0]=1,h[0]=0,pt[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+s[i-1]*p)%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
			pt[i]=p;
		}
	}
	ll get(ll s, ll e){
		if(rev){
			s=SZ(S)-s;
			e=SZ(S)-e;
			swap(e,s);
		}
		return ((h[e]-h[s]+MOD+(s<pos&&pos<e)*dif)*pi[s])%MOD;
	}
	void set(ll p, char c){
		pos=p;
		dif=(c-S[p]+MOD)%MOD*pt[p]%MOD;
	}
};
ll n;
Hash ha,hb;
ll exp(ll i, ll p){
	ll s=0,e=n;
	while(s<=e){
		ll m=(s+e)/2;
		if(i-m<0||i+m+p>n||ha.get(i-m,i+m+p)!=hb.get(i-m,i+m+p))e=m-1;
		else s=m+1;
	}
	return s;
}

void end(string s, ll i, ll c){
	s[i]='a'+c;
	cout<<s<<"\n";
	exit(0);
}

const ll B=26;
int main(){FIN;
	cin>>n;
	string a,b; cin>>a;
	b=a; reverse(ALL(b));
	ha=Hash(a,0),hb=Hash(b,1);
	vector<ii> q[n][B];
	ll d[n][2],l[n][2],r[n][2];
	fore(i,0,n){
		fore(p,0,2){
			ll s=exp(i,p);
			d[i][p]=s;
			l[i][p]=i-s;
			r[i][p]=i+s-(p^1);
			cout<<i<<" "<<p<<": "<<s<<": "<<l[i][p]<<" "<<r[i][p]<<"\n";
			if(i-s-(p^1)>0&&i+s+p<n){
				q[l[i][p]][a[r[i][p]]-'a'].pb({i,p});
			}
		}
	}
	ll be[n][B]={};
	mset(be,0);
	ll sw[n+1]={};
	ll qan=0,sum=0;
	fore(i,0,n){
		fore(p,0,2)sum+=r[i][p],qan++,sw[r[i][p]]++;
		qan-=sw[i];
		sum-=sw[i]*i;
		cout<<i<<": "<<sum<<" "<<qan<<"\n";
		fore(c,0,B)if(c!=a[i]-'a'){
			be[i][c]-=sum-qan*i;
			ha.set(i,'a'+c);
			hb.set(i,'a'+c);
			for(auto [j,p]:q[i][c]){
				be[i][c]-=d[j][p];
				be[i][c]+=exp(j,p);
			}
		}
	}
	qan=0,sum=0;
	for(ll i=n-1;i>=0;i--){
		fore(p,0,2)sum+=l[i][p],qan++,sw[l[i][p]]++;
		qan-=sw[i];
		sum-=sw[i]*i;
		fore(c,0,B)if(c!=a[i]-'a'){
			be[i][c]-=qan*i-sum;
		}
	}
	ll mx=0;
	set<ll>st;
	fore(i,0,n)fore(c,0,B){
		if(be[i][c]>mx)mx=be[i][c],st={i};
		else if(be[i][c]==mx)st.insert(i);
	}
	cout<<mx<<": ";
	imp(st);
	fore(i,0,n){
		fore(c,0,B)cout<<be[i][c]<<" ";;cout<<"\n";
	}
	string res=a;
	fore(i,0,n){
		st.erase(i);
		fore(c,0,B){
			if(be[i][c]==mx){
				if(!SZ(st)||c<a[i]-'a')end(a,i,c);
			}
		}
	}
	return 0;
}
