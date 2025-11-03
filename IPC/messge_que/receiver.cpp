// #include<iostream>
// #include<sys/ipc.h>
// #include<sys/msg.h>
// #include<cstring>


// struct msg_buffer{
//     long msg_type;
//     char msg_text[100];
// };

// int main(){
//     key_t key = ftok("msgfile", 65);
//     int msgid = msgget(key, 0666 | IPC_CREAT);

//     msg_buffer message;
//     // message.msg_type = 1;
//     // strcpy(message.msg_text, "Hello via Message Queue!");

//     msgrcv(msgid, &message, sizeof(message.msg_text),1, 0);
//     std::cout<< "Message Received: "<<message.msg_text<<std::endl;
//     msgctl(msgid, IPC_RMID, NULL);
//     return 0;
// }

#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("msgfile", 65);
    if (key == -1) {
    perror("ftok");
    return 1;
    }
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
    perror("msgget");
    return 1;
    }

    msg_buffer message;
    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
    std::cout << "Message Received: " << message.msg_text << std::endl;

    msgctl(msgid, IPC_RMID, NULL); // delete queue
    return 0;
}
