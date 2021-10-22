#include <math.h>
#include "glm/glm.hpp"

namespace RRE3D {

    /* Classes */

    class Mesh
    {
        //Vector3* vertices;

        /* Create constructor that receives array of v3's */
    };

    class Object
    {
        //Vector3 position;
        Mesh mesh;
        //Vector3 scale;
    };

    // The scene is the class for all entities in the application.
    class Scene
    {

    };
    
    /* Functions */

    // Called upon RRE3D initialization is complete and ready to use.
    // This is before the first frame.
    void Start(void);

    // Called every frame
    void Update(void);

}