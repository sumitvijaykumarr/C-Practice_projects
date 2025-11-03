#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<unistd.h>


struct shared_data{
    int value;
};

int main(){
    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, sizeof(shared_data), 0666 | IPC_CREAT);
    shared_data* data = (shared_data*) shmat(shmid, NULL, 0);

    int semid = semget(key,1, 0666| IPC_CREAT);

    sembuf lock = {0,-1,0};
    sembuf unlock = {0,1,0};

    for(int i = 1; i<=5; i++){
        semop(semid, &lock, 1);
        std::cout<<"Reader read: "<<data->value<<std::endl;
        semop(semid, &unlock, 1);
        sleep(1);
    }

    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    return 0;

}