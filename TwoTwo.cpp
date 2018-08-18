#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char c = '-';
    int valid = 0;
    Node* next[10] = {NULL};
    
    Node()
    {
        for(int i=0; i<10; i++)
        {
            next[i] = NULL;
        }        
    }
    Node(char c) : c(c) 
    {
        for(int i=0; i<10; i++)
        {
            next[i] = NULL;
        }
    }    
};

Node* root = new Node;    
vector<long> memo;
string S;

void Insert(Node* root, string s)
{
    Node* node = root;
    
    for(int i=0; i<s.size(); i++)
    {
        int c = s[i] - '0';
        
        if(node->next[c] == NULL)
        {
            node->next[c] = new Node(s[i]);             
        }
        node = node->next[c];        
    }
    node->valid++;
}

int Solve(int i, string &s, Node* root)
{
    if(memo[i] != -1) return memo[i];
    if(i > s.size()) return 0;    
    
    long res = 0;
    
    Node* curr = root;

    int start = i;    
    long valid = 0;
    
    for(; i<s.size();)
    {
        int c = s[i] - '0';                
        
        if(curr->next[c])
        {
            curr = curr->next[c];
        }
        else break;
        
        valid += curr->valid;               
        ++i;
    }
    
    if(res == 0) 
    {
        res += valid;
    }
    memo[start] = res;
    
    if(start < s.size()-1)
    {
        res += Solve(start+1, s, root);
    }
    return res;
}


string Square(string a)
{
    string ans;    
    int index = 0;
    int carry = 0;
    
    for(int j=a.size()-1; j>=0; j--)
    {
        int prod = (a[j]-'0') * 2 + carry;

        carry = prod / 10;
        ans = to_string(prod % 10) + ans;
    }
    while(carry)
    {
        ans = to_string(carry % 10) + ans;
        carry /= 10;
    }        
                    
    return ans;
}

int main() 
{
    Insert(root, "1");
    string res = "2";
    
    for(int i=1; i<=800; i++)
    {
        Insert(root, res);
        res = Square(res);           
    }
    int t;
    cin >> t;
        
    while(t--)
    {
        string s;
        cin >> s;

        memo = vector<long>(100001, -1);    
        
        long ans = Solve(0, s, root);
        cout << ans << endl;
    }
    
    return 0;
}

