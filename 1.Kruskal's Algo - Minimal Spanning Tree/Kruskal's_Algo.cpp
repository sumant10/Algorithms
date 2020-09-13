#include <bits/stdc++.h>
using namespace std;

struct edge{
    int a;
    int b;
    int w;
};
edge arr[100001];
int par[10001];
bool comp(edge a, edge b){
    if(a.w<b.w){
        return true;
    }
    return false;
}

int find(int a){
    if(par[a]==-1) return a;
    return par[a] = find(par[a]);
}
void merge(int a, int b){
    par[a]=b;
}
int main(){
    int n,m;
    cin >>n >>m;
    for(int i=1;i<=n;i++) par[i]=-1;
    for(int i=0;i<m;i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }
    sort(arr, arr+m, comp);
    int sum=0;
    for(int i=0;i<m;i++){
        int n1 = find(arr[i].a);
        int n2 = find(arr[i].b);
        if(n1!=n2){
            sum+=arr[i].w;
            merge(n1,n2);
        }
    }
    cout << sum << endl;
}
