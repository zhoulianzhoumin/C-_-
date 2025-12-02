//菜单项定义，结构体与类职责分离

#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP

namespace MenuSys {
	//菜单项结构体：数据容器，只有成员，没有方法，不要和对象混为一体，对象是在堆上分配内存后初始化创建的
	struct MenuItem {
	//菜单项属性
		const char* title;
		int level;

	//关系字段
		MenuItem* parent; //更高一级菜单指针
		MenuItem** children; //二级指针指向子菜单指针数组，这个子菜单数组不在声明中确定和父菜单的关系，要通过双方的链接
		//MenuItem**相当于解引用MenuItem*（二级指针解引用一级指针），即得到MenuItem*的值，MenuItem对象的地址，MenuItem** == &children[0]
		int childCount;
	};
}

#endif