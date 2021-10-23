#include "glm/glm.hpp"

namespace RRE3D {

    /* Classes */

    class Mesh
    {
        glm::vec3 *vertices;

        /* Create constructor that receives array of vec3's */
        Mesh(glm::vec3* verts){
            vertices = verts;
        }
    };

    class Object
    {
        glm::vec3 position;
        Mesh mesh;
        glm::vec3 scale;
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