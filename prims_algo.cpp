#include <bits/stdc++.h>
#include<list>
#include<unordered_map>
#include<limits.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    
    //craete adj list
   unordered_map<int, list<pair<int,int>>> adj;
   //ek node k corresponding dusri node along with its weight

   for(int i=0;i<g.size();i++){
       int u=g[i].first.first;
       int v=g[i].first.second;
       int w=g[i].second;
       adj[u].push_back(make_pair(v,w));
       adj[v].push_back(make_pair(u,w));

   }

   vector<int> key(n+1);
   vector<bool> mst(n+1);
   vector<int> parent(n+1);

   for(int i=0;i<=n;i++){
       key[i]=INT_MAX;
       parent[i]=-1;
       mst[i]=false;
   }

   //start the algo

   key[1]=0;
   parent[1]=-1;
   for(int i=1;i<n;i++){
       int mini=INT_MAX;
       int u;
      
      //find the min vali node
       for(int v=1;v<=n;v++){
           if(mst[v]==false&&key[v]<mini){
               u=v;
               mini=key[v];

           }
       }

       //mark min node as true
       mst[u]=true;

       //check its adjacent nodes
       for(auto it:adj[u]){
           int v=it.first;
           int w=it.second;//weight
           if(mst[v]==false&& w<key[v]){
               parent[v]=u;
               key[v]=w;

           }
       }
   }


   vector<pair<pair<int, int>, int>> result;
  
  //node 1 se start hai aur 1 ka parent -1 hai isliye 2 se start krenge
   for(int i=2;i<=n;i++){
       result.push_back({{parent[i], i}, key[i]});
   }

   return result;

}
