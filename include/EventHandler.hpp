#pragma once

#include <functional>

template<typename T>
/* a seperate thread will register event*/
struct Events
{
    private:
    std::function<T()> events;

    public:
    template<typename F>
    Events(F&& function) : events(/*"push back in events"*/);
    /* call event handler with somethiing like [int x, int y]() {return (callAFunction)}*/
};

/*do this in a new file*/
template<typename T>
class EventHandler
{
    friend class Events<T>;
    public:
    /* handle event inside of Events::events if there are any*/
    auto handle_event() -> void


    private:
    std::thread handler;

};
