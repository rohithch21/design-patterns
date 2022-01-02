/* Weather Station records tempertaure, wind speed and pressure
The Observers - Alert, UserInterface, Logger must use this data from Weather Station to do their corresponding operations
*/

#include<bits/stdc++.h>
using namespace std;

class Observer{ // Abstract Class
    protected:
        float temperature, windSpeed, pressure;
        // string printRandomString(int n)
        // {
        //     char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
        //                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
        //                         'o', 'p', 'q', 'r', 's', 't', 'u',
        //                         'v', 'w', 'x', 'y', 'z' };
        
        //     string res = "";
        //     for (int i = 0; i < n; i++)
        //         res = res + alphabet[rand() % 26];
            
        //     return res;
        // }
        
    public:
        // string uuid;
        // void setUUID(){
        //         this->uuid = printRandomString(3);
        // }
        void update(float t, float ws, float p){
            this->temperature = t;
            this->windSpeed = ws;
            this->pressure = p;
            cout << "All data updated!\n";
        }

};

class ObserverUI : public Observer{
        public:
        // ObserverUI : Observer{
        //     setUUID();
        // }
        void display(){
            cout << "Temperature : " << this->temperature << endl;
            cout << "Wind Speed  : " << this->windSpeed << endl;
            cout << "Pressure    : " << this->pressure << endl;
        }
};

class Alert : public Observer{
    // Alert : Observer{
    //         setUUID();
    //     }
    public:
    void alert(string msg){
        cout << "ALERT : " + msg << endl;
    }
};

class Logger : public Observer{
    // Logger : Observer{
    //         setUUID();
    //     }
    public:
    void log(string msg){
        cout << "LOG : " + msg << endl;
    }
};

class WeatherStation{
    protected:
        float temperature, windSpeed, pressure;
        vector<Observer> observers;
    public:
        void addObserver(Observer o){
            observers.push_back(o);
            cout << "Added Observer\n";
        }
        // void removeObserver(Observer o){
        //     vector<Observer>::iterator itr1;
        //     for(itr1 = observers.begin(); itr1 != observers.end(); itr1++){
        //         if(o == *itr1){
        //             observers.erase(itr1);
        //             break;
        //         }
        //     }
        // }
        void notifyObservers(){
            Observer o;
            vector<Observer>:: iterator itr;
            for(itr = observers.begin(); itr != observers.end(); itr++){
                o = *itr;
                o.update(temperature,windSpeed,pressure);
            }
             
        }
};

class WeatherStationSubject : public WeatherStation{
    public:
    void setValue(float t, float ws, float p){
        this->temperature = t;
        this->windSpeed = ws;
        this->pressure = p;
        notifyObservers();
    }
};

int main(){
    float temprtr = 35.0, windSpeed = 1.5, pressure = 10;

    WeatherStationSubject station;
    Alert alerter;
    ObserverUI ui;
    Logger logger;
    station.addObserver(ui);
    station.addObserver(alerter);
    station.addObserver(logger);
    station.setValue(temprtr, windSpeed, pressure);

    ui.display();
    station.setValue(temprtr+1, windSpeed+2, pressure+3);
    ui.display();
    string status = "Pressure increasing";
    alerter.alert(status);
    logger.log(status);


}