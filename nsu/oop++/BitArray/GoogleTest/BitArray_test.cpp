#include "gtest/gtest.h"
#include "../BitArray.h"

using namespace std;

TEST(BitArrayConstructorSuite, DEFAULT_CONSTRUCTOR) {
    BitArray array;
    EXPECT_TRUE(array.empty());
    EXPECT_EQ(array.size(), 0);
    EXPECT_EQ(array.to_string(), "");
}

TEST(BitArrayConstructorSuite, EMPTY_CONSTRUCTOR) {
    BitArray array(0);
    EXPECT_TRUE(array.empty());
    EXPECT_EQ(array.size(), 0);
    EXPECT_EQ(array.to_string(), "");
}

TEST(BitArrayConstructorSuite, BAD_CONSTRUCTOR) {
    try {
        BitArray array(-1);
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument& e) {
        EXPECT_EQ(e.what(), string("Invalid argument"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(BitArrayConstructorSuite, FINE_CONSTRUCTOR) {
    BitArray array(9);
    EXPECT_FALSE(array.empty());
    EXPECT_EQ(array.size(), 9);
    EXPECT_EQ(array.to_string(), "000000000");
}

TEST(BitArrayConstructorSuite, EXPLICIT_CONSTRUCTOR) {
    int value = 30;
    int length = sizeof(unsigned char) * 8;
    BitArray array(length, value);
    EXPECT_EQ(array.size(), length);
    EXPECT_FALSE(array.empty());

    EXPECT_EQ(array.to_string(), "01111000");
}

TEST(BitArrayConstructSuite, EMPTYCOPY_CONSTRUCTOR) {
    BitArray array;
    BitArray copy(array);

    EXPECT_TRUE(copy.empty());
    EXPECT_EQ(copy.size(), 0);
    EXPECT_EQ(copy.to_string(), "");
}

TEST(BitArrayConstructSuite, DEFAULTCOPY_CONSTRUCTOR) {
    BitArray array(8, 1);
    BitArray copy(array);

    EXPECT_FALSE(copy.empty());
    EXPECT_EQ(copy.size(), 8);
    EXPECT_EQ(copy.to_string(), "10000000");
}

TEST(BitArrayAssigmentSuite, SWAP_EMPTY) {
    BitArray a;
    BitArray b;
    a.swap(b);
    EXPECT_TRUE(a.empty());
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.to_string(), "");

    EXPECT_TRUE(b.empty());
    EXPECT_EQ(b.size(), 0);
    EXPECT_EQ(b.to_string(), "");
}

TEST(BitArrayAssigmentSuite, SWAP_ONE_EMPTY) {
    BitArray a;
    BitArray b(8, 2);
    a.swap(b);

    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 8);
    EXPECT_EQ(a.to_string(), "01000000");

    EXPECT_TRUE(b.empty());
    EXPECT_EQ(b.size(), 0);
    EXPECT_EQ(b.to_string(), "");
}

TEST(BitArrayAssigmentSuite, SWAP_DEFAULT) {
    BitArray a(8, 2);
    BitArray b(16, 4);
    a.swap(b);
    EXPECT_FALSE(b.empty());
    EXPECT_EQ(b.size(), 8);
    EXPECT_EQ(b.to_string(), "01000000");

    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 16);
    EXPECT_EQ(a.to_string(), "0010000000000000");
}

TEST(BitArrayAssigmentSuite, ASSIGN_EMPTY) {
    BitArray a;
    BitArray b;
    a = b;
    EXPECT_TRUE(a.empty());
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.to_string(), "");
}

TEST(BitArrayAssigmentSuite, ASSIGN_ONE_EMPTY) {
    BitArray a;
    BitArray b(8, 2);
    a = b;
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 8);
    EXPECT_EQ(a.to_string(), "01000000");
}

TEST(BitArrayAssigmentSuite, ASSIGN_ANOTHER_EMPTY) {
    BitArray a;
    BitArray b(8, 2);
    b = a;
    EXPECT_TRUE(b.empty());
    EXPECT_EQ(b.size(), 0);
    EXPECT_EQ(b.to_string(), "");
}

TEST(BitArrayAssigmentSuite, ASSIGN_BIT) {
    BitArray a(8, 2);
    a[0] = true;
    a[1] = false;
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 8);
    EXPECT_EQ(a.to_string(), "10000000");
}

TEST(BitArraySizeSuite, EMPTY_PUSH_BIT) {
    BitArray a;
    a.push_back(true);
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 1);
    EXPECT_EQ(a.to_string(), "1");
}

TEST(BitArraySizeSuite, PUSH_BITS) {
    BitArray a;
    a.push_back(true);
    a.push_back(false);
    a.push_back(true);
    a.push_back(false);
    a.push_back(true);
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 5);
    EXPECT_EQ(a.to_string(), "10101");
}

TEST(BitArraySizeSuite, EMPTY_CLEAR) {
    BitArray a;
    a.clear();
    EXPECT_TRUE(a.empty());
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.to_string(), "");
}

TEST(BitArraySizeSuite, CLEAR) {
    BitArray a(8, 2);
    a.clear();
    EXPECT_TRUE(a.empty());
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.to_string(), "");
}

TEST(BitArraySizeSuite, BAD_RESIZE) {
    BitArray a(8, 2);
    EXPECT_THROW(a.resize(-1), invalid_argument);
}

TEST(BitArraySizeSuite, ZERO_RESIZE) {
    BitArray a(8, 1);
    a.resize(0);
    EXPECT_TRUE(a.empty());
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.to_string(), "");
}

TEST(BitArraySizeSuite, EMPTY_RESIZE) {
    BitArray a;
    a.resize(2);
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 2);
    EXPECT_EQ(a.to_string(), "00");
}

TEST(BitArraySizeSuite, SAME_SIZE_RESIZE) {
    BitArray a(8);
    a.set();
    a.resize(8);
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 8);
    EXPECT_EQ(a.to_string(), "11111111");
}

TEST(BitArraySizeSuite, LESS_SIZE_RESIZE) {
    BitArray a(8);
    a.set();
    a.resize(5);
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 5);
    EXPECT_EQ(a.to_string(), "11111");
}

TEST(BitArraySizeSuite, MORE_SIZE_RESIZE) {
    BitArray a(8);
    a.set();
    a.resize(16);
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 16);
    EXPECT_EQ(a.to_string(), "1111111100000000");
}

TEST(BitArraySizeSuite, VALUE_RESIZE) {
    BitArray a(8);
    a.resize(12, true);
    EXPECT_FALSE(a.empty());
    EXPECT_EQ(a.size(), 12);
    EXPECT_EQ(a.to_string(), "000000001111");
}

TEST(BitArrayIndexSuite, NONEXIST_ACCESS) {
    BitArray a;
    EXPECT_THROW(bool test = a[0], invalid_argument);
}

TEST(BitArrayIndexSuite, OUT_OF_RANGE_ACCESS) {
    BitArray a;
    EXPECT_THROW(bool test = a[10], invalid_argument);
}

TEST(BitArrayIndexSuite, INDEX_ACCESS) {
    BitArray a;
    a.push_back(true);
    a.push_back(false);
    a.push_back(true);
    a.push_back(false);
    a.push_back(true);

    EXPECT_TRUE(a[0]);
    EXPECT_FALSE(a[1]);
    EXPECT_TRUE(a[2]);
    EXPECT_FALSE(a[3]);
    EXPECT_TRUE(a[4]);
}

TEST(BitArrayIndexSuite, EMPTY_ASSIGN) {
    BitArray a;
    EXPECT_THROW(a[10] = false, invalid_argument);
}

TEST(BitArrayIndexSuite, OUT_OF_RANGE_ASSIGN) {
    BitArray a(10);
    EXPECT_THROW(a[100] = false, invalid_argument);
}

TEST(BitArrayIndexSuite, INDEX_ASSIGN) {
    BitArray a(8, 1);
    a[1] = false;
    a[2] = true;
    a[3] = false;

    EXPECT_EQ(a.to_string(), "10100000");
}

TEST(BitArrayLogicalSuite, EMPTY_ARRAY_LOG) {
    BitArray a;
    EXPECT_TRUE(a.empty());
    EXPECT_TRUE(a.none());
    EXPECT_EQ(a.count(), 0);
}

TEST(BitArrayLogicalSuite, FALSE_ARRAY_LOG) {
    BitArray a(8);
    a.reset();
    EXPECT_TRUE(a.none());
    EXPECT_EQ(a.count(), 0);
    EXPECT_FALSE(a.any());
}

TEST(BitArrayLogicalSuite, TRUE_ARRAY_LOG) {
    BitArray a(8);
    a.set();
    EXPECT_FALSE(a.none());
    EXPECT_EQ(a.count(), 8);
    EXPECT_TRUE(a.any());
}

TEST(BitArrayLogicalSuite, ARRAY_LOG) {
    BitArray a(8);
    a[1] = true;
    a[7] = true;
    EXPECT_TRUE(a.any());
    EXPECT_EQ(a.count(), 2);
    EXPECT_FALSE(a.none());
}

TEST(BitArrayBitsOp, EMPTY_ARRAY_BITSOP) {
    BitArray a;
    BitArray b;
    a &= b;
    EXPECT_TRUE(a.empty());

    BitArray a1;
    BitArray b1;
    a1 |= b1;
    EXPECT_TRUE(a1.empty());

    BitArray a2;
    BitArray b2;
    a2 ^= b2;
    EXPECT_TRUE(a2.empty());
}

TEST(BitArrayBitsOp, BAD_LENGTH_ARRAY_BITSOP) {
    BitArray a(5);
    BitArray b(9);
    EXPECT_THROW(a &= b, invalid_argument);

    BitArray a1(5);
    BitArray b1(9);
    EXPECT_THROW(a1 |= b1, invalid_argument);

    BitArray a2(5);
    BitArray b2(9);
    EXPECT_THROW(a2 ^= b2, invalid_argument);
}

TEST(BitArrayBitsOp, ARRAY_BITOPS) {
    BitArray a(8, 5);
    BitArray b(8, 2);

    BitArray a1(a);
    BitArray b1(b);
    a1 &= b1;
    EXPECT_EQ(a1.to_string(),"00000000");

    BitArray a2(a);
    BitArray b2(b);
    a2 |= b2;
    EXPECT_EQ(a2.to_string(),"11100000");

    BitArray a3(a);
    BitArray b3(b);
    a3 ^= b3;
    EXPECT_EQ(a3.to_string(),"11100000");
}

TEST(BitArrayBitsOp, EMPTY_ARRAY_BITSOP_SOLO) {
    BitArray a;
    BitArray b;
    BitArray c = a & b;
    EXPECT_TRUE(c.empty());

    BitArray a1;
    BitArray b1;
    BitArray c1 = a1 | b1;
    EXPECT_TRUE(c1.empty());

    BitArray a2;
    BitArray b2;
    BitArray c2 = a2 ^ b2;
    EXPECT_TRUE(c2.empty());

    BitArray a3;
    BitArray c3 = ~a3;
    EXPECT_TRUE(c3.empty());
}

TEST(BitArrayBitsOp, DIFF_SIZE_BITSOP_SOLO) {
    BitArray a(2);
    BitArray b(4);
    EXPECT_THROW(BitArray c = a | b, invalid_argument);

    BitArray a1(2);
    BitArray b1(4);
    EXPECT_THROW(BitArray c = a1 & b1, invalid_argument);

    BitArray a2(2);
    BitArray b2(4);
    EXPECT_THROW(BitArray c = a1 ^ b2, invalid_argument);
}

TEST(BitArrayBitsOp, ARRAY_BITSOP_SOLO) {
    BitArray a(8);
    BitArray b(8);
    a[1] = true;
    a[5] = true;
    b[2] = true;
    b[3] = true;
    b[1] = true;

    BitArray a1(a);
    BitArray b1(b);
    BitArray c1 = a1 | b1;
    EXPECT_EQ(c1.to_string(), "01110100");

    BitArray a2(a);
    BitArray b2(b);
    BitArray c2 = a2 & b2;
    EXPECT_EQ(c2.to_string(), "01000000");

    BitArray a3(a);
    BitArray b3(b);
    BitArray c3 = a3 ^ b3;
    EXPECT_EQ(c3.to_string(), "00110100");

    BitArray a4(a);
    BitArray c4 = ~a4;
    EXPECT_EQ(c4.to_string(), "10111011");
}

TEST(BitArrayBitsOp, EMPTY_COMPARE) {
    BitArray a;
    BitArray b;
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}

TEST(BitArrayBitsOp, DIFF_SIZE_COMPARE) {
    BitArray a(5);
    BitArray b(9);
    EXPECT_THROW(a == b, invalid_argument);
    EXPECT_THROW(a != b, invalid_argument);
}

TEST(BitArrayBitsOp, EQUAL_ARRAYS_COMPARE) {
    BitArray a(8, 5);
    a.push_back(false);
    a.push_back(true);
    a[6] = true;
    BitArray b(a);
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}

TEST(BitArrayBitsOp, NOT_EQUAL_ARRAYS_COMPARE) {
    BitArray a(8, 5);
    a.push_back(false);
    a.push_back(true);
    a[6] = true;
    BitArray b(a);
    b[1] = false;
    b[7] = true;
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a == b);
}

TEST(BitArrayBitsOp, EMPTY_ARRAY_SHIFT) {
    BitArray a;
    a >>= 2;
    EXPECT_TRUE(a.empty());

    BitArray b;
    b <<= 2;
    EXPECT_TRUE(b.empty());

    BitArray c;
    BitArray c_l = c << 2;
    EXPECT_TRUE(c_l.empty());
    BitArray c_r = c >> 2;
    EXPECT_TRUE(c_r.empty());
}

TEST(BitArrayBitsOp, NEGATIVE_SHIFT) {
    BitArray a(4);
    EXPECT_THROW(a >>= -2, invalid_argument);

    BitArray b(4);
    EXPECT_THROW(b <<= -2, invalid_argument);

    BitArray c(4);
    EXPECT_THROW(BitArray c_l = c << -2, invalid_argument);

    BitArray d(4);
    EXPECT_THROW(BitArray d_r = d >> -2, invalid_argument);
}

TEST(BitArrayBitsOp, GREAT_SHIFT) {
    BitArray a(8);
    a.set();
    a >>= 10000;
    EXPECT_EQ(a.to_string(), "00000000");

    BitArray b(8);
    b.set();
    b <<= 10000;
    EXPECT_EQ(b.to_string(), "00000000");

    BitArray c(8);
    c.set();
    BitArray c_r = c >> 10000;
    EXPECT_EQ(c_r.to_string(), "00000000");

    BitArray d(8);
    d.set();
    BitArray d_l = d << 10000;
    EXPECT_EQ(d_l.to_string(), "00000000");
}

TEST(BitArrayBitsOp, SHIFT_BITS) {
    BitArray a(8);
    a[1] = true;
    a[5] = true;

    BitArray a_right(a);
    a_right >>= 2;
    EXPECT_EQ(a_right.to_string(), "00010001");

    BitArray a_left(a);
    a_left <<= 2;
    EXPECT_EQ(a_left.to_string(), "00010000");

    BitArray a_right_right(a);
    a_right_right = a_right_right >> 2;
    EXPECT_EQ(a_right_right.to_string(), "00010001");

    BitArray a_left_left(a);;
    a_left_left = a_left_left << 2;
    EXPECT_EQ(a_left_left.to_string(), "00010000");
}
