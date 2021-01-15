#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> initial_state={3,3,0};
    vector<int> final_state={0,0,1};
    vector<vector<int>> allStates;
    queue<vector<int>> q;
    q.push(initial_state);
    map<vector<int>,int> visited;
    while(!q.empty())
    {
        vector<int> current_state=q.front();
        q.pop();
        if(current_state==final_state)
        {
            allStates.push_back(current_state);
            break;
        }
        else if(visited[current_state])
            continue;
        else
        {
            visited[current_state]=1;
            allStates.push_back(current_state);
            int mLeft,cLeft,mRight,cRight;
            mLeft=current_state[0];
            mRight=3-mLeft;
            cLeft=current_state[1];
            cRight=3-cLeft;
            if(current_state[2]==0)
            {
                if(mLeft-1>=cLeft-1 and mRight+1>=cRight+1)// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                    q.push({mLeft-1,cLeft-1,1});
                }
                if(mLeft-1>=cLeft and mRight+1>=cRight)// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                    q.push({mLeft-1,cLeft,1});
                }
                if(mLeft>=cLeft-1 and (mRight>=cRight+1 or mRight==0))// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                     q.push({mLeft,cLeft-1,1});
                }
                if(mLeft-2>=cLeft and mRight+2>=cRight)// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                    q.push({mLeft-2,cLeft,1});
                }
                if(mLeft>=cLeft-2 and (mRight>=cRight+2 or mRight==0))// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                    q.push({mLeft,cLeft-2,1});
                }
                if(mLeft-1==0 or mLeft-2==0)
                {
                    q.push({0,cLeft,1});
                }
            }
            else
            {
                 if(mRight-1>=cRight-1 and mLeft+1>=cLeft+1)// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                    q.push({mLeft+1,cLeft+1,0});
                }
                if(mRight-1>=cRight and mLeft+1>=cLeft)// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                    q.push({mLeft+1,cLeft,0});
                }
                if(mRight>=cRight-1 and (mLeft>=cLeft+1 or mLeft==0))// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                     q.push({mLeft,cLeft+1,0});
                }
                if(mRight-2>=cRight and mLeft+2>=cLeft)// and mLeft+mRight==3 and cLeft+cRight==3)
                {
                    q.push({mLeft+2,cLeft,0});
                }
                if(mRight>=cRight-2 and (mLeft>=cLeft+2 or mLeft==0) )//and mLeft+mRight==3 and cLeft+cRight==3)
                {
                    q.push({mLeft,cLeft+2,0});
                }
                if(mRight-1==0 or mRight-2==0)
                {
                    q.push({3,cLeft,0});
                }
            }
        }
    }
    
    for(auto state:allStates)
    {
         cout<<state[0]<<" Missionaries  and "<<state[1]<<" Carnibals on left side ";
        if(state[2]==1)
            cout<<"And Boat is on right Side\n";
        else
            cout<<"And Boat is on left Side\n";
    }
}