#include<bits/stdc++.h>

using namespace std;

struct node{
int data;
node* link;
};

struct node* XOR(node* x, node* y) {

return (node*)((uintptr_t(x))^(uintptr_t (y)));

}
node* push(node* &head, int data){

    node* newnode = new node();
    newnode->data = data;
    newnode->link = XOR(head,NULL);

    if(head){
    newnode->data = data;
    head->link = XOR(newnode,XOR(head->link,NULL));

    }
    cout<<"Inserting "<<data<<endl;
head=newnode;
}
void traverse(node* head){
node* current = head;
node* prev  = NULL;
node* next;
while(current!=NULL){
    cout<<current->data<<" ";
    next = XOR(prev,current->link);

    prev = current;
    current = next;
}
}

void Delete(node* head, int key){
node* current = head;
node* prev= NULL;
node* next;

while(current->data != key ){
    next = XOR(prev,current->link);
    cout<<"traverse"<<current->data<<" ";

    prev = current;
    current = next;
}
    next = XOR(prev,current->link);
    prev = XOR(XOR(prev->link,current),next);
    next = XOR(XOR(next->link,current),prev);


}
int main(){

int keys[]= {1,2,5,6,4};

node* head = NULL;

for(int i=0;i<5;i++)
    push(head,keys[i]);


node * temp = head;
Delete(head, 5);
head = NULL;
traverse(temp);



return 0;

}
