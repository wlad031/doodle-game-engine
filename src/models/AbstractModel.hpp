#ifndef DOODLEGAMEENGINE_MODELS_ABSTRACTMODEL_HPP
#define DOODLEGAMEENGINE_MODELS_ABSTRACTMODEL_HPP

#include "common/Identificated.hpp"
#include "common/Layered.hpp"
#include "common/Named.hpp"
#include "common/Tagged.hpp"

namespace models {

class AbstractModel :
        public Named,
        public Tagged,
        public Layered,
        public Identificated {
};

} // namespace models

#endif //DOODLEGAMEENGINE_MODELS_ABSTRACTMODEL_HPP
