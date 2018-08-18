#include <bits/stdc++.h>

#define A first
#define B second
#define SetBit(bits, index) bits | 1 << index
#define TestBit(bits, index) (bits & 1 << index)==0

using namespace std;

typedef pair<unsigned int, unsigned int> Grid;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
        
    for(int t=0; t < T; t++)
    {
        int N;
        string row1, row2;
        
        cin >> N;                
        cin >> row1 >> row2;
        
        Grid grid = {0, 0}; 
        
        unsigned int target = 0, count = 0;
        
        for(int i=0; i<N; i++)
        {
            if(row1[i] == '1') 
            {
                grid.A = SetBit(grid.A, i);        
                count++;
            }            
            if(row2[i] == '1')
            {
                grid.B = SetBit(grid.B, i);
                count++;
            }            
            target = SetBit(target, i);
        }                        
        if(count & 1 != 0)
        {
            cout << "NO\n";
            continue;
        }                   
        set<Grid> found;
        found.insert(grid);
        
        for(int i=0; i<N; i++)
        {            
            set<Grid> next;           
            
            for(auto G : found)
            {                
                Grid temp;

                if(TestBit(G.A, i) && TestBit(G.B, i))
                {
                    next.insert({ SetBit(G.A, i), SetBit(G.B, i) });
                }                
                if(i > 0)
                { 
                    if(TestBit(G.A, i) && TestBit(G.A, i-1)) 
                    {
                        next.insert({ SetBit(SetBit(G.A, i), i-1), G.B });    
                    }                    
                    if(TestBit(G.A, i) && TestBit(G.B, i-1))
                    {
                        next.insert({ SetBit(G.A, i), SetBit(G.B, i-1) });                    
                    }                    
                    if(TestBit(G.B, i) && TestBit(G.B, i-1))
                    {
                        next.insert({ G.A, SetBit(SetBit(G.B, i), i-1) });                   
                    }
                }
                next.insert(G);                
            }
            found = next;
        }        
        found.count({target, target}) ? cout << "YES\n" 
                                      : cout << "NO\n";
    }
    return 0;
}
