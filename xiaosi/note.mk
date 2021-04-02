
1.测试代码实际修改较少；
2.主要还是把Template代码调通了；非常抱歉，代码的修改可能已经离你的思路有点远了。但原逻辑没有修改，也没有验证和调试。


代码或者说设计问题；
1.friend class Queue<E>; //Queue是QueueNode的友元类，可以访问QueueNode的所有成员
Queue和QueueNode的耦合应该是单向的，Queue不应该是QueueNode的友元；QueueNode是一种结构，应该可以放到不同的容器中，如自己的Queue，或者vector等等
2.Queue这种名称和queue太接近，不建议使用；
3.Queue既然是一个模板类，就不应该看到QueueNode这种类型，应该只看到class T，这个class T既可以是int，也可以是子定义的QueueNode；
4.光靠返回值不能进行函数的重载；
		QueueNode<E>* Head() { return head_; }
		const QueueNode<E>* Head() const { return head_; } //为什么写两个 Head()? const？
5.代码要模块化，小范围就测试好，再扩大范围，不同的逻辑不要放到一起，所谓高内聚低耦合。
   
