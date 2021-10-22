#include <iostream>
#include <vector>

namespace RRE3D {
    
    // Called upon RRE3D initialization is complete
    void Start(void);

    // Called every frame
    void Update(void);

    // Called every timestep
    void FixedUpdate(void);

    // Change the timestep
    void ChangeTimestep(double);

}