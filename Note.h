//
// Created by 39393 on 22/02/2024.
//

#ifndef REALNOTE_NOTE_H
#define REALNOTE_NOTE_H

#include <string>
#include <list>

#include "Subject.h"

class Note : public Subject{
public:

    //Constructor
    Note(std::string title, std::string text);

    //Copy constructor
    Note(const Note &original);

    //Destructor
    bool deleteNote();

    //Modifies the title and text of the note
    bool modfiyNote(std::string title, std::string text);

    //Getters and Setters
    std::string getTitle() const;

    std::string getText() const;

    bool isLocked() const;

    bool isStarred() const;

    void setTitle(const std::string &new_title);

    void setText(const std::string &new_text);

    void setLocked(bool new_locked);

    void setStarred(bool new_starred);

    //Attach, detach and notify
    void attach(Observer *observer) override;

    void detach(Observer *observer) override;

    void notify() override;

private:
    std::string title;
    std::string text;
    bool locked = false;
    bool starred = false;
    std::list<Observer*> observers;

};

#endif //REALNOTE_NOTE_H
