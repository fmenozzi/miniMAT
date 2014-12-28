#ifndef MINIMAT_UTIL_STREAM_HPP
#define MINIMAT_UTIL_STREAM_HPP

#include <deque>

namespace miniMAT {
	namespace util {
		template <typename T>
		struct Stream {
			Stream() {
				stream = std::deque<T>();
			}

			template <typename Function, typename ...Args>
			void Take(Function f, Args ...params) {
				// Call user-provided function
				f(params...);

				// Advance item in stream
				stream.pop_front();
			}

			void PutBack(const T& t) {
				stream.push_front(t);
			}

		private:
			std::deque<T> stream;
		};
	}
}

#endif