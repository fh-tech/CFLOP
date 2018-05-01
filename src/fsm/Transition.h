//
// Created by daniel on 25.04.18.
//

#ifndef CFLOP_TRANSITION_H
#define CFLOP_TRANSITION_H
namespace fsm {
    template<class T>
    class Transition {

    private:
        T t;

    public:
        Transition(T t)
                : t(t) {}

        bool matches(T &other) const {
            return t == other;
        }

        static Transition<T> from(T t) {
            return Transition(t);
        }

        T into() {
            return t;
        }

        bool operator==(const Transition<T> &other) const {
            return t == other.t;
        }
    };

}
#endif //CFLOP_TRANSITION_H
