#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
    #ifdef ONLINE_JUDGE
freopen("deposits.in","r",stdin);     freopen("deposits.out","w",stdout);
#endif

    int n;
    cin>>n;
    fore(i,0,n){
        string s;
        getline(cin,s);
        cin.ignore();
        int j=0;
        while(s[j]<'A' && s[j]>'Z'){
            j++;
        }
        cout<<"("<<s[j]<<" | ~"<<s[j]<<")";
        if(i<n-1) cout<<" & ";
    }
    cout<<"\n";
    return 0;
}
