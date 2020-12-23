#include <iostream>
#include "BusinessObject/Dependent.h"
#include "DataAccess/DependentData.h"
#include "UI/DependentDisplay.h"
#include "BusinessObject/Project.h"
#include "DataAccess/ProjectData.h"
#include "UI/ProjectDisplay.h"
using namespace std;

int main() {
    DisplayDependentData();
    DisplayProjectData();
    return 0;
}