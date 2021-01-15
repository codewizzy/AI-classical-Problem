//Input format: size of first jug, size of 2nd jug, required amount
// 4 3 2

//output format: Intermediate states

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int jugOne,jugTwo,required;
    cin>>jugOne>>jugTwo>>required;
    queue<pair<int,int>> q;
    q.push({0,0});
    vector<pair<int,int>> intermediate;
    map<pair<int,int>,int> visited;
    while(!q.empty())
    {
        pair<int,int> current=q.front();
        q.pop();
        if(current==make_pair(required,0))
        {
            intermediate.push_back(make_pair(required,0));
                break;
        }
        if(current==make_pair(0,required))
        {
            intermediate.push_back(make_pair(0,required));
                break;
        }
        if(visited[current]==1)
            continue;
        else
        {
            visited[current]=1;
            intermediate.push_back(current);
            int a=current.first;
            int b=current.second;
            if(visited[{a,0}]!=1)
            {
               q.push({a,0});
            }
            if(visited[{0,b}]!=1)
            {
               q.push({0,b});
            }
            if(visited[{jugOne,b}]!=1)
            {
                q.push({jugOne,b});
            }
            if(visited[{a,jugTwo}]!=1)
            {
                q.push({a,jugTwo});
            }
            if(a>=jugTwo-b)
            {
                if(visited[{a-jugTwo+b,jugTwo}]!=1)
                {
                    q.push({a-jugTwo+b,jugTwo});
                }
            }
            if(b>jugOne-a)
            {
                if(visited[{jugOne,b-jugOne+a}]!=1)
                {
                    q.push({jugOne,b-jugOne+a});
                }
            }
            if(a<jugTwo-b)
            {
                if(visited[{0,a+b}]!=1)
                {
                    q.push({0,a+b});
                }
            }
            if(b<jugOne-a)
            {
                if(visited[{a+b,0}]!=1)
                {
                    q.push({a+b,0});
                }
            }
        }
    }
    for(auto k:intermediate)
    {
        cout<<"("<<k.first<<","<<k.second<<") ";
    }
}