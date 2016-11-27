#include <gtest/gtest.h>
#include <hackedit/editor/backend/Encodings.hpp>
#include <random>
#include <QtTest/QSignalSpy>

USE_HACKEDIT_NAMESPACE2(Editor, Backend)

TEST(EncodingsTests, availableEncodings_IsNotEmpty_Test) {
    Encodings encodings;
    EXPECT_NE(encodings.availableEncodings().count(), 0);
}

TEST(EncodingsTests, systemEncoding_IsNotEmpty_Test) {
    Encodings encodings;
    EXPECT_NE(encodings.systemEncoding(), "");
}

TEST(EncodingsTests, setCurrentEncoding_Test) {
    Encodings encodings;
    QSignalSpy spy(&encodings, SIGNAL(currentEncodingChanged(const QString&)));
    std::random_device rd;
    std::mt19937 gen(rd());
    QString encoding = encodings.availableEncodings()[10];
    encodings.setCurrentEncoding(encoding);
    EXPECT_EQ(encodings.currentEncoding(), encoding);
    EXPECT_EQ(spy.count(), 1);
}