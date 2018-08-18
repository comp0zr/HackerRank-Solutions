#include <bits/stdc++.h>
using namespace std;

int n;

int sherlockAndMinimax(vector <int> A, int p, int q) 
{
    int ans = -1e9;
    int maxMin = -1e9;    
    int lastMin = -1e9;
    int lastAns = -1e9;
    int lastIndex = 0;    
    int ansIndex = 0;
    
    sort(A.begin(), A.end());            
    
    while(p <= q)
    {
        int mn = 1e9;     
        int index = -1;
        
        for(int j=lastIndex; j<n; j++)
        {
            if(abs(A[j] - p) >= mn) break;            
            
            mn = abs(A[j] - p);
            index = j;            
        }                                   
        if(mn > maxMin)
        {            
            maxMin = mn;
            ansIndex = index;            
            ans = p;                       
        }
        else if(mn < lastMin) 
        {
            if(index < ansIndex) break;
            
            p += max(1, lastMin);
            lastMin = mn;
            continue;                        
        }      
        lastMin = mn;
        lastIndex = index;
        p++;
    }
    return ans;
}
int main() 
{
    cin >> n;    
    vector<int> A(n);
    
    for(int i=0; i<n; i++)
    {
       cin >> A[i];
    }
    int p, q;
    cin >> p >> q;
    
    int result = sherlockAndMinimax(A, p, q);
    cout << result << endl;
    return 0;
}
