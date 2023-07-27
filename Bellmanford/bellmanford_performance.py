import random
import time
import pandas as pd

N = 10**3 + 10
graph = [[0 for _ in range(N)] for _ in range(N)]
dist = [0] * N
INF = 10**9 + 10

def bellmanford(n):
    for k in range(1, n):
        for i in range(n):
            for j in range(n):
                if dist[j] > dist[i] + graph[i][j]:
                    dist[j] = dist[i] + graph[i][j]

def getRandomNumber():
    probability_zero = 0.7
    is_zero = random.random() < probability_zero
    if is_zero:
        return 0
    else:
        return random.randint(-100, 100)

def main():
    number_of_node =[]
    number_of_edge =[]
    duration_ =[]
    for node in range(20, 500, 10):
        n = node
        edge = 0

        for i in range(n):
            for j in range(i + 1, n):
                rnd = getRandomNumber()
                if rnd == 0:
                    graph[i][j] = INF
                else:
                    edge += 1
                    graph[i][j] = rnd
                    graph[j][i] = rnd

        source = random.randint(0, n - 1)

        start = time.time()
        for i in range(n):
            dist[i] = INF
            graph[i][i] = 0
        dist[source] = 0

        bellmanford(n)
        stop = time.time()

        duration = (stop - start) * 10**6
        number_of_node.append(n)
        number_of_edge.append(edge)
        duration_.append(duration)
        print(f"node : {node} Edge : {edge} duration : {duration:.2f} microseconds")

    result = pd.DataFrame()
    result['Number_of_node'] = number_of_node
    result['Number_of_edge'] = number_of_edge
    result['duration'] = duration_

    result.to_csv("bellmanford.csv", index=None) 
    #records are save to bellmanford.csv file
    print("Successfully completed")

if __name__ == "__main__":
    main()
