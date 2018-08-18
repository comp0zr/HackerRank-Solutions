#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
            
    vector<int> A(n);
    long total = 0;
    
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
        total += A[i];
    }
    if(k == n-1)
    {
        cout << total - *min_element(A.begin(), A.end());
        return 0;
    }
    vector<long> DP(n+1, 1e15), prev = DP;
    set<int> next;
    
    for(int i=0; i<=k; i++)
    {
        prev[i] = A[i];
        next.insert(i);
    }            
    long ans = 1e15;
    
    for(int i = 2; i <= n; i++)
    {
        set<int> temp;

        for(auto last : next)
        {            
            long mn = 1e15;
            int index = -1;
            
            for(int j = last + 1; j <= last + 1 + k && j < n; j++)
            {
                DP[j] = min(DP[j], prev[last] + A[j]);
             
                if((n-1)-j <= k)
                {
                    ans = min(ans, DP[j]);
                }
                if(DP[j] < mn)
                {
                    mn = DP[j];
                    index = j;
                }
            }               
            if(index != -1) temp.insert(index);
        }       
        if(n > 2000 && ans != 1e15) break;
        
        prev = DP;
        next = temp;
    }    
    cout << total - ans << "\n";
    return 0;
}

