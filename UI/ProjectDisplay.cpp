#include "ProjectDisplay.h"

void DisplayProject(ProjectData& projectData){
    for (int i=0; i<projectData.GetMaxId(); i++){
        Project p = projectData.Get(i);
    cout <<p.GetId()<<" "<< p.ToString() << endl;
    }
}

void DisplayProjectData()
{
    Project p1("ProductX", 1, "Bellaire", 5);
    Project p2("ProductY", 2, "Sugarland", 5);
    Project p3("ProductZ", 3, "Houston", 5);
    Project p4("Computerization", 10, "Stafford", 4);
    Project p5("Reorganization", 20, "Houston", 1);
    Project p6("Newbenefits", 30, "Stafford", 4);

    ProjectData(projectData);
    projectData.PushBack(p1);
    projectData.PushBack(p2);
    projectData.PushBack(p3);
    projectData.PushBack(p4);
    projectData.PushBack(p5);
    projectData.PushBack(p6);

    DisplayProject(projectData);
}