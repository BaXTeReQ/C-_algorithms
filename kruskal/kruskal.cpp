#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int x, y, z;
};

struct temp {
    int x, y;
};

bool compareInterval(edge e1, edge e2) {
    return (e1.z < e2.z);
}

int Find(int x, vector<temp>& check) {
    if (x != check[x].y)
        check[x].y = Find(check[x].y, check);
    return check[x].y;
}

void Merge(int x, int y, vector<temp>& check) {
    x = Find(x, check), y = Find(y, check);

    if (check[x].x > check[y].x)
        check[y].y = x;
    else
        check[x].y = y;

    if (check[x].x == check[y].x)
        check[y].x++;
}

void Kruskal(int numOfCities, vector<edge>& start_edges, vector<edge>& mst, vector<temp>& check, int numOfRoads) {

    int x = 0, y = 0, i = 0, set_x = 0, set_y = 0;

    while ((i < numOfRoads)) {
        x = start_edges[i].x;
        y = start_edges[i].y;

        set_x = Find(x, check);
        set_y = Find(y, check);

        if (set_x != set_y) {
            mst.push_back({ start_edges[i].x, start_edges[i].y, start_edges[i].z });

            Merge(set_x, set_y, check);
        }

        i++;

    }
}

void dfs(int start, int finish, vector<edge>& mst, vector<int>& check, vector<int>& pathEdges, vector<int>& children, vector<edge>& finalPath) {

    int actual = start, last = 0;

    while (finish != actual) {

        if (!check[actual - 1]) pathEdges.push_back(actual);
        if (!check[actual - 1]) check[actual - 1] = 1;

        for (int i = 0; i < mst.size(); i++) {
            if (mst[i].y == actual) swap(mst[i].x, mst[i].y);
            if (mst[i].x == actual && !check[mst[i].y - 1]) {
                children.push_back(mst[i].y);
            }
        }

        if (children.size() == 0) {
            pathEdges.pop_back();
            actual = last;
            last = pathEdges[pathEdges.size() - 2];

            children.clear();
            continue;
        }

        last = actual;
        actual = children.front();
        children.clear();

    }

    pathEdges.push_back(actual);

    int j = 0, next = 0;

    for (int i = 1; i < pathEdges.size() - 1; i++) {
        actual = pathEdges[i];
        next = pathEdges[i + 1];
        j = 0;
        do {
            if (mst[j].y == actual) swap(mst[j].x, mst[j].y);

            if (mst[j].x == actual && mst[j].y == next) {
                finalPath.push_back({ mst[j].x, mst[j].y, mst[j].z });
            }
            j++;
        } while (j < mst.size());
    }
}

int main()
{
    vector<edge> start_edges;
    vector<edge> mst;
    vector<int> pathEdges;
    vector<int> children;
    vector<temp> check;
    vector<int> check2;
    vector<edge> finalPath;

    int numOfCities = 0, numOfRoads = 0, cityA = 0, cityB = 0, time = 0, start = 0, finish = 0, passengers = 0, a = 0;
    float result = 0;

    cin >> numOfCities >> numOfRoads;

    for (int i = 0; i <= numOfCities; i++) {
        check.push_back({ 0, i });
    }

    for (int i = 0; i < numOfRoads; i++) {
        cin >> cityA >> cityB >> time;
        time = time * (-1);
        start_edges.push_back({ cityA, cityB, time });
    }

    sort(start_edges.begin(), start_edges.end(), compareInterval);

    Kruskal(numOfCities, start_edges, mst, check, numOfRoads);

    while (true) {

        start = 0, finish = 0, passengers = 0, a = 0, result = 0;

        cin >> start >> finish;

        if (start == 0 || finish == 0) break;

        cin >> passengers;

        for (int i = 0; i < numOfCities; i++) {
            check2.push_back(0);
        }

        pathEdges.push_back(0);

        dfs(start, finish, mst, check2, pathEdges, children, finalPath);

        sort(finalPath.begin(), finalPath.end(), compareInterval);

        a = (finalPath[finalPath.size() - 1].z + 2) * (-1);

        result = (float)passengers / a;

        cout << ceil(result) << endl;

        pathEdges.clear();
        children.clear();
        check.clear();
        check2.clear();
        finalPath.clear();
    }

    return 0;
}
