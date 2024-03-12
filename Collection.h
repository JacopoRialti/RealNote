//
// Created by 39393 on 22/02/2024.
//

#ifndef REALNOTE_COLLECTION_H
#define REALNOTE_COLLECTION_H

#include "Observer.h"
#include "Note.h"

class Collection : public Observer{
public:
    //Constructor and empty constructor
    Collection(std::string name);

    Collection();

    //Destructor
    ~Collection() override;

    //Add and remove notes from the collection
    virtual void addNoteToCollection(Note *new_note);

    virtual bool removeNoteFromCollection(int index);

    //Modifies the title and text of the note
    bool modifyNoteInCollection(int index, std::string title, std::string text);

    //search for a note in the collection
    bool searchNoteInCollection(Note &note);

    //Getters and Setters
    std::string getName() const;

    void setName(const std::string &new_name);

    std::list<Note*> getNoteList() const;

    void update(Note &note) override;

    virtual void showCollection();


protected:
    std::list<Note*> note_list;
    std::string name;
};


#endif //REALNOTE_COLLECTION_H
