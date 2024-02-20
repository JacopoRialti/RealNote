//
// Created by 39393 on 20/02/2024.
//

#ifndef REALNOTE_OBSERVER_H
#define REALNOTE_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};
#endif //REALNOTE_OBSERVER_H
