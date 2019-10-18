static int defaultSize=100;
template <typename E> class List {//List ADT 抽象数据类型定义 
	private:
		void operator =(const List&) {	}
		List(const List&) {}
	public:
		List() {}//构造函数 
		virtual ~List() {}//析构函数 
		virtual void clear() =0;//清空列表中的内容 

		virtual void insert(const E& item) =0;//在当前位置插入元素item 

		virtual void append(const E& item) =0;//在表尾添加元素item 

		virtual E remove() =0;//删除当前元素并将其作为返回值 
		virtual void moveToStart() =0;//将当前位置设置为顺序表起始处 
		virtual void moveToEnd() =0;//将当前位置设为顺序表末尾 
		virtual void prev() =0;//将当前位置左移一步，如果当前位置在首位就不变 
		virtual void next() =0;//将当前位置右移一步，如果当前位置在末尾就不变 
		virtual int length() const =0;//返回列表当前元素的个数 
		virtual int currPos() const =0;//返回当前元素的位置 
		virtual void moveToPos(int pos) =0;//将当前位置设为pos 
		virtual const E& getValue() const =0;//返回当前元素 
};
