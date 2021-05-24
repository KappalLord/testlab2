#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(pn, normal1)
{
    std::string output_text = "";

    text txt = create_text();
    txt->myList->push_back("line 1");
    txt->myList->push_back("line 2");
    txt->myList->push_back("line 3");
    txt->length=3;
    output_text += "|line 1";
    output_text += "nope";
    output_text += "line 2";
    output_text += "line 3";

    //захват вывода
    testing::internal::CaptureStdout();
    mklb(txt,0);
    pn(txt,"nope");
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);

}


TEST(pn, normal2)
{
    std::string output_text = "";

    text txt = create_text();
    txt->myList->push_back("line 1");
    txt->myList->push_back("line 2");
    txt->myList->push_back("line 3");
    txt->length=3;
    output_text += "line 1";
    output_text += "line 2";
    output_text += "|line 3";
    output_text += " ";

    //захват вывода
    testing::internal::CaptureStdout();
    mklb(txt,2);
    pn(txt," ");
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);

}


