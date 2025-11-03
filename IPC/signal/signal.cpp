#include<iostream>
#include<csignal>

void SignalHandler(int signum){
    if(signum == SIGINT)
    {
        std::cout<<"Gracefully shutdown"<<std::endl;
    }
    if(signum == SIGTERM){
        std::cout<<"Application Terminated forcefully"<<std::endl;
    }
    if(signum == SIGSEGV){
        std::cout<<"Application Terminated with core dump"<<std::endl;
    }
    if(signum == SIGALRM){
        std::cout<<"Application Terminated with alarm"<<std::endl;
    }
    exit(signum);
}

int main(){

    signal(SIGTERM, SignalHandler);
    signal(SIGINT, SignalHandler);
    signal(SIGSEGV, SignalHandler);
    signal(SIGALRM, SignalHandler);
    alarm(3);
    while(true){
        std::cout<<"Application Running.........."<<getpid()<<std::endl;
    
    }
    return 0;
}
