//
//  message_plat_test.cpp
//  MudBath
//
//  Created by Tejas Harith on 6/5/18.
//  Copyright © 2018 Tejas Harith. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "MessagingPlatform/OnValChanged.h"

enum simpleState
{
    OFF = 0,
    ON = 1
};

class StateChangeEvent
{
private:
    
public:
    int id= 3001;
};

class Class1
{
private:
    simpleState state;
    
    
    
public:
    Class1 * self = this;
    Class1* c5;
    OnValChanged onStateChange;
    void half_check(){
        c5 = new Class1();
    }
    void set_state(simpleState st)
    {
        
        state = st;
//        onStateChange( this, StateChangeEvent() );
    }
    void eventHandler(int s, int e){
        //do no
        std::cout << "class1" <<std::endl;
        int bo = s + e;
        std::cout << bo << std::endl;
        //        switch(e.id){
        //            case 3001:
        //                state = simpleState::ON;
        //                break;
        //            default:
        //                std::cout << "test" << std::endl
    }
    std::string get_state()
    {
        std::string g = std::to_string(state);
        return g;
    }
};

class Class2
{
private:
    simpleState state;
    
public:
    Class2()
    {
        state = simpleState::OFF;
    }
//    template <typename Send, typename Eve>
    void eventHandler(int s, int e){
        //do no
        int bo = s + e;
        std::cout << bo << std::endl;
//        switch(e.id){
//            case 3001:
//                state = simpleState::ON;
//                break;
//            default:
//                std::cout << "test" << std::endl
    }
    
    void doSomethur(Class1* cla1){
        //do no
        cla1->set_state(simpleState::ON);
    }
    std::string get_state()
    {
        std::string g = std::to_string(state);
        return g;
    }
    
};

int main()
{
    Class1 c1;
    Class1 c3;
    Class2 c2;
    Class1 * cptr = c1.self;
//    int c = 4;
//    int * ipr = &c;
    c1.half_check();
    std::cout << c1.c5->get_state() << std::endl;
    c2.doSomethur(c1.c5);
    std::cout << c1.c5->get_state() << std::endl;
    
    void * glux = cptr;
    Class1 ** tp = (Class1**)glux;
    std::cout << (*(*tp)).get_state() << std::endl;
    
    unsigned char a = *(char*)tp;
    std::cout << sizeof(a) << " and : " << std::to_string(a) << " yea" << std::endl;
    // do somethign
    
    
//    void ( * const click) ( Class1 s, StateChangeEvent e ) = &Class2::eventHandler<Class1, StateChangeEvent>;
//    c1.onStateChange.subscribe<Class2>(c2);
//    c1.onStateChange.subscribe<Class1>(c3);
//    c1.set_state(ON);
////    int j = 1;
////        int g = c1.onStateChange.simples(j);
////    std::cout << g << std::endl;
//    std::cout << c2.get_state() << std::endl;
}
