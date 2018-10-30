#include <iostream>
using namespace std;

template<typename T>
class SList{
	struct Node{
		T m_data;
		Node* m_next;
		Node(const T _data, Node* _next = nullptr){
			m_data = _data;
			m_next = _next;
		}
	};
	Node* m_head;
	Node* m_tail;
public:
	SList(){
		m_head = nullptr;
		m_tail = nullptr;
	}
	~SList(){
		Node* it = m_head;
		Node* del = m_head;
		while (it){
			del = it;
			it = it->m_next;
			delete del;
		}
		m_head = nullptr;
		m_tail = nullptr;
	}
	void push_front(T _data){
		Node* temp = new Node(_data, m_head);
		if (!m_head){
			m_tail = temp;
		}
		m_head = temp;
	}
	void push_back(T _data){
		Node* temp = new Node(_data);
		if (!m_head){
			m_head = temp;
		}
		else{
			m_tail->m_next = temp;
		}
		m_tail = temp;
	}
	void pop_front(){
		if (m_head){
			if (m_head != m_tail){
				Node* temp = m_head->m_next;
				delete m_head;
				m_head = temp;
			}
			else{
				delete m_head;
				m_head = m_tail = nullptr;
			}
		}
	}
	void pop_back(){
		if (m_tail){
			if (m_tail != m_head){
				Node* last = m_head;
				Node* secondLast = m_head;
				while (last != m_tail){
					secondLast = last;
					last = last->m_next;
				}
				secondLast->m_next = nullptr;
				delete last;
				m_tail = secondLast;
			}
			else{
				delete m_tail;
				m_tail = m_head = nullptr;
			}
		}
	}
	void print(){
		Node* it = m_head;
		while (it){
			cout << it->m_data << endl;
			it = it->m_next;
		}
		cout << "==========================" << endl;
	}
};