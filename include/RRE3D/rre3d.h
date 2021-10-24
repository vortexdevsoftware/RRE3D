#include <vector>
#include "glm/glm.hpp"

/* Namespace Declaration Order:
    1. Enums
    2. Structs
    3. Classes
    4. Functions
*/

namespace RRE3D {

    /* Enumerators */

    enum LIGHT_TYPE
    {
        Point, Spot, Area, Global
    };

    // The easing style specifies the rate of change of a parameter over time.
    enum Easing_Style
    {
        Linear,
        Sine,
        Cubic,
        Quint,
    };

    // The easing direction controls where the easing style is applied.
    enum Easing_Direction
    {
        In,
        Out,
        InOut
    };

    /* Structs */

    struct TweenInfo
    {
        Easing_Style easingStyle;
        Easing_Direction easingDirection;
        // The amount of time the tween takes in seconds.
        double time;
    };

    /* Classes */

    class Mesh
    {
        public:

        glm::vec3 *vertices;

        /* Create constructor that receives array of vec3's */
        Mesh(glm::vec3* verts){
            vertices = verts;
        }
    };

    class Object
    {
        public:
        
        glm::vec3 position;
        Mesh mesh;
        glm::vec3 scale;

        // Completely delete the object.
        void Destroy();
        // interpolate the properties of and object
        void Tween();
    };

    class Light
    {
        public:

        glm::vec3 position;
        LIGHT_TYPE lightType;
        glm::vec4 color;

    };

    // The scene is the class for all entities in the application.
    class Scene
    {
        std::vector<Object> objects;

        public:

        /* To be properly implemented */
        void AddToScene(Object obj)
        {
            objects.push_back(obj);
        }
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