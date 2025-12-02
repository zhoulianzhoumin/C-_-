#include "menu_item.hpp"
#include "menu_manager.hpp"
#include <iostream>

using namespace MenuSys;

/*
Главное меню:
	1 - Путешествовать по России
		1 - Дальний Восток
			1 - Владивосток
			2 - Сахалин
			3 - Хабаровск
			0 - Выйти в предыдущее меню
		2 - Алтай
		3 - Золотое Кольцо России
		0 - Выйти в главное меню
	0 - Закончить путешествия
*/

int main() {
	
	MenuManager manager;
	
//1.创建菜单结构
	//创建根菜单
	MenuItem* root = MenuManager::createMenuItem("Главное меню:");
	//一级目录：是否旅游
	MenuItem* depart = MenuManager::createMenuItem("1 - Путешествовать по России");
	MenuItem* exit = MenuManager::createMenuItem("0 - Закончить путешествия");
	MenuManager::addChild(root, depart);
	MenuManager::addChild(root, exit);
	//二级目录：旅游地点
	MenuItem* Far_East = MenuManager::createMenuItem("1 - Дальний Восток");
	MenuItem* Altai = MenuManager::createMenuItem("2 - Алтай");
	MenuItem* GoldenRing = MenuManager::createMenuItem("3 - Золотое Кольцо России");
	MenuItem* Return = MenuManager::createMenuItem("0 - Выйти в главное меню");
	MenuManager::addChild(depart, Far_East);
	MenuManager::addChild(depart, Altai);
	MenuManager::addChild(depart, GoldenRing);
	MenuManager::addChild(depart, Return);
	//三级目录示例：远东项目
	MenuItem* Vladivostok = MenuManager::createMenuItem("1 - Владивосток");
	MenuItem* Sakhalin = MenuManager::createMenuItem("2 - Сахалин");
	MenuItem* Khabarovsk = MenuManager::createMenuItem("3 - Хабаровск");
	MenuItem* Back = MenuManager::createMenuItem("0 - Выйти в предыдущее меню");
	MenuManager::addChild(Far_East, Vladivostok);
	MenuManager::addChild(Far_East, Sakhalin);
	MenuManager::addChild(Far_East, Khabarovsk);
	MenuManager::addChild(Far_East, Back);
    
//2.设置根菜单并开始程序
    manager.setRootMenu(root);
    std::cout << "Добро пожаловать в систему навигации по России!\n" << std::endl;
    
//3.主循环
    int choice;
    while (true) {
        //显示当前菜单
        manager.displayCurrentMenu();
        
        //获取用户输入
        std::cout << "\nВведите номер выбора: ";
        std::cin >> choice;
        
        //检查输入有效性
        if (std::cin.fail()) {
            std::cin.clear();  //清除错误状态
            std::cin.ignore(10000, '\n');  //忽略错误的输入
            std::cout << "Ошибка ввода! Пожалуйста, введите число.\n" << std::endl;
            continue;
        }
        
        std::cin.ignore(10000, '\n');  //清除输入缓冲区
        
        //执行用户选择
        manager.executeOption(choice);
    } 
    return 0;
}
