#include <bits/stdc++.h>
using namespace std;
using namespace std ::chrono;


const int N = 1e3 + 10;
int graph[N][N];
int dist[N];
const int INF = 1e9 + 10;

void bellmanford(int n)
{
    int i, j, k;
    for (k = 1; k <= n - 1; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[j] > dist[i] + graph[i][j])
                {
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
    }
}

int getRandomNumber()
{
    // Set up random number generator engine with random_device as the seed
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define a distribution to get 70% chance of getting 0 (true) and 30% chance of getting a non-zero value (false)
    std::bernoulli_distribution distribution(0.7);

    // Generate a random boolean value to decide between 0 and a value between 1 and 40
    bool isZero = distribution(gen);

    // 70% of the time return 0, otherwise return a value in the range 1 to 40
    if (isZero)
    {
        return 0;
    }
    else
    {
        // Define a new distribution for values in the range -100 to 100
        std::uniform_int_distribution<int> rangeDist(-100, 100);
        return rangeDist(gen);
    }
}

int main()
{
    int i, j, n, u, v, e, w, k;

    // cin>>n>>e;
    for (int node = 20; node < 900; node += 20)
    {
        n=node;
        int edge=0;



        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int rnd=getRandomNumber();
                if(rnd==0){
                    graph[i][j] = INF;
                }
                else{
                    edge++;
                    graph[i][j]=rnd;
                    graph[j][i]=rnd;
                }
                
            }
        }

       

        int source=rand()%n;
        auto start = high_resolution_clock::now();
        for (i = 0; i < n; i++)
        {
            dist[i] = INF;
            graph[i][i]=0;
        }
        dist[source] = 0;
        
        bellmanford(n);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout<< "  node : " << node << " Edge : " << edge << " duration : ";
        cout << duration.count() << endl;
    }
}
