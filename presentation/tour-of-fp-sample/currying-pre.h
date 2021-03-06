#include <functional>
#include <utility>

using std::function;

namespace tour_of_fp::curry {

template <class A, class B, class C>
function<function<C(B)>(A)> currying(function<C(A, B)>);

template <class BinaryFunc>
auto currying(BinaryFunc f) {
    return [=](auto a) {
        return [ f = std::move(f), a ](auto&& b) {
            return f(a, std::forward<decltype(b)>(b));
        };
    };
}

}  // namespace tour_of_fp::curry
