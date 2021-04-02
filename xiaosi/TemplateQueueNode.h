#pragma once
template<class T> 
class TemplateQueueNode
{
private:
	T element_;
	TemplateQueueNode<T>* next_;

public:
	explicit TemplateQueueNode(const T &an_element);
	TemplateQueueNode(const TemplateQueueNode&);
	const T& element() const;
	TemplateQueueNode<T>* next();
	const TemplateQueueNode<T>* next() const;
};


template<class T>
TemplateQueueNode<T>::TemplateQueueNode(const T &an_element) :element_(an_element), next_(nullptr)
{

}


template<class T>
TemplateQueueNode<T>::TemplateQueueNode(const TemplateQueueNode&)
{

};

template<class T>
const T& TemplateQueueNode<T>::element() const // Gets the element in this node. 返回结点的元素值(类型E的一个引用)
{
	return element_;
}

template<class T>
TemplateQueueNode<T>* TemplateQueueNode<T>::next() //Gets the next node in the queue.
{
	return next_;
}

template<class T>
const TemplateQueueNode<T>* TemplateQueueNode<T>::next() const  //为什么出现两个几乎完全一样的 next()呢？
{
	return next_;
}






