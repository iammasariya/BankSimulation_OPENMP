/*
Author : Team Nirvana - Pranav and Chirag
*/

class teller{
public:
    teller(){};

     void setTellerID(int id){
        tellerID = id;
    }
    int getTellerID()
    {
        return tellerID;
    }

    bool isAvailable(){
        return available;
    }

    bool isOnline(){
        return status;
    }

    void setStatus(bool status)
    {
        this->status = status;
    }

    void setAvailable(bool avail){
        available = avail;
    }

    void custServed()
    {
        this->customerServed++;
    }

    int getCustomerServed()
    {
        return customerServed;
    }


private:
    bool available = false;
    bool status = false;
    int tellerID = 0;
    int customerServed = 0;
};