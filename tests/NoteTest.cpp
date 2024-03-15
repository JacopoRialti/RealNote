//
// Created by 39393 on 12/03/2024.
//

#include "../src/Note.h"
#include <gtest/gtest.h>

// Test for the constructor
TEST(NoteTest, ConstructorTest) {
Note note("Test Title", "Test Text");
EXPECT_EQ(note.getTitle(), "Test Title");
EXPECT_EQ(note.getText(), "Test Text");
EXPECT_FALSE(note.isLocked());
EXPECT_FALSE(note.isStarred());
}

// Test for the copy constructor
TEST(NoteTest, CopyConstructorTest) {
Note original("Original Title", "Original Text");
original.setLocked(true);
original.setStarred(true);

Note copy(original);

EXPECT_EQ(copy.getTitle(), "Original Title");
EXPECT_EQ(copy.getText(), "Original Text");
EXPECT_TRUE(copy.isLocked());
EXPECT_TRUE(copy.isStarred());
}

// Test for the deleteNote method
TEST(NoteTest, DeleteNoteTest) {
Note* note = new Note("Test Title", "Test Text");

EXPECT_TRUE(note->deleteNote());
}

// Test for the modifyNote method
TEST(NoteTest, ModifyNoteTest) {
Note note("Test Title", "Test Text");

EXPECT_TRUE(note.modifiyNote("New Title", "New Text"));
EXPECT_EQ(note.getTitle(), "New Title");
EXPECT_EQ(note.getText(), "New Text");
}

TEST(NoteTest, GetTitleTest) {
    Note note("Test Title", "Test Text");
    EXPECT_EQ(note.getTitle(), "Test Title");
}

// Test for the getText method
TEST(NoteTest, GetTextTest) {
    Note note("Test Title", "Test Text");
    EXPECT_EQ(note.getText(), "Test Text");
}

// Test for the isLocked method
TEST(NoteTest, IsLockedTest) {
    Note note("Test Title", "Test Text");
    EXPECT_FALSE(note.isLocked());
}

// Test for the isStarred method
TEST(NoteTest, IsStarredTest) {
    Note note("Test Title", "Test Text");
    EXPECT_FALSE(note.isStarred());
}

// Test for the setLocked method
TEST(NoteTest, SetLockedTest) {
    Note note("Test Title", "Test Text");
    note.setLocked(true);
    EXPECT_TRUE(note.isLocked());
}

// Test for the setStarred method
TEST(NoteTest, SetStarredTest) {
    Note note("Test Title", "Test Text");
    note.setStarred(true);
    EXPECT_TRUE(note.isStarred());
}



