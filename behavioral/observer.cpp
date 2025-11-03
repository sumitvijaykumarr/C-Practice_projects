#include<iostream>
#include<vector>
#include<algorithm>
//Define Observer interface
//Define subject interface
//Create concreate Subject to broadcast data
//Create concrete observer
class Observer{
    public:
        // double humidity, temperature, pressure;
        virtual void update(double humidity, double temperature, double pressure) = 0;
    virtual ~Observer(){}
};

class Subject{
    public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObserver() = 0;
    virtual ~Subject(){};
};


class WeatherStation : public Subject{
    private:
    std::vector<Observer*> Observers;
    float temp, hum, press;
    public:
    void registerObserver(Observer* observer) override{
        Observers.push_back(observer);
    }
    void removeObserver(Observer* observer) override{
        Observers.erase(std::remove(Observers.begin(), Observers.end(), observer),
        Observers.end());
    }

    void notifyObserver() override{
        for(Observer* observer : Observers){
            observer->update(hum, temp, press);
        }
    }

    void setMeasureMents(double t, double h, double p){
        temp = t;
        hum = h;
        press = p;
        notifyObserver();
    }
};


class Display : public Observer{
    public:
    void update(double temperature, double humidity, double pressure) override{
        std::cout<<"Temperature = "<<temperature
                <<"Humidity = "<<humidity
                <<"Pressure = "<<pressure<<std::endl;
    }
};

int main(){
WeatherStation station;
Display display1;
Display display2;

station.registerObserver(&display1);
station.registerObserver(&display2);

//First Update
station.setMeasureMents(12,13,14);

//Second Update
station.setMeasureMents(10,20,30);

    return 0;
}