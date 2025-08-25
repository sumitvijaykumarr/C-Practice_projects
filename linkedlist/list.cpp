#include"iostream"

class Node{
    public:
    int data;
    Node* link;
};

void display(Node* head);

int main(){
   Node* temp1 = new Node();
   Node* temp2 = new Node();
   Node* temp3 = new Node();
   Node* temp4 = new Node();
   Node* temp5 = new Node();
   Node* temp6 = new Node();

    temp1->data = 30;
    temp1->link = temp2;
    temp2->data = 40;
    temp2->link = temp3;
    temp3->data = 50;
    temp3->link = temp4;
    temp4->data = 60;
    temp4->link = temp5;
    temp5->data = 70;
    temp5->link = temp6;
    temp6->data = 80;
    temp6->link = nullptr;

    display(temp1);


}
void display(Node* head){
    while(head->link != nullptr){
    std::cout<<head->data<<std::endl;
    head = head->link;
    }
}