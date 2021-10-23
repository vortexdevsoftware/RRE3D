#include <vector>
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

        public:
        // Completely delete the object.
        void Destroy();
    };

    enum LIGHT_TYPE
    {
        Point, Spot, Area, Global
    };

    class Light
    {
        glm::vec3 position;

        LIGHT_TYPE lightType;
        glm::vec4 color;
    };

    // The scene is the class for all entities in the application.
    class Scene
    {
        
        std::vector<Object> objects;
    };
    
    /* Functions */

    // Called upon RRE3D initialization is complete and ready to use.
    // This is before the first frame.
    void Start(void);

    // Called every frame
    void Update(void);

    // We need a function that creates a object within the Objects vector array in the scene,
    // and returns a pointer to the Object inside the array after its creation
    // so users can simply make a variable that calls the function and points to the object already.
    Object* CreateObject();

}