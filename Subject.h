//
// Created by 39393 on 20/02/2024.
//

#ifndef REALNOTE_SUBJECT_H
#define REALNOTE_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;

};

#endif //REALNOTE_SUBJECT_H
