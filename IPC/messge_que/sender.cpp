#include<iostream>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<cstring>


struct msg_buffer{
    long msg_type;
    char msg_text[100];
};

int main(){
    key_t key = ftok("msgfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    msg_buffer message;
    message.msg_type = 1;
    strcpy(message.msg_text, "Hello via Message Queue!");

    msgsnd(msgid, &message, sizeof(message.msg_text), 0);
    std::cout<< "Message Sent: "<<message.msg_text<<std::endl;
    return 0;
}
