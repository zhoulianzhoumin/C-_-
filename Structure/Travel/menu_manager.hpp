#ifndef MENU_MANAGER_HPP
#define MENU_MANAGER_HPP

#include "menu_item.hpp"

namespace MenuSys {
//菜单操作类：行为管理
	class MenuManager {
		private: //对外隐藏实现细节，封装状态
			MenuItem* currentMenu;
			MenuItem* rootMenu;

			void cleanupMenuTree(MenuItem* menu);

		public: //对外提供安全接口
			//生命周期管理
			MenuManager() : currentMenu(nullptr), rootMenu(nullptr) {
			//使用成员初始化列表，避免野指针干扰条件判断
			}
			~MenuManager() {
				if (rootMenu) {
					cleanupMenuTree(rootMenu);
				}
			}
		
			//创建菜单项，使用类中的静态工厂方法
			static MenuItem* createMenuItem(const char* title); //指针指向一个结构体
			//const char* title传递字符串字面量，被指向的字符串不可被修改，保证菜单标题的完整性
			//= nullptr默认参数，表示可选参数，有功能菜单项和纯导航菜单项，调用时可以不传第二个参数

			//添加子菜单
			static void addChild(MenuItem* parent, MenuItem* child);
			
			//展示菜单
			void displayCurrentMenu() const;

			//执行当前选择
			void executeOption(int option);

			//获取当前菜单
			MenuItem* getCurrentMenu() const;
			
			//设置当前菜单
			void setCurrentMenu(MenuItem* menu);

			//设置根菜单
			void setRootMenu(MenuItem* root);
	};
}

#endif