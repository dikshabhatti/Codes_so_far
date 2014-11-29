//solution to
//https://www.hackerrank.com/challenges/chocolate-feast

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=0;
        // Computer answer
        int p=n/c;
        int nu=0;
        
        /*if(p<m) answer= p;
        else answer=p+1;
        */
        while(p>=m){ p=p-m+1;
                    ++nu;                    
                     }
        answer =(n/c)+nu;
        
        cout<<answer<<endl;
    }
    return 0;
}
