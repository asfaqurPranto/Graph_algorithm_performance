
#run this code and check the performance in dijkstra.csv file
#for better observation lower the clockspeed of your pc

import random
from heapq import heappop, heappush
import time
import pandas as pd
import numpy as np

N = 10**5 + 10
INF = 10**9 + 10
visited = [0] * N
dist = [INF] * N
graph = [[] for _ in range(N)]

def dijkstra(source):
    st = []  # min-heap (weight, node)
    for i in range(N):
        dist[i] = INF
    heappush(st, (0, source))
    dist[source] = 0

    while st:
        wt, v = heappop(st)
        if not visited[v]:
            for child_wt, child_v in graph[v]:
                if dist[v] + child_wt < dist[child_v]:
                    dist[child_v] = dist[v] + child_wt
                    heappush(st, (dist[child_v], child_v))
            visited[v] = 1

def getRandomNumber():
    probability_zero = 0.8
    is_zero = random.random() < probability_zero
    if is_zero:
        return 0
    else:
        return random.randint(1, 300)
    

#restore point

def main():
    number_of_node =[]
    number_of_edge =[]
    duration_ =[]
    for node in range(100, 5100, 100):
        n = node

        for query in range(3):
            edge = 0
            for i in range(n):
                for j in range(i + 1, n):
                    wt=getRandomNumber()
                    # i have used  this random number generator function 
                    # this will give 80% of their value 0(which is considered as there is o edge)
                    # and range between 0 to 300
                    # you can change the range and probability zero inside getRandomNumber() function
                    if wt != 0:
                        edge += 1
                        # wt = arr[i][j]
                        graph[i].append((wt, j))
                        graph[j].append((wt, i))
            
            source = random.randint(0, n - 1)

            start = time.time()
            dijkstra(source)
            stop = time.time()
            duration = (stop - start) * 10**6
            print(f"query {query}  node : {n} Edge : {edge} duration : {duration:.2f} microseconds")
            
            number_of_node.append(n)
            number_of_edge.append(edge)
            duration_.append(duration)


    result = pd.DataFrame()
    result['Number_of_node'] = number_of_node
    result['Number_of_edge'] = number_of_edge
    result['duration'] = duration_

    result.to_csv("dijkstra.csv", index=None) 
    #records are save to dijkstra.csv file
    print("Successfully completed")
           
            
if __name__ == "__main__":
    main()
