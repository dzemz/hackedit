#include <hackedit/editor/backend/TextDocument.hpp>
#include <QSignalSpy>
#include <gtest/gtest.h>

using namespace hackedit::editor::backend;

class TestTextDocument: public testing::Test {

};

TEST_F(TestTextDocument, TextIsEmptyByDefault)
{
    TextDocument doc;
    EXPECT_EQ(doc.text(), "");
}

TEST_F(TestTextDocument, TextIsNotEmptyAfterSetText)
{
    TextDocument doc;
    EXPECT_EQ(doc.text(), "");
    doc.setText("some text");
    EXPECT_EQ(doc.text(), "some text");
}

TEST_F(TestTextDocument, SetText_EmitTextChanged)
{
    TextDocument doc;
    QSignalSpy spy(&doc, SIGNAL(textChanged(const QString&)));
    doc.setText("some text");
    EXPECT_EQ(spy.count(), 1);
    doc.setText("some text");
    EXPECT_EQ(spy.count(), 1);
    doc.setText("another text");
    EXPECT_EQ(spy.count(), 2);
}
