#include<bits/stdc++.h>
using namespace std;
vector<int> edge[1000];
bool visited[1000];

void dfs(int node){
  visited[node]=true;
      cout <<  node <<" ";
      for(int v : edge[node])
      {

            if(visited[v]==true) continue;
            dfs(v);

      }


}


int main(){

edge[1].emplace_back(2);
edge[2].emplace_back(1);


edge[1].emplace_back(3);
edge[3].emplace_back(1);


edge[1].emplace_back(4);
edge[4].emplace_back(1);


edge[2].emplace_back(5);
edge[5].emplace_back(2);

edge[4].emplace_back(5);
edge[5].emplace_back(4);

dfs(1);

}

