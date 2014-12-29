#ifndef MINIMAT_UTIL_STREAM_HPP
#define MINIMAT_UTIL_STREAM_HPP

#include <deque>

namespace miniMAT {
    namespace util {
        template <typename ElementType>
        struct Stream {
            template <typename Function, typename ...Args>
            void Take(Function f, Args ...params) {
                // Call user-provided function
                f(params...);

                // Advance item in stream
                stream.pop_front();
            }

            void PutBack(const ElementType& t) {
                stream.push_front(t);
            }

            void Add(const ElementType& t) {
                stream.push_back(t);
            }

            ElementType Current() {
                return stream.front();
            }

        private:
            std::deque<ElementType> stream = std::deque<ElementType>();
        };
    }
}

#endif