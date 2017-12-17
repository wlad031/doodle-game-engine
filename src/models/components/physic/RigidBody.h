#ifndef DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_RIGIDBODY_H
#define DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_RIGIDBODY_H

///// ------------------------------------------------ class forward declaration
namespace models {
namespace components {
namespace physic {
class RigidBody;
}  // namespace physic
}  // namespace components
}  // namespace models

///// ------------------------------ JSON serialization rule forward declaration
namespace json_dto {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::physic::RigidBody& rigidBody
);
#pragma clang diagnostic pop
}  // namespace json_dto

////////////////////////////////////////////////////////////////////////////////
/////                     RigidBody component declaration                  /////
////////////////////////////////////////////////////////////////////////////////

namespace models {
namespace components {
namespace physic {

///// ================================================================ RigidBody
class RigidBody {
public:

    ///// --------------------------------------------------------- constructors
    RigidBody() = default;

    ///// -------------------------------------------------------------- getters
    float getMass()        const { return _mass;        }
    float getDrag()        const { return _drag;        }
    float getAngularDrag() const { return _angularDrag; }
    bool isUseGravity()    const { return _useGravity;  }
    bool isKinematic()     const { return _kinematic;   }

    ///// -------------------------------------------------------------- setters
    void setMass(float mass)               { _mass = mass;               }
    void setDrag(float drag)               { _drag = drag;               }
    void setAngularDrag(float angularDrag) { _angularDrag = angularDrag; }
    void setUseGravity(bool useGravity)    { _useGravity = useGravity;   }
    void setKinematic(bool kinematic)      { _kinematic = kinematic;     }

private:

    float _mass;
    float _drag;
    float _angularDrag;
    bool  _useGravity;
    bool  _kinematic;

    ///// ---------------------------------------------- JSON serialization rule
    template<typename JSON_IO>
    friend void json_dto::json_io(
            JSON_IO& io,
            models::components::physic::RigidBody& rigidBody
    );
};

} // namespace physic
} // namespace components
} // namespace models

///// ================================================= JSON serialization rules
namespace json_dto {

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

template<typename JSON_IO>
void json_io(
        JSON_IO& io,
        models::components::physic::RigidBody& rigidBody
) {
    io;
}

#pragma clang diagnostic pop
}  // namespace json_dto

#endif //DOODLEGAMEENGINE_MODELS_COMPONENTS_PHYSIC_RIGIDBODY_H
