//
// Created by ge on 2020/11/5.
//

#ifndef DEMO_PERSON_H
#define DEMO_PERSON_H

#endif //DEMO_PERSON_H
#pragma once
#include <iostream>

template<class T1, class T2>
class Person{
public:
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_Name;
    T2 m_Age;
};