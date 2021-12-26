#ifndef FRAMEWORK_MENU_H
#define FRAMEWORK_MENU_H

#include <string>
#include <functional>
#include <iostream>
#include <exception>
#include <vector>
#include <utility>



class Menu;

class IMenu {
public:
    virtual void displayMenu() const = 0;
    virtual void addOption(std::string  description, std::function<void()> action) = 0;
    virtual void chooseSingleOption() const = 0;
    virtual void chooseOption() const = 0;
    virtual void chooseOption(bool doDisplayMenu) const = 0;
    virtual Menu& createContextMenu(const std::string& description) = 0;
    virtual Menu& createContextMenu(const std::string& description, bool doDisplayMenu) = 0;
};

class Menu : public IMenu {
private:
    class Option {
    private:
        std::string description;
        std::function<void()> action;
    public:
        virtual void invokeFunction() const;
        [[nodiscard]] virtual const std::string& getDescription() const;
        Option(std::string  description, std::function<void()> action) noexcept;

        Option& operator= (const Option& option);
    };



private:
    std::vector<Menu*> contextMenus;
    std::vector<Option> options;
    Menu* environmentPointer;
public:
    Menu();
    void displayMenu() const final;
    void addOption(std::string  description, std::function<void()> action) final;
    void chooseSingleOption() const final;
    void chooseOption() const final;
    void chooseOption(bool doDisplayMenu) const final;
    Menu& createContextMenu(const std::string& description) final;
    Menu& createContextMenu(const std::string& description, bool doDisplayMenu) final;
    ~Menu();
    Menu& operator= (const Menu& menu);


private:
    [[nodiscard]] bool chooseOneOption() const;
    explicit Menu(Menu* environmentPointer);
};


int getOptionFromInput(int min, int max);

#endif
