
// Unit-тест для lab_08_1char.cpp (Native Unit Test Project, Visual Studio)
#include "pch.h"
#include "CppUnitTest.h"

// стандартні заголовки - ДО namespace, щоб не потрапили всередину нього
#include <iostream>
#include <string>
#include <cstring>

// main() програми перейменовуємо, а весь файл ховаємо в окремий namespace,
// щоб однакові імена HasFour/Change з різних файлів не конфліктували в одній DLL
#define main program_main
namespace lab_char
{
#include "C:/Users/Legion/Desktop/laba8_unittest/laba8_unittest/lab_08_1char.cpp"
}
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace
{
static bool Has(const std::string& s) { return lab_char::HasFour(s.c_str()); }
static std::string Chg(const std::string& s)
{
    char buf[101];                       // як в оригінальній програмі
    lab_char::Change(s.c_str(), buf);
    return std::string(buf);
}
}

namespace UnitTests
{
    TEST_CLASS(TestChar)
    {
    public:
        TEST_METHOD(HasFour_EmptyString_ReturnsFalse)
        {
            Assert::AreEqual(false, Has(""));
        }

        TEST_METHOD(HasFour_ThreeIdentical_ReturnsFalse)
        {
            Assert::AreEqual(false, Has("aaa"));
        }

        TEST_METHOD(HasFour_ExactlyFour_ReturnsTrue)
        {
            Assert::AreEqual(true, Has("aaaa"));
        }

        TEST_METHOD(HasFour_AtStart_ReturnsTrue)
        {
            Assert::AreEqual(true, Has("aaaabc"));
        }

        TEST_METHOD(HasFour_InMiddle_ReturnsTrue)
        {
            Assert::AreEqual(true, Has("abbbbc"));
        }

        TEST_METHOD(HasFour_AtEnd_ReturnsTrue)
        {
            Assert::AreEqual(true, Has("abcdddd"));
        }

        TEST_METHOD(HasFour_Spaces_ReturnsTrue)
        {
            Assert::AreEqual(true, Has("    "));
        }

        TEST_METHOD(HasFour_NoRepeats_ReturnsFalse)
        {
            Assert::AreEqual(false, Has("abababab"));
        }

        TEST_METHOD(HasFour_TwoTriples_ReturnsFalse)
        {
            Assert::AreEqual(false, Has("aaabaaab"));
        }

        TEST_METHOD(HasFour_CaseSensitive_ReturnsFalse)
        {
            Assert::AreEqual(false, Has("AAAa"));
        }

        TEST_METHOD(Change_EmptyString_ReturnsEmpty)
        {
            Assert::AreEqual(std::string(""), Chg(""));
        }

        TEST_METHOD(Change_NoQuad_StringUnchanged)
        {
            Assert::AreEqual(std::string("hello world"), Chg("hello world"));
        }

        TEST_METHOD(Change_ExactlyFour_BecomesTwoStars)
        {
            Assert::AreEqual(std::string("**"), Chg("aaaa"));
        }

        TEST_METHOD(Change_FiveChars_StarsAndOneChar)
        {
            Assert::AreEqual(std::string("**a"), Chg("aaaaa"));
        }

        TEST_METHOD(Change_SevenChars_StarsAndThreeChars)
        {
            Assert::AreEqual(std::string("**aaa"), Chg("aaaaaaa"));
        }

        TEST_METHOD(Change_EightChars_FourStars)
        {
            Assert::AreEqual(std::string("****"), Chg("aaaaaaaa"));
        }

        TEST_METHOD(Change_QuadInMiddle)
        {
            Assert::AreEqual(std::string("a**c"), Chg("abbbbc"));
        }

        TEST_METHOD(Change_TripleThenQuad)
        {
            Assert::AreEqual(std::string("aaa**"), Chg("aaabbbb"));
        }

        TEST_METHOD(Change_TwoQuads)
        {
            Assert::AreEqual(std::string("**b**"), Chg("aaaabaaaa"));
        }

        TEST_METHOD(Change_TwoQuadsSeparatedBySpace)
        {
            Assert::AreEqual(std::string("** **"), Chg("aaaa bbbb"));
        }

        TEST_METHOD(Change_MaxLength100_FiftyStars)
        {
            Assert::AreEqual(std::string(50, '*'), Chg(std::string(100, 'a')));
        }

        TEST_METHOD(Change_ModifiesString_IffHasFour)
        {
            const char* inputs[] = { "", "abc", "aaa", "aaaa", "abbbbc", "aabbccdd", "xaaaay" };
            for (const char* s : inputs)
            {
                bool modified = Chg(s) != std::string(s);
                Assert::AreEqual(Has(s), modified);
            }
        }
    };
}
