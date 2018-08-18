#include <bits/stdc++.h>
using namespace std;

int n;

int Solve(vector<int> A) 
{
    vector<long> highestLeft(n);
    vector<long> last(n, -1e9), diff(n, -1e9);
    
    int mx = -1e9;
    
    for(int i=n-1; i>=0; i--)
    {
        mx = max(mx, A[i]);
        highestLeft[i] = mx;
    }
    int i = A[0] / 2;
    
    while(1)
    {
        long energy = i;
        int furthest = 0;
        
        for(int j=0; j<n; j++)
        {
            if(energy >= highestLeft[j])
            {
                return i;
            }            
            if(last[j] != -1e9 && diff[j] == -1e9)
            {
                diff[j] = energy - last[j];
            }
            last[j] = energy;                        
            furthest = j;
            
            if(energy < 0) break;
            
            energy += (energy < A[j]) ? -(A[j] - energy)
                                      :  (energy - A[j]);            
        }        
        if(energy >= 0) return i;        
        if(diff[furthest] != -1e9)
        {
            while(energy < 0)
            {
                i++;
                energy += diff[furthest];
            }            
        }
        else i++;
    }
    return 0;
}

int main() 
{
    cin >> n;
    vector<int> A(n);
    
    for(int i=0; i<n; i++)
    {
       cin >> A[i];
    }
    int result = Solve(A);
    cout << result << endl;
    return 0;
}

