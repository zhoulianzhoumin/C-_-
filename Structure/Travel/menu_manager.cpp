#include "menu_item.hpp"
#include "menu_manager.hpp"
#include <iostream>
#include <string>

namespace MenuSys {
	MenuItem* MenuManager::createMenuItem(const char* title){
		MenuItem* item = new MenuItem; //1.堆分配内存，大小在运行时确定，调用构造函数初始化堆上创建的对象，返回该对象在内存中的地址
		item->title = title; //2.设置标题，成员访问运算符通过指针访问对象的成员，等价于(*对象指针).成员 先解引用再访问
		//[指针]->成员变量
		item->parent = nullptr; //3.初始化父指针
		item->children = nullptr; //4.初始化子菜单数组
		item->childCount = 0; //5.子菜单初始数量为0
		item->level = 0; //6.菜单初始层级为0
		return item; //7.返回新创建的菜单项
	}
	
	void MenuManager::cleanupMenuTree(MenuItem* menu) {
		if (menu == nullptr) {
			return;
		}
		//1.递归删除所有子菜单，当childCount=0时，证明已经达到最深递归，可以直接删除，彼时该子菜单的子菜单数组为空数组
		for (int i = 0; i < menu->childCount; i++) {
			cleanupMenuTree(menu->children[i]);
		}
		//2.删除子项指针数组，防止内存泄漏
		if (menu->children != nullptr) {
			delete[] menu->children;
		}
		//3.删除菜单项本身
		delete menu;
	}
	
	void MenuManager::addChild(MenuItem* parent, MenuItem* child) {
		//创建新的子菜单数组
		MenuItem** newChildren = new MenuItem*[parent->childCount + 1]; //内存重新分配，添加父菜单拥有的子菜单数量，返回包含的MenuItem*数组
	
		//复制原有的子菜单，当childCount=0时，循环体不会执行
		for (int i = 0; i < parent->childCount; ++i) {
			newChildren[i] = parent->children[i];
		}
	
		//添加新子菜单
		newChildren[parent->childCount] = child;
		child->parent = parent;
		child->level = parent->level + 1;
	
		//删除原有数组并更新指针
		delete[] parent->children;
		parent->children = newChildren;
		parent->childCount++;
	}
	
	void MenuManager::displayCurrentMenu() const {
		if (!currentMenu) {
			return;
		}
    
		//显示当前菜单的标题
		std::cout << currentMenu->title << std::endl;
    
		//只显示当前菜单的直接子菜单
		for (int i = 0; i < currentMenu->childCount; i++) {
			std::cout << "\t" << currentMenu->children[i]->title << std::endl;
		}
	}
	
	void MenuManager::executeOption(int choice) {
        if (!currentMenu) return;
        
        //输入验证
        if (choice < 0 || choice > currentMenu->childCount) {
            std::cout << "Неверный выбор!" << std::endl;
            return;
        }
        
        //选择0：返回/退出
        if (choice == 0) {
            if (currentMenu->parent == nullptr) {
                std::cout << "\nВыход из программы...\n" << std::endl;
                exit(0);
            } else {
                setCurrentMenu(currentMenu->parent);
            }
            return;
        }
        
        //选择1-N
        int index = choice - 1;
        MenuItem* selected = currentMenu->children[index];
        
        if (selected->childCount > 0) {
            //有子菜单：进入
            setCurrentMenu(selected);
        } else {
            //没有子菜单：显示选择
            std::cout << "\nВы выбрали: " << selected->title << "\n" << std::endl;
        }
    }
	
	MenuItem* MenuManager::getCurrentMenu() const {
		return currentMenu; //必须返回当前菜单指针，匹配返回类型
	}
	
	void MenuManager::setCurrentMenu(MenuItem* menu) {
		currentMenu = menu;
	}
	
	void MenuManager::setRootMenu(MenuItem* root) {
		if (root != nullptr) { //避免空指针赋值
			rootMenu = root; //依靠rootMenu找回节点
			currentMenu = root; //初始时当前菜单 = 根菜单
		}
	}
}