static int defaultSize=100;
template <typename E> class List {//List ADT �����������Ͷ��� 
	private:
		void operator =(const List&) {	}
		List(const List&) {}
	public:
		List() {}//���캯�� 
		virtual ~List() {}//�������� 
		virtual void clear() =0;//����б��е����� 

		virtual void insert(const E& item) =0;//�ڵ�ǰλ�ò���Ԫ��item 

		virtual void append(const E& item) =0;//�ڱ�β���Ԫ��item 

		virtual E remove() =0;//ɾ����ǰԪ�ز�������Ϊ����ֵ 
		virtual void moveToStart() =0;//����ǰλ������Ϊ˳�����ʼ�� 
		virtual void moveToEnd() =0;//����ǰλ����Ϊ˳���ĩβ 
		virtual void prev() =0;//����ǰλ������һ���������ǰλ������λ�Ͳ��� 
		virtual void next() =0;//����ǰλ������һ���������ǰλ����ĩβ�Ͳ��� 
		virtual int length() const =0;//�����б�ǰԪ�صĸ��� 
		virtual int currPos() const =0;//���ص�ǰԪ�ص�λ�� 
		virtual void moveToPos(int pos) =0;//����ǰλ����Ϊpos 
		virtual const E& getValue() const =0;//���ص�ǰԪ�� 
};
