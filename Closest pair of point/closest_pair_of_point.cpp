#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
};

void PrintPoints(Point P[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "(" << P[i].x << "," << P[i].y << ") ";
    }
    cout << endl;
}

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(Point P[], int n)
{
    cout << "---------BruteForce function is called-----------" << endl;
    cout << "bruteForce function called with n = " << n << " and Points[] = ";
    PrintPoints(P, n);
    float min_dist = FLT_MAX; // Renamed to avoid confusion with std::min
    for (int i = 0; i < n; ++i)
    {
        cout << "\tFor i = " << i << endl;
        for (int j = i + 1; j < n; ++j)
        {
            cout << "\t\tFor j = " << j << ", P[" << i << "] = (" << P[i].x << "," << P[i].y << ") and P[j] = (" << P[j].x << "," << P[j].y << ")" << endl; // Fixed P[j] printing
            cout << "\t\tdist(P[i], P[j]) = " << dist(P[i], P[j]) << " and min_dist = " << min_dist << endl;
            float current_dist = dist(P[i], P[j]);
            if (current_dist < min_dist)
            {
                cout << "\t\tmin_dist updated from " << min_dist << " to " << current_dist << endl;
                min_dist = current_dist;
            }
        }
    }

    return min_dist;
}

float min_distance(float x, float y) // Renamed to avoid conflict with std::min
{
    return (x < y) ? x : y;
}

float stripClosest(Point strip[], int size, float d)
{
    cout << "-------------stripClosest is called-------------" << endl;
    cout << "strip size = " << size << ", d = " << d << " and strip points[] = ";
    PrintPoints(strip, size);
    float min_dist = d;

    // Sort strip according to y coordinate
    sort(strip, strip + size, [](const Point &a, const Point &b) -> bool
         { return a.y < b.y; });

    for (int i = 0; i < size; ++i)
    {
        cout << "For i = " << i << endl;
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min_dist; ++j)
        {
            cout << "\tstrip[i] = (" << strip[i].x << "," << strip[i].y << ") and strip[j] = (" << strip[j].x << "," << strip[j].y << ")" << endl; // Fixed missing parenthesis
            cout << "\tmin_dist = " << min_dist << " and dist(strip[i],strip[j]) = " << dist(strip[i], strip[j]) << endl;
            float current_dist = dist(strip[i], strip[j]);
            if (current_dist < min_dist)
            {
                cout << "\t\tmin_dist updated from " << min_dist << " to " << current_dist << endl;
                min_dist = current_dist;
            }
        }
    }

    return min_dist;
}

float closest(Point P[], int n)
{
    cout << "Closest function is called with n = " << n << " and Point P[] = ";
    PrintPoints(P, n);
    if (n <= 3)
        return bruteForce(P, n);
    int mid = n / 2;
    Point midPoint = P[mid];
    cout << "Closest function is calling for left part" << endl;
    float dl = closest(P, mid);
    cout << "\t\tLeft part closest distance = " << dl << endl;

    cout << "Closest function is calling for Right part" << endl;
    float dr = closest(P + mid, n - mid);                       // Fixed to store in dr
    cout << "\t\tRight part closest distance = " << dr << endl; // Fixed to print dr instead of dl

    float d = min_distance(dl, dr); // Use the custom min function
    cout << "\t\tMinimum of Left and right part closest distance = " << d << endl;
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "d= " << d << " and i = " << i << " and P[" << i << "].x = " << P[i].x << ", midPoint.x = " << midPoint.x << " and abs(P[i].x - midPoint.x) = " << abs(P[i].x - midPoint.x) << endl;
        if (abs(P[i].x - midPoint.x) < d)
        {
            strip[j] = P[i], j++;
            cout << "\tStrip is updated and strip[] = ";
            PrintPoints(strip, j);
        }
    }
    float strip_min = stripClosest(strip, j, d);
    cout << "Result of d = " << d << " and stripClosest(strip, j, d) = " << strip_min << endl;
    return min_distance(d, strip_min);
}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);

    // Sort the points based on the x-coordinate
    sort(P, P + n, [](const Point &a, const Point &b) -> bool
         { return a.x < b.x; });

    cout << "Points sorted by x-coordinate: ";
    PrintPoints(P, n);

    float d = closest(P, n);
    cout << "The smallest distance is " << d;
    return 0;
}