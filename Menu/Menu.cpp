#include "Menu.h"

void cleanMemory(std::vector<void*>& memory) {
    delete (GraphService<std::string, int>*)memory[0];
    delete (GraphService<std::string, double>*)memory[1];
    delete (GraphService<Point, double>*)memory[2];
    delete (GraphService<std::string, int>*)memory[3];
    delete (GraphService<std::string, double>*)memory[4];
    delete (GraphService<Point, double>*)memory[5];
}

void mainMenu() {
    std::vector<void*> memory;
    Menu menu;
    customMenu(menu, memory);

    menu.displayMenu();
    menu.chooseOption(false);

    cleanMemory(memory);
}

void customMenu(Menu& mainMenu, std::vector<void*>& memory) {
    Menu& customMenu = mainMenu.createContextMenu("Custom");
    Menu& randomMenu = mainMenu.createContextMenu("Random");
    mainMenu.addOption("Tests", [](){
        testing();
    });
    dataTypeCustomMenu(customMenu, memory);
    dataTypeRandomMenu(randomMenu, memory);
}

void testing() {
    std::cout << "Enter amount of tests: ";
    int amount = getInteger(0);
    mainTest(amount);
}


void dataTypeCustomMenu(Menu& customMenu, std::vector<void*>& memory) {
    GraphService<std::string, int>* strIntGraphService = new GraphService<std::string, int>(*(new Graph<std::string, int>));
    GraphService<std::string, double>* strDblGraphService = new GraphService<std::string, double>(*(new Graph<std::string, double>));
    GraphService<Point, double>* pointGraphService = new GraphService<Point, double>(*(new Graph<Point, double>));

    memory.push_back(strIntGraphService);
    memory.push_back(strDblGraphService);
    memory.push_back(pointGraphService);

    Menu& strIntMenu = customMenu.createContextMenu("String - Integer");
    Menu& strDblMenu = customMenu.createContextMenu("String - Double");
    Menu& pointMenu = customMenu.createContextMenu("Points");
    createStrIntMenu(strIntMenu, strIntGraphService);
    createStrDblMenu(strDblMenu, strDblGraphService);
    createPointMenu(pointMenu, pointGraphService);

}

void dataTypeRandomMenu(Menu& randomMenu, std::vector<void*>& memory) {
    GraphService<std::string, int>* strIntGraphService = new GraphService<std::string, int>(*(new Graph<std::string, int>));
    GraphService<std::string, double>* strDblGraphService = new GraphService<std::string, double>(*(new Graph<std::string, double>));
    GraphService<Point, double>* pointGraphService = new GraphService<Point, double>(*(new Graph<Point, double>));

    memory.push_back(strIntGraphService);
    memory.push_back(strDblGraphService);
    memory.push_back(pointGraphService);

    randomMenu.addOption("String - Integer", [strIntGraphService](){
        std::cout << "Enter count of vertices: ";
        int count = getInteger();
        strIntRandGraph( *(strIntGraphService->getGraph()) , count);
        Menu strIntMenu;
        createStrIntMenu(strIntMenu, strIntGraphService);
        strIntMenu.chooseOption();
    });
    randomMenu.addOption("String - Double", [strDblGraphService](){
        std::cout << "Enter count of vertices: ";
        int count = getInteger();
        strDblRandGraph( *(strDblGraphService->getGraph()) , count);
        Menu strDblMenu;
        createStrDblMenu(strDblMenu, strDblGraphService);
        strDblMenu.chooseOption();
    });
    randomMenu.addOption("Points", [pointGraphService](){
        std::cout << "Enter count of vertices: ";
        int count = getInteger();
        pointerRandGraph( *(pointGraphService->getGraph()) , count);
        Menu pointMenu;
        createPointMenu(pointMenu, pointGraphService);
        pointMenu.chooseOption();
    });

}




void createStrIntMenu(Menu& dataTypeChoiceMenu, GraphService<std::string, int>* strIntGraphService) {
    dataTypeChoiceMenu.addOption("Add vertex", [strIntGraphService]{
        std::string name;
        std::cout << "Enter vertex name: ";
        std::cin >> name;
        strIntGraphService->addVertex(name);
    });
    dataTypeChoiceMenu.addOption("Add edge", [strIntGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        std::cout << "Enter edge weight: ";
        int weight = getInteger();
        strIntGraphService->addEdge(nameFrom, nameTo, weight);
    });
    dataTypeChoiceMenu.addOption("Remove vertex", [strIntGraphService]{
        std::string name;
        std::cout << "Enter vertex name: ";
        std::cin >> name;
        strIntGraphService->removeVertex(name);
    });
    dataTypeChoiceMenu.addOption("Remove edge", [strIntGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        strIntGraphService->removeEdge(nameFrom, nameTo);
    });
    dataTypeChoiceMenu.addOption("Get weight", [strIntGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        strIntGraphService->outputWeight(nameFrom, nameTo);
    });
    dataTypeChoiceMenu.addOption("Show graph", [strIntGraphService]{
        strIntGraphService->outputGraph();
    });
    dataTypeChoiceMenu.addOption("Shortest path length", [strIntGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        strIntGraphService->outputShortestPathLength(nameFrom, nameTo);
    });
    dataTypeChoiceMenu.addOption("Show shortest path", [strIntGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        strIntGraphService->outputShortestPath(nameFrom, nameTo);
    });
}

void createStrDblMenu(Menu& dataTypeChoiceMenu, GraphService<std::string, double>* strDblGraphService) {
    dataTypeChoiceMenu.addOption("Add vertex", [strDblGraphService]{
        std::string name;
        std::cout << "Enter vertex name: ";
        std::cin >> name;
        strDblGraphService->addVertex(name);
    });
    dataTypeChoiceMenu.addOption("Add edge", [strDblGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        std::cout << "Enter edge weight: ";
        double weight = getDouble();
        strDblGraphService->addEdge(nameFrom, nameTo, weight);
    });
    dataTypeChoiceMenu.addOption("Remove vertex", [strDblGraphService]{
        std::string name;
        std::cout << "Enter vertex name: ";
        std::cin >> name;
        strDblGraphService->removeVertex(name);
    });
    dataTypeChoiceMenu.addOption("Remove edge", [strDblGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        strDblGraphService->removeEdge(nameFrom, nameTo);
    });
    dataTypeChoiceMenu.addOption("Get weight", [strDblGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        strDblGraphService->outputWeight(nameFrom, nameTo);
    });
    dataTypeChoiceMenu.addOption("Show graph", [strDblGraphService]{
        strDblGraphService->outputGraph();
    });
    dataTypeChoiceMenu.addOption("Shortest path length", [strDblGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        strDblGraphService->outputShortestPathLength(nameFrom, nameTo);
    });
    dataTypeChoiceMenu.addOption("Show shortest path", [strDblGraphService]{
        std::string nameFrom;
        std::cout << "Enter vertex name from: ";
        std::cin >> nameFrom;
        std::string nameTo;
        std::cout << "Enter vertex name to: ";
        std::cin >> nameTo;
        strDblGraphService->outputShortestPath(nameFrom, nameTo);
    });
}

void createPointMenu(Menu& dataTypeChoiceMenu, GraphService<Point, double>* pointGraphService) {
    dataTypeChoiceMenu.addOption("Add point", [pointGraphService]{
        Point point = getPoint();
        pointGraphService->addVertex(point);
    });
    dataTypeChoiceMenu.addOption("Connect points", [pointGraphService]{
        std::cout << "Point from" << std::endl;
        Point pointFrom = getPoint();
        std::cout << "Point to" << std::endl;
        Point pointTo = getPoint();
        pointGraphService->addEdge(pointFrom, pointTo,
                                   CoordinateGraph::calculateDistance(pointFrom, pointTo));
    });
    dataTypeChoiceMenu.addOption("Remove point", [pointGraphService]{
        Point point = getPoint();
        pointGraphService->removeVertex(point);
    });
    dataTypeChoiceMenu.addOption("Disconnect points", [pointGraphService]{
        std::cout << "Point from" << std::endl;
        Point pointFrom = getPoint();
        std::cout << "Point to" << std::endl;
        Point pointTo = getPoint();
        pointGraphService->removeEdge(pointFrom, pointTo);
    });
    dataTypeChoiceMenu.addOption("Get distance", [pointGraphService]{
        std::cout << "Point from" << std::endl;
        Point pointFrom = getPoint();
        std::cout << "Point to" << std::endl;
        Point pointTo = getPoint();
        pointGraphService->outputWeight(pointFrom, pointTo);
    });
    dataTypeChoiceMenu.addOption("Show graph", [pointGraphService]{
        pointGraphService->outputGraph();
    });
    dataTypeChoiceMenu.addOption("Shortest path length", [pointGraphService]{
        std::cout << "Point from" << std::endl;
        Point pointFrom = getPoint();
        std::cout << "Point to" << std::endl;
        Point pointTo = getPoint();
        pointGraphService->outputShortestPathLength(pointFrom, pointTo);
    });
    dataTypeChoiceMenu.addOption("Show shortest path", [pointGraphService]{
        std::cout << "Point from" << std::endl;
        Point pointFrom = getPoint();
        std::cout << "Point to" << std::endl;
        Point pointTo = getPoint();
        pointGraphService->outputShortestPath(pointFrom, pointTo);
    });
}












Point getPoint() {
    Point point(0, 0);
    std::cout << "Enter x: ";
    std::cin >> point.x;
    std::cout << "Enter y: ";
    std::cin >> point.y;
    return point;
}





int getInteger(int min, int max) {
    int num;
    bool isBad = true;
    do {
        std::cin >> num;

        if (std::cin.fail())
        {
            std::cerr << "Enter correct number" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            isBad = true;
            continue;
        }
        else if ((num < min || num > max))
        {
            std::cerr << "Enter number from " << min << " to " << max << std::endl;
            isBad = true;
        } else {
            isBad = false;
        }
    } while (isBad);
    std::cin.ignore(32767,'\n');
    return num;
}

double getDouble() {
    double num;
    bool isBad = true;
    do {
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cerr << "Enter correct number" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            isBad = true;
            continue;
        }
        else {
            isBad = false;
        }
    } while (isBad);
    std::cin.ignore(32767,'\n');
    return num;
}


int getInteger(int min) {
    int num;
    bool isBad = true;
    do {
        std::cin >> num;

        if (std::cin.fail())
        {
            std::cerr << "Enter correct number" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            isBad = true;
            continue;
        }
        else if (num < min)
        {
            std::cerr << "Enter number not less than " << min << std::endl;
            isBad = true;
        } else {
            isBad = false;
        }
    } while (isBad);
    std::cin.ignore(32767,'\n');
    return num;
}
int getInteger() {
    int num;
    bool isBad = true;
    do {
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cerr << "Enter correct number" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            isBad = true;
            continue;
        }
        else {
            isBad = false;
        }
    } while (isBad);
    std::cin.ignore(32767,'\n');
    return num;
}
