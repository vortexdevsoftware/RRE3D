#define STB_IMAGE_IMPLEMENTATION

// Includes

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include "glm/glm.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb/stb_image.h"

// This header file is for declaration of general RRE3D classes and functions

/* Namespace Declaration Order:
    1. Enums
    2. Structs
    3. Classes
    4. Functions
*/

namespace RRE3D {

    /* Enumerators */

    /* Structs */

    // Describes an object's position, rotation and scale.
    struct Transform {
        glm::vec3 Position;
        glm::vec3 Rotation;
        glm::vec3 Scale;
    };

    // RRE3D's fundamental 3D object struct.
    struct Object {
        bool Static = false; // Defines wether the object should be static or moving.
        bool CanCollide = true; // Defines if the object should collide with other objects.
        float Alpha = 0.0f; // Defines the object's transparency from 0.0f to 1.0f.
        float Mass = 1.0f; // Mass is both a property of a physical body and a measure of its resistance to acceleration when a net force is applied.
        glm::vec3 Position; // The object's Location in 3D Space.
        glm::vec3 Velocity; // The object's Velocity in 3D Space.
        // The force is an influence that can change the motion of an object, it will be immediatelly converted into velocity after a time step
        // if possible.
        glm::vec3 Force;
    };

    /* Classes */

    class Scene {
        private:
            std::vector<Object*> scene_objects;
            glm::vec3 gravity = glm::vec3(0.0f, -9.81f, 0.0f); // Scene's gravity in m/s^2
        public:
            // Add a new object onto the scene.
            void AddObject(Object* object) {
                scene_objects.push_back(object);
            }

            // Delete an object from the scene.
            void DestroyObject(Object* object)
            {
                if(!object) return;
                auto itr = std::find(scene_objects.begin(), scene_objects.end(), object);
                if(itr != scene_objects.end()) return;
                scene_objects.erase(itr);
            }

            // Simulate a single frame of the scene. This is work in progress.
            void PhysicsStep(float deltaTime)
            {
                for (Object* object : scene_objects)
                {   
                    if (!object->Static)
                    {
                    object->Force += object->Mass * gravity; // Apply force and gravity

                    object->Velocity += object->Force / object->Mass * deltaTime; // Update velocity
                    object->Position += object->Velocity * deltaTime; // Update position

                    object->Force = glm::vec3(0.0f); // Reset force.
                    }
                }
            }
    };
    
    /* Functions */

    // Called upon RRE3D initialization is complete and ready to use.
    // This is before the first frame.
    void Start(void);

    // Called every frame
    void Update(void);
}