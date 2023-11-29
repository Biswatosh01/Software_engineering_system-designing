#include<iostream>
#include<vector>
using namespace std;

string grade(int score){
    if(score>=90 && score<=100) return "S";
    else if(score>=80 && score<90) return "A";
    else if(score>=70 && score<80) return "B";
    else if(score>=60 && score<70) return "C";
    else if(score>=50 && score<60) return "D";
    else if(score>=0 && score<50) return "F";
    else return "X";
}

int gp(string g){
    if(g=="S") return 10;
    else if(g=="A") return 9;
    else if(g=="B") return 8;
    else if(g=="C") return 7;
    else if(g=="D") return 6;
    else if(g=="F") return 5;
    else return 0;
}

int main(){
    int m[30][30], marks[30],n,t=0;
    cout<<"Enter the number of students: ";
    cin>>n;
    float gpa[30][30],cgpa[30];
    vector<string> name(30);
    for(int j=0;j<4;j++){
        int x=0;
        cout<<"\n---------------------Semester "<<j+1<<"----------------------\n"<<endl;
        while(x<n){
            int sum=0;
            cout<<"Enter the name of student "<<x+1<<": ";
            cin>>name[t++];
            cout<<"Enter marks of the subjects in Quiz1: ";
            for(int i=0;i<5;i++){
                cin>>m[0][i];
                marks[i]=m[0][i];
            }
            cout<<"Enter marks of the subjects in Quiz2: ";
            for(int i=0;i<5;i++){
                cin>>m[1][i];
                marks[i]+=m[1][i];
            }
            cout<<"Enter marks of the subjects in Sessional1: ";
            for(int i=0;i<5;i++){
                cin>>m[2][i];
                marks[i]+=m[2][i];
            }
            cout<<"Enter marks of the subjects in Sessional2: ";
            for(int i=0;i<5;i++){
                cin>>m[3][i];
                marks[i]+=m[3][i];
            }
            cout<<"Enter marks of the subjects in Assignment: ";
            for(int i=0;i<5;i++){
                cin>>m[4][i];
                marks[i]+=m[4][i];
            }
            cout<<"Enter marks of the subjects in Attendence: ";
            for(int i=0;i<5;i++){
                cin>>m[5][i];
                marks[i]+=m[5][i];
            }
            cout<<"Enter marks of the subjects in External: ";
            for(int i=0;i<5;i++){
                cin>>m[6][i];
                marks[i]+=m[6][i];
            }
            for(int i=0;i<5;i++){
                int credit=gp(grade(marks[i]));
                sum+=(3*credit);
            }
            // cout<<m[4][0]<<" "<<m[5][0]<<endl;
            cout<<"\n************** "<<name[x]<<"'s Report for Semester "<<j+1<<" ***************"<<endl;
            cout<<"Subject\tQuiz1\tQuiz2\tSessional1\tSessional2\tAssignment\tAttendence\tExternal\tTotal Marks\tGrade\tGrade Point"<<endl;
            for(int i=0;i<5;i++){
                cout<<i+1<<"\t"<<m[0][i]<<"\t"<<m[1][i]<<"\t"<<m[2][i]<<"\t\t"<<m[3][i]<<"\t\t"<<m[4][i]<<"\t\t"<<m[5][i]<<"\t\t"<<m[6][i]<<"\t\t"<<marks[i]<<"\t\t"<<grade(marks[i])<<"\t"<<gp(grade(marks[i]))<<endl;
            }
            gpa[j][x]=sum/15.0;
            cout<<"GPA: "<<sum/15.0<<endl;
            x++;
        }
    }
    for(int i=0;i<n;i++){
        cgpa[i]=0;
        for(int j=0;j<4;j++){
            cgpa[i]+=gpa[j][i];
        }
        cgpa[i]/=4.0;
    }
    cout<<"\n---------------------CGPA----------------------\n"<<endl;
    for(int i=0;i<n;i++){
        cout<<name[i]<<"\t"<<cgpa[i]<<endl;
    }
    return 0;
}
