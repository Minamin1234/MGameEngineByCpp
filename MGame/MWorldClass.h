#pragma once
#include "MPrimitiveComponents.h"
#include "MObject.h"
#include "MWindow.h"

namespace Game2D
{

    class WorldClass
    {
    protected:
        
        Array<Object> WorldObjects;
        MWindow CurrentWindow;
        void Update()
        {

        }
    public:
        
        WorldClass()
        {
            WorldObjects = Array<Object>(0);
        }

        virtual void Event_BeginPlay()
        {

        }

        virtual void Event_Tick()
        {

        }

        MWindow Get_CurrentWindow()
        {
            return CurrentWindow;
        }

        void Set_CurrentWindow(MWindow Window)
        {
            CurrentWindow = Window;
        }

        void AddObject(Object Class)
        {
            WorldObjects.Append(Class);
        }

        int Get_NumberOfObjects()
        {
            return WorldObjects.GetLength();
        }
    };
}
