#include <functional>

template<typename T>
struct EventHandler
{
    private:
    std::function<T()> register_event_;
    template<typename U>
    EventHandler<T>(bool);
};
