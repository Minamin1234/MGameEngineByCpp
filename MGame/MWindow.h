#pragma once

#include <t-pro1.h>
#include "MPrimitiveComponents.h"

class MWindow
{
protected:
    Vector2D WindowSize = Vector2D(500, 500);
    Vector2D Max_WindowGrid = Vector2D(WindowSize.X / 5, WindowSize.Y / 5);
    int WindowID = win;
    ColorRGB BackColor = ColorRGB(0, 0, 0);
public:
    

    MWindow()
    {
        Resize(WindowSize);
        Set_BackColor(BackColor);
    }

    void Resize(Vector2D NewSize)
    {
        gresize(WindowID, WindowSize.X, WindowSize.Y);
        Max_WindowGrid = Vector2D(WindowSize.X / 5, WindowSize.Y / 5);
        window(WindowID, -Max_WindowGrid.X, -Max_WindowGrid.Y, Max_WindowGrid.X, Max_WindowGrid.Y);
    }

    void Set_BackColor(ColorRGB NewColor)
    {
        gsetbgcolorrgb(WindowID, NewColor.R, NewColor.G, NewColor.B);
        BackColor = NewColor;
    }

    ColorRGB Get_BackColor()
    {
        return BackColor;
    }

    Vector2D Get_WindowSize()
    {
        return WindowSize;
    }

    int Get_WindowID()
    {
        return WindowID;
    }

};