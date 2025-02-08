// #include <bits/stdc++.h>
// using namespace std;

// struct Point
// {
//     int x, y;
// };

// // Function to calculate the distance between two points
// double dist(Point p1, Point p2)
// {
//     return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
// }

// // Brute force method to find the minimum distance between 2 or 3 points
// double bruteForce(vector<Point> &points, int left, int right)
// {
//     double min_dist = DBL_MAX;
//     for (int i = left; i <= right; ++i)
//     {
//         for (int j = i + 1; j <= right; ++j)
//         {
//             min_dist = min(min_dist, dist(points[i], points[j]));
//         }
//     }
//     return min_dist;
// }

// // Function to merge the results of the left and right halves
// double stripClosest(vector<Point> &strip, double d)
// {
//     double min_dist = d;
//     int size = strip.size();
//     for (int i = 0; i < size; ++i)
//     {
//         for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min_dist; ++j)
//         {
//             min_dist = min(min_dist, dist(strip[i], strip[j]));
//         }
//     }
//     return min_dist;
// }

// // Recursive function to find the closest pair
// double closestUtil(vector<Point> &points, int left, int right)
// {
//     if (right - left <= 3)
//     {
//         return bruteForce(points, left, right);
//     }

//     int mid = left + (right - left) / 2;
//     Point midPoint = points[mid];

//     double leftDist = closestUtil(points, left, mid);
//     double rightDist = closestUtil(points, mid + 1, right);

//     double d = min(leftDist, rightDist);

//     vector<Point> strip;
//     for (int i = left; i <= right; ++i)
//     {
//         if (abs(points[i].x - midPoint.x) < d)
//         {
//             strip.push_back(points[i]);
//         }
//     }

//     return min(d, stripClosest(strip, d));
// }

// // Main function to find the closest pair
// double closestPair(vector<Point> &points)
// {
//     sort(points.begin(), points.end(), [](Point a, Point b)
//          { return a.x < b.x; });
//     return closestUtil(points, 0, points.size() - 1);
// }

// int main()
// {
//     int n;
//     cout << "Enter the number of points: ";
//     cin >> n;

//     vector<Point> points(n);
//     cout << "Enter the points (x, y):" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> points[i].x >> points[i].y;
//     }

//     double result = closestPair(points);
//     cout << "The closest pair distance is: " << result << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

double dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter the points (x, y):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    double min_dist = DBL_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            min_dist = min(min_dist, dist(points[i], points[j]));
        }
    }

    cout << "The closest pair distance is: " << min_dist << endl;

    return 0;
}
