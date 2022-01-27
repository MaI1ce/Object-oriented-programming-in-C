extern "C"{
#include "../lib/new.h"
#include "MyClass.h"
}
#include <gtest/gtest.h>

TEST(OOCTest, NewTest) {
    
    void * p = _new_(nullptr);
    EXPECT_EQ(p, nullptr);

    RTTI_info ClassInfo ={
        0,
        NULL,
        NULL,
        NULL
    };

    p = _new_(&ClassInfo);

    EXPECT_EQ(p, nullptr);

    ClassInfo.size = 10;

    p = _new_(&ClassInfo);

    ASSERT_EQ(*(RTTI_info **)p, &ClassInfo);
    EXPECT_EQ((*(RTTI_info **)p)->size , 10);

    p = _delete_(p);

    ASSERT_EQ(p, nullptr);
}

TEST(OOCTest, MacrosTest){

    MyClass * ptr = NEW(MyClass,10);

    ASSERT_EQ(ptr->data.x, 10);

    ptr = (MyClass *) DELETE(ptr);

}

TEST(OOCTest, MacrosTest2){

    MyClass obj;
    CTOR(MyClass,obj, 10);
    ASSERT_EQ(obj.data.x, 10);

    DTOR(MyClass,obj);
    ASSERT_EQ(obj.data.x, 0);
}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}