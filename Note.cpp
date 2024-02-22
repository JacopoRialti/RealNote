//
// Created by 39393 on 22/02/2024.
//

#include "Note.h"


Note::Note(std::string title, std::string text)
{
    title = title;
    text = text;
}

Note::Note(const Note &original)
{
    title = original.title;
    text = original.text;
    locked = original.locked;
    starred = original.starred;
}

bool Note::deleteNote()
{
    if(!this->isLocked()){
        delete this;
        notify();
        return true;
    }else
        return false;
}

bool Note::modfiyNote(std::string title, std::string text)
{
    if(!this->isLocked()){
        this->setTitle(title);
        this->setText(text);
        notify();
        return true;
    }else
        return false;
}

std::string Note::getTitle() const
{
    return title;
}

std::string Note::getText() const
{
    return text;
}

bool Note::isLocked() const
{
    return locked;
}

bool Note::isStarred() const
{
    return starred;
}

void Note::setTitle(const std::string &new_title)
{
    title = new_title;
}

void Note::setText(const std::string &new_text)
{
    text = new_text;
}

void Note::setLocked(bool new_locked)
{
    locked = new_locked;
}

void Note::setStarred(bool new_starred)
{
    starred = new_starred;
}

void Note::attach(Observer *observer) {
    observers.push_back(observer);
}

void Note::detach(Observer *observer) {
    observers.remove(observer);
}

void Note::notify() {
    for (auto &observer : observers) {
        observer->update();
    }
}
