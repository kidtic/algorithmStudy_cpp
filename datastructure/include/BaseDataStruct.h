#pragma once
#include <iostream>

//基本数据结构

//=---------------堆栈
template <class T>
class myStack
{
public:
	myStack(int maxsize);
	~myStack();
	void push(T x);
	T pop();
	bool empty();
	T& operator[](int index);
	int size();

private:
	int top;
	T *pT;
	int m_maxsize;

};

template <class T> myStack<T>::myStack(int maxsize)
{
	pT = new T[maxsize];
	m_maxsize = maxsize;
	top = 0;
}
template <class T> myStack<T>::~myStack()
{
	delete[] pT;
}
template <class T> void myStack<T>::push(T x)
{
	if (top >= m_maxsize)
	{
		printf("ERROR:��ջ����");
		return;
	}
	pT[top] = x;
	top++;
}
template <class T> T myStack<T>::pop()
{
	if (top <= 0)
	{
		printf("ERROR:��ջ����");
		return pT[0];
	}
	top--;
	return pT[top];
}
template <class T> bool myStack<T>::empty()
{
	if (top == 0)
		return true;
	else
	{
		return false;
	}
}
template <class T> T& myStack<T>::operator[](int index)
{
	if (index >= top)
	{
		printf("�����������ֵ");
		return pT[0];
	}
	return pT[index];
}
template <class T> int myStack<T>::size()
{
	return top;
}

//=--------------队列
template<class T> 
class myQueue
{
public:
	myQueue(int maxsize);
	~myQueue();
	bool empty();//�ж��Ƿ�Ϊ��
	void enqueue(T x);//���
	T dequeue();//����
	int size();
	T& operator[](int index);

	

private:
	T *pT;
	int m_maxsize;
	int head; int tail;

	

};

template<class T> myQueue<T>::myQueue(int maxsize)
{
	pT = new T[maxsize];
	m_maxsize = maxsize;
	head = 0; tail = 0;
}
template<class T> myQueue<T>::~myQueue()
{
	delete[] pT;
}
template<class T> bool myQueue<T>::empty()
{
	if (head == tail)
		return true;
	else
	{
		return false;
	}
}
template<class T> void myQueue<T>::enqueue(T x)
{
	//�ж϶����Ƿ���
	if (size() == m_maxsize - 1)
	{
		printf("ERROR:��������");
		return;
	}

	pT[tail] = x;
	if (tail==m_maxsize-1)
	{
		tail = 0;
	}
	else
	{
		tail++;
	}
}
template<class T> T myQueue<T>::dequeue()
{
	//�ж��Ƿ�Ϊ��
	if (empty())
	{
		printf("ERROR:��������");
		return pT[head];
	}

	T x = pT[head];
	if (head == m_maxsize - 1)
	{
		head = 0;
	}
	else
	{
		head++;
	}
	return x;
}
template<class T> int myQueue<T>::size()
{
	int s = tail - head;
	if (s >= 0)
	{
		return s;
	}
	else
	{
		return m_maxsize + s;
	}
}
template <class T> T& myQueue<T>::operator[](int index)
{
	//�ж��Ƿ񳬹�����
	if (index >= size())
		printf("ERROR:�����������ֵ");
	if (index < 0)
		printf("ERROR:����Ϊ����");

	int s = head+index;
	if (s >= m_maxsize)
	{
		return pT[s - m_maxsize];
	}
	else
	{
		return pT[s];
	}
}



//=---------------链表
template<class T>
struct linkNode
{
	T key;
	linkNode* prev;
	linkNode* next;
};

template<class T>
class LinkList
{
public:
	linkNode<T>* head;//ָ������ͷ
	linkNode<T>* tail;//ָ������β

public:
	LinkList();
	~LinkList();
	bool empty();
	int size();
	void addNode(T key);//�ٱ�β���ӽڵ�
	void print();//��ӡ������Ԫ��
	bool insertNode(int index, T key , linkNode<T>* p);//����pΪ���λ�õ�ָ��λ�����ӽڵ�
	bool deleteNode(int index, linkNode<T>* p);//����pΪ���λ�õ�ָ��λ��ɾ���ڵ�
	T& operator[](int index);

	
private:
	int length;
	linkNode<T>* createNode(T key);

};

template<class T> LinkList<T>::LinkList()
{
	head = nullptr;
	tail = nullptr;
}
template<class T> LinkList<T>::~LinkList()
{
	while (head->next!=nullptr)
	{
		head = head->next;
		delete head->prev;
	}
	delete head;
}
template<class T> bool LinkList<T>::empty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<class T> int LinkList<T>::size()
{
	return length;
}
template<class T> linkNode<T>* LinkList<T>::createNode(T key)
{
	linkNode<T>* result = new linkNode<T>();
	result->key = key;
	return result;
}
template<class T> void LinkList<T>::addNode(T key)
{
	if (empty()==true)
	{
		head = createNode(key);
		tail = head;
		head->next = nullptr;
		head->prev = nullptr;

		
	}
	else
	{
		tail->next = createNode(key);
		tail->next->prev = tail; 
		tail = tail->next;	
		tail->next = nullptr;
	}

	length++;
}
template<class T> void LinkList<T>::print()
{
	linkNode<T>* p=head;
	while (p!=nullptr)
	{
		std::cout << p->key << " ";
		p = p->next;
	}
}
template<class T> bool LinkList<T>::insertNode(int index, T key, linkNode<T>* p)
{
	if (p==nullptr)
	{
		p = head;
	}
	if (index>0)
	{
		for (int i = 0; i < index; i++)
		{
			if(p->next!=nullptr)
				p = p->next;
			else
			{
				printf("ERROR;����������Χ");
				return false;
			}
		}
	}
	else if(index<0)
	{
		for (size_t i = 0; i < -index; i++)
		{
			if (p->prev != nullptr)
				p = p->prev;
			else
			{
				printf("ERROR;����������Χ");
				return false;
			}
			
		}
	}
	linkNode<T>* newkey = createNode(key);
	newkey->next = p->next;
	newkey->prev = p;
	if(p->next!=nullptr)
		p->next->prev = newkey;
	else
		tail = newkey;
	p->next = newkey;
	
	length++;
}
template<class T> bool LinkList<T>::deleteNode(int index, linkNode<T>* p)
{
	if (p == nullptr)
	{
		p = head;
	}
	//�����ҵ���ȷλ��
	if (index > 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (p->next != nullptr)
				p = p->next;
			else
			{
				printf("ERROR;����������Χ");
				return false;
			}
		}
	}
	else if (index < 0)
	{
		for (size_t i = 0; i < -index; i++)
		{
			if (p->prev != nullptr)
				p = p->prev;
			else
			{
				printf("ERROR;����������Χ");
				return false;
			}

		}
	}
	length--;
	//ɾ��
	if (p->prev!=nullptr)
		p->prev->next = p->next;
	else
		head = p->next;
	
	if (p->next != nullptr)
		p->next->prev = p->prev;
	else
		tail = p->prev;
	//delete�ͷ��ڴ�
	delete p;

}
template <class T> T& LinkList<T>::operator[](int index)
{
	linkNode<T>* ptr;
	if (index <= length / 2)
	{
		ptr = head;
		for (size_t i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}
	}
	else
	{
		ptr = tail;
		for (size_t i = 0; i < length-index-1; i++)
		{
			ptr = ptr->prev;
		}
	}
	return ptr->key;
}



