#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long MOD = 1000000007;

int main() 
{
    int q;
    cin >> q;
    
    while(q--)
    {
        int n, m;
        cin >> n >> m;
        
        long long y_cuts[n-1], x_cuts[m-1];
        
        for(int i=0; i<n-1; i++)
        {
            cin >> y_cuts[i];        
        }
        for(int i=0; i<m-1; i++)
        {
            cin >> x_cuts[i];
        }                
        sort(y_cuts, y_cuts + n-1, [](long long a, long long b){ return a > b; });
        sort(x_cuts, x_cuts + m-1, [](long long a, long long b){ return a > b; });        
        
        long long y_splits = 1, x_splits = 1;
        int cuts = 0;
        int y_index = 0, x_index = 0;
        
        long long ans = 0;
                
        while(cuts < (n+m)-2)
        {            
            long long add;
            
            if(y_index < n-1)
            {                                
                if(x_index < m-1)
                {                                            
                    if(y_cuts[y_index] >= x_cuts[x_index])
                    {             
                        add = (y_cuts[y_index] * x_splits) % MOD;                        
                        y_index++;
                        y_splits++;                        
                    }
                    else
                    {
                        add = (x_cuts[x_index] * y_splits) % MOD;                        
                        x_index++;
                        x_splits++;
                    }
                }
                else
                {
                    add = (y_cuts[y_index] * x_splits) % MOD;                    
                    y_index++;
                    y_splits++;
                }                
            }
            else
            {
                add = (x_cuts[x_index] * y_splits) % MOD;                
                x_index++;
                x_splits++;                 
            }
            ans = (ans + add) % MOD;
            
            if(ans < 0) ans += MOD;
            
            cuts++;
        }
        cout << ans % MOD << endl;
    }
    return 0;
}
