#include <iostream>
#include <math.h>

using namespace std;

class Point {
private:
    int _x, _y;

public:
    Point(int x, int y)
        : _x(x), _y(y) {}

    int GetX() {
        return _x;
    }

    int GetY() {
        return _y;
    }

    void Info() {
        cout << "x: " << _x << ", y: " << _y << endl;
    }
};


class Line {
private:
    Point _pt1, _pt2;

public:
    Line(int pt1x, int pt1y, int pt2x, int pt2y)
        : _pt1(pt1x, pt1y), _pt2(pt2x, pt2y) {}

    Line(Point pt1, Point pt2)
        : _pt1(pt1), _pt2(pt2) {}

    float GetLength() {
        int xBase = _pt2.GetX() - _pt1.GetX();
        int height = _pt1.GetY() - _pt2.GetY();

        return sqrt(pow(xBase, 2) + pow(height, 2)); // 피타고라스 정리
                                                     // sqrt() : 루트
                                                     // pow() : 제곱
    }
};

// 삼각형 클래스 (정삼각형, 직삼각형)
// 사각형 클래스 (정사각형, 직사각형)
// 원클래스

// 각각의 도형클래스를 만들고 면적을 출력하세요.

// 삼각형 클래스
class Triangle {
private:
    Point _topPt, _leftBottomPt, _rightBottomPt;

public:
    Triangle(Point leftBottomPt, Point topPt, Point rightBottomPt)
        : _topPt(topPt), _leftBottomPt(leftBottomPt), _rightBottomPt(rightBottomPt) {}

    Triangle(int leftBottomPtX, int leftBottomPtY, int topPtX, int topPtY, int rightBottomPtX, int rightBottomPtY)
        : _topPt(topPtX, topPtY), _leftBottomPt(leftBottomPtX, leftBottomPtY), _rightBottomPt(rightBottomPtX, rightBottomPtY) {}

    float GetArea() {
        int xBase = _rightBottomPt.GetX() - _leftBottomPt.GetX();
        int height = _rightBottomPt.GetY() - _topPt.GetY();

        return xBase * height * 1 / 2;
    }
};

class Rectangle {
private:
    Point _topPt, _bottomPt;

public:
    Rectangle(Point topPt, Point bottomPt)
        : _topPt(topPt), _bottomPt(bottomPt) {}

    Rectangle(int topPtX, int topPtY, int bottomPtX, int bottomPtY)
        : _topPt(topPtX, topPtY), _bottomPt(bottomPtX, bottomPtY) {}


    float GetArea() {
        int xBase = _bottomPt.GetX() - _topPt.GetX();
        int yBase = _bottomPt.GetY() - _topPt.GetY();

        return xBase * yBase;
    }
};


class Cycle {
private:
    Point _centerPt;   // 중심점
    int _radius;   // 반지름

    const float  PI = 3.14f;

public:
    Cycle(int centerPtX, int centerPtY, int radius)
        : _centerPt(centerPtX, centerPtY), _radius(radius) {}

    Cycle(Point centerPt, int radius)
        : _centerPt(centerPt), _radius(radius) {}

    Cycle(Point centerPt, Point edgePt)
        : _centerPt(centerPt)
    {
        Line line(centerPt, edgePt);
        _radius = line.GetLength();
    }

    Cycle(int centerPtX, int centerPtY, int edgePtX, int edgePtY)
        : _centerPt(centerPtX, centerPtY)
    {
        Line line(centerPtX, centerPtY, edgePtX, edgePtY);

        _radius = line.GetLength();
    }

    float GetArea() {
        return PI * _radius * _radius;
    }
};


int main() {
    Line line(0, 0, 4, 4);

    cout << "line length = " << line.GetLength() << endl;

    Triangle tri(0, 10, 10, 0, 10, 10);

    cout << "tri area = " << tri.GetArea() << endl;

    Rectangle rect(2, 2, 4, 4);

    cout << "rect Area = " << rect.GetArea() << endl;

    Cycle cycle(0, 0, 4, 4);

    cout << "cycle Area = " << cycle.GetArea() << endl;

    return 0;
}