
#include <iostream>
#include <iomanip>
using namespace std;

class Point {
    public:
        double x;
        double y;
};
class Line {
    public:
        double a;
        double b;
        double c;
};

int main() {
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    Line y1, y2;
    // tim phuong trinh duong thang
    y1.a = (B.y - A.y)*(-1);
    y1.b = B.x - A.x;
    y2.a = (-1)*(D.y - C.y);
    y2.b = D.x - C.x;
    y1.c = (-1)*(y1.a*(A.x) + y1.b*(A.y));
    y2.c = (-1)*(y2.a*(C.x) + y2.b*(C.y));

    double determinant = y1.a*y2.b + y2.a*y1.b;
    cout << y1.a << " " << y1.b << " " << y1.c << endl;
    cout << y2.a << " " << y2.b << " " << y2.c << endl;
    // Xet dieu kien xac dinh so diem giao
    if (determinant == 0){
        if (y1.c == y2.c) cout << "MANY" << endl;
        else {
            cout << "NO" << endl;
        }
    } else {
        Point intersection_point;
        intersection_point.x = (-y1.c*y2.b + y2.c*y1.b)/(y1.a*y2.b + y2.a*y1.b);
        intersection_point.y = (y1.a*y2.c - y2.a*y1.c)/(y1.a*y2.b + y2.a*y1.b);
        cout << setprecision(2) << fixed << intersection_point.x << " " << intersection_point.y;
    }
    return 0;
}
