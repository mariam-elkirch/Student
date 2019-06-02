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
     data.open("data.txt");
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
 void exit(){
     cout<<"Thank you for using my program";
     exit(-1);}
 void selection_sort(int n,student s[]){
    int i,j,temp,smallest;
    ifstream data;
    data.open("open.txt");

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
    data.open("open.txt");

    for(i=0;i<n;i++)
    data>>s[i].id>>s[i].gpa>>s[i].score>>s[i].name;

    cout<<"enter id of student you want to search";
    cin>>id;
    for(i=0;i<n;i++){
    if(s[i].id==id){
    found=1;index=i;}}
    if(found==0)
    cout<<"student not found";
    else

    cout<<"found"<<"::name:"<<s[index].name<<",score:"<<s[index].score<<",gpa:"<<s[index].gpa<<endl;

    data.close();
}
void update(int n,student s[])
{
    ifstream data;




    int i,id,found,index;
     data.open("open.txt");

    for(i=0;i<n;i++)
    data>>s[i].id>>s[i].gpa>>s[i].score>>s[i].name;
    cout<<"enter id of student you want to update"<<endl;
    cin>>id;
    for(i=0;i<n;i++){
    if(s[i].id==id){
    found=1;index=i;}}
    if(found==0)
    cout<<"student not found";
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
   /** void deletebyid(int n,student s[])
    {
        int i,id,found,index;
         student arr[30];
    cout<<"enter id of student you want to delete"<<endl;
    cin>>id;
    for(i=0;i<n;i++){
    if(s[i].id==id){
    found=1;index=i;}}
    if(found==0)
    cout<<"student not found";
    else{
          s[index].gpa=none_of

        }




    }
    }**/




int main()
{
    int x,n;
  cout<<"if you want to enter data base click 1.if you want student information click2. if you want to update information click 3. if you want to delete information click4";
    cin>>x;
    cout<<"enter number of students:";
     cin>>n;
     student s[n];
    switch(x){
case 1:{

      input(n,s);


     selection_sort(n,s);
     }
    break;
   case 2:
   searchbyid(n,s);

    break;
    case 3:
        update(n,s);

    break;
    case 4:
        exit();
    default:cout<<"error";}


    return 0;
}
