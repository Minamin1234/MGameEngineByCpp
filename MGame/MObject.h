#pragma once

#include "MPrimitiveComponents.h"
#include "ErrorManager.h"
#include "MWorldClass.h"

namespace Game2D
{
    class Object
    {
        
    protected:
        WorldClass C_WorldClass;

    public:
        ErrorManager EManager = ErrorManager();
        Vector2D Location = Vector2D(0, 0);
        Rotator2D Rotation = Rotator2D(0);


        Object()
        {

        }

        virtual void Event_BeginPlay()
        {

        }

        virtual void Event_Tick()
        {

        }

        virtual void Event_Delete()
        {

        }

        virtual void Update(WorldClass CurrentWorldClass)
        {
            C_WorldClass = CurrentWorldClass;
        }

        void Set_Location(double X, double Y)
        {
            Location.X = X;
            Location.Y = Y;
        }

        void Set_Location(Vector2D NewLocation)
        {
            Location = NewLocation;
        }

        void Add_Location(double X, double Y)
        {
            Location.X += X;
            Location.Y += Y;
        }

        void AddLocation(Vector2D DeltaLocation)
        {
            Location.X += DeltaLocation.X;
            Location.Y += DeltaLocation.Y;
        }

        void Set_Rotation(double NewRot)
        {
            Rotation.Rot = NewRot;
        }

        void Set_Rotation(Rotator2D NewRotation)
        {
            Rotation = NewRotation;
        }

        void Add_Rotation(double DeltaRot)
        {
            Rotation.Rot += DeltaRot;
        }

        void Add_Rotation(Rotator2D DeltaRotation)
        {
            Rotation.Rot += DeltaRotation.Rot;
        }

        Vector2D Get_Location()
        {
            return Location;
        }

        Rotator2D Get_Rotation()
        {
            return Rotation;
        }

    };

    class Pawn : public Object
    {
    protected:
        S_Shape Shape = S_Shape();
        S_Collision Collision = S_Collision();

        void Draw(WorldClass CurrentWorldClass)
        {
            C_WorldClass = CurrentWorldClass;
            int C_WindowID = CurrentWorldClass.Get_CurrentWindow().Get_WindowID();
            switch (Shape.ShapeType)
            {
            case E_TypeOfShape::Circle:
                newrgbcolor(C_WindowID, Shape.FilledColor.R, Shape.FilledColor.G, Shape.FilledColor.B);
                if (Shape.IsFilled == true)
                {
                    fillcirc(win, Location.X, Location.Y, Shape.Radius, Shape.Radius);
                }
                else
                {
                    circle(win, Location.X, Location.Y, Shape.Radius, Shape.Radius);
                }
                break;

            case E_TypeOfShape::Polygon:
                newrgbcolor(C_WindowID, Shape.OutLineColor.R, Shape.OutLineColor.G, Shape.OutLineColor.B);
                newlinewidth(win, Shape.OutLineWidth);
                Vector2D* CurrentVertex = Shape.Vertex;
                for (int i = 0; i < Shape.NumberOfVertex; i++)
                {
                    drawline(C_WindowID, CurrentVertex[i].X, CurrentVertex[i].Y, CurrentVertex[i + 1].X, CurrentVertex[i + 1].Y);
                    if (i = Shape.NumberOfVertex - 1)
                    {
                        drawline(C_WindowID, CurrentVertex[i].X, CurrentVertex[i].Y, CurrentVertex[0].X, CurrentVertex[0].Y);
                        break;
                    }
                }
                break;

            case E_TypeOfShape::Square:
                if (Shape.IsFilled == true)
                {
                    newrgbcolor(C_WindowID, Shape.FilledColor.R, Shape.FilledColor.G, Shape.FilledColor.B);
                    fillrect(C_WindowID, Location.X, Location.Y, Shape.Size.X, Shape.Size.Y);
                }
                else
                {
                    newrgbcolor(C_WindowID, Shape.OutLineColor.R, Shape.OutLineColor.G, Shape.OutLineColor.B);
                    drawrect(C_WindowID, Location.X, Location.Y, Shape.Size.X, Shape.Size.Y);
                }
                break;

            case E_TypeOfShape::Square_Circle:
                newrgbcolor(C_WindowID, Shape.FilledColor.R, Shape.FilledColor.G, Shape.FilledColor.B);
                if (Shape.IsFilled == true)
                {
                    fillcirc(C_WindowID, Location.X, Location.Y, Shape.Size.X, Shape.Size.Y);
                }
                else
                {
                    circle(C_WindowID, Location.X, Location.Y, Shape.Size.X, Shape.Size.Y);
                }
            default:
                cout << "Error: ShapeType Not Set." << endl;
                break;
            }
        }

        void CollisionDetect()
        {
            if (Collision.CollisionEnabled == true)
            {

            }
        }

        
    public:
        

        Pawn()
        {

        }

        virtual void Event_BeginPlay() override
        {

        }

        virtual void Event_Tick() override
        {

        }

        virtual void Event_Delete() override
        {

        }

        virtual void Update(WorldClass CurrentWorldClass) override
        {
            Draw(CurrentWorldClass);

        }

        

    };
}