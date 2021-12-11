/* 
 PhoneCameraApp {
     take()
     edit()
     save()
     share()
    }
    edit() is an abstract method
    share() method -> text, mail, social media, etc
 
 SubClasses => BasicCamerApp{}, ProCameraApp{}

 */

#include <bits/stdc++.h>
using namespace std;

/*
    Sharing Strategy algorithm can be assigned runtime based on the selection

*/ 
// Interface creation 
class sharingBehavior{
    public:
    virtual void share(){};
};
// End of interface creation

class ShareByText : public sharingBehavior{
    public:
    void share(){
        cout << "Shared by Text\n";
    }
};

class ShareByMail : public sharingBehavior{
    public:
    void share(){
        cout << "Shared by Mail\n";
    }
};

class ShareBySocial : public sharingBehavior{
    public:
    void share(){
        cout << "Uploading picture to social media\n";
    }
};

class PhoneCamera {
    protected:
    sharingBehavior *delegateSharing;
    public:
        void take(){
            cout << "Taking Picture!" << endl;
        }
        virtual void edit() = 0; // Abstract method implemented -> makes this class abstract -> It is not possible to create a object
        // directly from this class. Need to create object of subclass where this logic implemented
        
        void save(){
            cout << "Saving picture!" << endl;
        }

        void setSharing(sharingBehavior *sharingStrategy){
            delegateSharing = sharingStrategy;   
        }

        void share(){
            delegateSharing->share();
        }
        /*
        void share(){
            string shareType;
            cout << "How would you like to share? t - text, m - mail\n" ;
            cin >> shareType;
            if(shareType == "t"){
                cout << "Sending picture by text\n";
            }
            else if(shareType == "m"){
                cout << "Sending picture by mail\n";
            }
            else{
                cout << "Invalid sharing method\n";
            }
        }
        This method requires me to add changes to Super class everytime there is a new share feature. Since its a changing code,
        we need to move this logic out of the super class. 
        */
};


class BasicCameraApp : public PhoneCamera{
    public:
    void edit(){
        cout << "Editing picture using BasicCameraApp!\n";
    }
    
};

class ProCameraApp : public PhoneCamera{
    public:
    void edit(){
        cout << "Editing picture using ProCamerApp!!!!\n";
    }
};

int main(){
    string shareType;
    ProCameraApp b;

    cout << "How would you like to share? t - text, m - mail\n" ;
    cin >> shareType;
    // Sending Object reference implementing interface SharingBehavior
    if(shareType == "t"){
        cout << "User input - text\n";
        b.setSharing(new ShareByText());
        
    }
    else if(shareType == "m"){
        cout << "User input - mail\n";
        b.setSharing(new ShareByMail());
    }
    else if(shareType == "s"){
        cout << "User input - social media\n";
        b.setSharing(new ShareBySocial());
    }
    else{
        cout << "main - Invalid sharing method\n";
    }
    
    b.take();
    b.save();
    b.edit();
    b.share();

    cout << "--------------------------------------------\n";
}