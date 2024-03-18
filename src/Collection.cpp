//
// Created by 39393 on 22/02/2024.
//

#include <iostream>

#include "Collection.h"

Collection::Collection(std::string nm)
{
name = nm;
std::list<Note*> noteList;
note_list = noteList;
}

Collection::Collection()
{
    name = "No name collection";
}
Collection::~Collection()= default;

void Collection::addNoteToCollection(Note *new_note)
{
    note_list.push_back(new_note);
    new_note->subscribe(this);

}

bool Collection::removeNoteFromCollection(int index)
{
    int i = 0;
    for(auto it = note_list.begin(); it != note_list.end(); it++){
        if(i == index){
            (*it)->unsubscribe(this);
            note_list.erase(it);
            return true;
        }
        i++;
    } return false;
}

bool Collection::modifyNoteInCollection(int index, std::string title, std::string text)
{
    int i = 0;
    bool found = false;
    for(auto & it : note_list){
        if(i == index){
            found = it->modifiyNote(title, text);
        }
        i++;
    }
    return found;
}

bool Collection::searchNoteInCollection(Note &note)
{
    for (auto & it : note_list) {
        if (it == &note) {
            return true;
        }
    }return false;
}

std::string Collection::getName() const
{
    return name;
}

void Collection::setName(const std::string &new_name)
{
    name = new_name;
}

std::list<Note *> Collection::getNoteList() const
{
    return note_list;
}

//remove the note from the collection when it is deleted
void Collection::update(Note &note)
{
   note_list.remove(&note);
}

void Collection::showCollection()
{
    std::cout << "La collezione " << name << " contiene le seguenti note: " << std::endl;
    int index = 0;
    for (auto & it : note_list) {
        std::cout << "Index: " << index << ", Title: " << it->getTitle() << std::endl;
        index++;
    }
}
