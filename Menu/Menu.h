#ifndef LAB3_MENU_H
#define LAB3_MENU_H

#include "../CoordinateGraph/CoordinateGrpah.h"
#include "../Service/GraphService.h"
#include "../MenuFW/MenuFW.h"
#include "../Random/Random.h"
#include "../Tests/Tests.h"


void mainMenu();
void testing();

void customMenu(Menu& mainMenu, std::vector<void*>& memory);

void dataTypeCustomMenu(Menu& customMenu, std::vector<void*>& memory);
void dataTypeRandomMenu(Menu& customMenu, std::vector<void*>& memory);

template<typename VertT, typename EdgeT>
void customTypedDataMenu(Menu& dataTypeChoiceMenu);

void createStrIntMenu(Menu& dataTypeChoiceMenu, GraphService<std::string, int>* strIntGraphService);
void createStrDblMenu(Menu& dataTypeChoiceMenu, GraphService<std::string, double>* strDblGraphService);
void createPointMenu(Menu& dataTypeChoiceMenu, GraphService<Point, double>* pointGraphService);

void cleanMemory(std::vector<void*>& memory);

Point getPoint();
int getInteger(int min, int max);
int getInteger(int min);
int getInteger();
double getDouble();
#endif
