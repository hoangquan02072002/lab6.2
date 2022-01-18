#include<string>
#include <iostream>
#include <deque>
#include<vector>
using namespace std;
bool palchecker(string String) {
	deque<char> chardeque;
	int strLen = String.length();
	for (int i = 0; i < strLen; i++) {
		chardeque.push_back(String[i]);
	}
	bool stillEqual = true;
	while (chardeque.size() > 1 && stillEqual) {
		char first = chardeque.front();
		chardeque.pop_front();
		char last = chardeque.back();
		chardeque.pop_back();
		if (first != last) {
			stillEqual = false;
		}
	}
	return stillEqual;
}
struct Point
{
	int x;
	int y;
};

int orientation(Point A, Point B, Point C)
{
	int val = (B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y);

	if (val == 0)
		return 0; // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

void convexHull(Point points[], int n)// Prints convex hull of a set of n points.
{
	if (n < 3)// There must be at least 3 points
		return;

	vector<Point> hull;// Initialize Result
	int l = 0;
	for (int i = 1; i < n; i++) {// Find the leftmost point
		if (points[i].x < points[l].x) {// Start from leftmost point, keep moving counterclockwise
			l = i;                      // until reach the start point again
		}
	}

	int A = l, B;
	do
	{
		hull.push_back(points[A]);// Search for a point 'A' such that orientation(A, i, B) is
		B = (A + 1) % n;          // counterclockwise for all points 'i'
		for (int i = 0; i < n; i++) {
			if (orientation(points[A], points[i], points[B]) == 2) {
				B = i;
			}
		}
		A = B; // Set A as B for next iteration
	} while (A != l);

	for (int i = 0; i < hull.size(); i++) // Print Result
	{
		cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
	}
}


int main()
{
	string String;
	cout << "enter string:";
	cin >> String;
	if (palchecker(String))
	{
		cout << "palindrome";
	}
	else
	{
		cout << "no palindrome";
	}
	cout << "\nlession 2" << endl;
	Point points[] = { { 0, 3 }, { 5, 5 }, { 1, 2 }, { 2, 1 }, { 1, 0 },
   { 0, 0 }, { 3, 3 } };
	cout << "The points in the convex hull are: " << endl;
	int n = sizeof(points) / sizeof(points[0]);
	convexHull(points, n);
}