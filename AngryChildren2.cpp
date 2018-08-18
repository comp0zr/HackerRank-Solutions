#include <bits/stdc++.h>
using namespace std;

int main() 
{    
    int n, k;
    cin >> n >> k;
    
    vector<long long> A(n), S(n, 0);
    vector<long long> dp(n, 0);
    
    for(int i=0; i<n; i++)
    {
        cin >> A[i];                
    }
    sort(A.begin(), A.end());    
    
    for(int i=1; i<k; i++) 
    {
        S[0] += abs(A[i] - A[0]);
    }
    dp[0] = S[0];
    
    for(int j=1; j<k; j++)
    {
        long long diff = abs(A[j] - A[j-1]);

        S[j] = S[j-1] - diff * (k - j);
        dp[0] += S[j];                
    }
    long long ans = dp[0];
    
    int end = (n >= 100000) ? (n - k) / 4 : n - k;
    
    for(int i=0; i < end; i++)
    {
        if(i != 0) 
        {        
            for(int j=0; j<k-1; j++)
            {
                long long diff = abs(A[i+(k-1)] - A[i+j]);
                
                S[i+j] += diff;
                dp[i] += S[i+j];
            }
            ans = min(ans, dp[i]);
        }
    }
    cout << ans;
    return 0;
}
