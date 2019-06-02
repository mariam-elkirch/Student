#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
struct student{
int id;
float gpa,score;
 char name[30];};

 void input(int n,student s[])
 {
   int i;

     ofstream data;
     data.open("data.txt");//,ios_base::app);
 for(i=0;i<n;i++){
cout<<"enter id:";
    cin>>s[i].id;
 data<<s[i].id<<'\t';
cout<<"enter name:";

    cin>>s[i].name;
    data<<s[i].name<<'\t';
    cout<<"enter score:";

    cin>>s[i].score;
data<<s[i].score<<'\t';
cout<<"enter GPA:";

    cin>>s[i].gpa;
data<<s[i].gpa<<'\t'<<endl;

cout<<"************"<<endl;}

data.close();

 }

 void selection_sort(int n,student s[]){
    int i,j,temp,smallest;
    ifstream data;
    data.open("data.txt");

        for(i=0;i<n;i++)
    data>>s[i].id>>s[i].gpa>>s[i].score>>s[i].name;

    cout<<"the id sorting in ascending order"<<endl;
    for(i=0;i<n-1;i++){
        smallest=i;
        for(j=i+1;j<n;j++){
            if(s[smallest].id>s[j].id)
            smallest=j;}
            temp=s[i].id;
            s[i].id=s[smallest].id;
            s[smallest].id=temp;
            }
            for(i=0;i<n;i++)
            cout<<s[i].id<<",";cout<<endl;
             data.close();

 }
 void searchbyid(int n,student s[])
 {
    int i,found=0,index,id;
    ifstream data;
    data.open("data.txt");
    for(i=0;i<n;i++)

    data>>s[i].id>>s[i].gpa>>s[i].score>>s[i].name;

    cout<<"enter id of student you want to search";
    cin>>id;
    for(i=0;i<n;i++){
    if(s[i].id==id){
    found=1;index=i;}}
    if(found==0)
    cout<<"student not found"<<endl;
    else

    cout<<"found"<<"::name:"<<s[index].name<<",score:"<<s[index].score<<",gpa:"<<s[index].gpa<<endl;
     data.close();
}
void update(int n,student s[])
{
    ifstream data;
    int i,id,found,index;
     data.open("data.txt");

    for(i=0;i<n;i++)
    data>>s[i].id>>s[i].gpa>>s[i].score>>s[i].name;
    cout<<"enter id of student you want to update"<<endl;
    cin>>id;
    for(i=0;i<n;i++){
    if(s[i].id==id){
    found=1;index=i;}}
    if(found==0)
    cout<<"student not found"<<endl;
    else
    {
       cout<<"enter id:";
        cin>>s[index].id;
       cout<<"enter gpa:";
        cin>>s[index].gpa;
        cout<<"enter score:";
        cin>>s[index].score;
        cout<<"enter name:";
        cin>>s[index].name;
    } data.close();}
   void deletebyid(int n,student s[])
    {
        int i,id,found,index;
        ifstream data;
    data.open("data.txt");
    for(i=0;i<n;i++)

    data>>s[i].id>>s[i].gpa>>s[i].score>>s[i].name;

    cout<<"enter id of student you want to delete"<<endl;
    cin>>id;
    for(i=0;i<n;i++){
    if(s[i].id==id){
    found=1;index=i;}}
    if(found==0)
    cout<<"student not found";
    else{
          s[index].id=NULL;
          s[index].gpa=NULL;
          *s[index].name=NULL;
          s[index].score=NULL;


        }data.close();

    }
    void exit(){
     cout<<"Thank you for using my program";
     exit(-1);}
int main()
{
    int x,n;
    cout<<"enter number of students:";
     cin>>n;
     student s[n];
      while(1){

  cout<<"if you want to enter data base click 1"<<endl;
  cout<<"if you want to search for student click2"<<endl;
  cout<<"if you want to sort ids click3"<<endl;
  cout<<"if you want to update data click4"<<endl;
  cout<<"if you want to delete a student click 5"<<endl;
  cout<<"if you want to exit program click6"<<endl;
    cin>>x;
    switch(x){
case 1:
      input(n,s);
  break;
   case 2:
   searchbyid(n,s);
    break;
    case 3:
        selection_sort(n,s);
   break;
    case 4:
        update(n,s);
        break;
    case 5:
        deletebyid(n,s);
        break;
        case 6:
        exit();
        break;
    default:cout<<"your choice is wrong"<<endl;}}

    return 0;

}
