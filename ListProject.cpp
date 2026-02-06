#include <iostream>
#include <stdlib.h>
struct SNode{
    int SNo;
    SNode *snext;
};
struct CNode {
    int CNo;
    CNode *cnext;
    SNode *slist;
};

CNode *clist = NULL;

void insertCourses(int CNo){
    CNode *temp = (CNode *)malloc(sizeof(CNode));
    temp -> CNo = CNo;
    temp -> cnext = NULL;
    temp -> slist = NULL;

    if(clist == NULL){
        clist = temp;
    } else {
        CNode *curr = clist; // traversing 
        while (curr->cnext != NULL){
            curr = curr -> cnext; // traversing till we get bthe next NULL 
        }
        curr -> cnext = temp; // temp ko ham ne last value ma daal dia; // the value which bwe are inserting we will insert after traversing and then add it to the last
    }
}
void CourseOffered(){
    if(clist==NULL){
        std::cout << "NO COURSES ARE OFFFERED AT THE MOMENT\n";
        return;
    }
    CNode *Ccurr = clist;
    while(Ccurr!=NULL){
        std::cout << "Course Offered: " << Ccurr->CNo << "\n";
        Ccurr = Ccurr->cnext;
    }

}
void DeleteCourse(int CNo){
    if(clist==NULL){
        std::cout << "THE LIST IS EMPTY!!\n";
        return;
    }
    CNode *curr = clist;
    // for deleting the first or the only Node 
    if(curr->CNo==CNo){
        SNode *stemp = curr->slist;
        while(stemp!=NULL){
            SNode *sNext = stemp->snext;
            free(stemp);
            stemp = sNext;
        }
        clist=clist->cnext;
        free(curr);
        return;
    }
    // other than 1st Node
    CNode *pvs = clist;
    while(curr!=NULL){
        if(CNo==curr->CNo){
             SNode *stemp = curr->slist;
            while(stemp!=NULL){
                SNode *sNext = stemp->snext;
                free(stemp);
                stemp = sNext;
        }
            pvs->cnext=curr->cnext;
            free(curr);
            return;
        }
        curr = curr->cnext;
        pvs = curr;
    }
    std::cout << "Course Not Found!!\n";
}
void searchCourse(int CNo){
    if(clist==NULL){
        std::cout << "The list is empty!!\n";
        return;
    } 
    CNode *curr = clist;
    while(curr!=NULL){
        if(curr->CNo==CNo){
            std::cout << "Course Found!!\n";
            return;
        }
        curr = curr->cnext;
    }
    std::cout << "NOT FOUND\n";
    return;
}
void searchStudent(int SNo){
    if(clist==NULL){
        std::cout << "List is empty!!\n";
        return;
    }
    CNode *Ccurr = clist;
    while(Ccurr!=NULL){
        SNode *scurr = Ccurr->slist;
        while(scurr!=NULL){
            if(scurr->SNo==SNo){
                std::cout << "Student exist!!\n";
                return;
            }
            Ccurr = Ccurr->cnext;
        }
        std::cout << "Student Not Found\n";
        return;
    }
}
void insertStudentToACourse(int CNo , int SNo){
    CNode *Ccurr = clist; // Ccurr ko initialize kardia to traverse the course list, starts at the head of the list
    while (Ccurr != NULL){
        // traversing through the course until finding one with the matching course CNo
        if(Ccurr -> CNo == CNo){
            // student ko insert karna ha 
            SNode *temp = (SNode *)malloc(sizeof(SNode));
            temp -> SNo = SNo;
            temp -> snext = NULL;
            
            // if course has no students yet, if studentlist is empty then make temp the first student
            if(Ccurr -> slist == NULL){
                Ccurr -> slist = temp;
            } else { // else if the course already has the students then travers to the end of the list then add
                SNode *scur = Ccurr -> slist;
                while (scur -> snext!=NULL){
                    scur = scur->snext;
                }
            scur -> snext = temp;
            }
            return;
        }
        // move to the next course
        Ccurr = Ccurr -> cnext;
    }
    std::cout << "LIST NOT FOUND!!!\n";
}
void checkStudentInACourse(int SNo, int CNo){
    if(clist==NULL){
        std::cout << "THE LIST IS EMPTY\n";
        return;
    }
    CNode *Ccurr = clist;
    while(Ccurr!=NULL){
        if(Ccurr->CNo==CNo){
        SNode *scurr = Ccurr->slist;
        while(scurr!=NULL){
            if(scurr->SNo==SNo){
                std::cout << "Student: "<< scurr->SNo << " in " << Ccurr->CNo << " exist\n";
                return;
            }
            scurr = scurr->snext;
        }
        Ccurr = Ccurr->cnext;
        }
    }
    std::cout << "Student not enrolled in this Course!!\n";
    return;
}
void DeleteStudentFromCourse(int CNo , int SNo){
    if(clist==NULL){
        std::cout << "THE LIST IS EMPTY\n";
        return;
    }
    CNode *Ccurr = clist;
    while(Ccurr!=NULL){
        if(Ccurr->CNo==CNo){
            SNode *scurr = Ccurr->slist;
            SNode *prev = NULL;
            while(scurr!=NULL){
                if(scurr->SNo==SNo){
                    if(prev==NULL){
                    Ccurr->slist = Ccurr->slist->snext;
                } else {
                    prev ->snext = scurr ->snext;
                }
                    free(scurr);
                    std::cout << "STUDENT DELETED SUCCESSFULLY\n";
                    return;
            }
            prev = scurr;
            scurr = scurr->snext;
        }
        std::cout << "STUDENT NOT FOUND IN THIS COURSE\n";
        return;
        }
        Ccurr = Ccurr->cnext;
        }
        std::cout << "Course not found\n";
}
void DeleteStudent(int SNo){
   if(clist==NULL){
        std::cout << "THE LIST IS EMPTY\n";
        return;
    }
    int count =0; // to track how many times we have deleted the student
    CNode *Ccurr = clist;
    while(Ccurr!=NULL){
            SNode *scurr = Ccurr->slist;
            SNode *prev = NULL;
            while(scurr!=NULL){
                if(scurr->SNo==SNo){ // found the student
                    if(prev==NULL){
                    Ccurr->slist = Ccurr->slist ->snext;
                } else {
                    prev ->snext = scurr->snext;
                }
                    free(scurr);
                    count++;
                    std::cout << "STUDENT DELETED SUCCESSFULLY\n";
                    break;
            }
            prev = scurr;
            scurr = scurr->snext;
        }
        Ccurr = Ccurr->cnext;
        }
        if(count==0){
            std::cout << "STUDENT NOT FOUND IN ANY COURSE!!\n";
        } else {
            std::cout << "Student Deleted Successfully!! " << "from " << count << " courses\n";
        }
        std::cout << "Course not found\n";
}

void display(){

    CNode *ccurr = clist;
    while(ccurr !=NULL){
        std::cout << ccurr -> CNo << " ";
        SNode *scurr = ccurr->slist;
        while (scurr!=NULL){
            std::cout << scurr->SNo << " ";
            scurr = scurr->snext;
        }
        std::cout << "\n";
        ccurr = ccurr->cnext;
    }
}
void displayStudentCourse(int SNo){

    if(clist==NULL){
        std::cout << "THE LIST IS EMPTY!!\n";
        return;
    }
    CNode *Ccurr = clist;
    bool found = false;
    while(Ccurr!=NULL){
        SNode *scur = Ccurr -> slist;
        while(scur!=NULL){
            if(scur->SNo==SNo){
                std::cout << "This student is enrolled in: " << Ccurr->CNo << " \n";
                found = true;
                //return;
                break; // use break, not return;
            }
            scur = scur->snext;
        }
        Ccurr = Ccurr -> cnext;
    }
    if(false){
    std::cout << "STUDENT IS NOT ENROLLED IN ANY COURSE\n";
    return;
    }
}

int main(){


    std::cout << "INSERTING COURSES\n";
    insertCourses(341);
    insertCourses(345);
    insertCourses(451);
    insertCourses(356);
    insertCourses(678);
    
    CourseOffered(); 

    searchCourse(345);

    insertStudentToACourse(341,1);
    insertStudentToACourse(345,1);
    insertStudentToACourse(356,1);
    insertStudentToACourse(678,1);
    insertStudentToACourse(341,4);
    insertStudentToACourse(678,4);
    insertStudentToACourse(356,4);

    insertStudentToACourse(341,6);
    insertStudentToACourse(345,1);

    checkStudentInACourse(1,341);
    display();

    DeleteStudent(4);

    DeleteStudentFromCourse(341,1);
    displayStudentCourse(1);
//    std::cout << "Deleting the Courses!!\n";
//    DeleteCourse(345);
//    display();

    searchStudent(1);
    return 0;
}