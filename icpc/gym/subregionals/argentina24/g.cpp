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

int main(){
    JET
    int a=0,t=0,p=0;
    string s;
    cin>>s;
    fore(i,0,SZ(s)){
        if(s[i]=='A'||s[i]=='U'){
            a++;
        }
        else if(s[i]=='T') t++;
        else if (s[i]=='P')p++;
    }
    cout<<min(a,min(t,p))<<"\n";
    return 0;
}