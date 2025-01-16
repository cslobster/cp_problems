#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f0r(i,n) for(ll i = 0; i<(ll)(n); i++)




int main(){
    srand(time(0));

    ll n=20000,m=20000,k=20000;
    cout<<n<<" "<<m<<" "<<k<<"\n";

    f0r(i,k){
        ll p=rand()%n+1;
        ll x=rand()%m+1;
        ll q;
        do{
            q=rand()%n+1;
        }
        while(q==p);
        ll y=rand()%m+1;
        // make a bunch of relevant ones
        // if(rand()%2) x = rand()%50+1;
        // if(rand()%2) y = rand()%50+1;
        // if(rand()%2) x = rand()%5+1;
        // if(rand()%2) y = rand()%5+1;
        cout<<p<<" "<<x<<" "<<q<<" "<<y<<"\n";
    }
}