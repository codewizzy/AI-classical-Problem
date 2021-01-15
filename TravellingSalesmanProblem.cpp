// input format
// number of vertex
// names of vertex
// number of edges
// vertex1 vertex2 weight

// example input1
// 5
// A
// B
// C
// D
// E
// 8
// A B 4
// A E 3
// A C 1
// E C 2
// E B 2
// E D 1
// C D 3
// B D 5

// example input2
// 4
// 1
// 2
// 3
// 4
// 6
// 1 2 10
// 2 3 35
// 3 4 30
// 1 3 15
// 2 4 25
// 4 1 20

// output format
// minimum weight accross the path : path


#include<bits/stdc++.h>
using namespace std;

class edges
{
    public:
    int dest,weight;
    edges(int dest,int weight)
    {
        this->dest=dest;
        this->weight=weight;
    }
};

class node
{
    public:
    int src;
    int weight;
    unordered_set<int> st;
    string str;
    node(int src,int weight,unordered_set<int> st,string str)
    {
        this->src=src;
        this->weight=weight;
        this->st=st;
        this->str=str;
    }
};

int main()
{
    int vertex,n;
    cin>>vertex;
    unordered_map<string,int> mp;
    vector<string> match(vertex+1);
    for(int i=0;i<vertex;i++)
    {
        string s;
        cin>>s;
        mp[s]=i+1;
        match[mp[s]]=s;
    }
    cin>>n;
    vector<vector<edges*>> graph(vertex+1);
    for(int i=0;i<n;i++)
    {
        string from,to;
        int weight;
        cin>>from>>to>>weight;
        graph[mp[from]].push_back(new edges(mp[to],weight));
        graph[mp[to]].push_back(new edges(mp[from],weight));
    }
    string source;
    source=match[1];
    unordered_set<int> st;
    st.insert(mp[source]);
    node *first=new node(mp[source],0,st,source);
    queue<node*> q;
    q.push(first);
    int m=1;
    vector<string> ans;
    int minWeight=INT_MAX;
    while(m!=vertex+1 and !q.empty())
    {
        int a=q.size();
        m++;
        while(a-- and m!=vertex+1)
        {
            node* temp=q.front();
            q.pop();
            int src=temp->src;
            for(auto k:graph[src])
            {
                int dest=k->dest;
                int w=k->weight;
                if(temp->st.find(dest)==temp->st.end())
                {
                    string str=temp->str+", "+match[dest];
                    unordered_set <int> temp_st=temp->st;
                    temp_st.insert(dest);
                    node *res=new node(dest,temp->weight+k->weight,temp_st,str);
                    q.push(res);
                }
            }
        }
        if(m==vertex+1)
        {
            while(a--)
            {
                node* temp=q.front();
                q.pop();
                if(temp->st.size()!=vertex)
                    continue;
                int src=temp->src;
                for(auto k:graph[src])
                {
                    if(k->dest==mp[source])
                    {
                        if(minWeight>temp->weight+k->weight)
                        {     
                            ans.clear();
                            minWeight=temp->weight+k->weight;
                            ans.push_back(temp->str+", "+source);
                        }
                        else if(minWeight==temp->weight+k->weight)
                        {
                            ans.push_back(temp->str+", "+source);
                        }
                    }
                }
            }
        }  
    }
    if(minWeight==INT_MAX)
    {
        cout<<"No path Exist\n";
        return 0;
    }
    for(auto k:ans)
      cout<<minWeight<<": "<<k<<endl;
    return 0;
}