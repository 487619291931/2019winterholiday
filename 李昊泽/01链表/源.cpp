/*�ڶ�����ҵ��дһ������, Ҫ��:  ����������, ����������,ɾ������,�޸�����,����ʾ�洢����������.   [��ֹ��Ϯ��ֹ����ճ��!!!]*/
#include<iostream>
using namespace std;

template <typename T>
class Node {//�ڵ���
public:
	/*��Ա����*/
	T element;
	Node* next;//��һ���ڵ�
};

template <typename T>
class List {
private:
	Node<T>* head = new Node<T>;//ͷ�ڵ�
public:
	Node<T>* getHead() { return head; };//��ȡͷ���,ע�ⷵ��ֵ����
	/*���ܽӿ�*/
	void createList(Node<T>* head);//��������
	void travel(Node<T>* head);//��������
	void addNode(Node<T>* head);//ĩβ�����½ڵ�
	void delNode(Node<T>* head);//�����������ݣ�ɾ��ָ���ڵ�
	void change(Node<T>* head);//������������,�޸�ָ���ڵ�
	void delList(Node<T>* head);//�ͷ���������
};

template <typename T>
void List<T> ::createList(Node<T>* head) {	//β�巨����������
	int i = 0, num;//val������������,num��ʾ��������ʱ���ݵĸ���
	T val;
	Node<T>* p = head;

	cout << "�������������ݸ��� : ";
	cin >> num;
	cout << "��������..." << endl;

	for (; i < num; i++) {
		Node<T>* s = new Node<T>;//sΪ�½ڵ�
		cout << "����������" << i + 1 << " : ";
		cin >> val;

		s->element = val;
		s->next = NULL;
		p->next = s;
		p = p->next;//�ڵ�p�����ƶ�
	}
	cout << "���������!" << endl;
}

template <typename T>
void List<T>::travel(Node<T>* head){//�������
	int i = 1;//��ʾ��i������
	Node<T>* p = head;
	cout << "ִ����������������� : " << endl;
	p = p->next;
	while (p) {
		cout << "����" << i << "Ϊ : " << p->element << endl;
		p = p->next;//�ڵ������ƶ�
		i++;
	}
	cout << "�����������!" << endl;
}

template <typename T>
void List<T>::addNode(Node<T>* head) {//�ҵ����һ���ڵ㲢������������½ڵ�
	T val;//�����洢������
	Node<T>* p = head;
	cout << "��������µĽڵ�" << endl;
	while (p->next) {//�ҵ����һ���ڵ�,ע��ѭ���ж�����
		p = p->next;
	}
	Node<T>* s = new Node<T>;
	cout << "�������½ڵ㴢������� : ";
	cin >> val;
	s->element = val;
	p->next = s;
	s->next = NULL;
	cout << "�½ڵ�������!" << endl;
}

template <typename T>
void List<T>::delNode(Node<T>* head) {//ͨ������ȷ�Ͻڵ�λ����ɾ���ڵ�
	int judge = 0;//�����ж������Ƿ������������,Ĭ��Ϊ0������
	T val;//��ɾ���ڵ���������
	Node<T>* p = head;
	cout << "������Ҫɾ���Ľڵ����� : ";
	cin >> val;
	while (p) {
		if (p->next->element == val) {//�˴����ҵ�������Ϊ�����ݵ�ǰһ�ڵ�
			judge = 1;
			break;
		}
		else
			p = p->next;
	}
	if (judge == 1) {
		/*��p�ڵ㸳ֵ��s�ڵ㣬���Ž�s�������ݽڵ㣬
		ʹ���ݽڵ��ָ����ֵ��ǰһָ��ﵽɾ��Ч��*/
		Node<T>* s = p;
		s = s->next;
		p->next = s->next;
		delete s;//�ͷű�ɾ���ڵ�
		cout << "�ڵ�ɾ���ɹ�!" << endl;
	}
	else
		cout << "δ�ҵ�������" << endl;
}

template <typename T>
void List<T>::change(Node<T>* head) {//�뷨����ɾ������ֻ�������ݵ��޸�
	int judge = 0;//�����ж������Ƿ������������,Ĭ��Ϊ0������
	T val;//���޸Ľڵ���������
	Node<T>* p = head;
	cout << "������Ҫ�޸ĵĽڵ����� : ";
	cin >> val;
	while (p) {
		if (p->element == val) {//�˴����ҵ�������Ϊ�����ݽڵ�(��ɾ��������)
			judge = 1;
			break;
		}
		else
			p = p->next;
	}
	if (judge == 0) {
		cout << "δ�ҵ�������" << endl;
	}
	else {
		cout << "�ɹ��ҵ������ݣ��������޸ĺ������ : " ;
		cin >> val;
		p->element = val;
		cout << "�޸ĳɹ�!" << endl;
	}
}

template <typename T>
void List<T>::delList(Node<T>*head){//���������ڽڵ㣬һ���ƶ�һ���ͷ�
	int num = 1;//��¼�ͷŵĽڵ���
	Node<T>* p = head;//�����ƶ��Ľڵ�,����ͷ�
	cout << "�����ͷ������нڵ�" << endl;
	while (p->next) {
		Node<T>* s = p;//�����ͷŵĽڵ�
		p = p->next;//�ڵ��ƶ�����һ��
		delete s;//�ͷŽڵ�
		cout << "�ͷŵ�" << num << "���ڵ�" << endl;
		num++;
	}
	delete p;//�����ͷ�
	cout << "�ͷŵ�" << num << "���ڵ�" << endl;
}

int main() {
	List<int>* list = new List<int>;
	int n;//����ִ�и��ֹ��ܽӿ�
	cout << "****************************************************" << endl;
	cout << "*      ��ӭʹ��USTIL�ڶ��μ�����ҵ���������       *" << endl;
	cout << "****************************************************" << endl;
	list->createList(list->getHead());
	cout << "****************************************************" << endl;
	cout << "*              ����������ִ�й��ܽӿ�              *" << endl;
	cout << "*    1����   2�޸�   3ɾ��   4����   -1��������    *" << endl;
	cout << "****************************************************" << endl;
	while (cin >> n && n != -1) {
		if (n == 1)
			list->addNode(list->getHead());
		else if (n == 2)
			list->change(list->getHead());
		else if (n == 3)
			list->delNode(list->getHead());
		else if (n == 4)
			list->travel(list->getHead());
		else
			cout << "��������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!������" << endl;
		cout << "****************************************************" << endl;
	}
	list->delList(list->getHead());//�ͷ�����
	cout << "���򼴽��ر�...." << endl;
	return 0;
}