//
// Created by 39393 on 15/03/2024.
//

#include <gtest/gtest.h>
#include "../src/Starred.h"
#include "../src/Note.h"

//test constructor
TEST(StarredTest, ConstructorTest) {
    Starred* starred = Starred::getInstance();
    EXPECT_EQ(starred->getName(), "Starred");
    EXPECT_TRUE(starred->getNoteList().empty());
}

//test addNoteToCollection
TEST(StarredTest, AddNoteToCollectionTest) {
    Starred* starred = Starred::getInstance();
    Note* note = new Note("test", "test");
    starred->addNoteToCollection(note);
    EXPECT_EQ(starred->getNoteList().size(), 1);
}

//test removeNoteFromCollection
TEST(StarredTest, RemoveNoteFromCollectionTest) {
    Starred* starred = Starred::getInstance();
    Note* note = new Note("test", "test");
    Note* note2 = new Note("test2", "test2");
    starred->addNoteToCollection(note);
    starred->addNoteToCollection(note2);
    starred->removeNoteFromCollection(0);
    EXPECT_EQ(starred->getNoteList().back()->getTitle(), "test2");
}

TEST(StarredTest, SearchNoteByNameInCollectionTest) {
    Starred* starred = Starred::getInstance();
    Note* note = new Note("test", "test");
    Note* note2 = new Note("test2", "test2");
    starred->addNoteToCollection(note);
    starred->addNoteToCollection(note2);
    Note* found = starred->searchNoteByNameInCollection("test2");
    EXPECT_EQ(found->getTitle(), "test2");
}