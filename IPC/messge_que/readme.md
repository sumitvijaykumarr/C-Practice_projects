🔍 Line-by-Line Explanation
########################################################################
1. key_t key = ftok("msgfile", 65);
Purpose: Generates a unique key for the message queue.

Details:

ftok() stands for "file to key".

"msgfile" is a filename used to generate the key. The file must exist.

65 is a project identifier (can be any number).

The combination of the file and project ID ensures uniqueness.

Result: key is a unique identifier used to access or create the message queue.
########################################################################
2. int msgid = msgget(key, 0666 | IPC_CREAT);
Purpose: Creates or accesses a message queue.

Details:

msgget() uses the key to locate or create a message queue.

0666 sets read/write permissions for user, group, and others.

IPC_CREAT tells the system to create the queue if it doesn't exist.

Result: msgid is the identifier for the message queue.
########################################################################
3. msg_buffer message;
Purpose: Declares a message structure.

Details:

msg_buffer is a user-defined struct that holds the message.

It typically includes:
msg_type is used to categorize messages.

msg_text holds the actual message content.
########################################################################
4. message.msg_type = 1;
Purpose: Sets the message type.

Details:

Message queues can hold multiple messages of different types.

msg_type = 1 means this message belongs to type 1.
########################################################################
5. strcpy(message.msg_text, "Hello via Message Queue!");
Purpose: Copies the message string into the buffer.

Details:

strcpy() copies the string into msg_text.

This is the actual content that will be sent.
########################################################################
6. msgsnd(msgid, &message, sizeof(message.msg_text), 0);
Purpose: Sends the message to the queue.

Details:

msgsnd() sends the message to the queue identified by msgid.

&message is the pointer to the message.

sizeof(message.msg_text) is the size of the message content (excluding msg_type).

0 means default behavior (no special flags).

Result: The message is placed into the queue for a receiver to read.

This code:

Generates a key using a file.

Creates or accesses a message queue.

Prepares a message.

Sends it to the queue.