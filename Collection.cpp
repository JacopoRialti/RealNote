//
// Created by 39393 on 22/02/2024.
//

#include <iostream>

#include "Collection.h"

Collection::Collection(std::string name)
{
name = name;
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
    }
}

bool Collection::modifyNoteInCollection(int index, std::string title, std::string text)
{
    int i = 0;
    bool found = false;
    for(auto & it : note_list){
        if(i == index){
            found = it->modfiyNote(title, text);
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

void Collection::update()
{
    std::cout << "Collection " << name << " has been updated" << std::endl;
    //TODO: Implement the update method correctly

}
