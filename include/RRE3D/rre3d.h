#include <vector>

namespace RRE3D {

    /* Classes */

    class Mesh
    {
        Vector3* vertices;

        /* Create constructor that receives array of v3's */
    };

    class Object
    {
        Vector3 position;
        Mesh mesh;
        Vector3 scale;
    };

    
    // The scene is the class for all entities in the application.
    class Scene
    {
        std::vector<Object> objects;
    };

    class Vector3
    {
        float x, y, z;
        Vector3(float xx, float yy, float zz){
            x = xx;
            y = yy;
            z = zz;
        }

        float distance(Vector3 vector){
            return sqrt(dot(vector));
        }
        float dot(Vector3 vector){
            return x * vector.x + y * vector.y + z * vector.z;
        }
        float dot(Vector3 v1, Vector3 v2){
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }
        float operator*(float scalar){
            x *= scalar;
            y *= scalar;
            z *= scalar;
        }
        float operator+(float scalar){
            x += scalar;
            y += scalar;
            z += scalar;
        }
        float operator+(Vector3 vector){
            x += vector.x;
            y += vector.y;
            z += vector.z;
        }
    };
    
    /* Functions */

    // Called upon RRE3D initialization is complete and ready to use.
    // This is before the first frame.
    void Start(void);

    // Called every frame
    void Update(void);

}