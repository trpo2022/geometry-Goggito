#pragma once

#include <string>

using namespace std;

struct Point
{
    double x;
    double y;
};

struct Circle
{
    int Order;
    Point Center;
    double r;
    double P;
    double S;
};

struct Triangle
{
    int Order;
    Point A;
    Point B;
    Point C;
    Point End;
    double P;
    double S;
};

Point Point_analysis(int string, std::string storage[]);
Circle Circle_analysis(int order, int string, std::string storage[]);
Triangle Triangle_analysis(int order, int string, std::string storage[]);

void Circle_intersec(Circle C, Circle CM[], Triangle TM[]);
void Triangle_intersec(Triangle T, Circle CM[], Triangle TM[]);

void Circle_print(Circle C, std::string storage[]);
void Triangle_print(Triangle T, std::string storage[]);