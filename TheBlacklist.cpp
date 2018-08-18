#include <bits/stdc++.h>
#define TestBit(bits, x) (bits & 1 << x) != 0
#define SetBit(bits, x) bits |= (1 << x)
using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    
    vector<vector<int>> sum(K, vector<int>(N+1, 0));    
    vector<vector<int>> DP(N+1, vector<int>((int)pow(2, K) + 1, -1));
    
    int ans = 1e9;
    
    for(int i=0; i<K; i++)
    {
        unsigned int index = 0;
        index |= (1 << i);        
        
        for(int j=0; j<N; j++)
        {
            int cost;
            cin >> cost;
            
            sum[i][j+1] = sum[i][j] + cost;            
            DP[j+1][index] = sum[i][j+1];                        
        }
        ans = min(ans, DP[N][index]);
    }    
    
    for(int i = 1; i < N; i++)
    {            
        for(unsigned int j = 0; j <= pow(2, K); j++)
        {                                    
            if(DP[i][j] == -1) continue;                        
            
            for(int k = N; k > i; k--)
            {            
                for(int l = 0; (1 << l) < pow(2, K); l++)
                {
                    if(TestBit(j, l)) continue;
                    
                    unsigned int next_index = j;
                    int add = sum[l][k] - sum[l][i];
                    
                    SetBit(next_index, l);
                    
                    if(DP[k][next_index] == -1 || DP[k][next_index] > DP[i][j] + add)
                    {
                        DP[k][next_index] = DP[i][j] + add;
                                                
                        if(k == N) ans = min(ans, DP[k][next_index]);                        
                    }                               
                }                
            }
        }
    }    
    cout << ans;
}

