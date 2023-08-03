#include<bits/stdc++.h>
using namespace std;
using namespace std ::chrono;
const int INF=1e9+10;
const int N=1e3;
int dist[N][N];

void floyed_warshal(int n,int e)
{
    int i,j,k;
    

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int getRandomNumber()
{
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

    int i,j,k,n;

    for (int node = 20; node < 800; node += 20)
    {
        n=node;
        int edge=0;



        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int rnd=getRandomNumber();
                if(rnd==0){
                    dist[i][j] = INF;
                }
                else{
                    edge++;
                    dist[i][j]=rnd;
                    dist[j][i]=rnd;
                }
                
            }
        }
        for(i=0;i<n;i++){
            dist[i][i]=0;
        }

       
        auto start = high_resolution_clock::now();
        
        
        floyed_warshal(node,edge);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout<< "  node : " << node << " Edge : " << edge << " duration : ";
        cout << duration.count() << endl;
    }
}
