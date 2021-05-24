#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <string>
#include <iostream>
#include <sstream>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(showdo, normal_1)
{
    std::string output_text = "";

    text txt = create_text();
    txt->myList->push_back("line 1");
    txt->myList->push_back("line 2");
    txt->myList->push_back("line 3");
    txt->length=3;
    output_text += "1";
    output_text += "2";
    output_text += "3";

    //захват вывода
    testing::internal::CaptureStdout();
    showdigitsonly(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);



}

TEST(showdo, normal_2)
{
    std::string output_text = "";

    text txt = create_text();
    txt->myList->push_back("line 1");
    txt->myList->push_back("line");
    txt->myList->push_back("line 3");
    txt->length=3;
    output_text += "1";
    output_text += "";
    output_text += "3";

    //захват вывода
    testing::internal::CaptureStdout();

    showdigitsonly(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);



}

TEST(showdo, negative)
{
    std::string output_text = "";

    text txt = create_text();

    txt->myList->push_back("");
    txt->myList->push_back("");
    txt->myList->push_back("");
    txt->length=3;
    output_text += "";
    output_text += "";
    output_text += "";

    //захват вывода
    testing::internal::CaptureStdout();
    showdigitsonly(txt);
    std::string text = testing::internal::GetCapturedStdout();



    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);



}
