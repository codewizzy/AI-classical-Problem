// input formant -> 0 - 8 natural numbers where 0 represent empty state eg. 0 1 3 4 2 5 7 8 6
// output -> shows allthe intermediate step to reach final state which is 1 2 3 4 5 6 7 8 0

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ret;

struct compare
{
    bool operator()(vector<int>&v1,vector<int>&v2)
   {
    int cnt1=0,cnt2=0;
    for(int i=0;i<9;i++)
    {
        if(v1[i]==0)
            continue;
        if(v1[i]!=i+1)
            cnt1++;
    }
    cnt1+=v1[9];
    for(int i=0;i<9;i++)
    {
        if(v2[i]==0)
            continue;
        if(v2[i]!=i+1)
            cnt2++;
    }
    cnt2+=v1[9];
    return cnt1>=cnt2;
   }
};

void solve(vector<int> &puzzle)
{
    int moves=0;
    vector<int> final_state;
    final_state={1,2,3,4,5,6,7,8,0};
    priority_queue<vector<int>,vector<vector<int>>,compare> pq;
    map<vector<int>,vector<int>> visited;
    visited[puzzle]={1,2,3,4,5,6,7,8,9,0};
    puzzle.push_back(0);
    pq.push(puzzle);
    
    
    while(!pq.empty())
    {
        vector<int> temp=pq.top();
        pq.pop();
        int k=temp[9];
        temp.pop_back();
        if(temp==final_state)
            break;
        ret.push_back(temp);
        int i=0;
        for(i=0;i<9;i++)
            if(temp[i]==0)
                break;
        if(i>2)
        {
            vector<int> v=temp;
            swap(v[i-3],v[i]);
            if(visited.count(v)==0)
            {
                
                visited[v]=temp;
                v.push_back(k+1);
                pq.push(v);
            }
        }
        if(i<6)
        {
            vector<int> v=temp;
            swap(v[i+3],v[i]);
            if(visited.count(v)==0)
            {
               
                visited[v]=temp;
                 v.push_back(k+1);
                pq.push(v);
            }     
        }
        if(i!=0 and i!=3 and i!=6)
        {
            vector<int> v=temp;
            swap(v[i-1],v[i]);
            if(visited.count(v)==0)
            {
                
                visited[v]=temp;
                v.push_back(k+1);
                pq.push(v);
            }
        }
        if(i!=2 and i!=5 and i!=8)
        {
            vector<int> v=temp;
            swap(v[i+1],v[i]);
            if(visited.count(v)==0)
            {
                
                visited[v]=temp;
                v.push_back(k+1);
                pq.push(v);
            }
        }
    }
    ret.push_back(final_state);
    return ;
}

int main()
{
    vector<int> puzzle(9);
    
    for(int i=0;i<9;i++)
       cin>>puzzle[i];
    
    solve(puzzle);
    for(auto k:ret)
    {
        cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<endl;
        cout<<k[3]<<" "<<k[4]<<" "<<k[5]<<endl;
        cout<<k[6]<<" "<<k[7]<<" "<<k[8]<<endl;
        cout<<"\n";
    }
}