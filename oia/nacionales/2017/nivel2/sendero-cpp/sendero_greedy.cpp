#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll sendero(int B, int G, int N, string &baldosas){
	string &b=baldosas;
    vector<pair<ll,ll>> c={{B,0},{G,1},{N,2}},c2=c;
    sort(ALL(c2));
    ll c3[3];
    fore(i,0,3)c3[i]=c2[i].snd;
    ll n=SZ(b);
    ll a[n];
    fore(i,0,n){
    	if(b[i]=='B')a[i]=0;
    	else if(b[i]=='G')a[i]=1;
    	else if(b[i]=='N')a[i]=2;
    	else a[i]=3;
    }
    ll res=0;
    ll u=2;
    fore(i,0,n){
    	if(a[i]==3){
    		if(u==2){
				ll r=i;
				while(r<n&&a[r]==3)r++;
				if(r<n-1){
					//cout<<i<<" "<<r-i<<" "<<a[r]<<"\n";
					if((r-i)%2&&a[r]==0)u=0;//,cout<<"N_impar_B\n";
					else if((r-i)%2==0&&a[r]==1)u=0;//,cout<<"N_par_G\n";
					else u=1;
				}
    		}
    		u^=1, a[i]=c3[u],res+=c[a[i]].fst;
    	}
    	else {
    		if(i&&a[i]==a[i-1]){
    			res-=c[a[i-1]].fst;
    			a[i-1]=c3[2];
    			res+=c[a[i-1]].fst;
    		}
    		u=a[i];
    	}
    }
    fore(i,0,n){
    	if(a[i]==0)b[i]='B';
    	if(a[i]==1)b[i]='G';
    	if(a[i]==2)b[i]='N';
    }
    return res;
}
