#include "RRE3D/rre3d.h"

/* This is the true entry point of the application */ 
int main()
{
    /* Once everything is ready, call the first function */
    RRE3D::Start();

    /* The main loop, which keeps the application open */
    while(true)
    {
        RRE3D::Update();
    }
}