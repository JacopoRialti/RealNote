//
// Created by 39393 on 12/03/2024.
//

#ifndef REALNOTE_STARRED_H
#define REALNOTE_STARRED_H

#include "Collection.h"

class Starred : public Collection{
public:
    //Singleton
    static Starred* getInstance();

    ~Starred() override = default;

    //Add, remove, update and show the collection
    void addNoteToCollection(Note *new_note) override;

    bool removeNoteFromCollection(int index) override;

    void update(Note &note) override;

    void showCollection() override;

    Note* searchNoteByNameInCollection(const std::string & title) override;

private:
    //Constructor
    Starred(): Collection("Starred"){};
    //Singleton instance
    static Starred* instance;
};


#endif //REALNOTE_STARRED_H
