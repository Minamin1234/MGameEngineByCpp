#pragma once
#include <iostream>

using std::cout;
using std::endl;

enum E_ErrorType
{
    UnknownError,
    E_ShapeType_NotSetError,
};

enum E_ErrorFrom
{
    AtErrorManager,
    Unknown,
};

struct S_Error
{
    E_ErrorType Type = E_ErrorType();
    E_ErrorFrom From = E_ErrorFrom();
};

class ErrorManager
{

    
protected:
    int NumberOfErrors = 0;
    S_Error* CurrentErrors;

    void Resize(int NewSize)
    {
        S_Error* Current = CurrentErrors;
        CurrentErrors = new S_Error[NewSize];
        for (int i = 0; i < NumberOfErrors; i++)
        {
            CurrentErrors[i] = Current[i];
        }
        NumberOfErrors = NewSize;
    }

    void Insert(S_Error Error)
    {
        Resize(NumberOfErrors + 1);
        CurrentErrors[NumberOfErrors] = Error;
        NumberOfErrors++;
    }

    void InsertTo(int Index, S_Error Error)
    {
        if (NumberOfErrors < Index) cout << "Error: OutOfRangeError At ErrorManager." << endl;
        else CurrentErrors[Index] = Error;
    }

public:

    ErrorManager()
    {

    }

    void ThrowError(S_Error Error)
    {
        Insert(Error);
    }

    void PrintErrors()
    {
        for (int i = 0; i < NumberOfErrors; i++)
        {
            switch (CurrentErrors[i].Type)
            {
            case E_ErrorType::E_ShapeType_NotSetError:
                cout << "Error: ShapeType Not Set." << endl;
                break;

            case E_ErrorType::UnknownError:
                cout << "Error: UnknownError." << endl;
                break;

            default:
                break;
            }
        }
    }
};