#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(m_func, normal)
{
    text txt = create_text();
    txt->myList->push_back("line 1\n");
    txt->myList->push_back("line 2\n");
    txt->myList->push_back("line 3\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;

    m(txt, 0, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 0, 1);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 1);

    m(txt, 1, 0);
    EXPECT_EQ(txt->cursor->line_num, 1);
    EXPECT_EQ(txt->cursor->position, 0);

    m(txt, 2, 2);
    EXPECT_EQ(txt->cursor->line_num, 2);
    EXPECT_EQ(txt->cursor->position, 2);

    m(txt, 2, 3);
    EXPECT_EQ(txt->cursor->line_num, 2);
    EXPECT_EQ(txt->cursor->position, 3);



    free(txt);
}


TEST(m_func, big)
{
    text txt = create_text();
    txt->myList->push_back("line 1\n");
    txt->myList->push_back("line 2\n");
    txt->myList->push_back("line 3\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;


    m(txt, 100, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 100, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 0, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 7);
    m(txt, 1, 150);
    EXPECT_EQ(txt->cursor->line_num, 1);
    EXPECT_EQ(txt->cursor->position, 7);
    m(txt, 2, 200);
    EXPECT_EQ(txt->cursor->line_num, 2);
    EXPECT_EQ(txt->cursor->position, 7);
    free(txt);
}

TEST(m_func, minus)
{
    text txt = create_text();
    txt->myList->push_back("line 1\n");
    txt->myList->push_back("line 2\n");
    txt->myList->push_back("line 3\n");
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;


    m(txt, -1, 0);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 0, -1);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, -1, 100);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, -2,-1);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    m(txt, 2, -1);
    EXPECT_EQ(txt->cursor->line_num, 0);
    EXPECT_EQ(txt->cursor->position, 0);
    free(txt);
}
