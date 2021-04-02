#pragma once
template<class T> 
class TemplateQueue
{
private:
	T* head_;  // The first node of the queue.
	T* last_;  // The last node of the queue.
	size_t size_;  //The number of elements in the queue. //size_t almost equal to int 

public:
	TemplateQueue();
	TemplateQueue(const TemplateQueue<T>& q);
	~TemplateQueue();
	void Clear();
	size_t Size() const;
	T* Head();
	T* Last();
	void Enqueue(const T& element);
	T* Dequeue();
	TemplateQueue<T>& CopyTemplateQueue(TemplateQueue<T>& source);
};


template<class T>
TemplateQueue<T>::TemplateQueue() :
	head_(nullptr), last_(nullptr), size_(0)
{

}


template<class T>
TemplateQueue<T>::TemplateQueue(const TemplateQueue<T>& q)
{
	head_ = q.head_;
	last_ = q.last_;
	size_ = q.size_;
}

template<class T>
TemplateQueue<T>::~TemplateQueue()
{
	Clear();
}

template<class T>
void TemplateQueue<T>::Clear()
{
	if (size_ > 0)
	{
		// 1. Deletes every node.
		T* node = head_;
		T* next = node->next();
		for (; ;)
		{
			delete node;
			node = next;
			if (node == nullptr)
				break;
			next = node->next();
		}

		// 2. Resets the member variables.
		head_ = last_ = nullptr;
		size_ = 0;
	}
}


template<class T>
size_t TemplateQueue<T>::Size() const
{
	return size_;
}

template<class T>
T* TemplateQueue<T>::Head()
{
	return head_;
}

template<class T>
T* TemplateQueue<T>::Last()
{
	return last_;
}

template<class T>
void TemplateQueue<T>::Enqueue(const T& element)
{
	T* new_node = new T(element); //Apply for memory through 'new'
			// explicit QueueNode(const E &an_element):element_(an_element), next_(nullptr) {} 
	if (size_ == 0)
	{
		head_ = last_ = new_node;
		size_ = 1;
	}
	else
	{
		last_->next_ = new_node;
		last_ = new_node;
		size_++;
	}
}

template<class T>
T* TemplateQueue<T>::Dequeue()
{
	if (size_ == 0)
	{
		return nullptr;
	}

	const T* old_head = head_;
	head_ = head_->next_;
	size_--;

	if (size_ == 0)
	{
		last_ = nullptr;
	}

	T* element = new T(old_head->element());
	delete old_head;

	return element;
}

template<class T>
TemplateQueue<T>&TemplateQueue<T>::CopyTemplateQueue(TemplateQueue<T>& source)
{
	TemplateQueue<T>* new_queue = new TemplateQueue<T>();

	for (const T* node = head_; node != nullptr; node = node->next_)
	{
		new_queue->Enqueue(function(node->element())); //直接void Enqueue(const E &element); 就可以了吧，function多此一举吧？
		//不是多此一举，在 sample03UnitTest.cpp中就可以看到function()的巧妙使用
	}

	return new_queue;
}





