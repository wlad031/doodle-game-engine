#ifndef DOODLEGAMEENGINE_COMMON_PATTERNS_OBSERVER_HPP
#define DOODLEGAMEENGINE_COMMON_PATTERNS_OBSERVER_HPP

#include <bits/refwrap.h>

#include <vector>

namespace patterns {

////////////////////////////////////////////////////////////////////////////////
/////          Standard implementation of the Observer pattern             /////
////////////////////////////////////////////////////////////////////////////////

///// ================================================================= Observer
class Observer {
public:

    ///// --------------------------------------------------------------- update
    virtual void update() = 0;
};

///// =============================================================== Observable
class Observable {
public:

    ///// ----------------------------------------------------------- addWatcher
    template<
            typename T, typename std::enable_if<
                    std::is_base_of<
                            Observer,
                            T
                    >::value
            >::type* = nullptr
    >
    void addWatcher(const T& obj) {
        _observers.push_back(std::ref((Observer&) obj));
    }

    ///// --------------------------------------------------------------- notify
    void notify() {
        for (auto&& observer : _observers) {
            observer.get().update();
        }
    }

private:
    std::vector<std::reference_wrapper<Observer>> _observers;
};

}  // namespace patterns

#endif //DOODLEGAMEENGINE_COMMON_PATTERNS_OBSERVER_HPP
