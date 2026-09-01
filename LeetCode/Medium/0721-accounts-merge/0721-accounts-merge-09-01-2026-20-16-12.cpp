class Disjointset
{
    public:
        vector<int> parent, rank,size;
    Disjointset(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        rank.resize(n + 1, 0);
		size.resize(n+1,0);
    }
    int ultiamteParent(int node)
    {
        if (node == parent[node]) return node;
        return parent[node] = ultiamteParent(parent[node]);
    }
    void unionFindrank(int u, int v)
    {
        int ultiamteParent_u = ultiamteParent(u);
        int ultiamteParent_v = ultiamteParent(v);
        if (ultiamteParent_u == ultiamteParent_v) return;
        if (rank[ultiamteParent_u] > rank[ultiamteParent_v])
        {
            parent[ultiamteParent_v] = ultiamteParent_u;
        }
        else if (rank[ultiamteParent_u] < rank[ultiamteParent_v])
        {
            parent[ultiamteParent_u] = ultiamteParent_v;
        }
        else
        {
            parent[ultiamteParent_u] = ultiamteParent_v;
            rank[ultiamteParent_u]++;
        }
    }
	void unionFindSize(int u,int v)
	{
		int ultiamteParent_u = ultiamteParent(u);
        int ultiamteParent_v = ultiamteParent(v);
        if (ultiamteParent_u == ultiamteParent_v) return;
		if(size[ultiamteParent_u]>size[ultiamteParent_v])
		{
			parent[ultiamteParent_v]=ultiamteParent_u;
			size[ultiamteParent_u]+=size[ultiamteParent_v];
		}
		else
		{
			parent[ultiamteParent_u]=ultiamteParent_v;
			size[ultiamteParent_v]+=size[ultiamteParent_u];
		}
	}
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
    	Disjointset dis(n);
    	unordered_map<string,int> m;
    	for(auto it=0;it<n;it++)
    	{
    		for(int i=1;i<accounts[it].size();i++)
    		{
    			if(m.find(accounts[it][i])==m.end()) m[accounts[it][i]]=it;
    			else dis.unionFindSize(m[accounts[it][i]],it);
    		}
    	}
    	vector<set<string>> detials(n);
    	for(auto i:m)
    	{
    		detials[dis.ultiamteParent(i.second)].insert(i.first);
    	}
    	vector<vector<string>> ans;
    	for(auto i=0;i<n;i++)
    	{
    		if(detials[i].size())
    		{
    			vector<string> temp;
    			temp.emplace_back(accounts[i][0]);
    			temp.insert(temp.end(),detials[i].begin(),detials[i].end());
    			ans.push_back(temp);
    		}
    	}
    	return ans;
    }
};