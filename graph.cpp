#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Edge{
    int src, dest;
};

class Graph{
    public:
        vector<vector<int>> adj_list;
        
        Graph(vector<Edge> const &edges){
            int maxValue = 0;
            for (auto &edge : edges){
                int temp = max(edge.src, edge.dest);
                maxValue = max(temp, maxValue);
            }
            adj_list.resize(maxValue + 1);

            for (auto &edge : edges){
                adj_list[edge.src].push_back(edge.dest);
            }
        }

        string get_string();
};

string Graph::get_string(){
    string result = "";
    for (int i = 0; i < adj_list.size(); i++){
        result += std::to_string(i) + ": ";
        result += '{';
        for (int adjnode : adj_list[i]){
            result += std::to_string(adjnode) + ",";
        }
        result += "}\n";
    }
    return result;
}

int main(){
    vector<Edge> edges ={
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}, {2, 3}
    };
    Graph graph(edges);
    cout << graph.get_string()<< endl;
}
