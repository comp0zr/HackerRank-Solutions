#include <bits/stdc++.h>
using namespace std;

set<vector<long long>> vis;

void PrintSolution(vector<int> &A, vector<int> &ops)
{
    for(int j=0; j<ops.size(); j++)
    {
        cout << A[j];

        if(ops[j] == 0) cout << "+";
        if(ops[j] == 1) cout << "-";
        if(ops[j] == 2) cout << "*";
    }
    cout << A.back();
    exit(0);
}

void Solve(vector<int> &A, vector<int> ops, int i, long long solution = 0)
{
    if(vis.count({i, solution})) return;    
    vis.insert({i, solution});    

    if(i == ops.size())
    {
        if(solution % 101 == 0)
        {            
            PrintSolution(A, ops);
            exit(0);
        }
        return;
    }
    else if(solution % 101 == 0 && i > 0)
    {
        for(int j=i; j<ops.size(); j++)
        {
            ops[j] = 2;
        }        
        PrintSolution(A, ops);
    }
    if(i >= A.size()-1) return;
    
    long long temp;
    
    for(int j=0; j<3; j++)
    {
        if(i == 0)
        {
            temp = (j == 0) ? (A[i] + A[i+1])
                 : (j == 1) ? (A[i] - A[i+1])
                            : (A[i] * A[i+1]);                        
        }
        else
        {
            temp = (j == 0) ? (solution + A[i+1])
                 : (j == 1) ? (solution - A[i+1])
                            : (solution * A[i+1]);
        }
        ops[i] = j;
        Solve(A, ops, i+1, temp % 101);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n), ops(n-1, 0);
    
    for(int i=0; i<n; i++)
    {
        cin >> A[i];       
    }    
    Solve(A, ops, 0);
    
    return 0;
}

