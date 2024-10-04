#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

set<int> s[9];
int dp[20000][10];
int pot[9];

int f (ll mask, int p){
    if(dp[mask][p]!=-1) return dp[mask][p];
    int a[9];
    fore(i,0,9)a[i]=0;
    int cnt=0;
    fore(i,0,9){
        a[i]=(mask/pot[i])%3;
        if(a[i])cnt++;
    }
    bool t=(cnt==4);
    cnt%=2;
    cnt++;
    //chequeo si gano alguien
    fore(i,0,3) if(a[3*i]!=0 && a[3*i]==a[3*i+1] && a[3*i]==a[3*i+2]){
        return (a[3*i]==1) ? 2 : 0;  
    }
    fore(i,0,3) if(a[i]!=0 && a[i]==a[3+i] && a[i]==a[6+i]){
        return (a[i]==1) ? 2 : 0;  
    }
    if(a[0]!=0 && a[0]==a[4] && a[0]==a[8]){
        return (a[0]==1) ? 2 : 0;  
    }
    if(a[2]!=0 && a[2]==a[4]&& a[2]==a[6]){
        return (a[2]==1) ? 2 : 0;  
    }


    if(t) return 1;


    ll nmask=mask+pot[p]*(cnt);
    int rta;
    if(cnt==1){
        rta=0;
        
        fore(i,0,9){    
            bool b=true;
            for(auto x:s[i]){
                if(a[x]==0) b=false;
            }
            if(a[i]==0 && i!=p && b)rta=max(rta,f(nmask,i));
        }
    }
    else{
        rta=2;
        
        fore(i,0,9){
            bool b=true;
            for(auto x:s[i]){
                if(a[x]==0) b=false;
            }
            if(b&&a[i]==0 && i!=p) rta=min(rta,f(nmask,i));
        }
    }
    dp[mask][p]=rta;
    cout<<"mask "<<mask<<" p "<<p<<" "<<dp[mask][p]<<"\n";
    return dp[mask][p];
}

int main(){
    JET
    mset(dp,-1);
    pot[0]=1;
    fore(i,1,9) pot[i]=pot[i-1]*3;
    int n; cin>>n;
    fore(i,0,n){
        int x,y; cin>>x>>y;
        x--;y--;
        s[y].insert(x);
    }
    int a=0;
    fore(i,0,9){
        if(s[i].empty())a=max(a,f(0,i));
    }
    cout<<a<<"\n";
    return 0;
}