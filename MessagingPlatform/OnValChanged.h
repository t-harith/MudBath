//
//  MessageNode.hpp
//  MudBath
//
//  Created by Tejas Harith on 6/5/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//
#define MAX_SUBS_LIST 10
#ifndef MessageNode_h
#define MessageNode_h

#include <stdio.h>
#include <iostream>

#endif /* MessageNode_h */

//template <typename Sender, typename Event>
class OnValChanged
{
private:
//    template <typename Sender, typename Event, typename Listener>
//    typedef void (*sub_type)(void*, Sender, Event);
//    sub_type subsArr[MAX_SUBS_LIST];
//    sub_type subT;
    //internalDel subscribers[MAX_SUBS_LIST];
    
    int subs_idx;
    
public:
//    template <typename Sender, typename Event>
    OnValChanged();
//     template <typename Q>
//    int simples(Q lit);
//    ~OnValChanged();
//    template <typename Sender, typename Event, typename Listener>
    // void (Listener::*handle)(int, int)
    template <typename Listener>
    int subscribe(Listener& obj);
//    int unsubscribe(internalDel hand, int id);
    
//    template <typename Sender, typename Event>
//    void operator() (const Sender* s, Event e);
//    template <typename Listener, void (Listener::*handle)(Sender, Event)>
//    void helper_method(void* obj, Sender s, Event e);
};

//template <typename Sender, typename Event>
OnValChanged::OnValChanged()
: subs_idx(0)
{
    //not yet
}


//template<typename Sender, typename Event>
// void (Listener::*handle)(int, int)
template<typename Listener>
int OnValChanged::subscribe(Listener& obj)
{
    std::cout << "do nothing" << std::endl;
//    void (*wrapper) (Listener*, int , int) = reinterpret_cast<void(*)(Listener*, int, int)>(handle);
    obj.eventHandler(4,5);
//    wrapper(4, 5);
//    typename Listener::handle ob_func = static_cast<typename Listener::handle>(&pt->eventHandler);
//    subT = &helper_method<Listener, handle>;

    return 1;
}

//template<typename Sender, typename Event>
//template <typename Listener, void (Listener::*handle)(Sender, Event)>
//void OnValChanged<Sender, Event>::helper_method(void* obj, Sender s, Event e)
//{
//    Listener* pt = static_cast<Listener*>(obj);
//    return (pt->*handle)(s, e);
//}

//template<typename Sender, typename Event>
//int OnValChanged<Sender, Event>::unsubscribe(internalDel hand, int id)
//{
//
//}

//template<typename Sender, typename Event>
//void OnValChanged::operator() (const Sender* s, Event e)
//{
////    for(int i = 0 ; i < MAX_SUBS_LIST; ++i)
////    {
//    std::cout << "iin opertor" << std::endl;
////        *(*subsArr[i])(s, e);
////    }
//}


//template<typename Q>
//int OnValChanged<Sender, Event>::simples(Q lit)
//{
//    std::cout << "in simples" << lit << std::endl;
//    return 1;
//}
