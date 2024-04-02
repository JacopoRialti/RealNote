//
// Created by 39393 on 15/03/2024.
//

#include <gtest/gtest.h>
#include "../src/Collection.h"
#include "../src/Note.h"

// Test for the constructor
TEST(CollectionTest, ConstructorTest) {
    Collection collection("Test Collection");
    EXPECT_EQ(collection.getName(), "Test Collection");
    EXPECT_TRUE(collection.getNoteList().empty());
}

// Test for the addNoteToCollection method
TEST(CollectionTest, AddNoteToCollectionTest) {
    Collection collection("Test Collection");
    Note* note = new Note("test", "test");
    collection.addNoteToCollection(note);
    EXPECT_EQ(collection.getNoteList().size(), 1);
}

// Test for the removeNoteFromCollection method
TEST(CollectionTest, RemoveNoteFromCollectionTest) {
    Collection collection("Test Collection");
    Note* note = new Note("test", "test");
    collection.addNoteToCollection(note);
    collection.removeNoteFromCollection(0);
    EXPECT_EQ(collection.getNoteList().size(), 0);
}

// Test for the modifyNoteInCollection method
TEST(CollectionTest, ModifyNoteInCollectionTest) {
    Collection collection("Test Collection");
    Note* note = new Note("test", "test");
    collection.addNoteToCollection(note);
    collection.modifyNoteInCollection(0, "new", "new");
    EXPECT_EQ(collection.getNoteList().front()->getTitle(), "new");
    EXPECT_EQ(collection.getNoteList().front()->getText(), "new");
}

// Test for the searchNoteInCollection method
TEST(CollectionTest, SearchNoteInCollectionTest) {
    Collection collection("Test Collection");
    Note* note = new Note("test", "test");
    collection.addNoteToCollection(note);
    EXPECT_TRUE(collection.searchNoteInCollection(*note));
}

// Test for setName method
TEST(CollectionTest, SetNameTest) {
    Collection collection("Test Collection");
    collection.setName("New Name");
    EXPECT_EQ(collection.getName(), "New Name");
}

// Test for getName method
TEST(CollectionTest, GetNameTest) {
    Collection collection("Test Collection");
    EXPECT_EQ(collection.getName(), "Test Collection");
}

// Test for the destructor
TEST(CollectionTest, DestructorTest) {
    Collection* collection = new Collection("Test Collection");
    delete collection;
    EXPECT_TRUE(true);
}

// Test for the getNoteList method
TEST(CollectionTest, GetNoteListTest) {
    Collection collection("Test Collection");
    Note* note = new Note("test", "test");
    collection.addNoteToCollection(note);
    EXPECT_EQ(collection.getNoteList().front(), note);
}

TEST(CollectionTest, SearchNoteByNameInCollectionTest) {
    Collection collection("Test Collection");
    Note* note = new Note("test name", "test");
    collection.addNoteToCollection(note);
    EXPECT_EQ(collection.searchNoteByNameInCollection("test name"), note);
}

// Test modifying a locked note
TEST(CollectionTest, ModifyLockedNote) {
    Collection collection("Test Collection");
    Note* note = new Note("Test Note", "Test Text");
    note->setLocked(true);
    collection.addNoteToCollection(note);
    bool result = collection.modifyNoteInCollection(0, "New Title", "New Text");
    EXPECT_FALSE(result);
}




