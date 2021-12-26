#include "MenuFW.h"


Menu::Option::Option(std::string description, std::function<void()> action) noexcept
        : description(std::move(description)), action(std::move(action)) {};

void Menu::Option::invokeFunction() const {
    action();
}

const std::string& Menu::Option::getDescription() const {
    return description;
}

Menu::Menu() : environmentPointer(nullptr) {
    addOption("Exit", []() {std::cout << "Exit from menu" << std::endl;});
}

Menu::Menu(Menu* environmentPointer) : environmentPointer(environmentPointer) {
    addOption("Back", [environmentPointer]() {environmentPointer->displayMenu();});
};

void Menu::displayMenu() const {
    for (int index = 1; index < options.size(); ++index) {
        std::cout << index << ".\t" << options[index].getDescription() << std::endl;
    }
    std::cout << 0 << ".\t" << options[0].getDescription() << std::endl; // "Exit" or "Back"
}

void Menu::addOption(std::string  description,
                     std::function<void()> action)
{
    options.emplace_back(description, action);
}

void Menu::chooseSingleOption() const {
    displayMenu();
    chooseOneOption();
}

void Menu::chooseOption() const {
    chooseOption(true);
}

void Menu::chooseOption(bool doDisplayMenu) const {
    bool keepDoing = true;
    while (keepDoing) {
        if (doDisplayMenu)
            displayMenu();
        keepDoing = chooseOneOption();
    }
}

bool Menu::chooseOneOption() const {
    bool keepDoing = true;
    try {
        std::cout << "Option: ";
        int option = getOptionFromInput(-1, options.size() - 1);
        if (option == -1)
            displayMenu();
        else
            options[option].invokeFunction(); // Надо ли вызывать функцию по индексу 0?
        if (option == 0)
            keepDoing = false;
    } catch (std::exception& error) {
        std::cout << error.what() << std::endl;
    }
    return keepDoing;
}

int getOptionFromInput(int min, int max) {
    int num;
    std::cin >> num;

    // Обрабатываем случай, когда пользователь ввел нецелочисленное значение
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        throw std::runtime_error("Incorrect input. Type -1 to show menu");
    }
    else if ((num < min || num > max))
    {
        throw std::runtime_error("There is no such option. Type -1 to show menu");
    }
    std::cin.ignore(32767,'\n');
    return num;
}

//Menu Menu::createContextMenu() {
//    Menu menu(this);
////    menu.environmentPointer = this;
//    return menu;
//}

Menu& Menu::createContextMenu(const std::string& description) {
    return createContextMenu(description, false);
}

Menu& Menu::createContextMenu(const std::string& description, bool doDisplayMenu) {
    Menu* contextMenu = new Menu(this);

    std::cout << description << " " << contextMenu << std::endl;

    contextMenus.push_back(contextMenu);

    addOption(description, [contextMenu, doDisplayMenu](){
        contextMenu->displayMenu();
        contextMenu->chooseOption(doDisplayMenu);
    });
    return *contextMenu;
}

Menu::Option& Menu::Option::operator= (const Option& option) {
    if (this != &option) {
        description = option.description;
        action = option.action;
    }
    return *this;
}

Menu& Menu::operator= (const Menu& menu) {
    options = menu.options;
}

Menu::~Menu() {
    for (auto item : contextMenus)
        delete item;
}