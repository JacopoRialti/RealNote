//
// Created by 39393 on 12/03/2024.
//

#include <iostream>
#include "Starred.h"

Starred* Starred::instance = nullptr;

Starred *Starred::getInstance() {
    if (instance == nullptr)
        instance = new Starred();
    return instance;
}

void Starred::addNoteToCollection(Note *new_note) {
    new_note->setStarred(true);
    Collection::addNoteToCollection(new_note);
}

bool Starred::removeNoteFromCollection(int index) {
    int i = 0;
    for(auto it = note_list.begin(); it != note_list.end(); it++){
        if(i == index){
            (*it)->unsubscribe(this);
            note_list.erase(it);
            return true;
        }
        i++;
    }
    return false;
}

void Starred::update(Note &note) {
    Collection::update(note);
}

void Starred::showCollection() {
    std::cout << "Starred notes: " << std::endl;
    Collection::showCollection();
}

Note *Starred::searchNoteByNameInCollection(const std::string &title) {
    return Collection::searchNoteByNameInCollection(title);
}
