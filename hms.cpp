#include<iostream>
#include <fstream>
using namespace std;

int ward=0,id=1, age,doctor_id,nurse_id,checkup_room=0;
string name, no, patient_type;

struct patient{
patient *address;
int data,age;
string name,no,patient_type;
};
patient *l, *head, *temp;

struct patient1{
patient1 *address1;
int data,age;
string name,no,patient_type;
};
patient1  *l2,*temp2, *head2 ;

struct doctor{
doctor *address1;
int data1,age;
string name1,no1;
};
doctor *ll, *head1, *temp1;

struct nurse{
nurse* address3;
int data3,age3;
string name3,no3;
};
nurse *l3,*head3, *temp3;


void appointment (){
    patient_type=" normal";
    cout<<"...enter patient name...";
    cin>> name;
    cout<<endl;
    cout<<"...enter contact number...";
    cin>>no;
    cout<<endl;
    cout<<"...enter age...";
    cin>>age;

    while(!cin){
        cin.clear();
        cin.ignore();
        cout<<"....enter valid age....";
        cin>>age;
    }

l=new patient();
l->data=id;
l->name=name;
l->no=no;
l->age=age;
l->patient_type=patient_type;
l->address=NULL;

l2=new patient1();
l2->data=id;
l2->name=name;
l2->no=no;
l2->age=age;
l2->patient_type=patient_type;
l2->address1=NULL;
while(checkup_room<11){
if(head==NULL && head2==NULL ){
    head=l;
    head2=l2;
id++;
checkup_room++;
cout<<endl;
cout<<"....patient add successfully...."<<endl;
cout<<endl;
}

else if(head==NULL && head2!=NULL ){
    head=l;
    temp2=head2;
       while (temp2->address1!=NULL)
         temp2=temp2->address1;
        temp2->address1=l2;
id++;
checkup_room++;
cout<<endl;
cout<<"....patient add successfully...."<<endl;
cout<<endl;
}

else if( (head!=NULL)&&(head2!=NULL)){
    temp=head;
    temp2=head2;
    if(temp!=NULL){
       while( (temp->address!=NULL)  )

       temp=temp->address;
        temp->address=l;}
         if(temp2!=NULL){
       while( (temp2->address1!=NULL)  )
       temp2=temp2->address1;
        temp2->address1=l2;}
id++;
checkup_room++;
cout<<endl;
cout<<"....patient add successfully...."<<endl;
cout<<endl;
}
break;
}
if (checkup_room>=10){
    cout<<endl;
    cout<<".........hospital checkup room capacity is full, wait plz...."<<endl;
    cout<<endl;
}
}

void add_critical_patient(){
 patient_type="critical/accident";
    cout<<"enter patient name...";
    cin>> name;
    cout<<endl;
    cout<<"enter contact number";
    cin>>no;
    cout<<endl;
    cout<<"enter age";
    cin>>age;

    while(!cin){
        cin.clear();
        cin.ignore();
        cout<<"....enter valid age....";
        cin>>age;
    }

l=new patient();
l->data=id;
l->name=name;
l->no=no;
l->age=age;
l->patient_type=patient_type;
l->address=NULL;

l2=new patient1();
l2->data=id;
l2->name=name;
l2->no=no;
l2->age=age;
l2->patient_type=patient_type;
l2->address1=NULL;

while(ward<20){
if(head==NULL && head2==NULL ){
    head=l;
    head2=l2;
id++;
ward++;
cout<<endl;
cout<<"....patient add successfully...."<<endl;
cout<<endl;
}
else if(head==NULL && head2!=NULL ){
    head=l;
    temp2=head2;
       while (temp2->address1!=NULL)
         temp2=temp2->address1;
        temp2->address1=l2;
id++;
ward++;
cout<<endl;
cout<<"....patient add successfully...."<<endl;
cout<<endl;
}
else if( (head!=NULL)&&(head2!=NULL)){
    temp=head;
    temp2=head2;
    if(temp!=NULL){
       while( (temp->address!=NULL)  )

       temp=temp->address;
        temp->address=l;}
         if(temp2!=NULL){
       while( (temp2->address1!=NULL)  )

       temp2=temp2->address1;
        temp2->address1=l2;}
id++;
ward++;
cout<<endl;
cout<<"....patient add successfully...."<<endl;
cout<<endl;
}
break;
}

if (ward>=20){
    cout<<endl;
    cout<<"hospital capacity is full, can't enter more...."<<endl;
    cout<<endl;
}
}

void print_patient_data(){
temp=head;
if(temp!=NULL){
    cout<<"ID "<<"  "<<"    name"<<"  "<<"  phone "<<"    "<<temp->age<<"    "<<"   patient type  "<<endl;
    cout<<"   "<<"  "<<"        "<<"  "<<"        "<<"    "<<"       "<<"    "<<"                 "<<endl;
    while(temp!=NULL){
    cout<<temp->data<<"        "<<temp->name<<"   "<<temp->no<<"     "<<temp->age<<"   "<< temp->patient_type<< endl;
    temp=temp->address;
}}
else{
    cout<<endl;
    cout<<"no available data of patient"<<endl;
    cout<<endl;
}
}

void print_patient_history(){
temp2=head2;
if(temp2!=NULL){
    cout<<"ID  "<<"     "<<"    name   "<<"     "<<"phone   "<<"   "<<"patient type"<<endl;
    while(temp2!=NULL){
    cout<<temp2->data<<"     "<<temp2->name<<"     "<<temp2->no<<"   "<<temp2->age<<"  "<<temp2->patient_type<<endl;
    temp2=temp2->address1;
}}
else{
    cout<<endl;
    cout<<"no available data of patient"<<endl;
    cout<<endl;
}
}
void delete_patient_data() {
int idd,num;
cout<<endl;
cout<<"...........enter patient type..........."<<"\n enter 1 for emergency patients"<<"\n enter 2 for normal patients"<<endl;
cin>>num;
while(!cin){
    cin.clear();
    cin.ignore();
    cout<<"......invalid input....."<<"\n .......enter valid input......"<<endl;
    cin>>num;
    cout<<endl;
}
cout<<"enter patient id u want to delete.......";
cin>>idd;
cout<<endl;

if(head!=NULL){
    if (head != NULL)
    {
       patient * currNode = head;
        if (head->data == idd)
        {
            head = head->address;
            delete currNode;
            cout<<endl;
            cout<<"patient has been discharged"<<endl;
            if(num==1){
                ward=ward-1;
            }
            else if(num==2){
                 checkup_room=checkup_room-1;
            }
            cout<<endl;
        }

        else
        {
           patient * prevNode = NULL;
            while (currNode != NULL && currNode->data!=idd )
            {
                prevNode = currNode;
                currNode = currNode->address;
            }

            if (currNode->data== idd)
            {

                prevNode->address = currNode->address;
                delete currNode;
                cout<<endl;
                cout<<"patient has been discharged"<<endl;
                cout<<endl;
                  if(num==1){
                ward=ward-1;
            }
            else if(num==2){
                 checkup_room=checkup_room-1;
            }
            cout<<endl;
            }
        }
    }
}
else{
    cout<<endl;
    cout<<"no record found against this input value"<<endl;
    cout<<endl;
}
}
void search_patient(){
int number;
    int found=0;
    cout<<endl;
    cout<<"enter patient id...";
    cin>>number;
    temp=head;
    if(temp!=NULL){
    while(temp!=NULL){
    if(number== temp->data){
        found++;
        break;
    }
temp=temp->address;
 }
  if(found==1){
        cout<<"ID"<<"  "<<"  "<<"    name"<<" "<<"phone "<<"  "<<" age  " <<"  "<< " patient type  "<<endl;
        cout<<temp->data<<"  "<<temp->name<<" "<<temp->no<<"  "<<temp->age<<"  "<<temp->patient_type<<endl;
    }}
    else{
        cout<<"list is empty";
    }
 }

void add_doctor(){
    doctor_id=6;
    doctor_id=doctor_id+1;
    cout<<"enter name...";
    cin>>name;
    cout<<"enter age...";
    cin>>age;
while(!cin){
    cin.clear();
    cin.ignore();
    cout<<"invalid input"<<" \nenter valid input"<<endl;
    cin>>age;
}

     ll=new doctor();
     ll->data1=doctor_id;
     ll->name1=name;
     ll->age=age;
     ll->address1=NULL;
     if(head1==NULL){
        head1=ll;
cout<<endl;
cout<<"....doctors add successfully...."<<endl;
cout<<endl;
     }
     else{
        temp1=head1;
        while(temp1->address1!=NULL)
            temp1=temp1->address1;
            temp1->address1=ll;
cout<<endl;
cout<<"....doctors add successfully...."<<endl;
cout<<endl;
}
}

void delete_doctor_data(){
int id;
cout<<"enter doctor id to...delete";
cin>>id;
while(!cin){
    cin.clear();
    cin.ignore();
    cout<<"....invalid........      "<<"....enter valid input......"<<endl;
    cout<<"enter doctor id to...delete";
    cin>>id;
}

    if (head1 != NULL)
    {
       doctor * currNode = head1;
        if (head1->data1 == id)
        {
            head1 = head1->address1;
            delete currNode;
            cout<<endl;
            cout<<"....doctor data deleted...."<<endl;
            cout<<endl;
        }
        else
        {
           doctor * prevNode = NULL;
            while (currNode != NULL && currNode->data1 !=id)
            {
                prevNode = currNode;
                currNode = currNode->address1;
            }

            if  (currNode->data1== id)
            {

                prevNode->address1 = currNode->address1;
                delete currNode;
            cout<<endl;
            cout<<"....doctor data deleted...."<<endl;
            cout<<endl;
            }
        }
    }
    else{
    cout<<endl;
    cout<<".........no doctor data found........."<<endl;
    cout<<endl;}
}
void print_doctor_data(){
temp1=head1;
if(temp1!=NULL){
    while(temp1!=NULL){
    cout<<" Id "<<" "<<" name "<<" "<<"age"<<endl;
    cout<<temp1->data1<<"    "<<temp1->name1<<"    "<<temp1->age;
    temp1=temp1->address1;
}
}
else{
    cout<<endl;
    cout<<"....no data found...."<<endl;
    cout<<endl;
}

}
void available_doctor(){
    cout<<".....available doctors are....."<<endl;
if(id==1){

    cout<<".........doctor1........"<<endl;
    cout<<".........doctor2......."<<endl;
    cout<<".........doctor3......."<<endl;
    cout<<".........doctor4......."<<endl;
    cout<<".........doctor5......."<<endl;
    cout<<".........doctor6......."<<endl;
}
else if(id==2){

    cout<<".........doctor1........"<<endl;
    cout<<".........doctor2......."<<endl;
    cout<<".........doctor3......."<<endl;
    cout<<".........doctor4......."<<endl;
    cout<<".........doctor5......."<<endl;
}
 else if(id==3){
    cout<<".........doctor1........"<<endl;
    cout<<".........doctor2......."<<endl;
    cout<<".........doctor3......."<<endl;
    cout<<".........doctor4......."<<endl;
    }
  else   if(id==4){
    cout<<".........doctor1........"<<endl;
    cout<<".........doctor2......."<<endl;
    cout<<".........doctor3......."<<endl;
 }
   else if(id==5){
    cout<<".........doctor1........"<<endl;
    cout<<".........doctor2......."<<endl;
    }
   else if(id==6){
    cout<<".........doctor1......."<<endl;
   }
   else if(id>=7){
temp1=head1;
if(temp1!=NULL){
    while(temp1!=NULL){
    cout<<" Id       "<<"  "<<" name     "<<"   "<<"age";
    cout<<temp1->data1<<"  "<<temp1->name1<<"   "<<temp1->age;
    temp1=temp1->address1;
}}}
}
void add_nurse(){
    nurse_id=6;
    nurse_id++;
    cout<<"enter name...";
    cin>>name;
    cout<<"enter age...";
    cin>>age;
     while(!cin){
        cin.clear();
        cin.ignore();
        cout<<"....enter valid age....";
        cin>>age;

    }
    cout<<"enter number";
    cin>>no;

     l3=new nurse();
     l3->data3=nurse_id;
     l3->name3=name;
     l3->age3=age;



     l3->address3=NULL;
     if(head3==NULL){
        head3=l3;
        cout<<endl;
cout<<"....nurse add successfully...."<<endl;
cout<<endl;
     }
     else{
        temp3=head3;
        while(temp3->address3!=NULL)
            temp3=temp3->address3;
        temp3->address3=l3;
     }
        }

void delete_nurse_data(){
int nurse_id;
cout<<endl;
cout<<"....enter nurse id u want to delete...."<<endl;
cin>>nurse_id;
if(head3!=NULL){
    if (head3 != NULL)
    {
       nurse * currNode = head3;
        if (head3->data3 == nurse_id)
        {
            head3 = head3->address3;
            delete currNode;
            cout<<endl;
            cout<<".... data deleted...."<<endl;
            cout<<endl;
        }
        else
        {
           nurse * prevNode = NULL;
            while (currNode != NULL && currNode->data3!=nurse_id)
            {
                prevNode = currNode;
                currNode = currNode->address3;
            }
        if (currNode->data3 ==nurse_id)
            {
                prevNode->address3 = currNode->address3;
                delete currNode;
            cout<<endl;
            cout<<".... data deleted...."<<endl;
            cout<<endl;
            }
        }
    }
}
else{
    cout<<endl;
    cout<<".....no data found....."<<endl;
    cout<<endl;
}
}
void print_nurse_data(){
temp3=head3;
if(temp3!=NULL){
    while(temp3!=NULL){
    cout<<"Nurse id"<<"    "<<"nurse name  "<<"   "<<"   age   "<<endl;
    cout<<temp3->data3<<"     "<<temp3->name3<<"     "<<temp3->age3;
    temp3=temp3->address3;
}}}
void availabl_nurses(){
 cout<<".....available nurses are....."<<endl;
  if(id==1){
    cout<<".........nurse1......."<<endl;
    cout<<".........nurse2......."<<endl;
    cout<<".........nurse3......."<<endl;
    cout<<".........nurse4......."<<endl;
    cout<<".........nurse5......."<<endl;
    cout<<".........nurse6......."<<endl;}
 else if(id==2){
    cout<<".........nurse1......."<<endl;
    cout<<".........nurse2......."<<endl;
    cout<<".........nurse3......."<<endl;
    cout<<".........nurse4......."<<endl;
    cout<<".........nurse5......."<<endl;}
 else if(id==3){
    cout<<".........nurse1......."<<endl;
    cout<<".........nurse2......."<<endl;
    cout<<".........nurse3......."<<endl;
    cout<<".........nurse4......."<<endl;
    }
  else   if(id==4){
    cout<<".........nurse1......."<<endl;
    cout<<".........nurse2......."<<endl;
    cout<<".........nurse3......."<<endl;
 }
   else if(id==5){
    cout<<".........nurse1......."<<endl;
    cout<<".........nurse2......."<<endl;
    }
   else if(id==6){
    cout<<".........nurse1......."<<endl;
   }
   else if(id>=7){
temp3=head3;
if(temp3!=NULL){
    while(temp3!=NULL){
    cout<<"Nurse id"<<"  "<<"nurse name  "<<"   "<<"   age   ";
    cout<<temp3->data3<<"  "<<temp3->name3<<"   "<<temp3->age3;
    temp3=temp3->address3;
}}
   }
   else{
    cout<<"....zero...."<<endl;
    cout<<endl;
   }
}


void available_rooms(){
int room_ward=20;
int room=10;
int  w=room_ward-ward;
int c=room-checkup_room;
cout<<endl;
cout<<w <<" ......ward rooms are available for crtitcal/ accident patients....."<<endl;
cout<<endl;
cout<<c <<".......check up rooms are available for normal patients .........."<<endl;
}

int main(){
int choice,command;
string id,no,position,age;
string name;
int number;

cout<<"                                                           "<<endl;
cout<<"                                                           "<<endl;
cout<<"                                                           "<<endl;
cout<<"......welcome to great HOSPITAL, how may can I help u......"<<endl;
cout<<"                                                           "<<endl;
cout<<"                                                           "<<endl;
cout<<"                                                           "<<endl;

first:
cout<<"\ 1 for patient "<< "\n 2 for doctor"<<"\n 3 for nurses"<<"\n 4 for check room status"<<"\n 5 to exit"<<endl;
cout<<"                                                       "<<endl;

while(1){
cout<<" enter command....";
cin>>command;
while(!cin){
    cin.clear();
    cin.ignore();
    cout<<"....invalid output...."<<"\n enter valid input"<<endl;
    cin>>command;
}

if(command==1){
while(1){
cout<<"                                                           "<<endl;
cout<<" 1 for add patient"<<"  \n 2 for delete patient data"<<"\n 3 for print patient data "<<"\n 4 for search patient  "<<"\n 5 for patient history "<<"\n 6 to go back to main menu"<<"\n 7 to exit  "<<endl;
cout<<"                                                           "<<endl;
cout<<"enter choice....";
cin>>choice;
while(!cin){
    cin.clear();
    cin.ignore();
    cout<<"......invlaid input....."<<" \n..... enter valid input..... "<<endl;
    cin>>choice;
}
switch(choice){
case 1:
int num;
cout<<endl;
cout<<"1: press 1 for emergency patients"<<"\n2: press 2 for normal patients   "<<endl;
cout<<endl;
cout<<"enter patient type"<<endl;
cout<<endl;
cin>>num;
while(!cin){
    cin.clear();
    cin.ignore();
    cout<<"enter valid number....";
    cin>>num;
}
if(num==1){
        cout<<endl;
        cout<<" entrance of emergency patients...."<<endl;
        cout<<endl;
    add_critical_patient();}
else if(num==2){
        cout<<endl;
        cout<<" entrance of normal patients...."<<endl;
        cout<<endl;
    appointment();
}
    break;
case 2:
    delete_patient_data();
    break;
case 3:
    print_patient_data();
    break;
case 4:
    search_patient();
    break;
case 5:
    print_patient_history();
    break;
case 6:
    goto first;
case 7:
    return 0;
default:
    cout<<"invalid value"<<endl;
}}
}

if(command==2){
while(1){
cout<<endl;
cout<<"1.......for add doctor......"<<" \n2......for delete doctor data......"<<"\n3.....for print doctor data....."<<"\n4.....for print available doctor data....."<<"\n5.....to go back to main menu...."<<endl;
cout<<endl;
cin>>choice;
while(!cin){
    cin.clear();
    cin.ignore();
    cout<<"......invlaid input....."<<" \n..... enter valid input..... "<<endl;
    cin>>choice;
}
switch(choice){
case 1:
    add_doctor();
    break;
case 2:
    cout<<endl;
    delete_doctor_data();
    break;
case 3:
    print_doctor_data();
    break;
case 4:
    available_doctor();
    break;
case 5:
    goto first;
default:
    cout<<"invalid value"<<endl;
}}}

if(command==3){
while(1){
cout<<endl;
cout<<"1 .....for add nurse..... "<<" \n2 ......for delete nurse data"<<"\n3........for print nurse data"<<" \n4......for print available nurses data......"<<"\n5......to go back to main menu....."<<endl;
cout<<endl;
cin>>choice;
while(!cin){
    cin.clear();
    cin.ignore();
    cout<<"......invlaid input....."<<" \n..... enter valid input..... "<<endl;
    cin>>choice;
}
switch(choice){
case 1:
    add_nurse();
    break;
case 2:
    cout<<endl;
    delete_nurse_data();
    break;
case 3:
    print_nurse_data();
    break;
case 4:
    availabl_nurses();
    break;
case 5:
    goto first;
default:
    cout<<"invalid value"<<endl;
    cout<<endl;

}}}



if(command==4){
    cout<<endl;
    available_rooms();
    cout<<endl;
    goto first;
}

if(command==5){
cout<<"........................................................................"<<endl;
cout<<"........................................................................"<<endl;
cout<<"........................................................................"<<endl;
cout<<"............................terminating................................."<<endl;
cout<<"........................................................................"<<endl;
cout<<"........................................................................"<<endl;
cout<<"........................................................................"<<endl;
return 0;
}
}
}