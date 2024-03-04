#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long double dd;

dd getAngle(dd length, dd R)
{
    return 2 * asin(length / 2 / R);
}

dd getLengthAB(dd x1, dd y1, dd x2, dd y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

dd getArcLen(dd x1, dd y1, dd x2, dd y2, dd R)
{
    dd AB = getLengthAB(x1, y1, x2, y2);
    dd angle = getAngle(AB, R);
    return angle * R;
}

pair<dd, dd> getPointByZero(dd x, dd y, dd r)
{
    if (x == 0)
        return make_pair(0, (y > 0 ? 1 : -1) * r);
    return make_pair((x > 0 ? 1 : -1) * r, 0);
}

int main()
{
    dd x1, x2, y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if (x1 == x2 && y1 == y2){
        cout << 0;
        return 0;
    }
    dd r1 = sqrt(x1 * x1 + y1 * y1),
           r2 = sqrt(x2 * x2 + y2 * y2);
    if (r1 > r2)
        swap(r1, r2), swap(x1, x2), swap(y1, y2);
    if (x1 == 0 && y1 == 0){
        cout << r2;
        return 0;
    }
    // через дугу и прямую
    dd ans1 = r2 - r1,
           // через две прямые (радиусы)
        ans2 = r1 + r2;
    // промежуточная точка
    pair<dd, dd> p;
    if (x2 == 0 || y2 == 0)
    {
        p = getPointByZero(x2, y2, r1);
    }
    else
    {
        // коэф прямой до второй точки, для пересечения
        dd k2 = (y2 / x2);
        // модуль х промежуточной точки
        p.first = sqrt(r1 * r1 / (1 + k2 * k2));
        // модуль у промежуточной точки
        p.second = sqrt(r1 * r1 - p.first * p.first);
        if (x2 < 0)
            p.first *= (-1);
        if (y2 < 0)
            p.second *= (-1);
    }
    if (x1 != p.first && y1 != p.second)
        ans1 += getArcLen(x1, y1, p.first, p.second, r1);
    cout << setprecision(10) << (dd(0.), min(ans1, ans2));
    return 0;
}