#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct pos {
    long long x, y;
    double angle, distance;
};

struct cHull {
    long long x, y;
};

bool comp1(pos v1, pos v2) {
    if (v1.y == v2.y) return (v1.x < v2.x);
    return (v1.y < v2.y);
}

bool comp2(pos v1, pos v2) {
    if (v1.angle == v2.angle) return (v1.distance < v2.distance);
    return (v1.angle < v2.angle);
}

void replace(long long x, long long y, vector<pos>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        v[i].x -= x;
        v[i].y -= y;
    }
}

void calc(vector<pos>& v) {
    long long x = v[0].x, y = v[0].y;
    double m = 0, n = 0;

    for (size_t i = 1; i < v.size(); i++) {
        m = atan2(((double)v[i].y - y), ((double)v[i].x - x));
        n = sqrt(pow((double)v[i].x - v[0].x, 2) + pow((double)v[i].y - v[0].y, 2));
        v[i].angle = m;
        v[i].distance = n;
    }
}

long long orientation(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    long long value = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);

    if (value >= 0) return 1;
    return 0;
}

void convexHull(vector<pos>& v0, vector<cHull>& v1) {
    v1.push_back({ v0[0].x, v0[0].y });
    v1.push_back({ v0[1].x, v0[1].y });
    v1.push_back({ v0[2].x, v0[2].y });

    for (size_t i = 3; i < v0.size(); i++) {

        while (v1.size() > 1 &&
            !orientation(v1[v1.size() - 2].x, v1[v1.size() - 2].y, v1[v1.size() - 1].x,
                v1[v1.size() - 1].y, v0[i].x, v0[i].y)) v1.pop_back();
        v1.push_back({ v0[i].x, v0[i].y });
    }

    v1.push_back({ v0[0].x, v0[0].y });
}

bool isInside(vector<cHull>& c, long long x, long long y) {

    for (size_t i = 1; i < c.size(); i++) {
        if (
            !orientation(c[i - 1].x, c[i - 1].y, c[i].x, c[i].y, x, y)
            ) return 0;
    }

    return 1;
}

int main()
{
    int L = 0, S = 0, counter = 0;
    long long x = 0, y = 0; 
    vector<pos> largeLanterns;
    vector<pos> smallLanterns;
    vector<cHull> convex;

    cin >> L;

    for (int i = 0; i < L; i++) {
        cin >> x >> y;
        largeLanterns.push_back({ x, y, 0, 0 });
    }

    cin >> S;

    for (int i = 0; i < S; i++) {
        cin >> x >> y;
        smallLanterns.push_back({ x, y });
    }

    sort(largeLanterns.begin(), largeLanterns.end(), comp1);

    x = largeLanterns[0].x;
    y = largeLanterns[0].y;

    replace(x, y, largeLanterns);
    replace(x, y, smallLanterns);

    calc(largeLanterns);

    sort(largeLanterns.begin(), largeLanterns.end(), comp2);
    
    convexHull(largeLanterns, convex);

    for (size_t i = 0; i < smallLanterns.size(); i++) {
        if (
            isInside(convex, smallLanterns[i].x, smallLanterns[i].y) == 1
            ) counter++;
    }

    cout << counter;

    return 0;
}