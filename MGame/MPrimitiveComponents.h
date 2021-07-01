#pragma once
#include <t-pro1.h>

//Class,struct...etc.
class Vector2D
{
private:
public:
    double X = 0;
    double Y = 0;

    Vector2D()
    {

    }

    Vector2D(double Current_X, double Current_Y)
    {
        X = Current_X;
        Y = Current_Y;
    }

    Vector2D(double Current_XY)
    {
        X = Current_XY;
        Y = Current_XY;
    }

    void Set_ScalerVector(double Scale)
    {
        X *= Scale;
        Y *= Scale;
    }

    void Set_RotatedVector(Rotator2D Rotation)
    {
        double Current_Rot = ToRadian(Rotation.Rot);
        double Current_X = (X * cos(Current_Rot)) + (sin(Current_Rot) * Y);
        double Current_Y = -(X * sin(Current_Rot)) + (cos(Current_Rot) * Y);
        X = Current_X;
        Y = Current_Y;
    }

    double Get_VectorLength_Squared()
    {
        double Current = pow(X, 2) + pow(Y, 2);
        return Current;
    }

    double Get_VectorLength()
    {
        double Current = sqrt(pow(X, 2) + pow(Y, 2));
        return Current;
    }

    double Get_DistanceInAB_Squared(Vector2D B)
    {
        double dX = X - B.X;
        double dY = Y - B.Y;
        double Current = pow(dX, 2) + pow(dY, 2);
        return Current;
    }

    double Get_DistanceInAB(Vector2D B)
    {
        double dX = X - B.X;
        double dY = Y - B.Y;
        double Current = sqrt(pow(dX, 2) + pow(dY, 2));
        return Current;
    }

};

class Rotator2D
{
private:
public:
    double Rot = 0;

    Rotator2D()
    {

    }

    Rotator2D(double Current_Rot)
    {
        Rot = Current_Rot;
    }
};

class ColorRGB
{
private:
public:
    int R = 0;
    int G = 0;
    int B = 0;

    ColorRGB()
    {

    }

    ColorRGB(int Current_R, int Current_G, int Current_B)
    {
        R = Current_R % 256;
        G = Current_G % 256;
        B = Current_B % 256;
    }

};

template<typename T>
class Array
{
protected:
    T* C_Array;
    int ArrayLength = 0;
public:
    Array()
    {

    }

    Array(int Length)
    {
        C_Array = new T[Length];
        ArrayLength = Length;
    }

    //配列の長さを変更します。
    void Resize(int NewSize)
    {
        T* Current = C_Array;
        C_Array = new T[NewSize];
        for (int i = 0; i < ArrayLength; i++)
        {
            C_Array[i] = Current[i];
        }
        ArrayLength = NewSize;
    }

    //配列の末尾にデーターを追加します。
    void Append(T Data)
    {
        Resize(ArrayLength + 1);
        C_Array[ArrayLength] = Data;
    }

    //配列の長さを取得します。
    int GetLength()
    {
        return ArrayLength;
    }

};

enum E_TypeOfShape
{
    Polygon,
    Square,
    Circle,
    Square_Circle
};

enum E_CollisionType
{
    Square,
    Circle,
};

struct S_Shape
{
public:
    E_TypeOfShape ShapeType = E_TypeOfShape::Circle;
    ColorRGB FilledColor = ColorRGB(0, 0, 0);
    ColorRGB OutLineColor = ColorRGB(0, 0, 0);
    double OutLineWidth = 3;
    Vector2D Vertex[1];
    Vector2D Size = Vector2D(10, 10);
    int NumberOfVertex = 1;
    bool IsFilled = false;
    double Radius = 0;

};

struct S_Collision
{
    bool CollisionEnabled = false;
    E_CollisionType CollisionType = E_CollisionType::Square;
    bool IsFitToShape = true;
    Vector2D CollisionExtent = Vector2D(10, 10);
};

//Functions

double ToRadian(double Degree)
{
    double Current = Degree * M_PI / 180;
    return Current;
}

double ToDegree(double Radian)
{
    double Current = Radian * 180 / M_PI;
    return Current;
}