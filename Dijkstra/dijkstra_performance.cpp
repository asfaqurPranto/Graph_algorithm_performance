
#include <bits/stdc++.h>
using namespace std ::chrono;

using namespace std;
const int N = 1e5 + 10;
int INF = 1e9 + 10, visited[N] = {0};
int dist[N];
vector<pair<int, int>> graph[N];

void dijkstra(int source)
{
    set<pair<int, int>> st; // which will work as sortrd in queue (wt,node);
    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
    }
    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();
        int v = node.second;
        int wt = node.first;
        st.erase(st.begin());
        if (!visited[v])
        {
            for (auto child : graph[v])
            {
                int child_wt = child.first;
                int child_v = child.second;

                if (dist[v] + child_wt < dist[child_v])
                {
                    dist[child_v] = dist[v] + child_wt;

                    st.insert({dist[child_v], child_v});
                }
            }
            visited[v] = 1;
        }
    }
}

int getRandomNumber() {
    // Set up random number generator engine with random_device as the seed
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define a distribution to get 70% chance of getting 0 (true) and 30% chance of getting a non-zero value (false)
    std::bernoulli_distribution distribution(0.7);

    // Generate a random boolean value to decide between 0 and a value between 1 and 40
    bool isZero = distribution(gen);

    // 70% of the time return 0, otherwise return a value in the range 1 to 40
    if (isZero) {
        return 0;
    } else {
        // Define a new distribution for values in the range 1 to 40
        std::uniform_int_distribution<int> rangeDist(1, 100);
        return rangeDist(gen);
    }
}

int main()
{

    int n, i, j;
    for (int node = 100; node <= 2000; node += 10)
    {
        n = node;
        for (int query = 0; query < 3; query++)
        {
            

            // for better performance i have used --- method rather than adj metrix
            int edge = 0;
            for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    int wt=getRandomNumber();
                    if (wt != 0)
                    {
                        edge++;                        
                        graph[i].push_back({wt, j});
                        graph[j].push_back({wt, i});
                    }
                }
            }
            int source = rand() % n;
            auto start = high_resolution_clock::now();
            dijkstra(source);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout <<"query "<<query << "  node : " << node << " Edge : " << edge << " duration : ";
            cout << duration.count() << endl;
        }
    }
}
