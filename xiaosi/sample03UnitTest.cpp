// In this example, we use a more advanced feature of Google Test called test fixture.
// 
// A test fixture is a place to hold objects and functions shared by all tests in a test case.  
// Using a test fixture avoids duplicating the test code necessary to initialize and cleanup those common objects for each test.
// test fixture中的资源被所有测试用例调用，这样做的好处是：避免代码冗余、进行代码共享；测试资源的初始化和清除只需要编码一次
// 
// It is also useful for defining sub-routines that your tests need to invoke a lot.
// 反复调用测试资源时，就可以考虑使用 test fixture
// 
// <TechnicalDetails>
// The tests share the test fixture in the sense of code sharing, not  //in the sense of code sharing 从代码共享的意义上说
// data sharing.  Each test is given its own fresh copy of the
// fixture.  You cannot expect the data modified by one test to be
// passed on to another test, which is a bad idea.
// 每一个测试用例的数据都是独立的，测试数据不会修改后再传递到下一个用例。这样设计是因为：测试用例之间彼此独立
// The reason for this design is that tests should be independent and
// repeatable.  In particular, a test should not fail as the result of
// another test's failure.  If one test depends on info produced by
// another test, then the two tests should really be one big test.
//
// The macros for indicating the success/failure of a test
// (EXPECT_TRUE, FAIL, etc) need to know what the current test is
// (when Google Test prints the test result, it tells you which test
// each failure belongs to).  
// 
// Technically, these macros invoke a member function of the Test class.  Therefore, you cannot use them
// in a global function.  That's why you should put test sub-routines in a test fixture.
// </TechnicalDetails>

#include <vector>
#include "pch.h"
#include "TemplateQueueNode.h"
//using namespace std;
//#include "gtest/gtest.h"
//namespace {

using namespace std;
class TestFixtureEG : public testing::Test
{
public:
	vector<int> a;

	TestFixtureEG()
	{

	}

	~TestFixtureEG()
	{

	}

};

TEST_F(TestFixtureEG, basicTest)
{
	TemplateQueueNode<int> tqn(100);
	cout << tqn.element() << endl;
	EXPECT_EQ(100, tqn.element());
	
	
	//EXPECT_EQ(100, qa.element());
}


// To use a test fixture, derive a class from testing::Test.
//class QueueTestSmpl3 : public testing::Test
//{
//    protected:          // You should make the members protected s.t. they can be accessed from sub-classes. 
//                        // s.t.全称subject to，意思是使得...满足...
//        Queue<int> q0;// Declares the variables your tests want to use.
//        Queue<int> q1; // 创建三个 sample03.h中定义的队列
//        Queue<int> q2;
//
//        // virtual void SetUp() will be called before each test is run.  //Google Test每一条用例执行前都会调用 void SetUp()
//        // Youshould define it if you need to initialize the variables.
//        // Otherwise, this can be skipped.
//        void SetUp() override //override?
//        {
//            q1.Enqueue(1); //向队列中添加元素
//            q2.Enqueue(2);
//            q2.Enqueue(3);
//        }
//
//        // virtual void TearDown() will be called after each test is run. //Google Test每一条用例执行后都会调用 virtual void TearDown()
//        // You should define it if there is cleanup work to do. //TearDown用来清理数据
//        // Otherwise,you don't have to provide it.
//        // virtual void TearDown() { }
//
//        // A helper function that some test uses.
//        static int Double(int n)
//        {
//            return 2 * n;
//        }
//        // A helper function for testing Queue::Map(). //测试类Queue的函数Map()
//        void MapTester(const Queue<int>* q)
//        {
//            // Creates a new queue, where each element is twice as big as the corresponding one in q.
//            // 产生了一个新队列，和源队列相比，新队列的每一个元素值都是源队列对应元素值的两倍，这就是function的作用
//            const Queue<int>* const new_q = q->Map(Double);
//
//            // Verifies that the new queue has the same size as q.
//            ASSERT_EQ(q->Size(), new_q->Size()); //为什么要把单元测试用例写在类的声明中呢？ //因为下面的测试用例会调用 见114行
//
//            // Verifies the relationship between the elements of the two queues.
//            for (const QueueNode<int>* n1 = q->Head(), *n2 = new_q->Head(); n1 != nullptr; n1 = n1->next(), n2 = n2->next())
//            {
//                EXPECT_EQ(2 * n1->element(), n2->element()); //感觉代码写的真棒，这还是人家Google 2005年的例子
//            }
//
//            delete new_q;
//        }
//};
//
//// When you have a test fixture, you define a test using TEST_F instead of TEST.
//// TEST Fixture使用宏 TEST_F
//
//// Tests the default c'tor.  //1.测试默认的构造函数
//TEST_F(QueueTestSmpl3, DefaultConstructor) //注意：测试用例集名字 必须和定义的类名保持一致
//{
//    // You can access data in the test fixture here.
//    EXPECT_EQ(0, q0.Size()); //这里的结果应该是Pass，因为SetUP()中 q0_ 未添加数据
//}
//
//// Tests Dequeue().
//TEST_F(QueueTestSmpl3, Dequeue) //2.测试Dequeue()函数
//{
//    int* n = q0.Dequeue(); //测试结果Pass，因为SetUP()中 q0_ 未添加元素
//    EXPECT_TRUE(n == nullptr);
//
//    n = q1.Dequeue(); //Dequeue()的返回值是一个E类型的指针
//    ASSERT_TRUE(n != nullptr); //pass, SetUP()中 q1_ 中添加了一个元素
//    EXPECT_EQ(1, *n);  //q1_.Enqueue(1);  pass, 元素值就是1
//    EXPECT_EQ(0, q1.Size()); //弹出一个元素后，队列的元素个数为0; 0 equal to 0u, 0u?
//    delete n;
//
//    n = q2.Dequeue();
//    ASSERT_TRUE(n != nullptr);
//    EXPECT_EQ(2, *n);
//    EXPECT_EQ(1, q2.Size()); //1u equal to 1
//    delete n;
//}
//
//// Tests the Queue::Map() function.
//TEST_F(QueueTestSmpl3, Map)
//{
//    MapTester(&q0); //传入的实际是队列的引用
//    MapTester(&q1);
//    MapTester(&q2);
//}

//}  // namespace
